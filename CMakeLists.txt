cmake_minimum_required(VERSION 3.0.0)
project(IsntMissle VERSION 0.1.0)

include(CTest)
enable_testing()

project(IsntMissle) #project name, outputted into build dir


# this is involved in the default cmake file but creates an error in use
# set(CPACK_PROJECT_NAME ${PROJECT_NAME})
# set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
# include(CPack)

cmake_minimum_required(VERSION 3.22.1) #requried


file(GLOB_RECURSE SRC_FILES src/*.cpp) #cmake discourages this
add_executable(${PROJECT_NAME} ${SRC_FILES})


target_include_directories(${PROJECT_NAME} PUBLIC
                           ${CMAKE_CURRENT_SOURCE_DIR}/include)
                           
target_include_directories(${PROJECT_NAME} PUBLIC ${SFML_INCLUDE_DIR})

# find_package(SFML COMPONENTS system window graphics CONFIG REQUIRED)
# target_link_libraries(${PROJECT_NAME} PRIVATE sfml-system sfml-network sfml-graphics sfml-window)
# target_link_libraries(${PROJECT_NAME} PUBLIC ${SFML_LIBRARIES} ${SFML_DEPENDENCIES})
