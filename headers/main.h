#pragma once

#include "SoundPlayer.h"
#include <stdio.h>
#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include <imgui/imgui.h>
#include <imgui/imgui_impl_glfw.h>
#include <imgui/imgui_impl_opengl3.h>

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <utility>
#include <set>
#include <filesystem>
#include <map>

#include "shader.h"
#include "camera.h"
#include "basic_camera.h"
#include "pointLight.h"
#include "sphere.h"
#include "spotLight.h"
#include "directionLight.h"
#include "cube.h"
#include "stb_image.h"
#include "curve.h"
#include "sphere.h"
#include "octagon.h"

#include "shape_maker_functions.h"
#include "vertex_values.h"
#include "map_chunk.h"
#include "collision_cube_gen.h"
#include "building_location_generator.h"

#include <ft2build.h>
#include FT_FREETYPE_H  

// settings
const unsigned int SCR_WIDTH = 1500;
const unsigned int SCR_HEIGHT = 1000;

float rotateAngle_X = 0.0f;
float rotateAngle_Y = 0.0f;
float rotateAngle_Z = 0.0f;
float fanRotationAngle = 30.0f;

// camera settings
int LOOP_ITER = 0;
float PLANE_SPEED = 7.0f;
glm::vec3 MAP_SIZE = glm::vec3(40.0f, 0.00001f, 90.0f);
glm::vec3 MAP_TRANSLATE_VECTOR = glm::vec3(0.0f, 0.0f, -90.0f);

float MAP_CENTER = MAP_SIZE.x / 2;

glm::vec3 PLANE_SIZE = glm::vec3(0.5f, 0.5f, 2.0f);
glm::vec3 PLANE_TRANSLATE_VECTOR = glm::vec3(MAP_CENTER, 2.0f, -10.0f);

std::pair<float, float> PLANE_BOUNDARY(MAP_SIZE.x / 2 - (MAP_SIZE.x / 9), MAP_SIZE.x / 2 + (MAP_SIZE.x / 9)); //for 30.0f sized map, (-12.7, 18.3)

std::vector<glm::vec3> collision_cube_positions;

//building cubes
std::vector<glm::vec3> right_building_cube_positions;
std::vector<glm::vec3> left_building_cube_positions;
std::vector<glm::vec3> left_building_scales;
std::vector<glm::vec3> right_building_scales;
std::vector<unsigned int> left_building_texture_indices;
std::vector<unsigned int> right_building_texture_indices;

std::vector<glm::vec3> right_lamp_cube_positions;
std::vector<glm::vec3> left_lamp_cube_positions;

//glm::vec3 building_scale_vector = glm::vec3(randomNumber(bsz_min, bsz_max), randomNumber(bsz_min, bsz_max), randomNumber(bsz_min, bsz_max));

// camera
Camera camera(glm::vec3(MAP_CENTER, 5.2f, -2.0f));
float lastX = SCR_WIDTH / 2.0f;
float lastY = SCR_HEIGHT / 2.0f;
bool firstMouse = true;

float eyeX = 0.0, eyeY = 1.0, eyeZ = 0.0f;
float lookAtX = 0.0, lookAtY = 0.0, lookAtZ = 0.0;
glm::vec3 V = glm::vec3(0.0f, 1.0f, 0.0f);

float bsZ_min = 1.2f;
float bsZ_max = 5.0f;

float bsX_min = 1.5f;
float bsX_max = 6.0f;

SoundPlayer* gSoundPlayer = nullptr;

void processInput(GLFWwindow* window);
void framebuffer_size_callback(GLFWwindow* window, int width, int height);
void mouse_callback(GLFWwindow* window, double xpos, double ypos);
void scroll_callback(GLFWwindow* window, double xoffset, double yoffset);
void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods);


bool isPlaneAtNPercent() {
    float map_one_third_pos = (MAP_TRANSLATE_VECTOR.z + MAP_SIZE.z) - ((MAP_SIZE.z * 2) / 3);
    return int(PLANE_TRANSLATE_VECTOR.z) == map_one_third_pos;
}

