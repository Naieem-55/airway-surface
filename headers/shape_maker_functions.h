#pragma once

#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#include "shader.h"
#include "camera.h"
#include "basic_camera.h"
#include "pointLight.h"
#include "sphere.h"
#include "spotLight.h"
#include "directionLight.h"
#include "cube.h"
#include "curve.h"
#include "sphere.h"
#include "octagon.h"
#include "load_texture.h"


void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods);
void processInput(GLFWwindow* window);
void drawCube(unsigned int& cubeVAO, Shader& lightingShader, glm::mat4 model, float r, float g, float b);
//void bed(unsigned int& cubeVAO, Shader& lightingShader, glm::mat4 alTogether);
void drawField(unsigned int& cubeVAO, Shader& lightingShader, glm::mat4 alTogether);
void drawFieldWithTexture(Shader& lightingShader, glm::mat4 alTogether);
void drawBase(unsigned int& cubeVAO, Shader& lightingShader, glm::mat4 alTogether);
//void drawFrontLake(unsigned int& cubeVAO, Shader& lightingShader, glm::mat4 alTogether);
//void drawLake(unsigned int& cubeVAO, Shader& lightingShader, glm::mat4 alTogether);
void drawMain(unsigned int& cubeVAO, Shader& lightingShader, glm::mat4 alTogether);
void drawEntrance(unsigned int& cubeVAO, Shader& lightingShader, glm::mat4 alTogether);
void drawSideFrame(unsigned int& cubeVAO, Shader& lightingShader, glm::mat4 alTogether);
void drawRoof(unsigned int& cubeVAO, Shader& lightingShader, glm::mat4 alTogether);
//void drawTreeWithFractiles(unsigned int& cubeVAO, Shader& lightingShader, glm::mat4 alTogether, float L, float H, float W, int N);
void drawTajmahal(unsigned int& cubeVAO, Shader& lightingShader, glm::mat4 alTogether);
void drawSemiDome(unsigned int& cubeVAO, BezierCurve& semiDome, Octagon& base, Octagon& mid, Shader& lightingShader, glm::mat4 alTogether);
void drawDome(unsigned int& cubeVAO, BezierCurve& semiDome, Octagon& base, Shader& lightingShader, glm::mat4 alTogether);
void drawFloor(unsigned int& cubeVAO, Shader& lightingShader, glm::mat4 alTogether);
//void drawCylindricalTree(BezierCurve& CylinderGreen, BezierCurve& CylinderGrey, Shader& lightingShader, glm::mat4 alTogether);
//void drawNormalTree(BezierCurve& NormalTree, BezierCurve& CylinderGrey, Shader& lightingShader, glm::mat4 alTogether);
//void drawTrees(BezierCurve& NormalTree, BezierCurve& CylinderGreen, BezierCurve& CylinderGrey, Shader& lightingShader, glm::mat4 alTogether);
void drawMinar(unsigned int& cubeVAO, BezierCurve& cylinder, BezierCurve& semiDome, Octagon& base, Octagon& oct, Shader& lightingShader, glm::mat4 alTogether);
void drawNarrowMinar(unsigned int& cubeVAO, BezierCurve& cylinder, BezierCurve& semiDome, Octagon& base, Octagon& oct, Shader& lightingShader, glm::mat4 alTogether);
void drawNarrowMinarTogether(unsigned int& cubeVAO, BezierCurve& minar, BezierCurve& semiDome, Octagon& oct3, Octagon& oct2, Shader& lightingShader, glm::mat4 next); unsigned int loadTexture(char const* path, GLenum textureWrappingModeS, GLenum textureWrappingModeT, GLenum textureFilteringModeMin, GLenum textureFilteringModeMax);


