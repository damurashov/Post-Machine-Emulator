#include "original_rule.h"

using namespace std;

Original_Rule::Original_Rule() {}

Original_Rule::Original_Rule( const string& rin, const string& rout ) :
    rule_in( rin ),
    rule_out( rout ) {}

Original_Rule::Original_Rule( const Original_Rule& orr ) :
    rule_in(orr.rule_in),
    rule_out(orr.rule_out) {}

const Original_Rule Original_Rule::operator=( const Original_Rule& orr ) {
    rule_in.assign(orr.rule_in);
    rule_out.assign(orr.rule_out);
    return *this;
}
