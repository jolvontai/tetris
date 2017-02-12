cmake_minimum_required (VERSION 2.6)
project (tetris)

#project version nunber
set (tetris_VERSION_MAJOR 0)
set (tetris_VERSION_MINOR 1)

#add everything in src file
file(GLOB SOURCES "src/*")

if(WIN32)
	#add new CMakeList
	file(GLOB LIBS "libs/*.lib")
	message(${LIBS})

	#Property->Linker->General->Additional Library Directories
	#link_directories(${PROJECT_SOURCE_DIR}/libs)
endif(WIN32)


#Property->Additional Include Directories
include_directories(include)


#add the executable
add_executable(tetris ${SOURCES})


if(WIN32)

	
	
	
	#Property->Linker->Input->Additional Dependencies
	target_link_libraries(tetris ${LIBS})

endif(WIN32)