//void drawTrees(BezierCurve& NormalTree, BezierCurve& CylinderGreen, BezierCurve& CylinderGrey, Shader& lightingShader, glm::mat4 alTogether)
//{
//
//    glm::mat4 model = glm::mat4(1.0f);
//    glm::mat4 translate = glm::mat4(1.0f);
//    glm::mat4 identityMatrix = glm::mat4(1.0f);
//    glm::mat4 scale = glm::mat4(1.0f);
//    glm::mat4 rotate = glm::mat4(1.0f);
//
//
//
//    translate = glm::translate(identityMatrix, glm::vec3(-3.5, 0.0, 4.0));
//    model = alTogether * translate;
//    //drawCylindricalTree(CylinderGreen,CylinderGrey,lightingShader, model);
//
//    translate = glm::translate(identityMatrix, glm::vec3(-3.5, 0.0, 14.0));
//    model = alTogether * translate;
//    //drawCylindricalTree(CylinderGreen, CylinderGrey, lightingShader, model);
//
//    translate = glm::translate(identityMatrix, glm::vec3(-3.5, 0.0, 24.0));
//    model = alTogether *  translate;
//    //drawCylindricalTree(CylinderGreen, CylinderGrey, lightingShader, model);
//
//    translate = glm::translate(identityMatrix, glm::vec3(-3.5, 0.0, 34.0));
//    model = alTogether *  translate;
//    //drawCylindricalTree(CylinderGreen, CylinderGrey, lightingShader, model);
//
//    translate = glm::translate(identityMatrix, glm::vec3(-3.5, 0.0, 44.0));
//    model = alTogether *  translate;
//    //drawCylindricalTree(CylinderGreen, CylinderGrey, lightingShader, model);
//
//    translate = glm::translate(identityMatrix, glm::vec3(-3.5, 0.0, 54.0));
//    model = alTogether *  translate;
//    //drawCylindricalTree(CylinderGreen, CylinderGrey, lightingShader, model);
//
//    translate = glm::translate(identityMatrix, glm::vec3(-3.5, 0.0, 80.0));
//    model = alTogether * translate;
//    drawCylindricalTree(CylinderGreen, CylinderGrey, lightingShader, model);
//
//    translate = glm::translate(identityMatrix, glm::vec3(-3.5, 0.0, 90.0));
//    model = alTogether * translate;
//    drawCylindricalTree(CylinderGreen, CylinderGrey, lightingShader, model);
//    
//    translate = glm::translate(identityMatrix, glm::vec3(-3.5, 0.0, 100.0));
//    model = alTogether * translate;
//    drawCylindricalTree(CylinderGreen, CylinderGrey, lightingShader, model);
//
//    translate = glm::translate(identityMatrix, glm::vec3(-3.5, 0.0, 110.0));
//    model = alTogether * translate;
//    drawCylindricalTree(CylinderGreen, CylinderGrey, lightingShader, model);
//
//    translate = glm::translate(identityMatrix, glm::vec3(-3.5, 0.0, 120.0));
//    model = alTogether * translate;
//    drawCylindricalTree(CylinderGreen, CylinderGrey, lightingShader, model);
//
//    translate = glm::translate(identityMatrix, glm::vec3(-3.5, 0.0, 130.0));
//    model = alTogether * translate;
//    drawCylindricalTree(CylinderGreen, CylinderGrey, lightingShader, model);
//
//
//
//
//    translate = glm::translate(identityMatrix, glm::vec3(3.5, 0.0, 4.0));
//    model = alTogether *  translate;
//    drawCylindricalTree(CylinderGreen, CylinderGrey, lightingShader, model);
//
//    translate = glm::translate(identityMatrix, glm::vec3(3.5, 0.0, 14.0));
//    model = alTogether *  translate;
//    drawCylindricalTree(CylinderGreen, CylinderGrey, lightingShader, model);
//
//    translate = glm::translate(identityMatrix, glm::vec3(3.5, 0.0, 24.0));
//    model = alTogether *  translate;
//    drawCylindricalTree(CylinderGreen, CylinderGrey, lightingShader, model);
//
//    translate = glm::translate(identityMatrix, glm::vec3(3.5, 0.0, 34.0));
//    model = alTogether *  translate;
//    drawCylindricalTree(CylinderGreen, CylinderGrey, lightingShader, model);
//
//    translate = glm::translate(identityMatrix, glm::vec3(3.5, 0.0, 44.0));
//    model = alTogether *  translate;
//    drawCylindricalTree(CylinderGreen, CylinderGrey, lightingShader, model);
//
//    translate = glm::translate(identityMatrix, glm::vec3(3.5, 0.0, 54.0));
//    model = alTogether *  translate;
//    drawCylindricalTree(CylinderGreen, CylinderGrey, lightingShader, model);
//
//    translate = glm::translate(identityMatrix, glm::vec3(3.5, 0.0, 80.0));
//    model = alTogether * translate;
//    drawCylindricalTree(CylinderGreen, CylinderGrey, lightingShader, model);
//
//    translate = glm::translate(identityMatrix, glm::vec3(3.5, 0.0, 90.0));
//    model = alTogether * translate;
//    drawCylindricalTree(CylinderGreen, CylinderGrey, lightingShader, model);
//
//    translate = glm::translate(identityMatrix, glm::vec3(3.5, 0.0, 100.0));
//    model = alTogether * translate;
//    drawCylindricalTree(CylinderGreen, CylinderGrey, lightingShader, model);
//
//    translate = glm::translate(identityMatrix, glm::vec3(3.5, 0.0, 110.0));
//    model = alTogether * translate;
//    drawCylindricalTree(CylinderGreen, CylinderGrey, lightingShader, model);
//
//    translate = glm::translate(identityMatrix, glm::vec3(3.5, 0.0, 120.0));
//    model = alTogether * translate;
//    drawCylindricalTree(CylinderGreen, CylinderGrey, lightingShader, model);
//
//    translate = glm::translate(identityMatrix, glm::vec3(3.5, 0.0, 130.0));
//    model = alTogether * translate;
//    drawCylindricalTree(CylinderGreen, CylinderGrey, lightingShader, model);
//
//
//
//
//
//
//    translate = glm::translate(identityMatrix, glm::vec3(-50.0, 0.0, 63.0));
//    model = alTogether * translate;
//    drawCylindricalTree(CylinderGreen, CylinderGrey, lightingShader, model);
//
//    translate = glm::translate(identityMatrix, glm::vec3(-40.0, 0.0, 63.0));
//    model = alTogether * translate;
//    drawCylindricalTree(CylinderGreen, CylinderGrey, lightingShader, model);
//
//    translate = glm::translate(identityMatrix, glm::vec3(-30.0, 0.0, 63.0));
//    model = alTogether * translate;
//    drawCylindricalTree(CylinderGreen, CylinderGrey, lightingShader, model);
//
//    translate = glm::translate(identityMatrix, glm::vec3(-20.0, 0.0, 63.0));
//    model = alTogether * translate;
//    drawCylindricalTree(CylinderGreen, CylinderGrey, lightingShader, model);
//
//    translate = glm::translate(identityMatrix, glm::vec3(-12.0, 0.0, 63.0));
//    model = alTogether * translate;
//    drawCylindricalTree(CylinderGreen, CylinderGrey, lightingShader, model);
//
//    translate = glm::translate(identityMatrix, glm::vec3(50.0, 0.0, 63.0));
//    model = alTogether * translate;
//    drawCylindricalTree(CylinderGreen, CylinderGrey, lightingShader, model);
//
//    translate = glm::translate(identityMatrix, glm::vec3(40.0, 0.0, 63.0));
//    model = alTogether * translate;
//    drawCylindricalTree(CylinderGreen, CylinderGrey, lightingShader, model);
//
//    translate = glm::translate(identityMatrix, glm::vec3(30.0, 0.0, 63.0));
//    model = alTogether * translate;
//    drawCylindricalTree(CylinderGreen, CylinderGrey, lightingShader, model);
//
//    translate = glm::translate(identityMatrix, glm::vec3(20.0, 0.0, 63.0));
//    model = alTogether * translate;
//    drawCylindricalTree(CylinderGreen, CylinderGrey, lightingShader, model);
//
//    translate = glm::translate(identityMatrix, glm::vec3(12.0, 0.0, 63.0));
//    model = alTogether * translate;
//    drawCylindricalTree(CylinderGreen, CylinderGrey, lightingShader, model);
//
//
//
//
//    translate = glm::translate(identityMatrix, glm::vec3(-50.0, 0.0, 70.0));
//    model = alTogether * translate;
//    drawCylindricalTree(CylinderGreen, CylinderGrey, lightingShader, model);
//
//    translate = glm::translate(identityMatrix, glm::vec3(-40.0, 0.0, 70.0));
//    model = alTogether * translate;
//    drawCylindricalTree(CylinderGreen, CylinderGrey, lightingShader, model);
//
//    translate = glm::translate(identityMatrix, glm::vec3(-30.0, 0.0, 70.0));
//    model = alTogether * translate;
//    drawCylindricalTree(CylinderGreen, CylinderGrey, lightingShader, model);
//
//    translate = glm::translate(identityMatrix, glm::vec3(-20.0, 0.0, 70.0));
//    model = alTogether * translate;
//    drawCylindricalTree(CylinderGreen, CylinderGrey, lightingShader, model);
//
//    translate = glm::translate(identityMatrix, glm::vec3(-12.0, 0.0, 70.0));
//    model = alTogether * translate;
//    drawCylindricalTree(CylinderGreen, CylinderGrey, lightingShader, model);
//
//    translate = glm::translate(identityMatrix, glm::vec3(50.0, 0.0, 70.0));
//    model = alTogether * translate;
//    drawCylindricalTree(CylinderGreen, CylinderGrey, lightingShader, model);
//
//    translate = glm::translate(identityMatrix, glm::vec3(40.0, 0.0, 70.0));
//    model = alTogether * translate;
//    drawCylindricalTree(CylinderGreen, CylinderGrey, lightingShader, model);
//
//    translate = glm::translate(identityMatrix, glm::vec3(30.0, 0.0, 70.0));
//    model = alTogether * translate;
//    drawCylindricalTree(CylinderGreen, CylinderGrey, lightingShader, model);
//
//    translate = glm::translate(identityMatrix, glm::vec3(20.0, 0.0, 70.0));
//    model = alTogether * translate;
//    drawCylindricalTree(CylinderGreen, CylinderGrey, lightingShader, model);
//
//    translate = glm::translate(identityMatrix, glm::vec3(12.0, 0.0, 70.0));
//    model = alTogether * translate;
//    drawCylindricalTree(CylinderGreen, CylinderGrey, lightingShader, model);
//
//
//
//
//
//
//
//    scale = glm::scale(identityMatrix, glm::vec3(2.0, 2.5, 2.0));
//
//    //right side
//    translate = glm::translate(identityMatrix, glm::vec3(19.0, 0.0, 12.0));
//    model = alTogether * translate * scale;
//    drawNormalTree(NormalTree, CylinderGrey, lightingShader, model);
//
//    translate = glm::translate(identityMatrix, glm::vec3(45.0, 0.0, 12.0));
//    model = alTogether * translate * scale;
//    drawNormalTree(NormalTree, CylinderGrey, lightingShader, model);
//
//    translate = glm::translate(identityMatrix, glm::vec3(19.0, 0.0, 45.0));
//    model = alTogether * translate * scale;
//    drawNormalTree(NormalTree, CylinderGrey, lightingShader, model);
//
//    translate = glm::translate(identityMatrix, glm::vec3(45.0, 0.0, 45.0));
//    model = alTogether * translate * scale;
//    drawNormalTree(NormalTree, CylinderGrey, lightingShader, model);
//
//    translate = glm::translate(identityMatrix, glm::vec3(19.0, 0.0, 90.0));
//    model = alTogether * translate * scale;
//    drawNormalTree(NormalTree, CylinderGrey, lightingShader, model);
//
//    translate = glm::translate(identityMatrix, glm::vec3(45.0, 0.0, 90.0));
//    model = alTogether * translate * scale;
//    drawNormalTree(NormalTree, CylinderGrey, lightingShader, model);
//
//    translate = glm::translate(identityMatrix, glm::vec3(19.0, 0.0, 120.0));
//    model = alTogether * translate * scale;
//    drawNormalTree(NormalTree, CylinderGrey, lightingShader, model);
//
//    translate = glm::translate(identityMatrix, glm::vec3(45.0, 0.0, 120.0));
//    model = alTogether * translate * scale;
//    drawNormalTree(NormalTree, CylinderGrey, lightingShader, model);
//
//
//
//
//
//    //left side
//    translate = glm::translate(identityMatrix, glm::vec3(-19.0, 0.0, 12.0));
//    model = alTogether * translate * scale;
//    drawNormalTree(NormalTree, CylinderGrey, lightingShader, model);
//
//    translate = glm::translate(identityMatrix, glm::vec3(-45.0, 0.0, 12.0));
//    model = alTogether * translate * scale;
//    drawNormalTree(NormalTree, CylinderGrey, lightingShader, model);
//
//    translate = glm::translate(identityMatrix, glm::vec3(-19.0, 0.0, 45.0));
//    model = alTogether * translate * scale;
//    drawNormalTree(NormalTree, CylinderGrey, lightingShader, model);
//
//    translate = glm::translate(identityMatrix, glm::vec3(-45.0, 0.0, 45.0));
//    model = alTogether * translate * scale;
//    drawNormalTree(NormalTree, CylinderGrey, lightingShader, model);
//
//    translate = glm::translate(identityMatrix, glm::vec3(-19.0, 0.0, 90.0));
//    model = alTogether * translate * scale;
//    drawNormalTree(NormalTree, CylinderGrey, lightingShader, model);
//
//    translate = glm::translate(identityMatrix, glm::vec3(-45.0, 0.0, 90.0));
//    model = alTogether * translate * scale;
//    drawNormalTree(NormalTree, CylinderGrey, lightingShader, model);
//
//    translate = glm::translate(identityMatrix, glm::vec3(-19.0, 0.0, 120.0));
//    model = alTogether * translate * scale;
//    drawNormalTree(NormalTree, CylinderGrey, lightingShader, model);
//
//    translate = glm::translate(identityMatrix, glm::vec3(-45.0, 0.0, 120.0));
//    model = alTogether * translate * scale;
//    drawNormalTree(NormalTree, CylinderGrey, lightingShader, model);
//
//}

void drawNarrowMinar(unsigned int& cubeVAO, BezierCurve& cylinder, BezierCurve& semiDome, Octagon& base, Octagon& oct, Shader& lightingShader, glm::mat4 alTogether)
{
    glm::mat4 model = glm::mat4(1.0f);
    glm::mat4 translate = glm::mat4(1.0f);
    glm::mat4 identityMatrix = glm::mat4(1.0f);
    glm::mat4 scale = glm::mat4(1.0f);
    glm::mat4 scale2 = glm::mat4(1.0f);
    glm::mat4 rotate = glm::mat4(1.0f);


    scale2 = glm::scale(identityMatrix, glm::vec3(0.15, 0.8, 0.15));


    scale = glm::scale(identityMatrix, glm::vec3(2.0, 4.0, 2.0));
    translate = glm::translate(identityMatrix, glm::vec3(0.0, -0.5, 0.0));
    model = alTogether * scale2 * scale * translate;
    oct.drawOctagonWithMaterialisticProperty(lightingShader, model);

    scale = glm::scale(identityMatrix, glm::vec3(2.5, 9.0, 2.5));
    translate = glm::translate(identityMatrix, glm::vec3(2.4, 2.0, 2.4));
    model = alTogether * scale2 * translate * scale;
    cylinder.drawBezierCurve(lightingShader, model);

    scale = glm::scale(identityMatrix, glm::vec3(1.9, 0.3, 1.9));
    translate = glm::translate(identityMatrix, glm::vec3(0.1, 7.0, 0.1));
    model = alTogether * scale2 * translate * scale;
    oct.drawOctagonWithMaterialisticProperty(lightingShader, model);

    scale = glm::scale(identityMatrix, glm::vec3(1.7, 0.3, 1.7));
    translate = glm::translate(identityMatrix, glm::vec3(0.3, 13.0, 0.3));
    model = alTogether * scale2 * translate * scale;
    oct.drawOctagonWithMaterialisticProperty(lightingShader, model);

    scale2 = glm::scale(identityMatrix, glm::vec3(0.15, 0.15, 0.15));

    translate = glm::translate(identityMatrix, glm::vec3(0.6, 101.5, 0.6));
    model = alTogether * scale2 * translate;
    drawSemiDome(cubeVAO, semiDome, oct, oct, lightingShader, model);

}

