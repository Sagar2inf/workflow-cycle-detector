#pragma once
#include <string>
#include <vector>
#include <optional>

#include "workflow/workflow.hpp"
#include "workflow/executor.hpp"
#include "services/workflow_service.hpp"
#include "services/rule_service.hpp"

namespace services {

class ExecutionService {
public:
    ExecutionService(WorkflowService& wfService, RuleService& ruleService);

    // Executes the workflow and returns execution log
    workflow::ExecutionResult execute(const std::string& workflowId);

private:
    WorkflowService& workflowService_;
    RuleService& ruleService_;
};

} // namespace services
