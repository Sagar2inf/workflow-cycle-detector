#ifndef APP_HPP
#define APP_HPP

#include <string>

/**
 * App serves as the root orchestrator for all services.
 * It initializes the storage layer and exposes high-level APIs for the server.
 */
class App {
public:
    App();

    // ----- Workflow APIs -----
    bool create_workflow(const std::string& workflow_json, std::string& out_error);
    bool validate_workflow(const std::string& workflow_id, std::string& out_error);
    bool execute_workflow(const std::string& workflow_id, std::string& out_output);

    // ----- Rule APIs -----
    bool create_rule(const std::string& workflow_id, const std::string& rule_json, std::string& out_error);

    // Health check
    bool ping() const;

private:
    WorkflowService workflow_service;
    RuleService rule_service;
    ExecutionService execution_service;
};

#endif // APP_HPP