void drawNarrowMinarTogether(unsigned int& cubeVAO, BezierCurve& minar, BezierCurve& semiDome, Octagon& oct3, Octagon& oct2, Shader& lightingShader, glm::mat4 next)
{

    glm::mat4 model = glm::mat4(1.0f);
    glm::mat4 translate = glm::mat4(1.0f);
    glm::mat4 identityMatrix = glm::mat4(1.0f);
    glm::mat4 scale = glm::mat4(1.0f);
    glm::mat4 scale2 = glm::mat4(1.0f);
    glm::mat4 rotate = glm::mat4(1.0f);

    //narrow minar shape
    translate = glm::translate(identityMatrix, glm::vec3(-5.6, 0.0, -6.1));
    model = next * translate;
    drawNarrowMinar(cubeVAO, minar, semiDome, oct3, oct2, lightingShader, model);


    translate = glm::translate(identityMatrix, glm::vec3(4.9, 0.0, -6.1));
    model = next * translate;
    drawNarrowMinar(cubeVAO, minar, semiDome, oct3, oct2, lightingShader, model);


    translate = glm::translate(identityMatrix, glm::vec3(-11.0, 0.0, -6.5));
    model = next * translate;
    drawNarrowMinar(cubeVAO, minar, semiDome, oct3, oct2, lightingShader, model);


    translate = glm::translate(identityMatrix, glm::vec3(10.5, 0.0, -6.5));
    model = next * translate;
    drawNarrowMinar(cubeVAO, minar, semiDome, oct3, oct2, lightingShader, model);



    translate = glm::translate(identityMatrix, glm::vec3(-15.1, 0.0, -10.6));
    model = next * translate;
    drawNarrowMinar(cubeVAO, minar, semiDome, oct3, oct2, lightingShader, model);


    translate = glm::translate(identityMatrix, glm::vec3(14.6, 0.0, -10.6));
    model = next * translate;
    drawNarrowMinar(cubeVAO, minar, semiDome, oct3, oct2, lightingShader, model);


    translate = glm::translate(identityMatrix, glm::vec3(-15.6, 0.0, -16.1));
    model = next * translate;
    drawNarrowMinar(cubeVAO, minar, semiDome, oct3, oct2, lightingShader, model);


    translate = glm::translate(identityMatrix, glm::vec3(14.9, 0.0, -16.1));
    model = next * translate;
    drawNarrowMinar(cubeVAO, minar, semiDome, oct3, oct2, lightingShader, model);


    translate = glm::translate(identityMatrix, glm::vec3(-15.6, 0.0, -26.6));
    model = next * translate;
    drawNarrowMinar(cubeVAO, minar, semiDome, oct3, oct2, lightingShader, model);


    translate = glm::translate(identityMatrix, glm::vec3(14.9, 0.0, -26.6));
    model = next * translate;
    drawNarrowMinar(cubeVAO, minar, semiDome, oct3, oct2, lightingShader, model);


    translate = glm::translate(identityMatrix, glm::vec3(-5.6, 0.0, -36.6));
    model = next * translate;
    drawNarrowMinar(cubeVAO, minar, semiDome, oct3, oct2, lightingShader, model);


    translate = glm::translate(identityMatrix, glm::vec3(4.9, 0.0, -36.6));
    model = next * translate;
    drawNarrowMinar(cubeVAO, minar, semiDome, oct3, oct2, lightingShader, model);


    translate = glm::translate(identityMatrix, glm::vec3(-11.0, 0.0, -36.1));
    model = next * translate;
    drawNarrowMinar(cubeVAO, minar, semiDome, oct3, oct2, lightingShader, model);


    translate = glm::translate(identityMatrix, glm::vec3(10.5, 0.0, -36.1));
    model = next * translate;
    drawNarrowMinar(cubeVAO, minar, semiDome, oct3, oct2, lightingShader, model);


    translate = glm::translate(identityMatrix, glm::vec3(-15.1, 0.0, -32.2));
    model = next * translate;
    drawNarrowMinar(cubeVAO, minar, semiDome, oct3, oct2, lightingShader, model);


    translate = glm::translate(identityMatrix, glm::vec3(14.6, 0.0, -32.2));
    model = next * translate;
    drawNarrowMinar(cubeVAO, minar, semiDome, oct3, oct2, lightingShader, model);


}

void drawMinar(
    unsigned int& cubeVAO,
    BezierCurve& cylinder,
    BezierCurve& semiDome,
    Octagon& base,
    Octagon& oct,
    Shader& lightingShader,
    glm::mat4 alTogether)
{



    /*float baseHeight = 4.2;
    float width = 6.1f;
    float length = 1.5f;*/

    string diffuseMapPath = "bigben.jpg";
    string specularMapPath = "bigben.jpg";


    unsigned int diffMap = loadTexture(diffuseMapPath.c_str(), GL_REPEAT, GL_REPEAT, GL_LINEAR_MIPMAP_LINEAR, GL_LINEAR);
    unsigned int specMap = loadTexture(specularMapPath.c_str(), GL_REPEAT, GL_REPEAT, GL_LINEAR_MIPMAP_LINEAR, GL_LINEAR);
    //std::cout << "Diffuse Map: " << diffMap << ", Specular Map: " << specMap << std::endl;

    Cube cube = Cube(diffMap, specMap, 32.0f, 0.0f, 0.0f, 1.0f, 15.0f);

    glm::mat4 model = glm::mat4(1.0f);
    glm::mat4 translate = glm::mat4(1.0f);
    glm::mat4 identityMatrix = glm::mat4(1.0f);
    glm::mat4 scale = glm::mat4(1.0f);
    //glm::mat4 mirror = glm::mat4(1.0f);

    // Base (Wide Octagon)
    scale = glm::scale(identityMatrix, glm::vec3(4.0f, 1.0f, 4.0f)); // Wide and flat base
    translate = glm::translate(identityMatrix, glm::vec3(0.1f, 0.5f, 0.0f)); // Slight lift for ground alignment
    model = alTogether * translate * scale;
    oct.drawOctagonWithMaterialisticProperty(lightingShader, model);

    // Tower (Cylinder Approximation)
    scale = glm::scale(identityMatrix, glm::vec3(6.0f, 26.30f, 2.0f)); // Tall and slender
    translate = glm::translate(identityMatrix, glm::vec3(2.0f, 0.5f, 6.0f)); // Positioned directly on top of the base
    model = alTogether * translate * scale;
    drawCube(cubeVAO, lightingShader, model, 1.0f, 1.0f, 1.0f);

    // Clock Face (Thin Octagon)
    scale = glm::scale(identityMatrix, glm::vec3(3.0f, 0.3f, 3.0f)); // Thin and wide
    translate = glm::translate(identityMatrix, glm::vec3(1.5f, 26.90f, 0.0f)); // Positioned directly on top of the tower
    model = alTogether * translate * scale;
    oct.drawOctagonWithMaterialisticProperty(lightingShader, model);

    // Upper Section (Narrower Octagon)
    scale = glm::scale(identityMatrix, glm::vec3(6.1f, 4.2f, 1.5f)); // Narrow and tall
    translate = glm::translate(identityMatrix, glm::vec3(2.3f, 27.0f, 0.0f)); // Positioned directly on top of the clock face
    model = alTogether * translate * scale;
    //drawCube(cubeVAO, lightingShader, model, 1.0f, 1.0f, 1.0f);
    cube.drawCubeWithTexture(lightingShader, model);








    // Spire (Semi-Dome)
    scale = glm::scale(identityMatrix, glm::vec3(1.6f, 2.0f, 1.0f)); // Small pointed spire
    translate = glm::translate(identityMatrix, glm::vec3(2.5f, 30.0f, 0.0f)); // Positioned directly on top of the upper section
    model = alTogether * translate * scale;
    drawSemiDome(cubeVAO, semiDome, oct, oct, lightingShader, model);
}




void drawCylindricalTree(BezierCurve& CylinderGreen, BezierCurve& CylinderGrey, Shader& lightingShader, glm::mat4 alTogether)
{
    glm::mat4 model = glm::mat4(1.0f);
    glm::mat4 translate = glm::mat4(1.0f);
    glm::mat4 identityMatrix = glm::mat4(1.0f);
    glm::mat4 scale = glm::mat4(1.0f);
    glm::mat4 rotate = glm::mat4(1.0f);



    scale = glm::scale(identityMatrix, glm::vec3(1.0, 3.0, 1.0));
    translate = glm::translate(identityMatrix, glm::vec3(0.0, 1.5, 0.0));
    model = alTogether * translate * scale;
    CylinderGreen.drawBezierCurve(lightingShader, model);

    scale = glm::scale(identityMatrix, glm::vec3(0.5, 1.0, 0.5));
    model = alTogether * scale;
    CylinderGrey.drawBezierCurve(lightingShader, model);

}

void drawNormalTree(BezierCurve& NormalTree, BezierCurve& CylinderGrey, Shader& lightingShader, glm::mat4 alTogether)
{
    glm::mat4 model = glm::mat4(1.0f);
    glm::mat4 translate = glm::mat4(1.0f);
    glm::mat4 identityMatrix = glm::mat4(1.0f);
    glm::mat4 scale = glm::mat4(1.0f);
    glm::mat4 rotate = glm::mat4(1.0f);



    scale = glm::scale(identityMatrix, glm::vec3(2.0, 2.0, 2.0));
    translate = glm::translate(identityMatrix, glm::vec3(0.0, 4.0, 0.0));
    model = alTogether * translate * scale;
    NormalTree.drawBezierCurve(lightingShader, model);

    scale = glm::scale(identityMatrix, glm::vec3(1.0, 4.0, 1.0));
    model = alTogether * scale;
    CylinderGrey.drawBezierCurve(lightingShader, model);

}

