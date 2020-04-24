#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "twosum.h"

TEST_CASE("two sum","twoSum")
{
    Solution s;
    std::vector<int> v1{2,17,11,15};
    REQUIRE((s.twoSum(v1,9))==std::vector<int>{0,1});

}