#include <catch2/catch_test_macros.hpp>
#include "services/rule_service.hpp"

TEST_CASE("Rule creation") {
    RuleService rs;

    auto rule = rs.createRule("r1", "greater_than", { {"value", "5"} });

    REQUIRE(rule.id == "r1");
    REQUIRE(rule.type == "greater_than");
}