void drawDome(unsigned int& cubeVAO, BezierCurve& Dome, Octagon& base, Shader& lightingShader, glm::mat4 alTogether)
{
    glm::mat4 model = glm::mat4(1.0f);
    glm::mat4 translate = glm::mat4(1.0f);
    glm::mat4 identityMatrix = glm::mat4(1.0f);
    glm::mat4 scale = glm::mat4(1.0f);
    glm::mat4 rotate = glm::mat4(1.0f);



    scale = glm::scale(identityMatrix, glm::vec3(4.0, 5.0, 4.0));
    translate = glm::translate(identityMatrix, glm::vec3(3.5, 1.0, 3.5));
    model = alTogether * translate * scale;
    Dome.drawBezierCurve(lightingShader, model);

    scale = glm::scale(identityMatrix, glm::vec3(3.0, 3.0, 3.0));
    model = alTogether * scale;
    base.drawOctagonWithMaterialisticProperty(lightingShader, model);

}

void drawSemiDome(unsigned int& cubeVAO, BezierCurve& spire, Octagon& base, Octagon& mid, Shader& lightingShader, glm::mat4 alTogether) {
    glm::mat4 model = glm::mat4(1.0f);
    glm::mat4 translate = glm::mat4(1.0f);
    glm::mat4 identityMatrix = glm::mat4(1.0f);
    glm::mat4 scale = glm::mat4(1.0f);
    glm::mat4 rotate = glm::mat4(1.0f);

    // Scale and translate the spire (narrow top)
    scale = glm::scale(identityMatrix, glm::vec3(2.2, 4.5, 0.5));  // Smaller width for the spire
    translate = glm::translate(identityMatrix, glm::vec3(1.8, -2.0, 1.8));  // Move the spire to the top
    model = alTogether * translate * scale;
    spire.drawBezierCurve(lightingShader, model);

    // Scale and translate the base (larger octagon)
    scale = glm::scale(identityMatrix, glm::vec3(2.0, 0.5, 2.0));  // Broader base
    translate = glm::translate(identityMatrix, glm::vec3(-0.8, 0.5, 1.8));  // Position the base
    model = alTogether * translate * scale;
    base.drawOctagonWithMaterialisticProperty(lightingShader, model);

    // Scale and translate the middle section (Mid-tier)
    scale = glm::scale(identityMatrix, glm::vec3(1.8, 0.3, 1.8));  // Slightly thinner middle section
    translate = glm::translate(identityMatrix, glm::vec3(-0.5, 2.5, 0.0));  // Positioned in the middle of the tower
    model = alTogether * translate * scale;
    mid.drawOctagonWithMaterialisticProperty(lightingShader, model);

    // Adding cube shapes for detailing at the base (like columns or smaller structures)
    scale = glm::scale(identityMatrix, glm::vec3(0.3, 1.5, 0.3));  // Small supporting cubes
    translate = glm::translate(identityMatrix, glm::vec3(1.1, 1.0, 0.1));  // Positions for detailing
    model = alTogether * translate * scale;
    drawCube(cubeVAO, lightingShader, model, 0.9, 0.9, 0.9);

    translate = glm::translate(identityMatrix, glm::vec3(2.2, 1.0, 0.1));
    model = alTogether * translate * scale;
    drawCube(cubeVAO, lightingShader, model, 0.9, 0.9, 0.9);

    translate = glm::translate(identityMatrix, glm::vec3(3.2, 1.0, 1.1));
    model = alTogether * translate * scale;
    drawCube(cubeVAO, lightingShader, model, 0.9, 0.9, 0.9);

    translate = glm::translate(identityMatrix, glm::vec3(3.2, 1.0, 2.2));
    model = alTogether * translate * scale;
    drawCube(cubeVAO, lightingShader, model, 0.9, 0.9, 0.9);

    translate = glm::translate(identityMatrix, glm::vec3(2.2, 1.0, 3.2));
    model = alTogether * translate * scale;
    drawCube(cubeVAO, lightingShader, model, 0.9, 0.9, 0.9);

    translate = glm::translate(identityMatrix, glm::vec3(1.1, 1.0, 3.2));
    model = alTogether * translate * scale;
    drawCube(cubeVAO, lightingShader, model, 0.9, 0.9, 0.9);

    translate = glm::translate(identityMatrix, glm::vec3(0.1, 1.0, 1.1));
    model = alTogether * translate * scale;
    drawCube(cubeVAO, lightingShader, model, 0.9, 0.9, 0.9);

    translate = glm::translate(identityMatrix, glm::vec3(0.1, 1.0, 2.2));
    model = alTogether * translate * scale;
    drawCube(cubeVAO, lightingShader, model, 0.9, 0.9, 0.9);
}


void drawCube(unsigned int& cubeVAO, Shader& lightingShader, glm::mat4 model = glm::mat4(1.0f), float r = 1.0f, float g = 1.0f, float b = 1.0f)
{
    lightingShader.use();

    lightingShader.setVec3("material.ambient", glm::vec3(r, g, b));
    lightingShader.setVec3("material.diffuse", glm::vec3(r, g, b));
    lightingShader.setVec3("material.specular", glm::vec3(0.5f, 0.5f, 0.5f));
    lightingShader.setFloat("material.shininess", 32.0f);

    lightingShader.setMat4("model", model);

    glBindVertexArray(cubeVAO);
    glDrawElements(GL_TRIANGLES, 36, GL_UNSIGNED_INT, 0);
}

void drawTajmahal(unsigned int& cubeVAO, Shader& lightingShader, glm::mat4 alTogether)
{
    glm::mat4 model = glm::mat4(1.0f);
    glm::mat4 translate = glm::mat4(1.0f);
    glm::mat4 translate2 = glm::mat4(1.0f);
    glm::mat4 identityMatrix = glm::mat4(1.0f);
    glm::mat4 scale = glm::mat4(1.0f);
    glm::mat4 rotate = glm::mat4(1.0f);

    model = alTogether * identityMatrix;
    drawMain(cubeVAO, lightingShader, model);

    rotate = glm::rotate(identityMatrix, glm::radians(-90.0f), glm::vec3(0.0f, 1.0f, 0.0f));
    translate = glm::translate(identityMatrix, glm::vec3(-21.0, 0.0, -21.0));
    model = alTogether * translate * rotate;
    drawMain(cubeVAO, lightingShader, model);

    rotate = glm::rotate(identityMatrix, glm::radians(-180.0f), glm::vec3(0.0f, 1.0f, 0.0f));
    translate = glm::translate(identityMatrix, glm::vec3(0.0, 0.0, -42.0));
    model = alTogether * translate * rotate;
    drawMain(cubeVAO, lightingShader, model);

    rotate = glm::rotate(identityMatrix, glm::radians(-270.0f), glm::vec3(0.0f, 1.0f, 0.0f));
    translate = glm::translate(identityMatrix, glm::vec3(21.0, 0.0, -21.0));
    model = alTogether * translate * rotate;
    drawMain(cubeVAO, lightingShader, model);

    model = alTogether * identityMatrix;
    drawRoof(cubeVAO, lightingShader, model);

    drawBase(cubeVAO, lightingShader, model);
}

void drawFloor(unsigned int& cubeVAO, Shader& lightingShader, glm::mat4 alTogether) {
    float baseHeight = 0.2;
    float width = 113;
    float length = 55;

    glm::mat4 model = glm::mat4(1.0f);
    glm::mat4 translate = glm::mat4(1.0f);
    glm::mat4 identityMatrix = glm::mat4(1.0f);

    glm::mat4 scale = glm::mat4(1.0f);
    glm::mat4 mirror = glm::mat4(1.0f);
    scale = glm::scale(model, glm::vec3(width, baseHeight, length));
    translate = glm::translate(model, glm::vec3(-0.5, 0.0, -1.0));
    model = alTogether * scale * translate;
    drawCube(cubeVAO, lightingShader, model, 0.9, 0.3, 0.3);


    //left area pond
    scale = glm::scale(identityMatrix, glm::vec3(20.0, 1.0, 2.0));
    translate = glm::translate(identityMatrix, glm::vec3(-48.0, 0.0, -17.0));
    model = alTogether * translate * scale;
    drawCube(cubeVAO, lightingShader, model, 0.9, 0.1, 0.1);

    scale = glm::scale(identityMatrix, glm::vec3(20.0, 1.0, 2.0));
    translate = glm::translate(identityMatrix, glm::vec3(-48.0, 0.0, -37.0));
    model = alTogether * translate * scale;
    drawCube(cubeVAO, lightingShader, model, 0.9, 0.1, 0.1);

    scale = glm::scale(identityMatrix, glm::vec3(2.0, 1.0, 20.0));
    translate = glm::translate(identityMatrix, glm::vec3(-30.0, 0.0, -37.0));
    model = alTogether * translate * scale;
    drawCube(cubeVAO, lightingShader, model, 0.9, 0.1, 0.1);

    scale = glm::scale(identityMatrix, glm::vec3(2.0, 1.0, 20.0));
    translate = glm::translate(identityMatrix, glm::vec3(-48.0, 0.0, -37.0));
    model = alTogether * translate * scale;
    drawCube(cubeVAO, lightingShader, model, 0.9, 0.1, 0.1);

    //water
    scale = glm::scale(identityMatrix, glm::vec3(18.0, 0.6, 18.0));
    translate = glm::translate(identityMatrix, glm::vec3(-48.0, 0.0, -35.0));
    model = alTogether * translate * scale;
    drawCube(cubeVAO, lightingShader, model, 0.0, 0.7, 0.7);



    //right area pond
    scale = glm::scale(identityMatrix, glm::vec3(20.0, 1.0, 2.0));
    translate = glm::translate(identityMatrix, glm::vec3(28.0, 0.0, -17.0));
    model = alTogether * translate * scale;
    drawCube(cubeVAO, lightingShader, model, 0.9, 0.1, 0.1);

    scale = glm::scale(identityMatrix, glm::vec3(20.0, 1.0, 2.0));
    translate = glm::translate(identityMatrix, glm::vec3(28.0, 0.0, -37.0));
    model = alTogether * translate * scale;
    drawCube(cubeVAO, lightingShader, model, 0.9, 0.1, 0.1);

    scale = glm::scale(identityMatrix, glm::vec3(2.0, 1.0, 20.0));
    translate = glm::translate(identityMatrix, glm::vec3(28.0, 0.0, -37.0));
    model = alTogether * translate * scale;
    drawCube(cubeVAO, lightingShader, model, 0.9, 0.1, 0.1);

    scale = glm::scale(identityMatrix, glm::vec3(2.0, 1.0, 20.0));
    translate = glm::translate(identityMatrix, glm::vec3(46.0, 0.0, -37.0));
    model = alTogether * translate * scale;
    drawCube(cubeVAO, lightingShader, model, 0.9, 0.1, 0.1);

    //water
    scale = glm::scale(identityMatrix, glm::vec3(18.0, 0.6, 18.0));
    translate = glm::translate(identityMatrix, glm::vec3(30.0, 0.0, -35.0));
    model = alTogether * translate * scale;
    drawCube(cubeVAO, lightingShader, model, 0.0, 0.7, 0.7);

}

