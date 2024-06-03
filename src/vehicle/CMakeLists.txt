
# Subdirectory for vehicle controller
add_executable(vehicle vehicle.c)

# Link necessary libraries
target_link_libraries(vehicle rt)

# Set the output directory for this executable
set_target_properties(vehicle PROPERTIES RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/../exe)
