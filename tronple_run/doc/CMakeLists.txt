find_package (Doxygen)

message("Tronple_run_SOURCE_DIR     " ${c3ga_SOURCE_DIR})
message("Tronple_run_BINARY_DIR     " ${c3ga_BINARY_DIR})
message("DOXYGEN_EXECUTABLE  " ${DOXYGEN_EXECUTABLE})

if(DOXYGEN_FOUND)
  configure_file (${Tronple_run_SOURCE_DIR}/doc/Doxyfile-html.cmake ${Tronple_run_BINARY_DIR}/doc/Doxyfile-html)
  add_custom_target (html ${DOXYGEN_EXECUTABLE} ${Tronple_run_BINARY_DIR}/doc/Doxyfile-html)
endif (DOXYGEN_FOUND)
