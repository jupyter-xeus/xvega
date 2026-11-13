#include "doctest/doctest.h"
#include <xvega/xvega.hpp>

using namespace xv;

TEST_SUITE("JsonSpecOutput")
{
TEST_CASE("HorizontalConcatenation")
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

    x_enc = X();
    x_enc.field = "Acceleration";
    x_enc.type = "quantitative";
    auto enc_2 = Encodings();
    enc_2.x = x_enc;
    enc_2.y = y_enc;
    enc_2.color = color_enc;

    auto fig = Chart();
    fig.data = df;
    fig.mark = mp;
    fig.encoding = enc;
    fig.width = 400;
    fig.height = 300;
    auto fig2 = Chart();
    fig2.data = df;
    fig2.mark = mp;
    fig2.encoding = enc_2;
    fig2.width = 400;
    fig2.height = 300;

    auto fig3 = hconcat();
    fig3.charts = std::vector<Chart>{fig, fig2};
    nl::json result = mime_bundle_repr(fig3);
    nl::json expected = R"({
                    "$schema": "https://vega.github.io/schema/vega-lite/v4.json",
                    "data": {"url": "https://vega.github.io/vega-datasets/data/cars.json"},
                    "hconcat": [
                        {
                            "encoding": {
                                "color": {"field": "Origin", "type": "nominal"},
                                "x": {"field": "Miles_per_Gallon", "type": "quantitative"},
                                "y": {"field": "Horsepower", "type": "quantitative"}
                            },
                            "height": 300,
                            "mark": {"type": "point"},
                            "width": 400
                        },
                        {
                            "encoding": {
                                "color": {"field": "Origin", "type": "nominal"},
                                "x": {"field": "Acceleration", "type": "quantitative"},
                                "y": {"field": "Horsepower", "type": "quantitative"}
                            },
                            "height": 300,
                            "mark": {"type": "point"},
                            "width": 400
                        }
                    ]
                })"_json;
    REQUIRE_EQ(expected, result["application/vnd.vegalite.v3+json"]);
}

TEST_CASE("VerticalConcatenation")
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

    x_enc = X();
    x_enc.field = "Acceleration";
    x_enc.type = "quantitative";
    auto enc_2 = Encodings();
    enc_2.x = x_enc;
    enc_2.y = y_enc;
    enc_2.color = color_enc;

    auto fig = Chart();
    fig.data = df;
    fig.mark = mp;
    fig.encoding = enc;
    fig.width = 400;
    fig.height = 300;
    auto fig2 = Chart();
    fig2.data = df;
    fig2.mark = mp;
    fig2.encoding = enc_2;
    fig2.width = 400;
    fig2.height = 300;

    auto fig3 = vconcat();
    fig3.charts = std::vector<Chart>{fig, fig2};
    nl::json result = mime_bundle_repr(fig3);
    nl::json expected = R"({
                    "$schema": "https://vega.github.io/schema/vega-lite/v4.json",
                    "data": {"url": "https://vega.github.io/vega-datasets/data/cars.json"},
                    "vconcat": [
                        {
                            "encoding": {
                                "color": {"field": "Origin", "type": "nominal"},
                                "x": {"field": "Miles_per_Gallon", "type": "quantitative"},
                                "y": {"field": "Horsepower", "type": "quantitative"}
                            },
                            "height": 300,
                            "mark": {"type": "point"},
                            "width": 400
                        },
                        {
                            "encoding": {
                                "color": {"field": "Origin", "type": "nominal"},
                                "x": {"field": "Acceleration", "type": "quantitative"},
                                "y": {"field": "Horsepower", "type": "quantitative"}
                            },
                            "height": 300,
                            "mark": {"type": "point"},
                            "width": 400
                        }
                    ]
                })"_json;
    REQUIRE_EQ(expected, result["application/vnd.vegalite.v3+json"]);
}

TEST_CASE("Layering")
{
    auto df = url_data();
    df.url = "https://vega.github.io/vega-datasets/data/cars.json";
    auto mp = mark_point();
    auto ml = mark_line();
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
    auto fig2 = Chart();
    fig2.data = df;
    fig2.mark = ml;
    fig2.encoding = enc;
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
                                "color": {"field": "Origin", "type": "nominal"},
                                "x": {"field": "Miles_per_Gallon", "type": "quantitative"},
                                "y": {"field": "Horsepower", "type": "quantitative"}
                            },
                            "height": 300,
                            "mark": {"type": "point"},
                            "width": 400
                        },
                        {
                            "encoding": {
                                "color": {"field": "Origin", "type": "nominal"},
                                "x": {"field": "Miles_per_Gallon", "type": "quantitative"},
                                "y": {"field": "Horsepower", "type": "quantitative"}
                            },
                            "height": 300,
                            "mark": {"type": "line"},
                            "width": 400
                        }
                    ]
                })"_json;
    REQUIRE_EQ(expected, result["application/vnd.vegalite.v3+json"]);
}
}
