if("${CMAKE_CURRENT_SOURCE_DIR}" STREQUAL "${CMAKE_SOURCE_DIR}")
	cmake_minimum_required(VERSION 2.8.9)
	set(CMAKE_BUILD_TYPE Debug|Release)
	if(WIN32)
		set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY "${CMAKE_SOURCE_DIR}/bin")
		set(CMAKE_LIBRARY_OUTPUT_DIRECTORY "${CMAKE_SOURCE_DIR}/bin")
		set(CMAKE_EXECUTABLE_OUTPUT_DIRECTORY "${CMAKE_SOURCE_DIR}/bin")
	else()
		set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY "${CMAKE_SOURCE_DIR}/bin/${CMAKE_BUILD_TYPE}")
		set(CMAKE_LIBRARY_OUTPUT_DIRECTORY "${CMAKE_SOURCE_DIR}/bin/${CMAKE_BUILD_TYPE}")
		set(CMAKE_EXECUTABLE_OUTPUT_DIRECTORY "${CMAKE_SOURCE_DIR}/bin/${CMAKE_BUILD_TYPE}")
	endif()
endif()

if(NOT TARGET GenericServerAndClient)
	execute_process(COMMAND git clone https://github.com/sumitdhyani/GenericServerAndClient.git "${CMAKE_SOURCE_DIR}/GenericServerAndClient")
endif()

if(NOT TARGET MTTools)
	execute_process(COMMAND git clone https://github.com/sumitdhyani/MTTools.git "${CMAKE_SOURCE_DIR}/MTTools")
endif()

if(NOT TARGET CommonUtils)
	execute_process(COMMAND git clone https://github.com/sumitdhyani/CommonUtils.git "${CMAKE_SOURCE_DIR}/CommonUtils")
endif()

if("${CMAKE_CURRENT_SOURCE_DIR}" STREQUAL "${CMAKE_SOURCE_DIR}")
	add_subdirectory(GenericServerAndClient)	
	add_subdirectory(MTTools)
	add_subdirectory(CommonUtils)	

endif()

project(SuperRepo)
add_executable("${PROJECT_NAME}" dummy.cpp)
add_dependencies("${PROJECT_NAME}" GenericServerAndClient MTTools CommonUtils)
#Needed for quaified paths, for protejects which have external dependencies
target_include_directories("${PROJECT_NAME}" PUBLIC "${CMAKE_SOURCE_DIR}")
