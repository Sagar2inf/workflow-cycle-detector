#include <catch2/catch_test_macros.hpp>
#include "workflow/validator.hpp"
#include "workflow/graph.hpp"
#include "workflow/node.hpp"
#include "workflow/edge.hpp"

TEST_CASE("Cycle detection - no cycle") {
    Graph g;
    g.addNode("A");
    g.addNode("B");
    g.addEdge("A", "B");

    Validator v;
    auto result = v.detectCycle(g);
    REQUIRE(result.hasCycle == false);
}

TEST_CASE("Cycle detection - simple cycle") {
    Graph g;
    g.addNode("A");
    g.addNode("B");
    g.addEdge("A", "B");
    g.addEdge("B", "A");

    Validator v;
    auto result = v.detectCycle(g);
    REQUIRE(result.hasCycle == true);
}
