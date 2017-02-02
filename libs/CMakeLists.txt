file(GLOB REMOVE_SOURCES LIBS "*.lib" )
message (${LIBS})
add_library(libraries ${LIBS})