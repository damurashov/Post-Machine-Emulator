project( pm_controller )
add_library( pm_controller pm_controller.cpp )
target_link_libraries( pm_controller
    pm_record
    rules_manager )
    #err_unknown_symbol )
if(_TEST)
    set(TEST_PUBLIC public:)
endif()
configure_file( pm_controller.h.in
    ${pm_controller_SOURCE_DIR}/pm_controller.h )
unset(TEST_PUBLIC)
