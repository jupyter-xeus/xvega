#include "doctest/doctest.h"
#include <xvega/xvega.hpp>

using namespace xv;

TEST_SUITE("JsonSpecOutput")
{
TEST_CASE("SingleTransformationWithLayering")
{
    auto df = url_data();
    df.url = "https://vega.github.io/vega-datasets/data/cars.json";
    auto mp = mark_point();
    auto ml = mark_line();
    ml.color = "firebrick";
    auto x_enc = X();
    x_enc.field = "Miles_per_Gallon";
    x_enc.type = "quantitative";
    auto y_enc = Y();
    y_enc.field = "Horsepower";
    y_enc.type = "quantitative";
    auto enc = Encodings();
    enc.x = x_enc;
    enc.y = y_enc;
    auto regr = transform_regression();
    regr.regression = "Horsepower";
    regr.on = "Miles_per_Gallon";
    regr.method = "poly";
    auto fig = Chart();
    fig.data = df;
    fig.mark = mp;
    fig.encoding = enc;
    fig.width = 400;
    fig.height = 300;
    auto fig2 = Chart();
    fig2.data = df;
    fig2.mark = ml;
    fig2.encoding = enc;
    fig2.transformations = std::vector<transform_type>{regr};
    fig2.width = 400;
    fig2.height = 300;
    auto fig3 = layer();
    fig3.charts = std::vector<Chart>{fig, fig2};
    nl::json result = mime_bundle_repr(fig3);
    nl::json expected = R"({
                    "$schema": "https://vega.github.io/schema/vega-lite/v4.json",
                    "data": {"url": "https://vega.github.io/vega-datasets/data/cars.json"},
                    "layer": [
                        {
                            "encoding": {
                                "x": {"field": "Miles_per_Gallon", "type": "quantitative"},
                                "y": {"field": "Horsepower", "type": "quantitative"}
                            },
                            "height": 300,
                            "mark": {"type": "point"},
                            "width": 400
                        },
                        {
                            "encoding": {
                                "x": {"field": "Miles_per_Gallon", "type": "quantitative"},
                                "y": {"field": "Horsepower", "type": "quantitative"}
                            },
                            "height": 300,
                            "mark": {"color": "firebrick", "type": "line"},
                            "transform": [
                                {"method": "poly", "on": "Miles_per_Gallon", "regression": "Horsepower"}
                            ],
                            "width": 400
                        }
                    ]
                })"_json;
    REQUIRE_EQ(expected, result["application/vnd.vegalite.v3+json"]);
}

