macro(setup_conan)
  include(${CMAKE_SOURCE_DIR}/conan.cmake)
  set(CONAN_SYSTEM_INCLUDES ON)
  conan_cmake_run(
    CONANFILE
    ${CMAKE_SOURCE_DIR}/conanfile.txt
    PROFILE
    default
    BASIC_SETUP
    BUILD
    missing)
endmacro()

function(add_test_executable NAME)
  cmake_parse_arguments(ARGS "" "" "SOURCES" ${ARGN})
  add_executable(${NAME} ${ARGS_SOURCES})

  target_link_libraries(${NAME} PUBLIC BlackjackLib)

  gtest_discover_tests(${NAME} WORKING_DIRECTORY ${CMAKE_SOURCE_DIR})
  set_target_properties(${NAME} PROPERTIES FOLDER ${CMAKE_SOURCE_DIR}/test)
endfunction()
