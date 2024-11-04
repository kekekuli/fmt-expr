cmake_minimum_required(VERSION 3.15)

project(fmtexpr)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

add_executable(main main.cpp Useless.hpp)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fno-elide-constructors")    
# add_subdirectory(libs/spdlog)
# add_subdirectory(libs/fmt)

# option(PROFILE_ENABLE "Enable profiling" OFF)

# if (PROFILE_ENABLE)
    # add_subdirectory(libs/tracy)
    # target_link_libraries(main Tracy::TracyClient)
# endif()

# target_link_libraries(main fmt::fmt)
# target_link_libraries(main spdlog::spdlog)