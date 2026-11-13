#include "doctest/doctest.h"
#include <xvega/xvega.hpp>

using namespace xv;

TEST_SUITE("JsonSpecOutput")
{
TEST_CASE("UrlData")
{
    auto df = url_data();
    df.url = "https://vega.github.io/vega-datasets/data/cars.json";
    auto fig = Chart();
    fig.data = df;
    nl::json result = mime_bundle_repr(fig);
    nl::json expected = R"({
                    "$schema": "https://vega.github.io/schema/vega-lite/v4.json",
                    "data": {"url": "https://vega.github.io/vega-datasets/data/cars.json"},
                    "mark": null
                })"_json;
    REQUIRE_EQ(expected, result["application/vnd.vegalite.v3+json"]);
}

TEST_CASE("Dataframe")
{
    df_type val;
    val["country"] = {"India", "France", "France", "Germany", "India", "Germany", "France"};
    val["score"]= {25, 57, 23, 19, 8, 47, 8};
    auto df = data_frame();
    df.values = val;

    auto fig = Chart();
    fig.data = df;
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
    REQUIRE_EQ(expected, result["application/vnd.vegalite.v3+json"]);
}

TEST_CASE("SequenceGenerator")
{
    auto seq = sequence_params();
    seq.start = 0;
    seq.stop = 12.7;
    seq.step = 0.1;
    seq.as = "x";
    auto df = sequence_generator();
    df.sequence = seq;

    auto fig = Chart();
    fig.data = df;
    nl::json result = mime_bundle_repr(fig);
    nl::json expected = R"({
                    "$schema": "https://vega.github.io/schema/vega-lite/v4.json",
                    "data": {"sequence": {"as": "x", "start": 0, "step": 0.1, "stop": 12.7}},
                    "mark": null
                })"_json;
    REQUIRE_EQ(expected, result["application/vnd.vegalite.v3+json"]);
}
}

