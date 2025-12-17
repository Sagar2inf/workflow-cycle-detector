#pragma once
#include <string>
#include <vector>
#include <optional>

#include "workflow/workflow.hpp"
#include "storage/workflow_store.hpp"
#include "workflow/validator.hpp"

namespace services {

class WorkflowService {
public:
    explicit WorkflowService(storage::WorkflowStore& store);

    // CRUD
    bool createWorkflow(const workflow::Workflow& wf);
    std::optional<workflow::Workflow> getWorkflow(const std::string& id);
    bool updateWorkflow(const workflow::Workflow& wf);
    bool deleteWorkflow(const std::string& id);

    // Validation
    workflow::ValidationResult validate(const workflow::Workflow& wf);

    // Utility
    std::vector<std::string> listWorkflows() const;

private:
    storage::WorkflowStore& store_;
    workflow::Validator validator_;
};

} // namespace services
