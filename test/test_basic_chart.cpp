#include <gtest/gtest.h>
#include <xvega/xvega.hpp>

using namespace xv;

TEST(JsonSpecOutput, BasicChart)
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

int main(int argc, char **argv) 
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}