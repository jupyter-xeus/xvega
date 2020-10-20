#include <gtest/gtest.h>
#include <xvega/xvega.hpp>

using namespace xv;

TEST(JsonSpecOutput, SingleEncodingChannel)
{
    auto df = url_data().url("https://vega.github.io/vega-datasets/data/cars.json");
    auto mp = mark_point();
    auto x_enc = X().field("Miles_per_Gallon").type("quantitative");
    auto enc = Encodings().x(x_enc);
    auto fig = Chart().data(df).mark(mp).encoding(enc).width(400);

    nl::json result = mime_bundle_repr(fig);
    nl::json expected = R"({
                    "$schema": "https://vega.github.io/schema/vega-lite/v4.json",
                    "data": {"url": "https://vega.github.io/vega-datasets/data/cars.json"},
                    "encoding": {"x": {"field": "Miles_per_Gallon", "type": "quantitative"}},
                    "mark": {"type": "point"},
                    "width": 400
                })"_json;
    ASSERT_EQ(expected, result["application/vnd.vegalite.v3+json"]);
}

TEST(JsonSpecOutput, DoubleEncodingChannel)
{
    auto df = url_data().url("https://vega.github.io/vega-datasets/data/cars.json");
    auto mp = mark_point();
    auto x_enc = X().field("Miles_per_Gallon").type("quantitative");
    auto y_enc = Y().field("Horsepower").type("quantitative");
    auto enc = Encodings().x(x_enc).y(y_enc);
    auto fig = Chart().data(df).mark(mp).encoding(enc).width(400).height(300);

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
                    "width": 400
                })"_json;
    ASSERT_EQ(expected, result["application/vnd.vegalite.v3+json"]);
}

TEST(JsonSpecOutput, TripleEncodingChannel)
{
    auto df = url_data().url("https://vega.github.io/vega-datasets/data/cars.json");
    auto mp = mark_point();
    auto x_enc = X().field("Miles_per_Gallon").type("quantitative");
    auto y_enc = Y().field("Horsepower").type("quantitative");
    auto color_enc = Color().field("Origin").type("nominal");
    auto enc = Encodings().x(x_enc).y(y_enc).color(color_enc);
    auto fig = Chart().data(df).mark(mp).encoding(enc).width(400).height(300);

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
    ASSERT_EQ(expected, result["application/vnd.vegalite.v3+json"]);
}

TEST(JsonSpecOutput, DoubleEncodingWithChannelOptions)
{
    auto df = url_data().url("https://vega.github.io/vega-datasets/data/cars.json");
    auto mb = mark_bar();
    auto bin_params = Bin().maxbins(30);
    auto x_enc = X().field("Miles_per_Gallon").type("quantitative").bin(bin_params);
    auto y_enc = Y().aggregate("count");
    auto enc = Encodings().x(x_enc).y(y_enc);
    auto fig = Chart().data(df).mark(mb).encoding(enc).width(400).height(300);

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
    ASSERT_EQ(expected, result["application/vnd.vegalite.v3+json"]);
}
