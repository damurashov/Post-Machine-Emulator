project( rules_manager )
add_library( rules_manager
    rules_manager.cpp
    rule.cpp
    regex_pair.cpp
)
target_link_libraries( rules_manager
    symbol_container
    original_rule
    err_unknown_symbol )

if( _TEST )
    set( TEST_PUBLIC public: )
    configure_file( rules_manager.h.in ${rules_manager_SOURCE_DIR}/rules_manager.h)
    unset( TEST_PUBLIC )
else()
    configure_file( rules_manager.h.in ${rules_manager_SOURCE_DIR}/rules_manager.h)
endif()
