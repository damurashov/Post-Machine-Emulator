#ifndef ORIGINAL_RULE_H
#define ORIGINAL_RULE_H

#ifndef STRING_H
#define STRING_H
#include <string>
#endif /* end of include guard: STRING_H */


struct Original_Rule {
    std::string rule_in;
    std::string rule_out;
    const Original_Rule operator=( const Original_Rule& original_rule );
    Original_Rule();
    Original_Rule( const std::string& rule_in, const std::string& rule_out );
    Original_Rule( const Original_Rule& original_rule );
};

#endif /* end of include guard: ORIGINAL_RULE_H */
