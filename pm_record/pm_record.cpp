#include "pm_record.h"

using namespace std;

Pm_Record::Pm_Record() {}

Pm_Record::Pm_Record( const Original_Rule& orr,
    const string& bfr,
    const string& aftr ):
    used_rule(orr),
    before(bfr),
    after(aftr) {}

Pm_Record::Pm_Record( const Pm_Record& record ) :
    used_rule(record.used_rule),
    before(record.before),
    after(record.after) {}

const Pm_Record Pm_Record::operator=( const Pm_Record& record ) {
    used_rule = record.used_rule;
    before.assign(record.before);
    after.assign(record.after);
    return *this;
}
