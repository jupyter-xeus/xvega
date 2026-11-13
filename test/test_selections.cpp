#include "doctest/doctest.h"
#include <xvega/xvega.hpp>

using namespace xv;

TEST_SUITE("JsonSpecOutput")
{
TEST_CASE("IntervalSelection")
{
    auto df = url_data();
    df.url = "https://vega.github.io/vega-datasets/data/cars.json";
    auto mp = mark_point();
    auto x_enc = X();
    x_enc.field = "Miles_per_Gallon";
    x_enc.type = "quantitative";
    auto y_enc = Y();
    y_enc.field = "Horsepower";
    y_enc.type = "quantitative";
    auto color_enc = Color();
    color_enc.field = "Origin";
    color_enc.type = "nominal";
    auto enc = Encodings();
    enc.x = x_enc;
    enc.y = y_enc;
    enc.color = color_enc;
    auto si = selection_interval();

    auto fig = Chart();
    fig.data = df;
    fig.mark = mp;
    fig.encoding = enc;
    fig.selections = std::vector<selection_type>{si};
    fig.width = 400;
    fig.height = 300;
    nl::json result = mime_bundle_repr(fig);

    result["application/vnd.vegalite.v3+json"].erase("selection");
    result["application/vnd.vegalite.v3+json"]["selection"]["selector_interval_nws23"]["type"] = "interval";

    nl::json expected = R"({
                    "$schema": "https://vega.github.io/schema/vega-lite/v4.json",
                    "data": {"url": "https://vega.github.io/vega-datasets/data/cars.json"},
                    "encoding": {
                        "color": {"field": "Origin", "type": "nominal"},
                        "x": {"field": "Miles_per_Gallon", "type": "quantitative"},
                        "y": {"field": "Horsepower", "type": "quantitative"}
                    },
                    "height": 300,
                    "mark": {"type": "point"},
                    "selection": {"selector_interval_nws23": {"type": "interval"}},
                    "width": 400
                })"_json;
    REQUIRE_EQ(expected, result["application/vnd.vegalite.v3+json"]);
}
}
