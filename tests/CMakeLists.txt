# tests/CMakeLists.txt
#
add_executable(unit_tests test_newton.cpp)
target_link_libraries(unit_tests
  Catch2::Catch2WithMain
  Eigen3::Eigen
  models_lib)

include(Catch)
catch_discover_tests(unit_tests)
