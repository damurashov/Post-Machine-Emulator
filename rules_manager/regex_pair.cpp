#include "rules_manager.h"

using namespace std;

Rules_Manager::Regex_Pair::Regex_Pair() {}

Rules_Manager::Regex_Pair::Regex_Pair(
    const string& in,
    const string& out ) :
    regex_in( in ),
    regex_out( out ) {}

const Rules_Manager::Regex_Pair Rules_Manager::Regex_Pair::operator=( const Regex_Pair& regex_pair ) {
    regex_in.assign(regex_pair.regex_in);
    regex_out.assign(regex_pair.regex_out);
    return *this;
}