void drawRoof(unsigned int& cubeVAO, Shader& lightingShader, glm::mat4 alTogether) {
    float height = 0.5;
    float width = 21;
    float length = 29;


    float r = 0.8f;
    float g = 0.8f;
    float b = 0.8f;

    float rp = 1.0f;
    float gp = 1.0f;
    float bp = 1.0f;

    glm::mat4 model = glm::mat4(1.0f);
    glm::mat4 translate = glm::mat4(1.0f);
    glm::mat4 translate2 = glm::mat4(1.0f);
    glm::mat4 identityMatrix = glm::mat4(1.0f);
    glm::mat4 scale = glm::mat4(1.0f);
    glm::mat4 rotate = glm::mat4(1.0f);

    //mid
    scale = glm::scale(identityMatrix, glm::vec3(width, height, length));
    translate = glm::translate(identityMatrix, glm::vec3(-0.5, 0.0, 0.0));
    translate2 = glm::translate(identityMatrix, glm::vec3(0.0, 11.0, -35.5));
    model = alTogether * translate2 * scale * translate;
    drawCube(cubeVAO, lightingShader, model, 0.7, 0.7, 0.7);

    //l
    scale = glm::scale(identityMatrix, glm::vec3(5.0, height, 22));
    translate = glm::translate(identityMatrix, glm::vec3(-0.5, 0.0, 0.0));
    translate2 = glm::translate(identityMatrix, glm::vec3(-12.0, 11.0, -32.5));
    model = alTogether * translate2 * scale * translate;
    drawCube(cubeVAO, lightingShader, model, 0.7, 0.7, 0.7);

    //r
    scale = glm::scale(identityMatrix, glm::vec3(5.0, height, 22));
    translate = glm::translate(identityMatrix, glm::vec3(-0.5, 0.0, 0.0));
    translate2 = glm::translate(identityMatrix, glm::vec3(12.0, 11.0, -32.5));
    model = alTogether * translate2 * scale * translate;
    drawCube(cubeVAO, lightingShader, model, 0.7, 0.7, 0.7);

    scale = glm::scale(identityMatrix, glm::vec3(5.0, height, 20));
    translate = glm::translate(identityMatrix, glm::vec3(-0.5, 0.0, 0.0));
    translate2 = glm::translate(identityMatrix, glm::vec3(12.0, 11.0, -30.0));
    model = alTogether * translate2 * scale * translate;
    drawCube(cubeVAO, lightingShader, model, 0.7, 0.7, 0.7);

    scale = glm::scale(identityMatrix, glm::vec3(6, height, 36));
    rotate = glm::rotate(identityMatrix, glm::radians(-45.0f), glm::vec3(0.0f, 1.0f, 0.0f));
    translate = glm::translate(identityMatrix, glm::vec3(10.5, 11.0, -36.0));
    model = alTogether * translate * rotate * scale;
    drawCube(cubeVAO, lightingShader, model, 0.7, 0.7, 0.7);

    scale = glm::scale(identityMatrix, glm::vec3(6, height, 36));
    rotate = glm::rotate(identityMatrix, glm::radians(45.0f), glm::vec3(0.0f, 1.0f, 0.0f));
    translate = glm::translate(identityMatrix, glm::vec3(-14.5, 11.0, -32.0));
    model = alTogether * translate * rotate * scale;
    drawCube(cubeVAO, lightingShader, model, 0.7, 0.7, 0.7);

}

void drawEntrance(unsigned int& cubeVAO, Shader& lightingShader, glm::mat4 alTogether)
{
    float height = 9.0;
    float width = 0.5;
    float length = 4.0;


    float r = 0.8f;
    float g = 0.8f;
    float b = 0.8f;

    float rp = 1.0f;
    float gp = 1.0f;
    float bp = 0.8f;

    glm::mat4 model = glm::mat4(1.0f);
    glm::mat4 translate = glm::mat4(1.0f);
    glm::mat4 identityMatrix = glm::mat4(1.0f);
    glm::mat4 scale = glm::mat4(1.0f);
    glm::mat4 mirror = glm::mat4(1.0f);

    //entrance right side 1 ERS1
    scale = glm::scale(identityMatrix, glm::vec3(width, height, length));
    translate = glm::translate(identityMatrix, glm::vec3(3.0, 2.0, -10.0));
    model = alTogether * translate * scale;
    drawCube(cubeVAO, lightingShader, model, rp, gp, bp);

    //ELS1
    scale = glm::scale(identityMatrix, glm::vec3(width, height, length));
    translate = glm::translate(identityMatrix, glm::vec3(-3.5, 2.0, -10.0));
    model = alTogether * translate * scale;
    drawCube(cubeVAO, lightingShader, model, rp, gp, bp);

    //ETS1
    scale = glm::scale(identityMatrix, glm::vec3(7.0f, 0.5f, length));
    translate = glm::translate(identityMatrix, glm::vec3(-3.5, 11.0, -10.0));
    model = alTogether * translate * scale;
    drawCube(cubeVAO, lightingShader, model, rp, gp, bp);

    //bottom
    scale = glm::scale(identityMatrix, glm::vec3(7.0f, 0.5f, length));
    translate = glm::translate(identityMatrix, glm::vec3(-3.5, 1.5, -10.0));
    model = alTogether * translate * scale;
    drawCube(cubeVAO, lightingShader, model, rp, gp, bp);

    //back
    scale = glm::scale(identityMatrix, glm::vec3(7.0f, height, 0.5));
    translate = glm::translate(identityMatrix, glm::vec3(-3.5, 2.0, -10.0));
    model = alTogether * translate * scale;
    drawCube(cubeVAO, lightingShader, model, rp, gp, bp);
}

void drawSideFrame(unsigned int& cubeVAO, Shader& lightingShader, glm::mat4 alTogether)
{
    float height = 9.0;
    float width = 0.5;
    float length = 0.5;

    float r = 0.8f;
    float g = 0.8f;
    float b = 0.8f;

    float rp = 1.0f;
    float gp = 1.0f;
    float bp = 1.0f;

    glm::mat4 model = glm::mat4(1.0f);
    glm::mat4 translate = glm::mat4(1.0f);
    glm::mat4 identityMatrix = glm::mat4(1.0f);
    glm::mat4 scale = glm::mat4(1.0f);
    glm::mat4 mirror = glm::mat4(1.0f);

    //left window top
    scale = glm::scale(identityMatrix, glm::vec3(0.5f, 0.4f, 1.0f));
    translate = glm::translate(identityMatrix, glm::vec3(-7.75, 5.5, -0.5));
    model = alTogether * translate * scale;
    drawEntrance(cubeVAO, lightingShader, model);

    //left window bottom
    scale = glm::scale(identityMatrix, glm::vec3(0.5f, 0.4f, 1.0f));
    translate = glm::translate(identityMatrix, glm::vec3(-7.75, 1.0, -0.5));
    model = alTogether * translate * scale;
    drawEntrance(cubeVAO, lightingShader, model);

    //side right
    scale = glm::scale(identityMatrix, glm::vec3(1.0, 10.0, 0.5));
    translate = glm::translate(identityMatrix, glm::vec3(-6.0, 1.0, -6.6));
    model = alTogether * translate * scale;
    drawCube(cubeVAO, lightingShader, model, rp, gp, bp);

    //side left
    scale = glm::scale(identityMatrix, glm::vec3(1.0, 10.0, 0.5));
    translate = glm::translate(identityMatrix, glm::vec3(-10.5, 1.0, -6.6));
    model = alTogether * translate * scale;
    drawCube(cubeVAO, lightingShader, model, rp, gp, bp);

    //side middle
    scale = glm::scale(identityMatrix, glm::vec3(4.0, 0.8, 0.5));
    translate = glm::translate(identityMatrix, glm::vec3(-10.0, 5.5, -6.6));
    model = alTogether * translate * scale;
    drawCube(cubeVAO, lightingShader, model, rp, gp, bp);

    //side top
    scale = glm::scale(identityMatrix, glm::vec3(4.0, 0.8, 0.5));
    translate = glm::translate(identityMatrix, glm::vec3(-10.0, 10.1, -6.6));
    model = alTogether * translate * scale;
    drawCube(cubeVAO, lightingShader, model, rp, gp, bp);

    //border top
    scale = glm::scale(identityMatrix, glm::vec3(5.5, 1.0, 0.5));
    translate = glm::translate(identityMatrix, glm::vec3(-10.5, 10.9, -6.5));
    model = alTogether * translate * scale;
    drawCube(cubeVAO, lightingShader, model, r, g, b);

}

