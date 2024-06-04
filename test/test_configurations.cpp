#include "doctest/doctest.h"
#include <xvega/xvega.hpp>

using namespace xv;

TEST_SUITE("JsonSpecOutput")
{
TEST_CASE("DoubleGlobalConfig")
{
    auto df = url_data().url("https://vega.github.io/vega-datasets/data/cars.json");
    auto mp = mark_point();
    auto x_enc = X().field("Miles_per_Gallon").type("quantitative");
    auto y_enc = Y().field("Horsepower").type("quantitative");
    auto enc = Encodings().x(x_enc).y(y_enc);

    auto ac = axis_config().grid(false);
    auto pc = mark_config().filled(true).size(200).color("red");
    auto cf = Config().point(pc).axis(ac);

    auto fig = Chart().data(df).mark(mp).encoding(enc).config(cf).width(400).height(300);
    nl::json result = mime_bundle_repr(fig);
    nl::json expected = R"({
                    "$schema": "https://vega.github.io/schema/vega-lite/v4.json",
                    "config": {
                        "axis": {"grid": false},
                        "point": {"color": "red", "filled": true, "size": 200}
                    },
                    "data": {"url": "https://vega.github.io/vega-datasets/data/cars.json"},
                    "encoding": {
                        "x": {"field": "Miles_per_Gallon", "type": "quantitative"},
                        "y": {"field": "Horsepower", "type": "quantitative"}
                    },
                    "height": 300,
                    "mark": {"type": "point"},
                    "width": 400
                })"_json;
    REQUIRE_EQ(expected, result["application/vnd.vegalite.v3+json"]);
}
}
