cmake_minimum_required (VERSION 2.8)

set(Boost_USE_STATIC_LIBS OFF)

set(Boost_USE_MULTITHREADED ON)

set(Boost_USE_STATIC_RUNTIME OFF)

set(CMAKE_CXX_COMPILER clang)


set (BOOST_COMPONENTS 
	thread
	filesystem)

include_directories( "/usr/local/include" )

add_definitions(-std=c++11)

project (final)



file(GLOB SRC

"connection.cpp"
"main.cpp"
"mime_types.cpp"
"reply.cpp"
"request_handler.cpp"
"request_parser.cpp"
"server.cpp"

)

add_executable(final ${SRC})

find_package (Boost COMPONENTS ${BOOST_COMPONENTS} REQUIRED)

target_link_libraries(final ${Boost_LIBRARIES})

target_link_libraries(final "stdc++")

target_link_libraries(final "pthread")