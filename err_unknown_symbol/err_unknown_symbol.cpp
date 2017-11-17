#include "err_unknown_symbol.h"

using namespace std;

Err_Unknown_Symbol::Err_Unknown_Symbol() :
    m_msg_what( "Nothing" ) {}

Err_Unknown_Symbol::Err_Unknown_Symbol( const string& msg_what ) :
    m_msg_what( msg_what ) {}

const string& Err_Unknown_Symbol::what() const {
    return m_msg_what;
}
