#pragma once

#include "cube.h"
#include "stb_image.h"
#include "load_texture.h"
#include "shader.h"
#include "cylinder.h"
#include "utils.h"
#include <vector>


Cube create_building(string diffuseMapPath, string specularMapPath, Shader lightingShaderWithTexture, glm::vec3 scale_vector, glm::vec3 translate_vector) {
	unsigned int diffMap = loadTexture(diffuseMapPath.c_str(), GL_REPEAT, GL_REPEAT, GL_LINEAR_MIPMAP_LINEAR, GL_LINEAR);
	unsigned int specMap = loadTexture(specularMapPath.c_str(), GL_REPEAT, GL_REPEAT, GL_LINEAR_MIPMAP_LINEAR, GL_LINEAR);

	Cube texcube = Cube(diffMap, specMap, 32.0f, 0.0f, 0.0f, 1.0f, 1.0f);

	glm::mat4 identityMatrix = glm::mat4(1.0f);
	glm::mat4 translate, rotate, revtranslate, alTogether, next, model, scale;

	translate = glm::translate(identityMatrix, glm::vec3(0.0f, 0.0f, 0.0f));
	scale = glm::scale(identityMatrix, glm::vec3(90.0f, 90.0f, 90.0f));
	rotate = glm::rotate(identityMatrix, glm::radians(20.0f * 0.05f), glm::vec3(0.0f, 1.0f, 0.0f));
	model = translate * scale;

	translate = glm::translate(identityMatrix, translate_vector);
	scale = glm::scale(identityMatrix, scale_vector);
	model = translate * scale;
	texcube.drawCubeWithTexture(lightingShaderWithTexture, model);

	return texcube;
}


void create_map(glm::vec3 map_scale, glm::vec3 translate_vector, Shader lightingShaderWithTexture, glm::vec4 ambient, glm::vec4 diffuse, glm::vec4 specular, float shiny) {

	Cube cube = Cube(ambient, diffuse, specular, shiny);

	glm::mat4 identityMatrix = glm::mat4(1.0f);
	glm::mat4 translate, rotate, revtranslate, alTogether, next, model, scale;

	//drawing the floor
	translate = glm::translate(identityMatrix, translate_vector);
	scale = glm::scale(identityMatrix, map_scale);
	model = translate * scale;

	lightingShaderWithTexture.use();
	lightingShaderWithTexture.setVec3("color", glm::vec3(1.0f, 0.0f, 0.0f));
	cube.drawCube(lightingShaderWithTexture, model);


	//Generate Buildings
	/*std::string buildingDiffuseMapPath = "resources/wall__brick2.jpg";
	std::string buildingSpecularMapPath = "resources/wall__brick2.jpg";
	unsigned int buildingDiffMap = loadTexture(buildingDiffuseMapPath.c_str(), GL_REPEAT, GL_REPEAT, GL_LINEAR_MIPMAP_LINEAR, GL_LINEAR);
	unsigned int buildingSpecMap = loadTexture(buildingSpecularMapPath.c_str(), GL_REPEAT, GL_REPEAT, GL_LINEAR_MIPMAP_LINEAR, GL_LINEAR);

	int bsz_min = 2.0f;
	int bsz_max = 5.0f;

	glm::vec3 building_scale_vector = glm::vec3(randomNumber(bsz_min, bsz_max), randomNumber(bsz_min, bsz_max), randomNumber(bsz_min, bsz_max));
	glm::vec3 building_translate_vector = glm::vec3(randomNumber(bsz_min, bsz_max), 0.0f, randomNumber(bsz_min, bsz_max));*/

	//create_building(buildingDiffuseMapPath, buildingSpecularMapPath, lightingShaderWithTexture, building_scale_vector, building_translate_vector);
}
