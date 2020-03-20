# httpCheckRequest.cmake
project(httpCheckRequest)

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/openZia/openZia)

# Save this directory as httpCheckRequestSourcesDir
get_filename_component(httpCheckRequestSourcesDir ${CMAKE_CURRENT_LIST_FILE}  PATH)

set(httpCheckRequestSources
	${httpCheckRequestSourcesDir}/httpCheckRequest.hpp
	${httpCheckRequestSourcesDir}/httpCheckRequest.cpp
)

# Compile the module, and link it to openZia
add_library(${PROJECT_NAME} SHARED ${httpCheckRequestSources})
target_link_libraries(${PROJECT_NAME} ${openZiaLibs})
target_include_directories(${PROJECT_NAME} PRIVATE ${openZiaIncludes})

# Copy the library into the binary modules directory
set_target_properties(${PROJECT_NAME} PROPERTIES
	LIBRARY_OUTPUT_DIRECTORY  ${CMAKE_BINARY_DIR}/modules
)