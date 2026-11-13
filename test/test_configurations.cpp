#include "doctest/doctest.h"
#include <xvega/xvega.hpp>

using namespace xv;

TEST_SUITE("JsonSpecOutput")
{
TEST_CASE("DoubleGlobalConfig")
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
    auto enc = Encodings();
    enc.x = x_enc;
    enc.y = y_enc;

    auto ac = axis_config();
    ac.grid = false;
    auto pc = mark_config();
    pc.filled = true;
    pc.size = 200;
    pc.color = "red";
    auto cf = Config();
    cf.point = pc;
    cf.axis = ac;

    auto fig = Chart();
    fig.data = df;
    fig.mark = mp;
    fig.encoding = enc;
    fig.config = cf;
    fig.width = 400;
    fig.height = 300;
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
