project(SecureConnectionModule)

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/openZia/openZia)

get_filename_component(SecureConnectionModuleSourcesDir ${CMAKE_CURRENT_LIST_FILE}  PATH)

set(SecureConnectionModuleSources
	${SecureConnectionModuleSourcesDir}/SecureConnectionModule.hpp
	${SecureConnectionModuleSourcesDir}/SecureConnectionModule.cpp
)

add_library(${PROJECT_NAME} SHARED ${SecureConnectionModuleSources})
target_link_libraries(${PROJECT_NAME} ${openZiaLibs})
target_link_libraries(${PROJECT_NAME} -lssl -lcrypto)
target_include_directories(${PROJECT_NAME} PRIVATE ${openZiaIncludes})

set_target_properties(${PROJECT_NAME} PROPERTIES
	LIBRARY_OUTPUT_DIRECTORY  ${CMAKE_BINARY_DIR}/modules
)