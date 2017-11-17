#ifndef FSTREAM_H
#define FSTREAM_H
#include <fstream>
#endif /* end of include guard: FSTREAM_H */

#ifndef IOSTREAM_H
#define IOSTREAM_H
#include <iostream>
#endif /* end of include guard: IOSTREAM_H */

#include "pm_controller.h"

using namespace std;

void print_intro() {
    cout << "Post Machine Emulator" << endl;
    cout << "SUAI, 2017" << endl << endl;
}
void print_machine_output( const list<Pm_Record>& records ) {
    //list<Pm_Record>::iterator it = records.begin();
    auto it = records.begin();
    cout << "INITIAL:\t" << it->before << endl;
    for (;it != records.end(); ++it) {
        cout << "RULE:\t\t" << it->used_rule.rule_in << " -> " << it->used_rule.rule_out << endl;
        cout << "AFTER RULE:\t" << it->after << endl;
    }
}
void print_machine_output( const list<Pm_Record>& records, const char* file_output ) {
    ofstream outfile;

    //list<Pm_Record>::iterator it = records.begin();
    auto it = records.begin();
    outfile.open(file_output, std::ofstream::out | std::ofstream::trunc );
    outfile << "Post Machine Emulator, St. Petersburg, SUAI, 2017" << endl << endl;
    outfile << "INITIAL:\t" << it->before << endl;
    for (;it != records.end(); ++it) {
        outfile << "RULE:\t\t" << it->used_rule.rule_in << " -> " << it->used_rule.rule_out << endl;
        outfile << "AFTER RULE:\t" << it->after << endl;
    }

}
const list<Pm_Record>& get_machine_output() throw(Err_Unknown_Symbol) {
    static Pm_Controller cont("SYMBOLS", "VARIABLES", "AXIOMS", "RULES");
    return cont.get_journal("MYINPUT");
}

int main( int argc, char const* argv[] ) {
    print_intro();
    try {
        switch (argc) {
        case 1:
            print_machine_output(get_machine_output());
            break;
        case 2:
            print_machine_output(get_machine_output(), argv[1]);
            break;
        }
    } catch (Err_Unknown_Symbol& e ) {cout << e.what() << endl;}

    return 0;
}
