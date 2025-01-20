#pragma once

#include <glad/glad.h>
#include <vector>
#include <glm/glm.hpp>
#include <cstdlib>  
#include <ctime> 

std::vector<glm::vec3> generate_building_locations(int buildingCount, float minZ, float maxZ, float minY = 0.3f, float maxY = 10.0f, float minX = 15.0f, float maxX = 20.0f) {
    srand(static_cast<unsigned int>(time(0)));
    std::vector<glm::vec3> cubePositions;

    for (int i = 0; i < buildingCount; ++i) {
        float randX = minX + static_cast<float>(rand()) / (static_cast<float>(RAND_MAX / (maxX - minX)));
        float randY = minY + static_cast<float>(rand()) / (static_cast<float>(RAND_MAX / (maxY - minY)));
        float randZ = minZ + static_cast<float>(rand()) / (static_cast<float>(RAND_MAX / (maxZ - minZ)));

        glm::vec3 cubePosition(randX, randY, randZ);

        cubePositions.push_back(cubePosition);
    }

    return cubePositions;
}
