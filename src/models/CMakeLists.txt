add_library(models_lib Algebraic.cpp)
target_link_libraries(models_lib PUBLIC Eigen3::Eigen)
target_include_directories(models_lib PUBLIC ${CMAKE_SOURCE_DIR}/include)
