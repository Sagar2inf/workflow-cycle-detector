#include "app.hpp"
#include "utils/logger.hpp"
#include "utils/errors.hpp"
#include <iostream>

App::App()
    : workflow_service(),
      rule_service(),
      execution_service(&workflow_service, &rule_service)
{
    Logger::info("App initialized");
}

bool App::ping() const {
    return true;
}

/**
 * Create workflow from JSON string
 */
bool App::create_workflow(const std::string& workflow_json, std::string& out_error) {
    try {
        return workflow_service.create_workflow_from_json(workflow_json, out_error);
    } catch (const std::exception& ex) {
        out_error = std::string("Exception: ") + ex.what();
        Logger::error(out_error);
        return false;
    }
}

/**
 * Validate workflow
 */
bool App::validate_workflow(const std::string& workflow_id, std::string& out_error) {
    try {
        return workflow_service.validate_workflow(workflow_id, out_error);
    } catch (const std::exception& ex) {
        out_error = std::string("Exception: ") + ex.what();
        Logger::error(out_error);
        return false;
    }
}

/**
 * Execute workflow
 */
bool App::execute_workflow(const std::string& workflow_id, std::string& out_output) {
    try {
        return execution_service.execute(workflow_id, out_output);
    } catch (const std::exception& ex) {
        out_output = std::string("Exception: ") + ex.what();
        Logger::error(out_output);
        return false;
    }
}

/**
 * Create rule
 */
bool App::create_rule(const std::string& workflow_id, const std::string& rule_json, std::string& out_error) {
    try {
        return rule_service.create_rule(workflow_id, rule_json, out_error);
    } catch (const std::exception& ex) {
        out_error = std::string("Exception: ") + ex.what();
        Logger::error(out_error);
        return false;
    }
}
