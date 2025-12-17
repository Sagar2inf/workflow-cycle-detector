#include <catch2/catch_test_macros.hpp>
#include "workflow/workflow.hpp"
#include "workflow/node.hpp"
#include "workflow/edge.hpp"

TEST_CASE("Workflow basic creation") {
    Workflow wf("wf1", "Test Workflow");

    REQUIRE(wf.getId() == "wf1");
    REQUIRE(wf.getName() == "Test Workflow");
}

TEST_CASE("Adding nodes to workflow") {
    Workflow wf("wf2", "Node Test");

    wf.addNode(Node("n1", "ACTION"));
    wf.addNode(Node("n2", "EVENT"));

    REQUIRE(wf.getNodes().size() == 2);
}
