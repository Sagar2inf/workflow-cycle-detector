#include <catch2/catch_test_macros.hpp>
#include "services/execution_service.hpp"
#include "workflow/workflow.hpp"

TEST_CASE("Execution: linear workflow") {
    Workflow wf("wf", "Exec Test");

    wf.addNode(Node("A", "ACTION"));
    wf.addNode(Node("B", "ACTION"));
    wf.addEdge(Edge("A", "B"));

    ExecutionService exec;

    auto result = exec.run(wf);

    REQUIRE(result.success == true);
}
