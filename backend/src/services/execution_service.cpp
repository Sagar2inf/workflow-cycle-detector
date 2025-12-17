#include "services/execution_service.hpp"

namespace services {

ExecutionService::ExecutionService(WorkflowService& wfService,
                                   RuleService& ruleService)
    : workflowService_(wfService), ruleService_(ruleService) {}

workflow::ExecutionResult ExecutionService::execute(const std::string& workflowId) {
    auto wfOpt = workflowService_.getWorkflow(workflowId);
    if (!wfOpt) {
        return workflow::ExecutionResult::error("Workflow not found");
    }

    workflow::Workflow wf = *wfOpt;

    workflow::Executor executor;
    return executor.run(wf);
}

} // namespace services
