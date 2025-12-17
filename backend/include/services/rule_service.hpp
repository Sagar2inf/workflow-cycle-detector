#pragma once
#include <string>
#include <optional>
#include <vector>

#include "storage/rule_store.hpp"
#include "utils/errors.hpp"

namespace services {

class RuleService {
public:
    explicit RuleService(storage::RuleStore& store);

    bool createRule(const Rule& rule);
    std::optional<Rule> getRule(const std::string& id);
    bool updateRule(const Rule& rule);
    bool deleteRule(const std::string& id);

    std::vector<std::string> listRules() const;

private:
    storage::RuleStore& store_;
};

} // namespace services
