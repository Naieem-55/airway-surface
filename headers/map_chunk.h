#pragma once

#include "cube.h"
#include "stb_image.h"
#include "load_texture.h"
#include "shader.h"
#include "cylinder.h"
#include "utils.h"
#include <vector>


Cube create_building(unsigned int diffMap, unsigned int specMap, Shader lightingShaderWithTexture, glm::vec3 scale_vector, glm::vec3 translate_vector) {
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


void create_map(glm::vec3 map_scale, glm::vec3 translate_vector, Shader lightingShaderWithTexture, unsigned int diffMap, unsigned int specMap, float shiny) {

	Cube cube = Cube(diffMap, specMap, shiny, 0.0f, 0.0f, 0.87f, 1.0f);

	glm::mat4 identityMatrix = glm::mat4(1.0f);
	glm::mat4 translate, rotate, revtranslate, alTogether, next, model, scale;

	//drawing the floor
	translate = glm::translate(identityMatrix, translate_vector);
	scale = glm::scale(identityMatrix, map_scale);
	model = translate * scale;

	lightingShaderWithTexture.use();
	lightingShaderWithTexture.setVec3("color", glm::vec3(1.0f, 0.0f, 0.0f));
	cube.drawCubeWithTexture(lightingShaderWithTexture, model);
}
