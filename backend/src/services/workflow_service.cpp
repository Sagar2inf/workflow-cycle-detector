#include "services/workflow_service.hpp"

namespace services {

WorkflowService::WorkflowService(storage::WorkflowStore& store)
    : store_(store), validator_() {}

bool WorkflowService::createWorkflow(const workflow::Workflow& wf) {
    return store_.save(wf);
}

std::optional<workflow::Workflow> WorkflowService::getWorkflow(const std::string& id) {
    return store_.load(id);
}

bool WorkflowService::updateWorkflow(const workflow::Workflow& wf) {
    return store_.update(wf);
}

bool WorkflowService::deleteWorkflow(const std::string& id) {
    return store_.remove(id);
}

workflow::ValidationResult WorkflowService::validate(const workflow::Workflow& wf) {
    return validator_.validate(wf);
}

std::vector<std::string> WorkflowService::listWorkflows() const {
    return store_.listIds();
}

} // namespace services