void drawDoorFrame(unsigned int& cubeVAO, Shader& lightingShader, glm::mat4 alTogether)
{
    float height = 9.0;
    float width = 0.5;
    float length = 1.0;

    float r = 0.8f;
    float g = 0.8f;
    float b = 0.8f;

    float rp = 1.0f;
    float gp = 1.0f;
    float bp = 1.0f;

    glm::mat4 model = glm::mat4(1.0f);
    glm::mat4 translate = glm::mat4(1.0f);
    glm::mat4 identityMatrix = glm::mat4(1.0f);
    glm::mat4 scale = glm::mat4(1.0f);
    glm::mat4 mirror = glm::mat4(1.0f);

    //ES1
    model = alTogether;
    drawEntrance(cubeVAO, lightingShader, model);

    //ERS2
    scale = glm::scale(identityMatrix, glm::vec3(1.0f, 9.5f, 0.9f));
    translate = glm::translate(identityMatrix, glm::vec3(3.5, 2.0, -6.6));
    model = alTogether * translate * scale;
    drawCube(cubeVAO, lightingShader, model, r, g, b);

    //ELS2
    scale = glm::scale(identityMatrix, glm::vec3(1.0f, 9.5f, 0.9f));
    translate = glm::translate(identityMatrix, glm::vec3(-4.5, 2.0, -6.6));
    model = alTogether * translate * scale;
    drawCube(cubeVAO, lightingShader, model, r, g, b);

    //ETS2
    scale = glm::scale(identityMatrix, glm::vec3(9.0f, 1.0f, 0.9f));
    translate = glm::translate(identityMatrix, glm::vec3(-4.5, 11.5, -6.6));
    model = alTogether * translate * scale;
    drawCube(cubeVAO, lightingShader, model, r, g, b);

    //ERS3
    scale = glm::scale(identityMatrix, glm::vec3(width, 10.5, length));
    translate = glm::translate(identityMatrix, glm::vec3(-5.0, 2.0, -6.5));
    model = alTogether * translate * scale;
    drawCube(cubeVAO, lightingShader, model, rp, gp, bp);

    //ELS3
    scale = glm::scale(identityMatrix, glm::vec3(width, 10.5, length));
    translate = glm::translate(identityMatrix, glm::vec3(4.5, 2.0, -6.5));
    model = alTogether * translate * scale;
    drawCube(cubeVAO, lightingShader, model, rp, gp, bp);

    //ETS3
    scale = glm::scale(identityMatrix, glm::vec3(10.0f, 0.5f, length));
    translate = glm::translate(identityMatrix, glm::vec3(-5.0, 12.5, -6.5));
    model = alTogether * translate * scale;
    drawCube(cubeVAO, lightingShader, model, rp, gp, bp);

    //ETS4
    scale = glm::scale(identityMatrix, glm::vec3(10.0f, 1.0f, length));
    translate = glm::translate(identityMatrix, glm::vec3(-5.0, 13.0, -6.5));
    model = alTogether * translate * scale;
    drawCube(cubeVAO, lightingShader, model, r, g, b);

    model = alTogether;
    drawSideFrame(cubeVAO, lightingShader, model);


    translate = glm::translate(identityMatrix, glm::vec3(15.5, 0.0, 0.0));
    model = alTogether * translate;
    drawSideFrame(cubeVAO, lightingShader, model);


}

void drawMain(unsigned int& cubeVAO, Shader& lightingShader, glm::mat4 alTogether)
{
    glm::mat4 model = glm::mat4(1.0f);
    glm::mat4 translate = glm::mat4(1.0f);
    glm::mat4 revtranslate = glm::mat4(1.0f);
    glm::mat4 identityMatrix = glm::mat4(1.0f);
    glm::mat4 scale = glm::mat4(1.0f);
    glm::mat4 rotate = glm::mat4(1.0f);

    //front
    drawDoorFrame(cubeVAO, lightingShader, alTogether);

    //rotate = glm::rotate(identityMatrix, glm::radians(45), glm::vec3(0.0f, .0f, 0.0f));
    rotate = glm::rotate(identityMatrix, glm::radians(-45.0f), glm::vec3(0.0f, 1.0f, 0.0f));
    translate = glm::translate(identityMatrix, glm::vec3(7.5, 0.0, 0.0));
    revtranslate = glm::translate(identityMatrix, glm::vec3(-17.0, 0.0, -3.5));
    model = alTogether * revtranslate * rotate * translate;
    drawSideFrame(cubeVAO, lightingShader, model);

}

void drawFieldWithTexture(Shader& lightingShader, glm::mat4 alTogether)
{
    float baseHeight = 0.2;
    float width = 2.0f;
    float length = 30.0f;

    string diffuseMapPath = "rsz_11texture-grass-field.jpg";
    string specularMapPath = "rsz_11texture-grass-field.jpg";


    unsigned int diffMap = loadTexture(diffuseMapPath.c_str(), GL_REPEAT, GL_REPEAT, GL_LINEAR_MIPMAP_LINEAR, GL_LINEAR);
    unsigned int specMap = loadTexture(specularMapPath.c_str(), GL_REPEAT, GL_REPEAT, GL_LINEAR_MIPMAP_LINEAR, GL_LINEAR);
    Cube cube = Cube(diffMap, specMap, 32.0f, 0.0f, 0.0f, 1.0f, 15.0f);

    glm::mat4 model = glm::mat4(1.0f);
    glm::mat4 translate = glm::mat4(1.0f);
    glm::mat4 identityMatrix = glm::mat4(1.0f);
    glm::mat4 scale = glm::mat4(1.0f);
    glm::mat4 mirror = glm::mat4(1.0f);

    scale = glm::scale(identityMatrix, glm::vec3(width, baseHeight, length));
    translate = glm::translate(identityMatrix, glm::vec3(2.5, 0, 0.0));
    model = alTogether * translate * scale;
    //drawCube(cubeVAO, lightingShader, model, 0.5, 1.0, 0.0);
    cube.drawCubeWithTexture(lightingShader, model);


    scale = glm::scale(identityMatrix, glm::vec3(width, baseHeight, length));
    translate = glm::translate(identityMatrix, glm::vec3(-4.5, 0, 0.0));
    model = alTogether * translate * scale;
    //drawCube(cubeVAO, lightingShader, model, 0.5, 1.0, 0.0);
    cube.drawCubeWithTexture(lightingShader, model);

}

