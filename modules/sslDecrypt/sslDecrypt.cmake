# sslDecrypt.cmake
project(sslDecrypt)

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/openZia/openZia)

# Save this directory as sslDecryptSourcesDir
get_filename_component(sslDecryptSourcesDir ${CMAKE_CURRENT_LIST_FILE}  PATH)

set(sslDecryptSources
	${sslDecryptSourcesDir}/sslDecrypt.hpp
	${sslDecryptSourcesDir}/sslDecrypt.cpp
)

# Compile the module, and link it to openZia
add_library(${PROJECT_NAME} SHARED ${sslDecryptSources})
target_link_libraries(${PROJECT_NAME} ${openZiaLibs})
target_link_libraries(${PROJECT_NAME} -lssl -lcrypto)
target_include_directories(${PROJECT_NAME} PRIVATE ${openZiaIncludes})

# Copy the library into the binary modules directory
set_target_properties(${PROJECT_NAME} PROPERTIES
	LIBRARY_OUTPUT_DIRECTORY  ${CMAKE_BINARY_DIR}/modules
)