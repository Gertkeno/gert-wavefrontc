cmake_minimum_required( VERSION 3.6 )
project( gert-wavefrontc )

set( CMAKE_CXX_STANDARD 14 )
include_directories( src )
file( GLOB sources src/*.cpp )

add_executable( gert-wavefrontc ${sources} )
