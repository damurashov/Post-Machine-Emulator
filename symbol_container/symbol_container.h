#ifndef SYMBOL_CONTAINER_H
#define SYMBOL_CONTAINER_H

#ifndef STRING_H
#define STRING_H
#include <string>
#endif /* end of include guard: STRING_H */

#ifndef FSTREAM_H
#define FSTREAM_H
#include <fstream>
#endif /* end of include guard: FSTREAM_H */

#ifndef SYMBOL_CONTAINER_PUBLIC
#define SYMBOL_CONTAINER_PUBLIC
#endif /* end of include guard: SYMBOL_CONTAINER_PUBLIC */


class Symbol_Container {
private:
SYMBOL_CONTAINER_PUBLIC
    static const char SYMBOL_SPACE = ' ';
    std::string m_symbols;
public:
    bool has_item( const char& symbol ) const;
    bool has_symbol( const char& symbol ) const;
    void push_symbols( const std::string& symbols );
    void push_symbols( const char* symbols );
    const std::string& get_symbols() const;

    Symbol_Container( const char* file_path );
    Symbol_Container( const std::string& symbols );
    Symbol_Container();
    Symbol_Container( const Symbol_Container& );
};

#endif /* end of include guard: SYMBOL_CONTAINER_H */
