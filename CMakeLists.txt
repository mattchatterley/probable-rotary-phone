
CMAKE_MINIMUM_REQUIRED( VERSION 3.0 )

PROJECT( UmbrellaMagic C CXX )

SET( TARGET "umbrella" )

#INCLUDE_DIRECTORIES( "${CMAKE_SOURCE_DIR}/../cpp-connector-api/include" )
INCLUDE_DIRECTORIES( "${CMAKE_SOURCE_DIR}/include" )

SET( CMAKE_CXX_STANDARD 11 )
ADD_DEFINITIONS( -g -Wall -Wextra ) 


FILE( GLOB HEADERS "${CMAKE_SOURCE_DIR}/include/*.h" )
ADD_EXECUTABLE( ${TARGET} src/sample1.cpp ${HEADERS} )

TARGET_LINK_LIBRARIES( ${TARGET} curl )

