
set(MODULE_NAME "NcrushFuzzer")
set(MODULE_PREFIX "NCRUSH_FUZZER")

file(COPY corpus DESTINATION "${CMAKE_CURRENT_BINARY_DIR}")

set(${MODULE_PREFIX}_SRCS
    NcrushFuzzerDecompress.c
)

foreach(test ${${MODULE_PREFIX}_SRCS})
	get_filename_component(TestName ${test} NAME_WE)
	add_executable(${TestName} ${test})
	# Use PUBLIC to force 'fuzzer_config' for all dependent targets.
	target_link_libraries(${TestName} PUBLIC freerdp winpr fuzzer_config)
	add_test(${TestName} ${TESTING_OUTPUT_DIRECTORY}/${MODULE_NAME} ${TestName})
	set_target_properties(${TestName} PROPERTIES RUNTIME_OUTPUT_DIRECTORY "${TESTING_OUTPUT_DIRECTORY}")
	add_dependencies(fuzzers ${TestName})
endforeach()


