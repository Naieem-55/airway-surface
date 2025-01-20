#pragma once

#include <glad/glad.h>
#include <vector>
#include <glm/glm.hpp>
#include <cstdlib>  // For rand() and srand()
#include <ctime>    // For time() to seed the random generator

// Function to generate random cube positions within a specified range for X, Y, and Z
std::vector<glm::vec3> generate_collision_cube_position(float minZ, float maxZ, float minY = 0.3f, float maxY = 10.0f, float minX = 15.0f, float maxX = 20.0f) {
    // Seed the random number generator with the current time
    srand(static_cast<unsigned int>(time(0)));

    // Vector to store the positions of the generated cubes
    std::vector<glm::vec3> cubePositions;

    // Generate 5 random cubes
    for (int i = 0; i < 5; ++i) {
        // Randomly generate X, Y coordinates within the given bounds
        float randX = minX + static_cast<float>(rand()) / (static_cast<float>(RAND_MAX / (maxX - minX)));
        float randY = minY + static_cast<float>(rand()) / (static_cast<float>(RAND_MAX / (maxY - minY)));

        // Randomly generate Z coordinates within the given bounds
        // Z value should be between minZ (closer to the camera) and maxZ (further away)
        float randZ = minZ + static_cast<float>(rand()) / (static_cast<float>(RAND_MAX / (maxZ - minZ)));

        // Create a new glm::vec3 with the generated position
        glm::vec3 cubePosition(randX, randY, randZ);

        // Add the generated position to the vector
        cubePositions.push_back(cubePosition);
    }

    return cubePositions;
}


