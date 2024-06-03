
# Subdirectory for traffic light controller
add_executable(traffic_light traffic_light.c)

# Link necessary libraries
target_link_libraries(traffic_light rt)

# Set the output directory for this executable
set_target_properties(traffic_light PROPERTIES RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/../exe)
