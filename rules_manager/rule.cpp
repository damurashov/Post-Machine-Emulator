#include "rules_manager.h"

using namespace std;

Rules_Manager::Rule::Rule() {}

Rules_Manager::Rule::Rule( const Rule& rule ) {
    regex_marked_up.assign(rule.regex_marked_up);
    regex_pairs.assign(rule.regex_pairs.begin(), rule.regex_pairs.end());
    original_rule = rule.original_rule;
}

Rules_Manager::Rule::Rule(
    const string& regmarkup,
    const list<Rules_Manager::Regex_Pair>& regpairs,
    const Original_Rule& orr ) :
    regex_marked_up( regmarkup ),
    regex_pairs( regpairs ),
    original_rule( orr ) {}

const Rules_Manager::Rule Rules_Manager::Rule::operator=( const Rule& rule ) {
    regex_marked_up.assign(rule.regex_marked_up);
    regex_pairs.assign(rule.regex_pairs.begin(), rule.regex_pairs.end());
    original_rule = rule.original_rule;
    return *this;
}