void updateMapNewZPosition() {
    MAP_TRANSLATE_VECTOR.z -= ((MAP_SIZE.z * 0.5));
}

struct BuildingTexture {
    std::string buildingDiffuseMapPath;
    std::string buildingSpecularMapPath;
    unsigned int buildingDiffMap;
    unsigned int buildingSpecMap;
};
std::vector<BuildingTexture> buildingTextures;



// positions of the point lights
glm::vec3 pointLightPositions[] = {
    glm::vec3(2.50f,  20.50f,  -28.0f),
    glm::vec3(2.50f,  20.5f,  -18.0f),
    glm::vec3(-2.5f,  20.5f,  -28.0f),
    glm::vec3(-2.5f,  20.5f,  -18.0f)
};

glm::vec3 spotLightPosition = glm::vec3(0.0f, 20.5f, 68.0f);

SpotLight spotlight(

    spotLightPosition.x, spotLightPosition.y, spotLightPosition.z,  // position
    0.0f, -1.0f, 0.0f,   //direction
    0.0f, 0.5f, 0.5f,    // ambient
    0.0f, 1.0f, 1.0f,    // diffuse
    0.0f, 1.0f, 1.0f,    // specular
    0.05f,   //k_c
    0.009f,  //k_l
    0.0032f, //k_q
    60,     //light angle
    5       // light number
);

DirectionLight moonlight(

    0.0f, -1.0f, -0.5f,   //direction
    0.031f, 0.04f, 0.045f,    // ambient
    0.031f, 0.04f, 0.45f,    // diffuse
    1.0f, 1.0f, 1.0f,    // specular
    7       // light number
);

DirectionLight daylight(

    0.0f, -1.0f, -0.5f,   //direction
    0.4f, 0.4f, 0.4f,    // ambient
    0.8f, 0.8f, 0.8f,    // diffuse
    1.0f, 1.0f, 1.0f,    // specular
    6       // light number
);

PointLight pointlight1(

    pointLightPositions[0].x, pointLightPositions[0].y, pointLightPositions[0].z,  // position
    0.1f, 0.05f, 0.1f,     // ambient
    0.8f, 0.8f, 0.8f,     // diffuse
    1.0f, 1.0f, 1.0f,        // specular
    1.0f,   //k_c
    0.09f,  //k_l
    0.032f, //k_q
    1       // light number
);
PointLight pointlight2(

    pointLightPositions[1].x, pointLightPositions[1].y, pointLightPositions[1].z,  // position
    0.05f, 0.05f, 0.15f,     // ambient
    0.8f, 0.8f, 0.8f,     // diffuse
    1.0f, 1.0f, 1.0f,        // specular
    1.0f,   //k_c
    0.09f,  //k_l
    0.032f, //k_q
    2       // light number
);
PointLight pointlight3(

    pointLightPositions[2].x, pointLightPositions[2].y, pointLightPositions[2].z,  // position
    0.05f, 0.1f, 0.1f,     // ambient
    0.8f, 0.8f, 0.8f,     // diffuse
    1.0f, 1.0f, 1.0f,        // specular
    1.0f,   //k_c
    0.09f,  //k_l
    0.032f, //k_q
    3       // light number
);
PointLight pointlight4(

    pointLightPositions[3].x, pointLightPositions[3].y, pointLightPositions[3].z,  // position
    0.1f, 0.1f, 0.05f,     // ambient
    0.8f, 0.8f, 0.8f,     // diffuse
    1.0f, 1.0f, 1.0f,        // specular
    1.0f,   //k_c
    0.09f,  //k_l
    0.032f, //k_q
    4       // light number
);


// light settings
bool pointLightOn = true;
bool spotLightOn = true;
bool dayLightOn = true;
bool moonLightOn = true;
bool ambientToggle = true;
bool diffuseToggle = true;
bool specularToggle = true;


