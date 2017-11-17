#ifndef PM_RECORD_H
#define PM_RECORD_H

#include "original_rule.h"

struct Pm_Record {
    Original_Rule used_rule;
    std::string before;
    std::string after;
    const Pm_Record operator=( const Pm_Record& pm_record );
    Pm_Record();
    Pm_Record( const Original_Rule& rule,
        const std::string& before,
        const std::string& after );
    Pm_Record( const Pm_Record& pm_record );
};

#endif /* end of include guard: PM_RECORD_H */
