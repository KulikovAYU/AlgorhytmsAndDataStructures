cmake_minimum_required(VERSION 3.12.4 FATAL_ERROR)

IF (CMAKE_VERSION VERSION_LESS "3.8")
    SET(CMAKE_CXX_STANDARD 14)
ELSEIF (CMAKE_VERSION VERSION_LESS "3.11")
    SET(CMAKE_CXX_STANDARD 17)
ELSE()
    SET(CMAKE_CXX_STANDARD 20)
ENDIF()

#project name
set(SOLUTION_NAME AlgorhytmsAndDataStructures)

#libraries
set(LIBRARY_STRUCTURE_DIR SrcDataStructurers)

#headers
set (HEADER_FILES_ALGO_IMPL AlgoImpl/TreesAlgorhytms.h)

set (HEADER_FILES_SRC_DATA_STRUCT SrcDataStructurers/pch.h
								  SrcDataStructurers/Node.h
								  SrcDataStructurers/TreesGenerator.h)				   
				 

#lets create solution
project(${SOLUTION_NAME})

#lets create libraries
add_library(${LIBRARY_STRUCTURE_DIR} 
			SrcDataStructurers/pch.cpp
			SrcDataStructurers/Node.cpp
			SrcDataStructurers/SrcDataStructurers.cpp
			SrcDataStructurers/TreesGenerator.cpp
			${HEADER_FILES_SRC_DATA_STRUCT})
			

add_executable(${SOLUTION_NAME} 
			   AlgoImpl/TreesAlgorhytms.cpp
			   AlgoImpl/AlgoImpl.cpp
			   ${HEADER_FILES_ALGO_IMPL})
			   
target_include_directories(${SOLUTION_NAME} PRIVATE ${LIBRARY_STRUCTURE_DIR})
link_directories (${SOLUTION_NAME} PUBLIC ${LIBRARY_STRUCTURE_DIR})
target_link_libraries (${SOLUTION_NAME} ${LIBRARY_STRUCTURE_DIR})
			
