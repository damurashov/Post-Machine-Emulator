#include "pm_controller.h"

using namespace std;

// ----- Constructors, destructors -----

Pm_Controller::Pm_Controller( const char* fsmbls,
    const char* fvrbls,
    const char* faxms,
    const char* frls ) :
    m_symbols(fsmbls),
    m_variables(fvrbls),
    m_axioms(faxms),
    m_rules_manager(m_symbols, m_variables, m_axioms) {
    /**/
    fstream infile(frls);
    string buf_rin;
    string buf_rout;
    /**/
    try {
        while(getline(infile, buf_rin)) {
            getline(infile, buf_rout);
            m_rules_manager.push_rule(buf_rin, buf_rout);
        }
    } catch (Err_Unknown_Symbol& e ) { throw; }

}

Pm_Controller::Pm_Controller( const string& symbols,
    const string& variables,
    const string& axioms,
    const list<Original_Rule>& rules ) :
    m_symbols(symbols),
    m_variables(variables),
    m_axioms(axioms),
    m_rules_manager(m_symbols, m_variables, m_axioms) {
    /**/
    try {
        for (auto it = rules.begin(); it != rules.end(); ++it)
            m_rules_manager.push_rule(*it);
    } catch (Err_Unknown_Symbol& e) { throw; }

}


// ----- Public methods -----

const list<Pm_Record>& Pm_Controller::get_journal() {
    return m_journal;
}

const list<Pm_Record>& Pm_Controller::get_journal( const string& in ) {
    Original_Rule rule;
    string        input(in);
    string        input_backup;

    erase_journal();
    input_backup.assign(input);
    while (m_rules_manager.execute(input, rule)) {
        m_journal.push_back(Pm_Record(rule, input_backup, input));
        input_backup.assign(input);
    }

    return m_journal;
}

const list<Pm_Record>& Pm_Controller::get_journal( const char* file_input ) {
    string input(Symbol_Container(file_input).get_symbols());
    return get_journal(input);
}

// ----- Private mehods -----

void Pm_Controller::erase_journal() {
    m_journal.clear();
}
