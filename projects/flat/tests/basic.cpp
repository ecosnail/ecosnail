#define CATCH_CONFIG_MAIN
#include <catch2/catch.hpp>

#include <ecosnail/flat.hpp>

namespace flat = ecosnail::flat;

TEST_CASE("Vector addition")
{
    auto v1 = flat::Vector{1, 2};
    auto v2 = flat::Vector{3, 4};

    auto v3 = v1 + v2;
    REQUIRE(v3.x == 4);
    REQUIRE(v3.y == 6);
}
