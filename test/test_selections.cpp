#include <gtest/gtest.h>
#include <xvega/xvega.hpp>

using namespace xv;

TEST(JsonSpecOutput, IntervalSelection)
{
    auto df = url_data().url("https://vega.github.io/vega-datasets/data/cars.json");
    auto mp = mark_point();
    auto x_enc = X().field("Miles_per_Gallon").type("quantitative");
    auto y_enc = Y().field("Horsepower").type("quantitative");
    auto color_enc = Color().field("Origin").type("nominal");
    auto enc = Encodings().x(x_enc).y(y_enc).color(color_enc);
    auto si = selection_interval();

    auto fig = Chart().data(df).mark(mp).encoding(enc).selections({si}).width(400).height(300);
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
    ASSERT_EQ(expected, result["application/vnd.vegalite.v3+json"]);
}