// timing
float deltaTime = 0.0f;    // time between current frame and last frame
float lastFrame = 0.0f;


void generateNewBuildings(bool isProgramInit) {
    float minZPossible = PLANE_TRANSLATE_VECTOR.z - 10.0f; //in-front of plane
    float maxZPossible = PLANE_TRANSLATE_VECTOR.z - int(MAP_SIZE.z * 0.7);

    int each_side_building_count = 20;

    /*
    * Left Side Buildings
    */
    auto new_left_building_locations = generate_building_locations(each_side_building_count, minZPossible, maxZPossible,
        0.0f, 0.0f, 1.0f, PLANE_BOUNDARY.first - (bsX_max * 1.5));
    
    //Insert newly generated items.
    for (int i = 0; i < new_left_building_locations.size(); i++) {
		left_building_cube_positions.push_back(new_left_building_locations[i]);
    }

    
    for (int i = 0; i < each_side_building_count; i++) { //Generate random scales and textures for the buildings
        auto szv = glm::vec3(randomNumber(bsX_min, bsX_max), randomNumber(bsX_min, bsX_max), randomNumber(bsZ_min, bsZ_max));
        left_building_scales.push_back(szv);

        //texture
        left_building_texture_indices.push_back(randomNumber(0, buildingTextures.size()-1));
    }

    
    /*
    * Right Side Buildings
    */
    auto new_right_building_locations = generate_building_locations(each_side_building_count, minZPossible, maxZPossible,
        0.3f, 3.0f, PLANE_BOUNDARY.second + (bsX_max * 1.5), (MAP_SIZE.x - 1.0f));
    
    //Insert newly generated items.
    for (int i = 0; i < new_right_building_locations.size(); i++) {
        right_building_cube_positions.push_back(new_right_building_locations[i]);
    }
    
    for (int i = 0; i < each_side_building_count; i++) { //Generate random scales and textures for the buildings 
        auto szv = glm::vec3(randomNumber(bsX_min, bsX_max), randomNumber(bsX_min, bsX_max), randomNumber(bsZ_min, bsZ_max));
        right_building_scales.push_back(szv);

        //texture
        right_building_texture_indices.push_back(randomNumber(0, buildingTextures.size()-1));
    }


    /*
    * Remove Buildings that are out of range.
    */
    if (!isProgramInit) {
    	//clear previous 12 buildings left
    	left_building_cube_positions.erase(left_building_cube_positions.begin(), left_building_cube_positions.begin() + int(left_building_cube_positions.size() / 2));
    	
        //clear previous 12 buildings right
    	right_building_cube_positions.erase(right_building_cube_positions.begin(), right_building_cube_positions.begin() + int(right_building_cube_positions.size() / 2));
    }
}

void generateNewLamps(bool isProgramInit) {
    float minZPossible = PLANE_TRANSLATE_VECTOR.z - 10.0f; //in-front of plane
    float maxZPossible = PLANE_TRANSLATE_VECTOR.z - int(MAP_SIZE.z * 0.7);

    int each_side_lamp_count = 5;

    /*
    * Left Side Lamps
    */
    left_lamp_cube_positions = generate_building_locations(each_side_lamp_count, minZPossible, maxZPossible,
        0.0f, 0.0f, PLANE_BOUNDARY.first + (bsX_max * 1.00f), PLANE_BOUNDARY.first + (bsX_max * 1.00f));


    /*
    * Right Side Lamps
    */
    right_lamp_cube_positions = generate_building_locations(each_side_lamp_count, minZPossible, maxZPossible,
        0.0f, 0.0f, PLANE_BOUNDARY.second + (bsX_max * 1.00f), PLANE_BOUNDARY.second + (bsX_max * 1.00f));

    /*
    * Remove lamp that are out of range.
    */
    if (!isProgramInit) {
        //clear previous 12 lamp left
        left_lamp_cube_positions.erase(left_lamp_cube_positions.begin(), left_lamp_cube_positions.begin() + int(left_lamp_cube_positions.size() / 2));

        //clear previous 12 lamp right
        right_lamp_cube_positions.erase(right_lamp_cube_positions.begin(), right_lamp_cube_positions.begin() + int(right_lamp_cube_positions.size() / 2));
    }
}

