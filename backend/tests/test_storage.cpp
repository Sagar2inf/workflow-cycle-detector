#include <catch2/catch_test_macros.hpp>
#include "storage/workflow_store.hpp"
#include <string>

TEST_CASE("Storage: save and load workflow") {
    WorkflowStore store("testdb.json");

    Workflow wf("wf1", "Storage Test");
    wf.addNode(Node("A", "ACTION"));

    store.save(wf);

    auto loaded = store.load("wf1");

    REQUIRE(loaded.getName() == "Storage Test");
}
