#include "doctest/doctest.h"
#include <xvega/xvega.hpp>

using namespace xv;

TEST_SUITE("JsonSpecOutput")
{
TEST_CASE("SingleTransformationWithLayering")
{
    auto df = url_data().url("https://vega.github.io/vega-datasets/data/cars.json");
    auto mp = mark_point();
    auto ml = mark_line().color("firebrick");
    auto x_enc = X().field("Miles_per_Gallon").type("quantitative");
    auto y_enc = Y().field("Horsepower").type("quantitative");
    auto enc = Encodings().x(x_enc).y(y_enc);
    auto regr = transform_regression().regression("Horsepower").on("Miles_per_Gallon").method("poly");
    auto fig = Chart().data(df).mark(mp).encoding(enc).width(400).height(300);
    auto fig2 = Chart().data(df).mark(ml).encoding(enc).transformations({regr}).width(400).height(300);
    auto fig3 = layer().charts({fig, fig2});
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
    auto df = url_data().url("https://vega.github.io/vega-datasets/data/cars.json");

    auto agg_field = aggregate_field_def().op("count").as("count_*");
    std::vector<std::string> group_fields = {"Origin", "Cylinders"};
    auto agg_vec = {agg_field};
    auto agg = transform_aggregate().aggregate(agg_vec).groupby(group_fields);

    auto sort_field = sort_field_def().field("Origin").order("ascending");
    auto sort_vec = {sort_field};
    std::vector<std::string> as_fields = {"stack_count_Origin1", "stack_count_Origin2"};
    std::vector<std::string> emp = {};
    auto stck = transform_stack().stack("count_*").offset("normalize").sort(sort_vec).as(as_fields).groupby(emp);

    auto join_agg_field_1 = join_aggregate_field_def().op("min").field("stack_count_Origin1").as("x");
    auto join_agg_field_2 = join_aggregate_field_def().op("max").field("stack_count_Origin2").as("x2");
    auto join_agg_vec = {join_agg_field_1, join_agg_field_2};
    std::vector<std::string> grp_vec = {"Origin"};
    auto join_agg = transform_join_aggregate().joinaggregate(join_agg_vec).groupby(grp_vec);

    std::vector<std::string> as_fields_2 = {"y", "y2"};
    auto sort_field_2 = sort_field_def().field("Cylinders").order("ascending");
    auto sort_vec_2 = {sort_field};

    auto stck_2 = transform_stack().stack("count_*").offset("normalize").sort(sort_vec_2).as(as_fields_2).groupby(grp_vec);

    auto mr = mark_rect();

    auto x_enc = X().field("x").type("quantitative").axis(nullptr);
    auto x2_enc = X2().field("x2");
    auto y_enc = Y().field("y").type("quantitative").axis(nullptr);
    auto y2_enc = Y2().field("y2");

    auto opacity_enc = Opacity().field("Cylinders").type("quantitative").legend(nullptr);

    auto color_enc = Color().field("Origin").type("nominal");

    auto tooltip_enc_1 = Tooltip().field("Origin").type("nominal");
    auto tooltip_enc_2 = Tooltip().field("Cylinders").type("quantitative");
    auto t = {tooltip_enc_1, tooltip_enc_2};

    auto enc = Encodings().x(x_enc).y(y_enc).x2(x2_enc).y2(y2_enc).opacity(opacity_enc).tooltip(t).color(color_enc);

    auto fig = Chart().data(df).mark(mr).encoding(enc).transformations({agg, stck, join_agg, stck_2});
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
