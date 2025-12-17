#include "services/rule_service.hpp"

namespace services {

RuleService::RuleService(storage::RuleStore& store)
    : store_(store) {}

bool RuleService::createRule(const Rule& rule) {
    return store_.save(rule);
}

std::optional<Rule> RuleService::getRule(const std::string& id) {
    return store_.load(id);
}

bool RuleService::updateRule(const Rule& rule) {
    return store_.update(rule);
}

bool RuleService::deleteRule(const std::string& id) {
    return store_.remove(id);
}

std::vector<std::string> RuleService::listRules() const {
    return store_.listIds();
}

} // namespace services
