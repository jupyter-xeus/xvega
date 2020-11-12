#include <gtest/gtest.h>
#include <xvega/xvega.hpp>

using namespace xv;

TEST(JsonSpecOutput, UrlData)
{
    auto df = url_data().url("https://vega.github.io/vega-datasets/data/cars.json");
    auto fig = Chart().data(df);
    nl::json result = mime_bundle_repr(fig);
    nl::json expected = R"({
                    "$schema": "https://vega.github.io/schema/vega-lite/v4.json",
                    "data": {"url": "https://vega.github.io/vega-datasets/data/cars.json"},
                    "mark": null
                })"_json;
    ASSERT_EQ(expected, result["application/vnd.vegalite.v3+json"]);
}

TEST(JsonSpecOutput, Dataframe)
{
    df_type val;
    val["country"] = {"India", "France", "France", "Germany", "India", "Germany", "France"};
    val["score"]= {25, 57, 23, 19, 8, 47, 8};
    auto df = data_frame().values(val);

    auto fig = Chart().data(df);
    nl::json result = mime_bundle_repr(fig);
    nl::json expected = R"({
                    "$schema": "https://vega.github.io/schema/vega-lite/v4.json",
                    "data": {
                        "values": [
                        {"country": "India", "score": 25},
                        {"country": "France", "score": 57},
                        {"country": "France", "score": 23},
                        {"country": "Germany", "score": 19},
                        {"country": "India", "score": 8},
                        {"country": "Germany", "score": 47},
                        {"country": "France", "score": 8}
                        ]
                    },
                    "mark": null
                })"_json;
    ASSERT_EQ(expected, result["application/vnd.vegalite.v3+json"]);
}

TEST(JsonSpecOutput, SequenceGenerator)
{
    auto seq = sequence_params().start(0).stop(12.7).step(0.1).as("x");
    auto df = sequence_generator().sequence(seq);

    auto fig = Chart().data(df);
    nl::json result = mime_bundle_repr(fig);
    nl::json expected = R"({
                    "$schema": "https://vega.github.io/schema/vega-lite/v4.json",
                    "data": {"sequence": {"as": "x", "start": 0, "step": 0.1, "stop": 12.7}},
                    "mark": null
                })"_json;
    ASSERT_EQ(expected, result["application/vnd.vegalite.v3+json"]);
}

