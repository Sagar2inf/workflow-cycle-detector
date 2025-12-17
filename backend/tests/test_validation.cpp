#include <catch2/catch_test_macros.hpp>
#include "workflow/validator.hpp"
#include "workflow/workflow.hpp"
#include "workflow/node.hpp"
#include "workflow/edge.hpp"

TEST_CASE("Validation: missing start node") {
    Workflow wf("wf", "Validation Test");
    wf.addNode(Node("B", "ACTION")); // No A

    wf.addEdge(Edge("A", "B"));

    Validator val;
    auto res = val.validate(wf);

    REQUIRE(res.valid == false);
}

TEST_CASE("Validation: duplicate edges") {
    Workflow wf("wf2", "Dup Edge Test");

    wf.addNode(Node("A", "ACTION"));
    wf.addNode(Node("B", "ACTION"));

    wf.addEdge(Edge("A", "B"));
    wf.addEdge(Edge("A", "B")); // duplicate

    Validator val;
    auto res = val.validate(wf);

    REQUIRE(res.valid == false);
}
