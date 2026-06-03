add_subdirectory(models)
add_executable(ODE main.cpp)
target_link_libraries(ODE models_lib)
target_include_directories(ODE PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)