void drawField(unsigned int& cubeVAO, Shader& lightingShader, glm::mat4 alTogether)
{
    float baseHeight = 0.2;
    float width = 2.0f;
    float length = 54.0f;

    glm::mat4 model = glm::mat4(1.0f);
    glm::mat4 translate = glm::mat4(1.0f);
    glm::mat4 identityMatrix = glm::mat4(1.0f);
    glm::mat4 scale = glm::mat4(1.0f);
    glm::mat4 mirror = glm::mat4(1.0f);

    //front horizontal edge
    scale = glm::scale(identityMatrix, glm::vec3(113.0, 0.3, 4.0));
    translate = glm::translate(identityMatrix, glm::vec3(-56.5, 0.0, -4.0));
    model = alTogether * translate * scale;
    drawCube(cubeVAO, lightingShader, model, 1.0, 0.2, 0.2);

    //GRS1
    scale = glm::scale(identityMatrix, glm::vec3(width, baseHeight, length));
    translate = glm::translate(identityMatrix, glm::vec3(2.5, 0, 0.0));
    model = alTogether * translate * scale;
    drawCube(cubeVAO, lightingShader, model, 0.5, 1.0, 0.0);

    scale = glm::scale(identityMatrix, glm::vec3(8.0, baseHeight, width));
    translate = glm::translate(identityMatrix, glm::vec3(2.5, 0, 54.0));
    model = alTogether * translate * scale;
    drawCube(cubeVAO, lightingShader, model, 0.5, 1.0, 0.0);

    scale = glm::scale(identityMatrix, glm::vec3(width, baseHeight, 8));
    translate = glm::translate(identityMatrix, glm::vec3(10.5, 0, 54.0));
    model = alTogether * translate * scale;
    drawCube(cubeVAO, lightingShader, model, 0.5, 1.0, 0.0);

    scale = glm::scale(identityMatrix, glm::vec3(42, baseHeight, width));
    translate = glm::translate(identityMatrix, glm::vec3(10.5, 0, 62.0));
    model = alTogether * translate * scale;
    drawCube(cubeVAO, lightingShader, model, 0.5, 1.0, 0.0);

    //GLS1
    scale = glm::scale(identityMatrix, glm::vec3(width, baseHeight, length));
    translate = glm::translate(identityMatrix, glm::vec3(-4.5, 0, 0.0));
    model = alTogether * translate * scale;
    drawCube(cubeVAO, lightingShader, model, 0.5, 1.0, 0.0);

    scale = glm::scale(identityMatrix, glm::vec3(8.0, baseHeight, width));
    translate = glm::translate(identityMatrix, glm::vec3(-10.5, 0, 54.0));
    model = alTogether * translate * scale;
    drawCube(cubeVAO, lightingShader, model, 0.5, 1.0, 0.0);

    scale = glm::scale(identityMatrix, glm::vec3(width, baseHeight, 8));
    translate = glm::translate(identityMatrix, glm::vec3(-12.5, 0, 54.0));
    model = alTogether * translate * scale;
    drawCube(cubeVAO, lightingShader, model, 0.5, 1.0, 0.0);

    scale = glm::scale(identityMatrix, glm::vec3(42, baseHeight, width));
    translate = glm::translate(identityMatrix, glm::vec3(-52.5, 0, 62.0));
    model = alTogether * translate * scale;
    drawCube(cubeVAO, lightingShader, model, 0.5, 1.0, 0.0);

    //GRS2B
    scale = glm::scale(identityMatrix, glm::vec3(21.0, baseHeight, 25.0));
    translate = glm::translate(identityMatrix, glm::vec3(8.5, 0, 0.0));
    model = alTogether * translate * scale;
    drawCube(cubeVAO, lightingShader, model, 0.5, 1.0, 0.0);

    scale = glm::scale(identityMatrix, glm::vec3(21.0, baseHeight, 25.0));
    translate = glm::translate(identityMatrix, glm::vec3(32.5, 0, 0.0));
    model = alTogether * translate * scale;
    drawCube(cubeVAO, lightingShader, model, 0.5, 1.0, 0.0);

    //GLS2B
    scale = glm::scale(identityMatrix, glm::vec3(21.0, baseHeight, 25.0));
    translate = glm::translate(identityMatrix, glm::vec3(-29.5, 0, 0.0));
    model = alTogether * translate * scale;
    drawCube(cubeVAO, lightingShader, model, 0.5, 1.0, 0.0);

    scale = glm::scale(identityMatrix, glm::vec3(21.0, baseHeight, 25.0));
    translate = glm::translate(identityMatrix, glm::vec3(-53.5, 0, 0.0));
    model = alTogether * translate * scale;
    drawCube(cubeVAO, lightingShader, model, 0.5, 1.0, 0.0);

    //GRS2F
    scale = glm::scale(identityMatrix, glm::vec3(21.0, baseHeight, 21.0));
    translate = glm::translate(identityMatrix, glm::vec3(8.5, 0, 29.0));
    model = alTogether * translate * scale;
    drawCube(cubeVAO, lightingShader, model, 0.5, 1.0, 0.0);

    scale = glm::scale(identityMatrix, glm::vec3(13.0, baseHeight, 8.0));
    translate = glm::translate(identityMatrix, glm::vec3(16.5, 0, 50.0));
    model = alTogether * translate * scale;
    drawCube(cubeVAO, lightingShader, model, 0.5, 1.0, 0.0);

    scale = glm::scale(identityMatrix, glm::vec3(21.0, baseHeight, 29.0));
    translate = glm::translate(identityMatrix, glm::vec3(32.5, 0, 29.0));
    model = alTogether * translate * scale;
    drawCube(cubeVAO, lightingShader, model, 0.5, 1.0, 0.0);

    //GLS2F
    scale = glm::scale(identityMatrix, glm::vec3(21.0, baseHeight, 21.0));
    translate = glm::translate(identityMatrix, glm::vec3(-29.5, 0, 29.0));
    model = alTogether * translate * scale;
    drawCube(cubeVAO, lightingShader, model, 0.5, 1.0, 0.0);

    scale = glm::scale(identityMatrix, glm::vec3(13.0, baseHeight, 8.0));
    translate = glm::translate(identityMatrix, glm::vec3(-29.5, 0, 50.0));
    model = alTogether * translate * scale;
    drawCube(cubeVAO, lightingShader, model, 0.5, 1.0, 0.0);

    scale = glm::scale(identityMatrix, glm::vec3(21.0, baseHeight, 29.0));
    translate = glm::translate(identityMatrix, glm::vec3(-53.5, 0, 29.0));
    model = alTogether * translate * scale;
    drawCube(cubeVAO, lightingShader, model, 0.5, 1.0, 0.0);

    //BRS2
    scale = glm::scale(identityMatrix, glm::vec3(4, 0.3, 50.0));
    translate = glm::translate(identityMatrix, glm::vec3(4.5, 0.0, 0.0));
    model = alTogether * translate * scale;
    drawCube(cubeVAO, lightingShader, model, 1.0, 0.2, 0.2);

    scale = glm::scale(identityMatrix, glm::vec3(4, 0.3, 8.0));
    translate = glm::translate(identityMatrix, glm::vec3(12.5, 0.0, 54.0));
    model = alTogether * translate * scale;
    drawCube(cubeVAO, lightingShader, model, 1.0, 0.2, 0.2);


    //BLS2
    scale = glm::scale(identityMatrix, glm::vec3(4, 0.3, 50.0));
    translate = glm::translate(identityMatrix, glm::vec3(-8.5, 0.0, 0.0));
    model = alTogether * translate * scale;
    drawCube(cubeVAO, lightingShader, model, 1.0, 0.2, 0.2);

    scale = glm::scale(identityMatrix, glm::vec3(4, 0.3, 8.0));
    translate = glm::translate(identityMatrix, glm::vec3(-16.5, 0.0, 54.0));
    model = alTogether * translate * scale;
    drawCube(cubeVAO, lightingShader, model, 1.0, 0.2, 0.2);

    //BRS3
    scale = glm::scale(identityMatrix, glm::vec3(4, 0.3, 58.0));
    translate = glm::translate(identityMatrix, glm::vec3(29.5, 0.0, 0.0));
    model = alTogether * translate * scale;
    drawCube(cubeVAO, lightingShader, model, 1.0, 0.2, 0.2);


    //BLS3
    scale = glm::scale(identityMatrix, glm::vec3(4, 0.3, 58.0));
    translate = glm::translate(identityMatrix, glm::vec3(-33.5, 0.0, 0.0));
    model = alTogether * translate * scale;
    drawCube(cubeVAO, lightingShader, model, 1.0, 0.2, 0.2);


    //BRS4
    scale = glm::scale(identityMatrix, glm::vec3(4, 0.3, 67.0));
    translate = glm::translate(identityMatrix, glm::vec3(52.5, 0.0, 0.0));
    model = alTogether * translate * scale;
    drawCube(cubeVAO, lightingShader, model, 1.0, 0.2, 0.2);


    //BLS4
    scale = glm::scale(identityMatrix, glm::vec3(4, 0.3, 67.0));
    translate = glm::translate(identityMatrix, glm::vec3(-56.5, 0.0, 0.0));
    model = alTogether * translate * scale;
    drawCube(cubeVAO, lightingShader, model, 1.0, 0.2, 0.2);


    //horizontal border right HBR
    scale = glm::scale(identityMatrix, glm::vec3(45.0, 0.3, 4.0));
    translate = glm::translate(identityMatrix, glm::vec3(8.5, 0.0, 25.0));
    model = alTogether * translate * scale;
    drawCube(cubeVAO, lightingShader, model, 1.0, 0.2, 0.2);

    scale = glm::scale(identityMatrix, glm::vec3(12.0, 0.3, 4.0));
    translate = glm::translate(identityMatrix, glm::vec3(4.5, 0.0, 50.0));
    model = alTogether * translate * scale;
    drawCube(cubeVAO, lightingShader, model, 1.0, 0.2, 0.2);

    scale = glm::scale(identityMatrix, glm::vec3(40.0, 0.3, 4.0));
    translate = glm::translate(identityMatrix, glm::vec3(16.5, 0.0, 58.0));
    model = alTogether * translate * scale;
    drawCube(cubeVAO, lightingShader, model, 1.0, 0.2, 0.2);


    //horizontal border left HBL
    scale = glm::scale(identityMatrix, glm::vec3(45.0, 0.3, 4.0));
    translate = glm::translate(identityMatrix, glm::vec3(-53.5, 0.0, 25.0));
    model = alTogether * translate * scale;
    drawCube(cubeVAO, lightingShader, model, 1.0, 0.2, 0.2);

    scale = glm::scale(identityMatrix, glm::vec3(12.0, 0.3, 4.0));
    translate = glm::translate(identityMatrix, glm::vec3(-16.5, 0.0, 50.0));
    model = alTogether * translate * scale;
    drawCube(cubeVAO, lightingShader, model, 1.0, 0.2, 0.2);

    scale = glm::scale(identityMatrix, glm::vec3(40.0, 0.3, 4.0));
    translate = glm::translate(identityMatrix, glm::vec3(-56.5, 0.0, 58.0));
    model = alTogether * translate * scale;
    drawCube(cubeVAO, lightingShader, model, 1.0, 0.2, 0.2);

}

void drawFrontLake(unsigned int& cubeVAO, Shader& lightingShader, glm::mat4 alTogether)
{
    float baseHeight = 0.3;
    float width = 1;
    float length = 62;

    glm::mat4 model = glm::mat4(1.0f);
    glm::mat4 translate = glm::mat4(1.0f);
    glm::mat4 identityMatrix = glm::mat4(1.0f);
    glm::mat4 scale = glm::mat4(1.0f);
    glm::mat4 mirror = glm::mat4(1.0f);

    //edges
    scale = glm::scale(identityMatrix, glm::vec3(width, baseHeight, length));
    translate = glm::translate(identityMatrix, glm::vec3(1.5, 0.0, 0.0));
    model = alTogether * translate * scale;
    drawCube(cubeVAO, lightingShader, model, 1.0, 0.2, 0.2);

    scale = glm::scale(identityMatrix, glm::vec3(width, baseHeight, length));
    translate = glm::translate(identityMatrix, glm::vec3(-2.5, 0.0, 0.0));
    model = alTogether * translate * scale;
    drawCube(cubeVAO, lightingShader, model, 1.0, 0.2, 0.2);

    //edge front
    translate = glm::translate(identityMatrix, glm::vec3(-1.5, 0.0, 0.0));
    scale = glm::scale(identityMatrix, glm::vec3(3.0, baseHeight, 1.0));
    model = alTogether * translate * scale;
    drawCube(cubeVAO, lightingShader, model, 1.0, 0.2, 0.2);

    //water
    translate = glm::translate(identityMatrix, glm::vec3(-1.5, 0.0, 1.0));
    scale = glm::scale(identityMatrix, glm::vec3(3.0, 0.2, 61.0));
    model = alTogether * translate * scale;
    drawCube(cubeVAO, lightingShader, model, 0.2, 1.0, 1.0);

}