void make_textures() {
    std::string directoryPath = "resources/buildings/";

    // Iterate over files in the directory
    for (const auto& entry : std::filesystem::directory_iterator(directoryPath)) {
        if (entry.is_regular_file()) {
            std::string filePath = entry.path().string();

            // Filter for .jpg files (or other supported texture formats)
            if (filePath.find(".jpg") != std::string::npos) {
                BuildingTexture texture;

                // Set the diffuse and specular paths to the same file for simplicity
                texture.buildingDiffuseMapPath = filePath;
                texture.buildingSpecularMapPath = filePath;

                // Load textures
                texture.buildingDiffMap = loadTexture(
                    texture.buildingDiffuseMapPath.c_str(), GL_REPEAT, GL_REPEAT, GL_LINEAR_MIPMAP_LINEAR, GL_LINEAR);
                texture.buildingSpecMap = loadTexture(
                    texture.buildingSpecularMapPath.c_str(), GL_REPEAT, GL_REPEAT, GL_LINEAR_MIPMAP_LINEAR, GL_LINEAR);

                // Add to the vector
                buildingTextures.push_back(texture);
            }
        }
    }
}

void drawBuildings(Shader & lightingShader) {

    glm::mat4 identityMatrix = glm::mat4(1.0f);

    for (int i = 0; i < left_building_cube_positions.size(); ++i) {
        glm::vec3 cubePosition = left_building_cube_positions[i];
        cubePosition.y = 0.0f;
        glm::mat4 translate = glm::translate(identityMatrix, cubePosition);
        glm::mat4 scale = glm::scale(identityMatrix, left_building_scales[i]);
        glm::mat4 model = translate * scale;

		BuildingTexture texture = buildingTextures[left_building_texture_indices[i]];

        Cube building_cube = Cube(texture.buildingDiffMap, texture.buildingSpecMap, 50.0f, 0.0f, 0.0f, 1.0f, 1.0f);
        building_cube.drawCubeWithTexture(lightingShader, model);
    }

    for (int i = 0; i < right_building_cube_positions.size(); ++i) {
        glm::vec3 cubePosition = right_building_cube_positions[i];
        cubePosition.y = 0.0f;
        glm::mat4 translate = glm::translate(identityMatrix, cubePosition);
        glm::mat4 scale = glm::scale(identityMatrix, right_building_scales[i]);
        glm::mat4 model = translate * scale;

        BuildingTexture texture = buildingTextures[right_building_texture_indices[i]];

        Cube building_cube = Cube(texture.buildingDiffMap, texture.buildingSpecMap, 50.0f, 0.0f, 0.0f, 1.0f, 1.0f);
        building_cube.drawCubeWithTexture(lightingShader, model);
    }
}

void drawFan(Shader& lightingShaderWithTexture, Cube& bladeCube) {
    glm::mat4 model, translate, rotate, scale;

    // Center of the fan in front of the plane
    translate = glm::translate(glm::mat4(1.0f), glm::vec3(
        PLANE_TRANSLATE_VECTOR.x + 0.1f,
        PLANE_TRANSLATE_VECTOR.y + 0.2f,
        PLANE_TRANSLATE_VECTOR.z 
    ));

    // Rotation around the Z-axis
    rotate = glm::rotate(translate, glm::radians(fanRotationAngle), glm::vec3(0.0f, 0.0f, 1.0f));

    // Draw multiple blades of the fan
    for (int i = 0; i < 3; i++) {
        glm::mat4 bladeTransform = glm::rotate(rotate, glm::radians(120.0f * i), glm::vec3(0.0f, 0.0f, 1.0f));
        model = glm::scale(bladeTransform, glm::vec3(0.05f, 0.8f, 0.02f)); // Scale for blade dimensions
        bladeCube.drawCubeWithTexture(lightingShaderWithTexture, model);
    }
}


