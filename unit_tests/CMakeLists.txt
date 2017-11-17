get_filename_component( TEST_FILE_1 input_files/TEST_FILE_1 ABSOLUTE )
get_filename_component( AXIOMS      input_files/AXIOMS      ABSOLUTE )
get_filename_component( RULES       input_files/RULES       ABSOLUTE )
get_filename_component( VARIABLES   input_files/VARIABLES   ABSOLUTE )
get_filename_component( SYMBOLS     input_files/SYMBOLS     ABSOLUTE )
get_filename_component( MYINPUT     input_files/MYINPUT     ABSOLUTE )

# test_symbol_container
project( test_symbol_container )
configure_file(
    test_symbol_container.cpp.in
    ${test_symbol_container_SOURCE_DIR}/test_symbol_container.cpp )
add_executable( test_symbol_container test_symbol_container.cpp )
target_link_libraries(
    test_symbol_container
    gtest
    gtest_main
    symbol_container )

# test_rules_manager
project( test_rules_manager )
configure_file(
    test_rules_manager.cpp.in
    ${test_rules_manager_SOURCE_DIR}/test_rules_manager.cpp )
add_executable( test_rules_manager test_rules_manager.cpp )
target_link_libraries(
    test_rules_manager
    gtest
    gtest_main
    rules_manager )

# test_pm_controller
project( test_pm_controller )
configure_file(
    test_pm_controller.cpp.in
    ${test_pm_controller_SOURCE_DIR}/test_pm_controller.cpp )
add_executable( test_pm_controller test_pm_controller.cpp )
target_link_libraries(
    test_pm_controller
    gtest_main
    gtest_main
    pm_controller )
