#include "symbol_container.h"

// ----- Constructors, destructors -----

Symbol_Container::Symbol_Container() {}

Symbol_Container::Symbol_Container( const char* file_path ) {
    std::fstream infile( file_path );
    std::string buf;

    while (std::getline(infile, buf)) {
        if (!(buf.compare("") == 0))
            m_symbols.append(buf);
    }
    //m_symbols.erase( remove_if(m_symbols.begin(), m_symbols.end(), isspace) );
    for (auto it = m_symbols.begin(); it != m_symbols.end(); ++it)
        if (*it == SYMBOL_SPACE)
            m_symbols.erase(it);
}

Symbol_Container::Symbol_Container( const std::string& symbols ) : m_symbols( symbols ) {
    for (auto it = m_symbols.begin(); it != m_symbols.end(); ++it)
        if (*it == SYMBOL_SPACE)
            m_symbols.erase(it);
}

Symbol_Container::Symbol_Container( const Symbol_Container& container ) {
    m_symbols.assign(container.m_symbols);
}

// ----- Public methods ---

bool Symbol_Container::has_item( const char& symbol ) const {
    for (auto it = m_symbols.begin(); it != m_symbols.end(); ++it) {
        if (*it == symbol)
            return true;
    }
    return false;
}

bool Symbol_Container::has_symbol( const char& symbol ) const {
    return has_item(symbol);
}

void Symbol_Container::push_symbols( const char* symbols ) {
    m_symbols.append(symbols);
}

void Symbol_Container::push_symbols( const std::string& symbols ) {
    m_symbols.append(symbols);
}

const std::string& Symbol_Container::get_symbols() const {
    return m_symbols;
}
