

add_executable(TestSocketAddress  SocketAddressTest.cpp ../src/SocketAddress.cpp)
target_link_libraries(TestSocketAddress gtest pthread)

target_include_directories(TestSocketAddress PRIVATE ${CMAKE_SOURCE_DIR}/include)