add_library(prototype-figures prototype.cpp)
add_executable(test-prototype-figures test.cpp)
target_link_libraries(test-prototype-figures prototype-figures)