void drawPlane(Shader& lightingShaderWithTexture, Cube & bodyCube, Cube &wingCube, Cube& bladeCube) {
    glm::mat4 translate, rotate, revtranslate, alTogether, next, model, scale, rotateXMatrix, rotateYMatrix, rotateZMatrix;
    model = glm::mat4(1.0f);
    translate = glm::translate(model, PLANE_TRANSLATE_VECTOR);
    rotateXMatrix = glm::rotate(translate, glm::radians(rotateAngle_X), glm::vec3(1.0f, 0.0f, 0.0f));
    rotateYMatrix = glm::rotate(rotateXMatrix, glm::radians(rotateAngle_Y), glm::vec3(0.0f, 1.0f, 0.0f));
    rotateZMatrix = glm::rotate(rotateYMatrix, glm::radians(rotateAngle_Z), glm::vec3(0.0f, 0.0f, 1.0f));
    model = glm::scale(rotateZMatrix, glm::vec3(0.25f, 0.25f, 1.75f));
    bodyCube.drawCubeWithTexture(lightingShaderWithTexture, model);


    model = glm::mat4(1.0f);
    translate = glm::translate(model, glm::vec3((PLANE_TRANSLATE_VECTOR.x - (1.35f / 2)), (PLANE_TRANSLATE_VECTOR.y + 0.1f), (PLANE_TRANSLATE_VECTOR.z + 0.4f)));
    rotateXMatrix = glm::rotate(translate, glm::radians(rotateAngle_X), glm::vec3(1.0f, 0.0f, 0.0f));
    rotateYMatrix = glm::rotate(rotateXMatrix, glm::radians(rotateAngle_Y + 90.0f), glm::vec3(0.0f, 1.0f, 0.0f));
    rotateZMatrix = glm::rotate(rotateYMatrix, glm::radians(rotateAngle_Z ), glm::vec3(0.0f, 0.0f, 1.0f));
    model = glm::scale(rotateZMatrix, glm::vec3(0.15f, 0.01f, 1.55f));
    wingCube.drawCubeWithTexture(lightingShaderWithTexture, model);

    model = glm::mat4(1.0f);
    translate = glm::translate(model, glm::vec3((PLANE_TRANSLATE_VECTOR.x + 0.1f), (PLANE_TRANSLATE_VECTOR.y + 0.1f), (PLANE_TRANSLATE_VECTOR.z + 1.6f)));
    rotateXMatrix = glm::rotate(translate, glm::radians(rotateAngle_X), glm::vec3(1.0f, 0.0f, 0.0f));
    rotateYMatrix = glm::rotate(rotateXMatrix, glm::radians(rotateAngle_Y + 90.0f - 30.0f), glm::vec3(0.0f, 1.0f, 0.0f));
    rotateZMatrix = glm::rotate(rotateYMatrix, glm::radians(rotateAngle_Z ), glm::vec3(0.0f, 0.0f, 1.0f));
    model = glm::scale(rotateZMatrix, glm::vec3(0.15f, 0.01f, 0.55f));
    wingCube.drawCubeWithTexture(lightingShaderWithTexture, model);

    model = glm::mat4(1.0f);
    translate = glm::translate(model, glm::vec3((PLANE_TRANSLATE_VECTOR.x), (PLANE_TRANSLATE_VECTOR.y + 0.1f), (PLANE_TRANSLATE_VECTOR.z + 1.6f)));
    rotateXMatrix = glm::rotate(translate, glm::radians(rotateAngle_X), glm::vec3(1.0f, 0.0f, 0.0f));
    rotateYMatrix = glm::rotate(rotateXMatrix, glm::radians(rotateAngle_Y + 270.0f + 30.0f), glm::vec3(0.0f, 1.0f, 0.0f));
    rotateZMatrix = glm::rotate(rotateYMatrix, glm::radians(rotateAngle_Z), glm::vec3(0.0f, 0.0f, 1.0f));
    model = glm::scale(rotateZMatrix, glm::vec3(0.15f, 0.01f, 0.55f));
    wingCube.drawCubeWithTexture(lightingShaderWithTexture, model);

    // Draw the fan
    drawFan(lightingShaderWithTexture, bladeCube);
}


