#ifndef SPHERE_H
#define SPHERE_H

#include <glad/glad.h>
#include <vector>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include "shader.h"
#define M_PI 3.14159

class Sphere {
public:
    Sphere(float radius = 1.0f, int sectors = 36, int stacks = 18)
        : radius(radius), sectors(sectors), stacks(stacks),
        diffuseMap(0), specularMap(0), shininess(32.0f), VAO(0), VBO(0), EBO(0) {
        generateSphereData();
        setupOpenGLBuffers();
    }

    ~Sphere() {
        glDeleteVertexArrays(1, &VAO);
        glDeleteBuffers(1, &VBO);
        glDeleteBuffers(1, &EBO);
    }

    void setTextureProperty(unsigned int diffuse, unsigned int specular, float shiny) {
        diffuseMap = diffuse;
        specularMap = specular;
        shininess = shiny;
    }

    void drawWithoutTexture(Shader& shader, const glm::mat4& model, float r = 1.0f, float g = 1.0f, float b = 1.0f) {
        shader.use();
        shader.setMat4("model", model);
        shader.setVec3("color", glm::vec3(r, g, b));

        glBindVertexArray(VAO);
        glDrawElements(GL_TRIANGLES, static_cast<GLsizei>(indices.size()), GL_UNSIGNED_INT, 0);
        glBindVertexArray(0);
    }

    void drawSphereWithTexture(Shader& shader, const glm::mat4& model) {
        shader.use();
        shader.setMat4("model", model);
        shader.setInt("textures.diffuse", 0);
        shader.setInt("textures.specular", 1);
        shader.setFloat("textures.shininess", shininess);
        shader.setBool("drawWithTexture", true);

        glActiveTexture(GL_TEXTURE0);
        glBindTexture(GL_TEXTURE_2D, diffuseMap);
        glActiveTexture(GL_TEXTURE1);
        glBindTexture(GL_TEXTURE_2D, specularMap);

        glBindVertexArray(VAO);
        glDrawElements(GL_TRIANGLES, static_cast<GLsizei>(indices.size()), GL_UNSIGNED_INT, 0);
        glBindVertexArray(0);
    }

private:
    float radius;
    int sectors, stacks;
    unsigned int diffuseMap, specularMap;
    float shininess;
    unsigned int VAO, VBO, EBO;
    std::vector<float> vertices;
    std::vector<unsigned int> indices;

    void generateSphereData() {
        float x, y, z, xy;
        float nx, ny, nz, s, t;
        float sectorStep = 2 * M_PI / sectors;
        float stackStep = M_PI / stacks;
        float sectorAngle, stackAngle;

        for (int i = 0; i <= stacks; ++i) {
            stackAngle = M_PI / 2 - i * stackStep;
            xy = radius * cosf(stackAngle);
            z = radius * sinf(stackAngle);

            for (int j = 0; j <= sectors; ++j) {
                sectorAngle = j * sectorStep;

                x = xy * cosf(sectorAngle);
                y = xy * sinf(sectorAngle);
                vertices.push_back(x);
                vertices.push_back(y);
                vertices.push_back(z);

                nx = x / radius;
                ny = y / radius;
                nz = z / radius;
                vertices.push_back(nx);
                vertices.push_back(ny);
                vertices.push_back(nz);

                s = (float)j / sectors;
                t = (float)i / stacks;
                vertices.push_back(s);
                vertices.push_back(t);
            }
        }

        for (int i = 0; i < stacks; ++i) {
            int k1 = i * (sectors + 1);
            int k2 = k1 + sectors + 1;

            for (int j = 0; j < sectors; ++j, ++k1, ++k2) {
                if (i != 0) {
                    indices.push_back(k1);
                    indices.push_back(k2);
                    indices.push_back(k1 + 1);
                }

                if (i != (stacks - 1)) {
                    indices.push_back(k1 + 1);
                    indices.push_back(k2);
                    indices.push_back(k2 + 1);
                }
            }
        }
    }

    void setupOpenGLBuffers() {
        glGenVertexArrays(1, &VAO);
        glGenBuffers(1, &VBO);
        glGenBuffers(1, &EBO);

        glBindVertexArray(VAO);

        glBindBuffer(GL_ARRAY_BUFFER, VBO);
        glBufferData(GL_ARRAY_BUFFER, vertices.size() * sizeof(float), vertices.data(), GL_STATIC_DRAW);

        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
        glBufferData(GL_ELEMENT_ARRAY_BUFFER, indices.size() * sizeof(unsigned int), indices.data(), GL_STATIC_DRAW);

        glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)0);
        glEnableVertexAttribArray(0);

        glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)(3 * sizeof(float)));
        glEnableVertexAttribArray(1);

        glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)(6 * sizeof(float)));
        glEnableVertexAttribArray(2);

        glBindVertexArray(0);
    }
};

#endif