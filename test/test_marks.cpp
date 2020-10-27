#include <gtest/gtest.h>
#include <xvega/xvega.hpp>

using namespace xv;

TEST(JsonSpecOutput, MarkPoint)
{
    auto df = url_data().url("https://vega.github.io/vega-datasets/data/cars.json");
    auto mp = mark_point();
    auto fig = Chart().data(df).mark(mp);
    nl::json result = mime_bundle_repr(fig);
    nl::json expected = R"({
                    "$schema": "https://vega.github.io/schema/vega-lite/v4.json",
                    "data": {"url": "https://vega.github.io/vega-datasets/data/cars.json"},
                    "mark": {"type": "point"}
                })"_json;
    ASSERT_EQ(expected, result["application/vnd.vegalite.v3+json"]);
}

TEST(JsonSpecOutput, MarkPointWithCommonProperty)
{
    auto df = url_data().url("https://vega.github.io/vega-datasets/data/cars.json");
    auto mp = mark_point().color("red");
    auto fig = Chart().data(df).mark(mp);
    nl::json result = mime_bundle_repr(fig);
    nl::json expected = R"({
                    "$schema": "https://vega.github.io/schema/vega-lite/v4.json",
                    "data": {"url": "https://vega.github.io/vega-datasets/data/cars.json"},
                    "mark": {"color": "red", "type": "point"}
                })"_json;
    ASSERT_EQ(expected, result["application/vnd.vegalite.v3+json"]);
}

TEST(JsonSpecOutput, MarkPointWithSpecificProperty)
{
    auto df = url_data().url("https://vega.github.io/vega-datasets/data/cars.json");
    auto mp = mark_point().color("red").size(100);
    auto fig = Chart().data(df).mark(mp);
    nl::json result = mime_bundle_repr(fig);
    nl::json expected = R"({
                    "$schema": "https://vega.github.io/schema/vega-lite/v4.json",
                    "data": {"url": "https://vega.github.io/vega-datasets/data/cars.json"},
                    "mark": {"color": "red", "size": 100, "type": "point"}
                })"_json;
    ASSERT_EQ(expected, result["application/vnd.vegalite.v3+json"]);
}
