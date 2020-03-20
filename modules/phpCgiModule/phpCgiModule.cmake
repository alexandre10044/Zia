project(phpCgiModule)

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/openZia/openZia)

get_filename_component(phpCgiModuleSourcesDir ${CMAKE_CURRENT_LIST_FILE}  PATH)

set(phpCgiModuleSources
	${phpCgiModuleSourcesDir}/Php.hpp
	${phpCgiModuleSourcesDir}/Php.cpp
)

add_library(${PROJECT_NAME} SHARED ${phpCgiModuleSources})
target_link_libraries(${PROJECT_NAME} ${openZiaLibs})
target_include_directories(${PROJECT_NAME} PRIVATE ${openZiaIncludes})

set_target_properties(${PROJECT_NAME} PROPERTIES
	LIBRARY_OUTPUT_DIRECTORY  ${CMAKE_BINARY_DIR}/modules
)