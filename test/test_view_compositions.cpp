#include <gtest/gtest.h>
#include <xvega/xvega.hpp>

using namespace xv;

TEST(JsonSpecOutput, HorizontalConcatenation)
{
    auto df = url_data().url("https://vega.github.io/vega-datasets/data/cars.json");
    auto mp = mark_point();

    auto x_enc = X().field("Miles_per_Gallon").type("quantitative");
    auto y_enc = Y().field("Horsepower").type("quantitative");
    auto color_enc = Color().field("Origin").type("nominal");

    auto enc = Encodings().x(x_enc).y(y_enc).color(color_enc);

    x_enc = X().field("Acceleration").type("quantitative");
    auto enc_2 = Encodings().x(x_enc).y(y_enc).color(color_enc);

    auto fig = Chart().data(df).mark(mp).encoding(enc).width(400).height(300);
    auto fig2 = Chart().data(df).mark(mp).encoding(enc_2).width(400).height(300);

    auto fig3 = hconcat().charts({fig, fig2});
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
    ASSERT_EQ(expected, result["application/vnd.vegalite.v3+json"]);
}

TEST(JsonSpecOutput, VerticalConcatenation)
{
    auto df = url_data().url("https://vega.github.io/vega-datasets/data/cars.json");
    auto mp = mark_point();

    auto x_enc = X().field("Miles_per_Gallon").type("quantitative");
    auto y_enc = Y().field("Horsepower").type("quantitative");
    auto color_enc = Color().field("Origin").type("nominal");

    auto enc = Encodings().x(x_enc).y(y_enc).color(color_enc);

    x_enc = X().field("Acceleration").type("quantitative");
    auto enc_2 = Encodings().x(x_enc).y(y_enc).color(color_enc);

    auto fig = Chart().data(df).mark(mp).encoding(enc).width(400).height(300);
    auto fig2 = Chart().data(df).mark(mp).encoding(enc_2).width(400).height(300);

    auto fig3 = vconcat().charts({fig, fig2});
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
    ASSERT_EQ(expected, result["application/vnd.vegalite.v3+json"]);
}

TEST(JsonSpecOutput, Layering)
{
    auto df = url_data().url("https://vega.github.io/vega-datasets/data/cars.json");
    auto mp = mark_point();
    auto ml = mark_line();
    auto x_enc = X().field("Miles_per_Gallon").type("quantitative");
    auto y_enc = Y().field("Horsepower").type("quantitative");
    auto color_enc = Color().field("Origin").type("nominal");
    auto enc = Encodings().x(x_enc).y(y_enc).color(color_enc);
    auto fig = Chart().data(df).mark(mp).encoding(enc).width(400).height(300);
    auto fig2 = Chart().data(df).mark(ml).encoding(enc).width(400).height(300);
    auto fig3 = layer().charts({fig, fig2});
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
    ASSERT_EQ(expected, result["application/vnd.vegalite.v3+json"]);
}
