#ifndef ERR_UNKNOWN_SYMBOL
#define ERR_UNKNOWN_SYMBOL

#ifndef STRING_H
#define STRING_H
#include <string>
#endif /* end of include guard: STRING_H */


class Err_Unknown_Symbol {
private:
    const std::string m_msg_what;
    Err_Unknown_Symbol();
public:
    const std::string& what() const;
    Err_Unknown_Symbol( const std::string& what );
};

#endif /* end of include guard: ERR_UNKNOWN_SYMBOL */
