# httpGet.cmake
project(httpGet)

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/openZia/openZia)

# Save this directory as httpGetSourcesDir
get_filename_component(httpGetSourcesDir ${CMAKE_CURRENT_LIST_FILE}  PATH)

set(httpGetSources
	${httpGetSourcesDir}/httpGet.hpp
	${httpGetSourcesDir}/httpGet.cpp
	#${httpGetSourcesDir}/Config/Config.cpp
)

# Compile the module, and link it to openZia
add_library(${PROJECT_NAME} SHARED ${httpGetSources})
target_link_libraries(${PROJECT_NAME} ${openZiaLibs})
target_include_directories(${PROJECT_NAME} PRIVATE ${openZiaIncludes})

# Copy the library into the binary modules directory
set_target_properties(${PROJECT_NAME} PROPERTIES
	LIBRARY_OUTPUT_DIRECTORY  ${CMAKE_BINARY_DIR}/modules
)