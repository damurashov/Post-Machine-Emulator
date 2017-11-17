cmake_minimum_required( VERSION 2.6 )
set( CMAKE_CXX_STANDARD 11 )
option( _TEST "Testing mode" OFF )

add_definitions( -D_VARIADIC_MAX=10 )
add_definitions( -D_DEBUG )
add_definitions( -D_MT )
add_definitions( -D_DLL )

# err_unknown_symbol
add_subdirectory( err_unknown_symbol )
include_directories( ${err_unknown_symbol_SOURCE_DIR})

# symbol_container
add_subdirectory( symbol_container )
include_directories( ${symbol_container_SOURCE_DIR} )

# original_rule
add_subdirectory( original_rule )
include_directories( ${original_rule_SOURCE_DIR} )

# pm_record
add_subdirectory( pm_record )
include_directories( ${pm_record_SOURCE_DIR} )

# rules_manager
add_subdirectory( rules_manager )
include_directories( ${rules_manager_SOURCE_DIR} )

# pm_controller
add_subdirectory( pm_controller )
include_directories( ${pm_controller_SOURCE_DIR} )

# post_machine (main)
add_subdirectory( main )

if( _TEST )
    # gtest
    add_subdirectory( gtest )
    include_directories(
        ${gtest_SOURCE_DIR}
        ${gtest_SOURCE_DIR}/include
    )
    # unit_tests
    add_subdirectory( unit_tests )
endif()
