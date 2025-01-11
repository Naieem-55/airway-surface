#pragma once

#include "cube.h"
#include "stb_image.h"
#include "load_texture.h"
#include "shader.h"
#include "cylinder.h"
#include <vector>


Cube create_building(string diffuseMapPath, string specularMapPath, Shader lightingShaderWithTexture, glm::vec3 scale_vector, glm::vec3 translate_vector) {
	unsigned int diffMap = loadTexture(diffuseMapPath.c_str(), GL_REPEAT, GL_REPEAT, GL_LINEAR_MIPMAP_LINEAR, GL_LINEAR);
	unsigned int specMap = loadTexture(specularMapPath.c_str(), GL_REPEAT, GL_REPEAT, GL_LINEAR_MIPMAP_LINEAR, GL_LINEAR);

	Cube texcube = Cube(diffMap, specMap, 32.0f, 0.0f, 0.0f, 1.0f, 1.0f);

	glm::mat4 identityMatrix = glm::mat4(1.0f);
	glm::mat4 translate, rotate, revtranslate, alTogether, next, model, scale;

	translate = glm::translate(identityMatrix, glm::vec3(0.0f, 0.0f, 30.0f));
	scale = glm::scale(identityMatrix, glm::vec3(90.0f, 90.0f, 90.0f));
	rotate = glm::rotate(identityMatrix, glm::radians(20.0f * 0.05f), glm::vec3(0.0f, 1.0f, 0.0f));
	model = translate * scale;

	translate = glm::translate(identityMatrix, translate_vector);
	scale = glm::scale(identityMatrix, scale_vector);
	model = translate * scale;
	texcube.drawCubeWithTexture(lightingShaderWithTexture, model);

	return texcube;
}

//void create_map(glm::vec3 translate_vector, Shader lightingShaderWithTexture){
//	std::string diffuseMapPath = "resources/sky_2.jpeg";
//	std::string specularMapPath = "resources/sky_2.jpeg";
//	unsigned int diffMap = loadTexture(diffuseMapPath.c_str(), GL_REPEAT, GL_REPEAT, GL_LINEAR_MIPMAP_LINEAR, GL_LINEAR);
//	unsigned int specMap = loadTexture(specularMapPath.c_str(), GL_REPEAT, GL_REPEAT, GL_LINEAR_MIPMAP_LINEAR, GL_LINEAR);
//
//	Cube cube = Cube();
//	//Cube texcube = Cube(diffMap, specMap, 32.0f, 0.0f, 0.0f, 1.0f, 1.0f);
//	Cylinder cylinder_sky = Cylinder(diffMap, specMap, 32.0f, 0.0f, 0.0f, 1.0f, 1.0f);
//
//	glm::mat4 identityMatrix = glm::mat4(1.0f);
//	glm::mat4 translate, rotate, revtranslate, alTogether, next, model, scale;
//
//	translate = glm::translate(identityMatrix, translate_vector);
//	scale = glm::scale(identityMatrix, glm::vec3(200.0f, 0.00001f, 300.0f));
//	model = translate * scale;
//	cube.drawCubeWithTexture(lightingShaderWithTexture, model);
//
//	/*translate = glm::translate(identityMatrix, glm::vec3(200.0f, 0.0f, 300.0f));
//	scale = glm::scale(identityMatrix, glm::vec3(200.0f, 100.0f, 1.0f));
//	model = translate * scale;
//	cylinder_sky.drawCylinder(lightingShaderWithTexture, model, 1.0f, 22.0f, 290.0f);*/
//
//	translate = glm::translate(identityMatrix, glm::vec3(100.0f, 0.0f, 0.0f));
//	scale = glm::scale(identityMatrix, glm::vec3(100.0f, 10.0f, 100.0f));
//	model = translate * scale;
//	cylinder_sky.drawCylinderWithTexture(lightingShaderWithTexture, model);
//}

void create_map(glm::vec3 translate_vector, Shader lightingShaderWithTexture) {

	float map_x_length = 150.0f;
	float map_y_length = 0.00001f;
	float map_z_length = 300.0f;

	std::string diffuseMapPath = "resources/sky_2.jpeg";
	std::string specularMapPath = "resources/sky_2.jpeg";
	unsigned int diffMap = loadTexture(diffuseMapPath.c_str(), GL_REPEAT, GL_REPEAT, GL_LINEAR_MIPMAP_LINEAR, GL_LINEAR);
	unsigned int specMap = loadTexture(specularMapPath.c_str(), GL_REPEAT, GL_REPEAT, GL_LINEAR_MIPMAP_LINEAR, GL_LINEAR);

	Cube cube = Cube();
	Cylinder cylinder_sky = Cylinder(diffMap, specMap, 32.0f, 0.0f, 0.0f, 1.0f, 1.0f);

	glm::mat4 identityMatrix = glm::mat4(1.0f);
	glm::mat4 translate, rotate, revtranslate, alTogether, next, model, scale;
	

	//drawing the floor
	translate = glm::translate(identityMatrix, translate_vector);
	scale = glm::scale(identityMatrix, glm::vec3(150.0f, 0.00001f, 300.0f));
	model = translate * scale;
	cube.drawCubeWithTexture(lightingShaderWithTexture, model);

	
	//drawing the sky cylinder
	translate = glm::translate(identityMatrix, glm::vec3(map_x_length / 2, 0.0f, map_z_length));  // Position of the cylinder
	scale = glm::scale(identityMatrix, glm::vec3(map_x_length/2, map_z_length, 80.0f));  // Scale of the cylinder

	// Apply 90-degree rotation around the X-axis
	rotate = glm::rotate(identityMatrix, glm::radians(-90.0f), glm::vec3(1.0f, 0.0f, 0.0f));  // Rotate 90 degrees around the X-axis
	model = translate * rotate * scale;  // Combine translation, rotation, and scale

	cylinder_sky.drawCylinderWithTexture(lightingShaderWithTexture, model);
}