void LampPost(Shader ourShader, glm::mat4 moveMatrix, unsigned int &cubeVAO, glm::vec3 translation)
{
    glm::mat4 identityMatrix = glm::mat4(1.0f); // make sure to initialize matrix to identity matrix first
    glm::mat4 translateMatrix, scaleMatrix, model, rotateZMatrix, rotateXMatrix, rotateYMatrix, rotate;

    //base
    translateMatrix = glm::translate(identityMatrix, translation);
    scaleMatrix = glm::scale(identityMatrix, glm::vec3(0.7f, 0.3f, 0.7f));
    model = translateMatrix * scaleMatrix;
    ourShader.setMat4("model", moveMatrix * model);
    ourShader.setVec4("material.ambient", glm::vec4(0.0f, 0.0f, 0.0f, 1.0f));
    ourShader.setVec4("material.diffuse", glm::vec4(0.0f, 0.0f, 0.0f, 1.0f));
    ourShader.setVec4("material.specular", glm::vec4(0.0, 0.0f, 0.0f, 1.0f));
    ourShader.setFloat("material.shininess", 32.0f);
    glBindVertexArray(cubeVAO);
    glDrawElements(GL_TRIANGLES, 36, GL_UNSIGNED_INT, 0);

    //pillar
    translation.x += 0.35f;
    translation.z += 0.35f;
    translateMatrix = glm::translate(identityMatrix, translation);
    scaleMatrix = glm::scale(identityMatrix, glm::vec3(0.1f, 6.0f, 0.1f));
    model = translateMatrix * scaleMatrix;
    ourShader.setMat4("model", moveMatrix * model);
    ourShader.setVec4("material.ambient", glm::vec4(0.0f, 0.0f, 0.0f, 1.0f));
    ourShader.setVec4("material.diffuse", glm::vec4(0.0f, 0.0f, 0.0f, 1.0f));
    ourShader.setVec4("material.specular", glm::vec4(0.0f, 0.0f, 0.0f, 1.0f));
    ourShader.setFloat("material.shininess", 32.0f);
    glDrawElements(GL_TRIANGLES, 36, GL_UNSIGNED_INT, 0);


    //pillar top
    translateMatrix = glm::translate(identityMatrix, glm::vec3(0.1f, 6.0f, 0.1f));
    rotateXMatrix = glm::rotate(translateMatrix, glm::radians(rotateAngle_X), glm::vec3(1.0f, 0.0f, 0.0f));
    rotateYMatrix = glm::rotate(rotateXMatrix, glm::radians(rotateAngle_Y - 30.0f), glm::vec3(0.0f, 1.0f, 0.0f));
    rotateZMatrix = glm::rotate(rotateYMatrix, glm::radians(rotateAngle_Z), glm::vec3(0.0f, 0.0f, 1.0f));
    scaleMatrix = glm::scale(identityMatrix, glm::vec3(0.1f, 6.0f, 0.1f));
    model = translateMatrix * scaleMatrix;
    ourShader.setMat4("model", moveMatrix * model);
    ourShader.setVec4("material.ambient", glm::vec4(0.0f, 0.0f, 0.0f, 1.0f));
    ourShader.setVec4("material.diffuse", glm::vec4(0.0f, 0.0f, 0.0f, 1.0f));
    ourShader.setVec4("material.specular", glm::vec4(0.0f, 0.0f, 0.0f, 1.0f));
    ourShader.setFloat("material.shininess", 32.0f);
    glDrawElements(GL_TRIANGLES, 36, GL_UNSIGNED_INT, 0);

}

