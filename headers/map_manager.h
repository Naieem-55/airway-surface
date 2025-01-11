#pragma once	
#include <queue>
#include <string>
#include <random>

#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#include "shader.h"
#include "map_chunk.h"

class Map {
	std::queue<glm::vec3> map_locations;
	std::vector< std::string> texture_path;
	
	float map_incremental_value = 100.0f;
	
	int loop_quotient = 5000;
	bool just_started = true;

	Shader lightingShaderWithTexture;

public:

	Map(std::vector<std::string> texture_path, Shader lightingShaderWithTexture) {
		this->texture_path = texture_path;

		//start at 0,0,0
		map_locations.push(glm::vec3(0.0f, 0.0f, 0.0f));
		map_locations.push(glm::vec3(0.0f, 0.0f, 1000.0f));

		

		//std::cout << dist6(rng) << std::endl;
	}

	void render_map(int loop_itr) {
		if (loop_itr % this->loop_quotient == 0) {
			if (just_started) {
				just_started = false;
			}
			else {
				//int map_index = this->random_number(1, 1); //3 map only --> top, left, right ... currently 1 for simplicity.
				
				create_map(this->map_locations.front(), this->lightingShaderWithTexture);
				create_map(this->map_locations.back(), this->lightingShaderWithTexture);
			}
		}
	}

	int random_number(int min, int max) {
		std::random_device dev;
		std::mt19937 rng(dev());
		std::uniform_int_distribution<std::mt19937::result_type> dist6(min, max); 

		return dist6(rng);
	}
};