void drawLake(unsigned int& cubeVAO, Shader& lightingShader, glm::mat4 alTogether)
{
    glm::mat4 model = glm::mat4(1.0f);
    glm::mat4 translate = glm::mat4(1.0f);
    glm::mat4 identityMatrix = glm::mat4(1.0f);
    glm::mat4 scale = glm::mat4(1.0f);
    glm::mat4 rotate = glm::mat4(1.0f);


    model = identityMatrix;
    drawFrontLake(cubeVAO, lightingShader, model);

    //left lake
    scale = glm::scale(identityMatrix, glm::vec3(1.0, 1.0, 0.81));
    rotate = glm::rotate(identityMatrix, glm::radians(90.0f), glm::vec3(0.0f, 1.0f, 0.0f));
    translate = glm::translate(identityMatrix, glm::vec3(-56.5, 0.0, 66.5));
    model = translate * rotate * scale;
    drawFrontLake(cubeVAO, lightingShader, model);

    //right lake
    scale = glm::scale(identityMatrix, glm::vec3(1.0, 1.0, 0.81));
    rotate = glm::rotate(identityMatrix, glm::radians(-90.0f), glm::vec3(0.0f, 1.0f, 0.0f));
    translate = glm::translate(identityMatrix, glm::vec3(56.5, 0.0, 66.5));
    model = translate * rotate * scale;
    drawFrontLake(cubeVAO, lightingShader, model);

    //front opposite
    scale = glm::scale(identityMatrix, glm::vec3(1.0, 1.0, -1.0));
    translate = glm::translate(identityMatrix, glm::vec3(0.0, 0.0, 133.0));
    model = translate * scale;
    drawFrontLake(cubeVAO, lightingShader, model);


    //center square
    scale = glm::scale(identityMatrix, glm::vec3(8.0, 0.8, 3.0));
    translate = glm::translate(identityMatrix, glm::vec3(-4.0, 0.0, 60.0));
    model = alTogether * translate * scale;
    drawCube(cubeVAO, lightingShader, model, 0.8, 0.8, 0.8);

    scale = glm::scale(identityMatrix, glm::vec3(8.0, 0.8, 3.0));
    translate = glm::translate(identityMatrix, glm::vec3(-4.0, 0.0, 70.0));
    model = alTogether * translate * scale;
    drawCube(cubeVAO, lightingShader, model, 0.8, 0.8, 0.8);

    scale = glm::scale(identityMatrix, glm::vec3(3.0, 0.8, 13.0));
    translate = glm::translate(identityMatrix, glm::vec3(-6.5, 0.0, 60.0));
    model = alTogether * translate * scale;
    drawCube(cubeVAO, lightingShader, model, 0.8, 0.8, 0.8);

    scale = glm::scale(identityMatrix, glm::vec3(3.0, 0.8, 13.0));
    translate = glm::translate(identityMatrix, glm::vec3(4.0, 0.0, 60.0));
    model = alTogether * translate * scale;
    drawCube(cubeVAO, lightingShader, model, 0.8, 0.8, 0.8);


    //inner edges
    scale = glm::scale(identityMatrix, glm::vec3(21.0, 0.3, 1.0));
    translate = glm::translate(identityMatrix, glm::vec3(-10.5, 0.0, 56.0));
    model = alTogether * translate * scale;
    drawCube(cubeVAO, lightingShader, model, 1.0, 0.2, 0.2);

    scale = glm::scale(identityMatrix, glm::vec3(1.0, 0.3, 21.0));
    translate = glm::translate(identityMatrix, glm::vec3(-10.5, 0.0, 56.0));
    model = alTogether * translate * scale;
    drawCube(cubeVAO, lightingShader, model, 1.0, 0.2, 0.2);

    scale = glm::scale(identityMatrix, glm::vec3(1.0, 0.3, 21.0));
    translate = glm::translate(identityMatrix, glm::vec3(9.5, 0.0, 56.0));
    model = alTogether * translate * scale;
    drawCube(cubeVAO, lightingShader, model, 1.0, 0.2, 0.2);

    scale = glm::scale(identityMatrix, glm::vec3(21.0, 0.3, 1.0));
    translate = glm::translate(identityMatrix, glm::vec3(-10.5, 0.0, 76.0));
    model = alTogether * translate * scale;
    drawCube(cubeVAO, lightingShader, model, 1.0, 0.2, 0.2);



    //center water
    scale = glm::scale(identityMatrix, glm::vec3(19.0, 0.2, 19.0));
    translate = glm::translate(identityMatrix, glm::vec3(-9.5, 0.0, 57.0));
    model = alTogether * translate * scale;
    drawCube(cubeVAO, lightingShader, model, 0.2, 1.0, 1.0);
}

void drawBase(unsigned int& cubeVAO, Shader& lightingShader, glm::mat4 alTogether)
{
    float baseHeight = 4.0;
    float width = 20;
    float length = -40;

    glm::mat4 model = glm::mat4(1.0f);
    glm::mat4 translate = glm::mat4(1.0f);
    glm::mat4 translate2 = glm::mat4(1.0f);
    glm::mat4 identityMatrix = glm::mat4(1.0f);



    glm::mat4 scale = glm::mat4(1.0f);
    glm::mat4 mirror = glm::mat4(1.0f);
    scale = glm::scale(model, glm::vec3(width, baseHeight, length));
    translate = glm::translate(model, glm::vec3(0.0, -0.5, 0.0));
    model = alTogether * scale * translate;
    drawCube(cubeVAO, lightingShader, model, 0.7, 0.7, 0.7);

    mirror = glm::scale(identityMatrix, glm::vec3(-1.0, 1.0, 1.0));
    model = mirror * model;
    drawCube(cubeVAO, lightingShader, model, 0.7, 0.7, 0.7);
}


void drawTreeWithFractiles(unsigned int& cubeVAO, Shader& lightingShader, glm::mat4 alTogether, float L, float H, float W, int N)
{
    glm::mat4 model = glm::mat4(1.0f);
    glm::mat4 translate = glm::mat4(1.0f);
    glm::mat4 identityMatrix = glm::mat4(1.0f);
    glm::mat4 scale = glm::mat4(1.0f);
    glm::mat4 next = glm::mat4(1.0f);
    glm::mat4 rotate = glm::mat4(1.0f);



    if (N == 0) {
        float length = 0.5;
        float height = 4.0;
        float width = 0.5;

        float mvx = length * 0.05;
        float mvy = height - height * 0.1;
        float mvz = width * 0.05;


        translate = glm::translate(identityMatrix, glm::vec3(mvx, mvy, mvz));
        next = translate * alTogether;


        scale = glm::scale(identityMatrix, glm::vec3(length, height, width));
        model = alTogether * scale;
        drawCube(cubeVAO, lightingShader, model, 0.0, 0.95, 0.95);
        drawTreeWithFractiles(cubeVAO, lightingShader, next, length, height, width, N + 1);
    }

    else if (N > 0 && N < 3) {
        float length = L * 0.6;
        float height = H * 0.6;
        float width = W * 0.6;

        scale = glm::scale(identityMatrix, glm::vec3(length, height, width));
        rotate = glm::rotate(identityMatrix, glm::radians(-45.0f), glm::vec3(0.0f, 0.0f, 1.0f));
        model = alTogether * rotate * scale;
        drawCube(cubeVAO, lightingShader, model, 0.0, 0.95, 0.95);

        scale = glm::scale(identityMatrix, glm::vec3(length, height, width));
        rotate = glm::rotate(identityMatrix, glm::radians(-45.0f), glm::vec3(1.0f, 0.0f, 0.0f));
        model = alTogether * rotate * scale;
        drawCube(cubeVAO, lightingShader, model, 0.0, 0.95, 0.95);

        scale = glm::scale(identityMatrix, glm::vec3(length, height, width));
        rotate = glm::rotate(identityMatrix, glm::radians(45.0f), glm::vec3(0.0f, 0.0f, 1.0f));
        model = alTogether * rotate * scale;
        drawCube(cubeVAO, lightingShader, model, 0.0, 0.95, 0.95);

        scale = glm::scale(identityMatrix, glm::vec3(length, height, width));
        rotate = glm::rotate(identityMatrix, glm::radians(45.0f), glm::vec3(1.0f, 0.0f, 0.0f));
        model = alTogether * rotate * scale;
        drawCube(cubeVAO, lightingShader, model, 0.0, 0.95, 0.95);

        scale = glm::scale(identityMatrix, glm::vec3(length, height, width));
        model = alTogether * scale;
        drawCube(cubeVAO, lightingShader, model, 0.0, 0.95, 0.95);


        float mvx = length * 0.3 + height * 0.7071;
        float mvy = height * 0.7071;
        float mvz = width * 0.3;
        translate = glm::translate(identityMatrix, glm::vec3(mvx, mvy, mvz));
        next = translate * alTogether;
        drawTreeWithFractiles(cubeVAO, lightingShader, next, length, height, width, N + 1);


        mvx = length * 0.3;
        mvy = height * 0.7071;
        mvz = width * 0.3 - height * 0.7071;
        translate = glm::translate(identityMatrix, glm::vec3(mvx, mvy, mvz));
        next = translate * alTogether;
        drawTreeWithFractiles(cubeVAO, lightingShader, next, length, height, width, N + 1);


        mvx = length * 0.3 - height * 0.7071;
        mvy = height * 0.7071;
        mvz = width * 0.3;
        translate = glm::translate(identityMatrix, glm::vec3(mvx, mvy, mvz));
        next = translate * alTogether;
        drawTreeWithFractiles(cubeVAO, lightingShader, next, length, height, width, N + 1);


        mvx = length * 0.3;
        mvy = height * 0.7071;
        mvz = width * 0.3 + height * 0.7071;
        translate = glm::translate(identityMatrix, glm::vec3(mvx, mvy, mvz));
        next = translate * alTogether;
        drawTreeWithFractiles(cubeVAO, lightingShader, next, length, height, width, N + 1);

        mvx = length * 0.3;
        mvy = height;
        mvz = width * 0.3;
        translate = glm::translate(identityMatrix, glm::vec3(mvx, mvy, mvz));
        next = translate * alTogether;
        drawTreeWithFractiles(cubeVAO, lightingShader, next, length, height, width, N + 1);
    }

    else if (N == 3) {
        float length = L * 0.6;
        float height = H * 0.6;
        float width = W * 0.6;

        scale = glm::scale(identityMatrix, glm::vec3(length, height, width));
        rotate = glm::rotate(identityMatrix, glm::radians(-45.0f), glm::vec3(0.0f, 0.0f, 1.0f));
        model = alTogether * rotate * scale;
        drawCube(cubeVAO, lightingShader, model, 0.0, 0.95, 0.1);

        scale = glm::scale(identityMatrix, glm::vec3(length, height, width));
        rotate = glm::rotate(identityMatrix, glm::radians(-45.0f), glm::vec3(1.0f, 0.0f, 0.0f));
        model = alTogether * rotate * scale;
        drawCube(cubeVAO, lightingShader, model, 0.0, 0.95, 0.1);

        scale = glm::scale(identityMatrix, glm::vec3(length, height, width));
        rotate = glm::rotate(identityMatrix, glm::radians(45.0f), glm::vec3(0.0f, 0.0f, 1.0f));
        model = alTogether * rotate * scale;
        drawCube(cubeVAO, lightingShader, model, 0.0, 0.95, 0.1);

        scale = glm::scale(identityMatrix, glm::vec3(length, height, width));
        rotate = glm::rotate(identityMatrix, glm::radians(45.0f), glm::vec3(1.0f, 0.0f, 0.0f));
        model = alTogether * rotate * scale;
        drawCube(cubeVAO, lightingShader, model, 0.0, 0.95, 0.1);

        scale = glm::scale(identityMatrix, glm::vec3(length, height, width));
        model = alTogether * scale;
        drawCube(cubeVAO, lightingShader, model, 0.0, 0.95, 0.1);
    }

}
