#include "doctest/doctest.h"
#include <xvega/xvega.hpp>

using namespace xv;
TEST_SUITE("JsonSpecOutput")
{
TEST_CASE("SingleEncodingChannel")
{
    auto df = url_data();
    df.url = "https://vega.github.io/vega-datasets/data/cars.json";
    auto mp = mark_point();
    auto x_enc = X();
    x_enc.field = "Miles_per_Gallon";
    x_enc.type = "quantitative";
    auto enc = Encodings();
    enc.x = x_enc;
    auto fig = Chart();
    fig.data = df;
    fig.mark = mp;
    fig.encoding = enc;
    fig.width = 400;

    nl::json result = mime_bundle_repr(fig);
    nl::json expected = R"({
                    "$schema": "https://vega.github.io/schema/vega-lite/v4.json",
                    "data": {"url": "https://vega.github.io/vega-datasets/data/cars.json"},
                    "encoding": {"x": {"field": "Miles_per_Gallon", "type": "quantitative"}},
                    "mark": {"type": "point"},
                    "width": 400
                })"_json;
    REQUIRE_EQ(expected, result["application/vnd.vegalite.v3+json"]);
}

TEST_CASE("DoubleEncodingChannel")
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
    auto fig = Chart();
    fig.data = df;
    fig.mark = mp;
    fig.encoding = enc;
    fig.title = "Simple 2D Chart";
    fig.width = 400;
    fig.height = 300;

    nl::json result = mime_bundle_repr(fig);
    nl::json expected = R"({
                    "$schema": "https://vega.github.io/schema/vega-lite/v4.json",
                    "data": {"url": "https://vega.github.io/vega-datasets/data/cars.json"},
                    "encoding": {
                        "x": {"field": "Miles_per_Gallon", "type": "quantitative"},
                        "y": {"field": "Horsepower", "type": "quantitative"}
                    },
                    "height": 300,
                    "mark": {"type": "point"},
                    "title": "Simple 2D Chart",
                    "width": 400
                })"_json;
    REQUIRE_EQ(expected, result["application/vnd.vegalite.v3+json"]);
}

TEST_CASE("TripleEncodingChannel")
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
    auto fig = Chart();
    fig.data = df;
    fig.mark = mp;
    fig.encoding = enc;
    fig.width = 400;
    fig.height = 300;

    nl::json result = mime_bundle_repr(fig);
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
                    "width": 400
                })"_json;
    REQUIRE_EQ(expected, result["application/vnd.vegalite.v3+json"]);
}

TEST_CASE("DoubleEncodingWithChannelOptions")
{
    auto df = url_data();
    df.url = "https://vega.github.io/vega-datasets/data/cars.json";
    auto mb = mark_bar();
    auto bin_params = Bin();
    bin_params.maxbins = 30;
    auto x_enc = X();
    x_enc.field = "Miles_per_Gallon";
    x_enc.type = "quantitative";
    x_enc.bin = bin_params;
    auto y_enc = Y();
    y_enc.aggregate = "count";
    auto enc = Encodings();
    enc.x = x_enc;
    enc.y = y_enc;
    auto fig = Chart();
    fig.data = df;
    fig.mark = mb;
    fig.encoding = enc;
    fig.width = 400;
    fig.height = 300;

    nl::json result = mime_bundle_repr(fig);
    nl::json expected = R"({
                    "$schema": "https://vega.github.io/schema/vega-lite/v4.json",
                    "data": {"url": "https://vega.github.io/vega-datasets/data/cars.json"},
                    "encoding": {
                        "x": {
                            "bin": {"maxbins": 30},
                            "field": "Miles_per_Gallon",
                            "type": "quantitative"
                        },
                        "y": {"aggregate": "count"}
                    },
                    "height": 300,
                    "mark": {"type": "bar"},
                    "width": 400
                })"_json;
    REQUIRE_EQ(expected, result["application/vnd.vegalite.v3+json"]);
}
}
