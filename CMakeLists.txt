PROJECT( SBOL_TEST )
CMAKE_MINIMUM_REQUIRED( VERSION 2.8 )
cmake_policy(SET CMP0015 NEW)  # set policy for using relative paths

# set up folder structure
SET( LINK_DIR ${CMAKE_INSTALL_PREFIX}/../SBOL/lib )
SET( HEADER_DIR	${CMAKE_INSTALL_PREFIX}/../SBOL/include   )
MESSAGE(${HEADER_DIR})
# gather headers
INCLUDE_DIRECTORIES( ${HEADER_DIR} )

# gather source files
FILE( GLOB APPLICATION_FILES
	"*.h"
	"Source.cpp"
)

# set the path to the library folder
# relative paths given to this command are passed to the linker unchanged (unlike many CMake commands which interpret them relative to the current source directory).
# must precede target creation
LINK_DIRECTORIES( LINK_DIR )

# build test executable
ADD_EXECUTABLE( sbol_test 
	${APPLICATION_FILES}
)

find_library(sbol
    NAME sbol.lib
	PATHS ${LINK_DIR}
    )

find_library(xml2
	NAME libxml2_a.lib
    PATHS ${LINK_DIR}
    )
find_library(zlib
	NAME zlib.lib
    PATHS ${LINK_DIR}
    )
find_library(iconv
	NAME iconv_a.lib
    PATHS ${LINK_DIR}
    )
find_library(xml2
	NAME libxml2.a
    PATHS ${LINK_DIR}
    )
IF (${CMAKE_SYSTEM_NAME} MATCHES "Windows")
    FIND_LIBRARY(raptor2
        NAME raptor2.lib
        PATHS ${LINK_DIR}
        )
ELSE ()
    FIND_LIBRARY (raptor2 raptor2)
ENDIF ()

TARGET_LINK_LIBRARIES( sbol_test
	${sbol}
	${raptor2}
	${xml2}
	${zlib}
	${iconv}
	ws2_32
)
