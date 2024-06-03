
# Subdirectory for pedestrian controller
add_executable(pedestrian pedestrian.c)

# Link necessary libraries
target_link_libraries(pedestrian rt)

# Set the output directory for this executable
set_target_properties(pedestrian PROPERTIES RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/../exe)
