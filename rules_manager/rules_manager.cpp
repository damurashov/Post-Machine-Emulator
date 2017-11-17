#include "rules_manager.h"
using namespace std;

// --------------- Constructors, destructors ---------------

Rules_Manager::Rules_Manager() :
    m_symbols( Symbol_Container::Symbol_Container() ),
    m_axioms( Symbol_Container::Symbol_Container() ),
    m_variables( Symbol_Container::Symbol_Container() ) {}

Rules_Manager::Rules_Manager(
    const Symbol_Container& symbols,
    const Symbol_Container& variables,
    const Symbol_Container& axioms) :
    m_symbols( symbols ),
    m_variables( variables ),
    m_axioms( axioms) {

    m_spec_chars.push_symbols("+*{}[]?");

    m_any_symbols.append("[");
    m_any_symbols.append(m_symbols.get_symbols());
    //m_any_symbols.append(const_cast<string&>(m_symbols.get_symbols()));
    m_any_symbols.append("]*");

    m_any_axioms.append("([");
    m_any_axioms.append(m_axioms.get_symbols());
    m_any_axioms.append("]*)");
}

// -------------- Public members ---------------

void Rules_Manager::push_rule( const string& string_in,
    const string& string_out ) {
    /**/
    try {
        validate_rule(string_in);
        validate_rule(string_out);
    } catch (Err_Unknown_Symbol& e) {
        throw;
    }
    Rule rule;

    // rule.original_rule.append(string_in);
    // rule.original_rule.append(" -> ");
    // rule.original_rule.append(string_out);
    rule.original_rule.rule_in.assign(string_in);
    rule.original_rule.rule_out.assign(string_out);
    rule.regex_marked_up.assign(markup_expr(string_in));
    rule.regex_pairs = get_pairs(string_in, string_out);
    m_rules.push_back(rule);
}

void Rules_Manager::push_rule( const Original_Rule& original_rule ) {
    /**/
    try {
        validate_rule(original_rule.rule_in);
        validate_rule(original_rule.rule_out);
    } catch (Err_Unknown_Symbol& e) {
        throw;
    }
    push_rule(original_rule.rule_in, original_rule.rule_out);
}

bool Rules_Manager::execute( string& input ) {
    return execute(input, Original_Rule::Original_Rule());
}

bool Rules_Manager::execute( string& input, Original_Rule& used_rule ) {
    cmatch m;
    string buf;
    int pos;

    for (auto it = m_rules.begin(); it != m_rules.end(); ++it) {
        if (regex_match(input.c_str(), m, regex(it->regex_marked_up.c_str()))) {
            for (auto it_in = it->regex_pairs.begin(); it_in != it->regex_pairs.end(); ++it_in) {
                buf.assign(m.format(it_in->regex_in));
                if ((pos = input.find(buf)) != string::npos) {
                    used_rule = it->original_rule;
                    input.replace(pos, buf.length(), m.format(it_in->regex_out));
                    return true;
                }
            }
        }
    }
    return false;
}

// ---------- Private members ----------

string Rules_Manager::format_serial( int serial ) {
    return string(1, '$').append(to_string(serial));
}

string Rules_Manager::format_spec_char( char symbol ) {
    return string("\\").append(1, symbol);
}

string Rules_Manager::markup_expr( const string& string_in ) {

    string buf;

    buf.append(m_any_symbols);
    for (auto it = string_in.begin(); it != string_in.end(); ++it) {
        if (m_spec_chars.has_item(*it))
            buf.append(format_spec_char(*it));
        else if (m_variables.has_item(*it))
            buf.append(m_any_axioms);
        else
            buf.append(1, *it);
    }
    buf.append(m_any_symbols);

    return buf;
}

string Rules_Manager::markup_expr(
    const string& string_in,
    const map<char, int>& serials ) {

    string buf;
    for (auto it = string_in.begin(); it != string_in.end(); ++it) {
        if (m_variables.has_item(*it))
            buf.append(format_serial(serials.at(*it)));
        else
            buf.append(1, *it);
    }
    return buf;
}

void Rules_Manager::validate_rule( const string& in ) throw(Err_Unknown_Symbol) {
    for (auto it = in.begin(); it != in.end(); ++it) {
        if (!m_symbols.has_item(*it) && !m_variables.has_item(*it))
            throw (Err_Unknown_Symbol(string("Unknown symbol or variable: ").append(1,*it)));
    }
}

void Rules_Manager::form_serials(
    const string& string_in,
    map<char, list<int>>& serials_to_form ) {

    int serial = 1;

    // Annotate every variable with a list of its serials
    for (auto it = string_in.begin(); it != string_in.end(); ++it) {
        if (m_variables.has_item(*it)) {
            serials_to_form[*it].push_back(serial++);
        }
    }
}

void Rules_Manager::form_serials_combs(
    const map<char, list<int>>& serials,
    list<map<char, int>>& combs_to_form,
    map<char, int>& container,
    unsigned iter_from_begin ) {

    auto  srls_iter  = next(serials.begin(), iter_from_begin);

    if (srls_iter == serials.end()) {
        combs_to_form.push_back(container);
    } else {
        auto value_iter = srls_iter->second.begin();
        char key        = srls_iter->first;
        for (;value_iter != srls_iter->second.end(); ++value_iter) {
            map<char,int> next_container(container); // Copy of current
            next_container.emplace(key, *value_iter);
            form_serials_combs(serials, combs_to_form, next_container, (iter_from_begin+1));
        }
    }
}

list<Rules_Manager::Regex_Pair> Rules_Manager::get_pairs(
    const string& string_in,
    const string& string_out ) {

    map<char, list<int>> serials;
    list<map<char, int>> combs;
    list<Regex_Pair>     pairs;
    map<char, int>       container;
    char                 key;

    form_serials(string_in, serials);
    key = serials.begin()->first;

    for (auto value_iter = serials.begin()->second.begin(); value_iter != serials.begin()->second.end(); ++value_iter) {
        map<char,int> container;
        container.emplace(key, *value_iter);
        form_serials_combs(serials, combs, container);
    }

    for (auto it = combs.begin(); it != combs.end(); ++it) {
        pairs.push_back(Regex_Pair( //...
            markup_expr(string_in, *it), markup_expr(string_out, *it)));
    }
    return pairs;
}