TEST_CASE("MultipleTransformations")
{
    auto df = url_data();
    df.url = "https://vega.github.io/vega-datasets/data/cars.json";

    auto agg_field = aggregate_field_def();
    agg_field.op = "count";
    agg_field.as = "count_*";
    std::vector<std::string> group_fields = {"Origin", "Cylinders"};
    auto agg_vec = {agg_field};
    auto agg = transform_aggregate();
    agg.aggregate = agg_vec;
    agg.groupby = group_fields;

    auto sort_field = sort_field_def();
    sort_field.field = "Origin";
    sort_field.order = "ascending";
    auto sort_vec = {sort_field};
    std::vector<std::string> as_fields = {"stack_count_Origin1", "stack_count_Origin2"};
    std::vector<std::string> emp = {};
    auto stck = transform_stack();
    stck.stack = "count_*";
    stck.offset = "normalize";
    stck.sort = sort_vec;
    stck.as = as_fields;
    stck.groupby = emp;

    auto join_agg_field_1 = join_aggregate_field_def();
    join_agg_field_1.op = "min";
    join_agg_field_1.field = "stack_count_Origin1";
    join_agg_field_1.as = "x";
    auto join_agg_field_2 = join_aggregate_field_def();
    join_agg_field_2.op = "max";
    join_agg_field_2.field = "stack_count_Origin2";
    join_agg_field_2.as = "x2";
    auto join_agg_vec = {join_agg_field_1, join_agg_field_2};
    std::vector<std::string> grp_vec = {"Origin"};
    auto join_agg = transform_join_aggregate();
    join_agg.joinaggregate = join_agg_vec;
    join_agg.groupby = grp_vec;

    std::vector<std::string> as_fields_2 = {"y", "y2"};
    auto sort_field_2 = sort_field_def();
    sort_field_2.field = "Cylinders";
    sort_field_2.order = "ascending";
    auto sort_vec_2 = {sort_field};

    auto stck_2 = transform_stack();
    stck_2.stack = "count_*";
    stck_2.offset = "normalize";
    stck_2.sort = sort_vec_2;
    stck_2.as = as_fields_2;
    stck_2.groupby = grp_vec;

    auto mr = mark_rect();

    auto x_enc = X();
    x_enc.field = "x";
    x_enc.type = "quantitative";
    x_enc.axis = nullptr;
    auto x2_enc = X2();
    x2_enc.field = "x2";
    auto y_enc = Y();
    y_enc.field = "y";
    y_enc.type = "quantitative";
    y_enc.axis = nullptr;
    auto y2_enc = Y2();
    y2_enc.field = "y2";

    auto opacity_enc = Opacity();
    opacity_enc.field = "Cylinders";
    opacity_enc.type = "quantitative";
    opacity_enc.legend = nullptr;

    auto color_enc = Color();
    color_enc.field = "Origin";
    color_enc.type = "nominal";

    auto tooltip_enc_1 = Tooltip();
    tooltip_enc_1.field = "Origin";
    tooltip_enc_1.type = "nominal";
    auto tooltip_enc_2 = Tooltip();
    tooltip_enc_2.field = "Cylinders";
    tooltip_enc_2.type = "quantitative";
    auto t = {tooltip_enc_1, tooltip_enc_2};

    auto enc = Encodings();
    enc.x = x_enc;
    enc.y = y_enc;
    enc.x2 = x2_enc;
    enc.y2 = y2_enc;
    enc.opacity = opacity_enc;
    enc.tooltip = t;
    enc.color = color_enc;

    auto fig = Chart();
    fig.data = df;
    fig.mark = mr;
    fig.encoding = enc;
    fig.transformations = std::vector<transform_type>{agg, stck, join_agg, stck_2};
    nl::json result = mime_bundle_repr(fig);
    nl::json expected = R"({
                    "$schema": "https://vega.github.io/schema/vega-lite/v4.json",
                    "data": {"url": "https://vega.github.io/vega-datasets/data/cars.json"},
                    "encoding": {
                        "color": {"field": "Origin", "type": "nominal"},
                        "opacity": {"field": "Cylinders", "legend": null, "type": "quantitative"},
                        "tooltip": [
                            {"field": "Origin", "type": "nominal"},
                            {"field": "Cylinders", "type": "quantitative"}
                        ],
                        "x": {"axis": null, "field": "x", "type": "quantitative"},
                        "x2": {"field": "x2"},
                        "y": {"axis": null, "field": "y", "type": "quantitative"},
                        "y2": {"field": "y2"}
                    },
                    "mark": {"type": "rect"},
                    "transform": [
                        {
                            "aggregate": [{"as": "count_*", "op": "count"}],
                            "groupby": ["Origin", "Cylinders"]
                        },
                        {
                            "as": ["stack_count_Origin1", "stack_count_Origin2"],
                            "groupby": [],
                            "offset": "normalize",
                            "sort": [{"field": "Origin", "order": "ascending"}],
                            "stack": "count_*"
                        },
                        {
                            "groupby": ["Origin"],
                            "joinaggregate": [
                                {"as": "x", "field": "stack_count_Origin1", "op": "min"},
                                {"as": "x2", "field": "stack_count_Origin2", "op": "max"}
                            ]
                        },
                        {
                            "as": ["y", "y2"],
                            "groupby": ["Origin"],
                            "offset": "normalize",
                            "sort": [{"field": "Origin", "order": "ascending"}],
                            "stack": "count_*"
                        }
                    ]
                })"_json;
    REQUIRE_EQ(expected, result["application/vnd.vegalite.v3+json"]);
}
}
