#include <iostream>
#include "headers/main.h"

using namespace std;

void drawTajmahal(unsigned int& cubeVAO, Shader& lightingShader, glm::mat4 alTogether);
void drawSemiDome(unsigned int& cubeVAO, BezierCurve& semiDome, Octagon& base, Octagon& mid, Shader& lightingShader, glm::mat4 alTogether);
void drawDome(unsigned int& cubeVAO, BezierCurve& semiDome, Octagon& base, Shader& lightingShader, glm::mat4 alTogether);

int main()
{

    // glfw: initialize and configure
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);


    // glfw window creation
    GLFWwindow* window = glfwCreateWindow(SCR_WIDTH, SCR_HEIGHT, "Airway Surfers", NULL, NULL);
    if (window == NULL)
    {
        std::cout << "Failed to create GLFW window" << std::endl;
        glfwTerminate();
        return -1;
    }
    glfwMakeContextCurrent(window);
    glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);
    glfwSetKeyCallback(window, key_callback);
    glfwSetCursorPosCallback(window, mouse_callback);
    glfwSetScrollCallback(window, scroll_callback);

    // tell GLFW to capture our mouse
    glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_HIDDEN);

    // glad: load all OpenGL function pointers
    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
    {
        std::cout << "Failed to initialize GLAD" << std::endl;
        return -1;
    }

    // configure global opengl state
    glEnable(GL_DEPTH_TEST);

    // build and compile our shader zprogram
    Shader lightingShader("shaders/vertexShaderForPhongShading.vs", "shaders/fragmentShaderForPhongShading.fs");
    Shader ourShader("shaders/vertexShader.vs", "shaders/fragmentShader.fs");
    Shader lightingShaderWithTexture("shaders/vertexShaderForPhongShadingWithTexture.vs", "shaders/fragmentShaderForPhongShadingWithTexture.fs");


    float v1[] = {1.0f, 2.0f, 3.0f, 4.0f, 5.0f, 6.0f};


    GLuint vbo;
    glGenBuffers(1, &vbo);
    glBindBuffer(GL_ARRAY_BUFFER, vbo);
    glBufferData(GL_ARRAY_BUFFER, sizeof(v1), v1, GL_STATIC_DRAW);

    cout << "VBO value: " << vbo << endl;

    GLuint vao;
    glGenVertexArrays(1, &vao);



    unsigned int cubeVAO, cubeVBO, cubeEBO;
    glGenVertexArrays(1, &cubeVAO);
    glGenBuffers(1, &cubeVBO);
    glGenBuffers(1, &cubeEBO);

    glBindVertexArray(cubeVAO);
    glBindBuffer(GL_ARRAY_BUFFER, cubeVBO);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, cubeEBO);

    glBufferData(GL_ARRAY_BUFFER, sizeof(cube_vertices), cube_vertices, GL_STATIC_DRAW);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(cube_indices), cube_indices, GL_STATIC_DRAW);


    // position attribute
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);

    // vertex normal attribute
    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)12);
    glEnableVertexAttribArray(1);

    // second, configure the light's VAO (VBO stays the same; the vertices are the same for the light object which is also a 3D cube)
    unsigned int lightCubeVAO;
    glGenVertexArrays(1, &lightCubeVAO);
    glBindVertexArray(lightCubeVAO);

    glBindBuffer(GL_ARRAY_BUFFER, cubeVBO);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, cubeEBO);
    
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)0); // note that we update the lamp's position attribute's stride to reflect the updated buffer data
    glEnableVertexAttribArray(0); 

    int loop_timer = 0;


    //Dome
    glm::vec4 domeAmbient = glm::vec4(1.0, 1.0, 0.8, 1.0);
    glm::vec4 domeDiffusive = glm::vec4(1.0, 1.0, 0.8, 1.0);
    glm::vec4 domeSpecular = glm::vec4(1.0, 1.0, 0.8, 1.0);
    float domeShiny = 32.0f;

    BezierCurve dome = BezierCurve(domeVerties, 75, domeAmbient, domeDiffusive, domeSpecular, domeShiny, 0);
    BezierCurve semiDome = BezierCurve(semiDomeVerties, 54, domeAmbient, domeDiffusive, domeSpecular, domeShiny, 0);
  

    glm::vec4 octAmbient = glm::vec4(0.5, 0.5, 0.5, 1.0);
    glm::vec4 octDiffusive = glm::vec4(0.5, 0.5, 0.5, 1.0);
    glm::vec4 octSpecular = glm::vec4(0.7, 0.7, 0.7, 1.0);
    float octShiny = 32.0f;

    glm::vec4 octWhite = glm::vec4(0.7, 0.7, 0.7, 1.0);
    glm::vec4 octGrey = glm::vec4(0.7, 0.3, 0.3, 1.0);

    Octagon oct1 = Octagon(octAmbient, octDiffusive, octSpecular, octShiny);
    Octagon oct2 = Octagon(octWhite, octWhite, octWhite, octShiny);
    Octagon oct3 = Octagon(octGrey, octGrey, octGrey, octShiny);

    // render loop
    // -----------
    while (!glfwWindowShouldClose(window))
    {
        float currentFrame = static_cast<float>(glfwGetTime());
        deltaTime = currentFrame - lastFrame;
        lastFrame = currentFrame;

        processInput(window);

        glClearColor(0.1f, 0.1f, 0.1f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        lightingShader.use();
        lightingShader.setVec3("viewPos", camera.Position);


        pointlight1.setUpPointLight(lightingShader);
        pointlight2.setUpPointLight(lightingShader);
        pointlight3.setUpPointLight(lightingShader);
        pointlight4.setUpPointLight(lightingShader);

        spotlight.setUpSpotLight(lightingShader);

        moonlight.setUpDirectionalLight(lightingShader);
        daylight.setUpDirectionalLight(lightingShader);


        // pass projection matrix to shader (note that in this case it could change every frame)
        glm::mat4 projection = glm::perspective(glm::radians(camera.Zoom), (float)SCR_WIDTH / (float)SCR_HEIGHT, 0.1f, 400.0f);
        //glm::mat4 projection = glm::ortho(-2.0f, +2.0f, -1.5f, +1.5f, 0.1f, 100.0f);
        lightingShader.setMat4("projection", projection);
        

        // camera/view transformation
        glm::mat4 view = camera.GetViewMatrix();
        //glm::mat4 view = basic_camera.createViewMatrix();
        lightingShader.setMat4("view", view);


        // Modelling Transformation
        glm::mat4 identityMatrix = glm::mat4(1.0f); // make sure to initialize matrix to identity matrix first
        glm::mat4 translate, rotate, revtranslate, alTogether, next, model, scale;
        model =  identityMatrix;
        lightingShader.setMat4("model", model);

        
        // we now draw as many light bulbs as we have point lights.
        glBindVertexArray(lightCubeVAO);
        for (unsigned int i = 0; i < 4; i++)
        {
            model = glm::mat4(1.0f);
            model = glm::translate(model, pointLightPositions[i]);
            model = glm::scale(model, glm::vec3(0.2f)); // Make it a smaller cube
            ourShader.setMat4("model", model);
            ourShader.setVec3("color", glm::vec3(0.8f, 0.8f, 0.8f));
            glDrawElements(GL_TRIANGLES, 36, GL_UNSIGNED_INT, 0);
        }

        model = glm::mat4(1.0f);
        model = glm::translate(model, spotLightPosition);
        model = glm::scale(model, glm::vec3(0.2f)); // Make it a smaller cube
        ourShader.setMat4("model", model);
        ourShader.setVec3("color", glm::vec3(0.8f, 0.8f, 0.8f));
        glDrawElements(GL_TRIANGLES, 36, GL_UNSIGNED_INT, 0);


        lightingShaderWithTexture.use();
        lightingShaderWithTexture.setVec3("viewPos", camera.Position);

        lightingShaderWithTexture.setMat4("projection", projection);
        lightingShaderWithTexture.setMat4("view", view);

        lightingShaderWithTexture.use();


        pointlight1.setUpPointLight(lightingShaderWithTexture);
        pointlight2.setUpPointLight(lightingShaderWithTexture);
        pointlight3.setUpPointLight(lightingShaderWithTexture);
        pointlight4.setUpPointLight(lightingShaderWithTexture);

        spotlight.setUpSpotLight(lightingShaderWithTexture);

        moonlight.setUpDirectionalLight(lightingShaderWithTexture);
        daylight.setUpDirectionalLight(lightingShaderWithTexture);

        
        model = identityMatrix;
        lightingShaderWithTexture.setMat4("model", model);

        translate = glm::translate(identityMatrix, glm::vec3(0.0f, 0.0f, 30.0f));
        scale = glm::scale(identityMatrix, glm::vec3(90.0f, 90.0f, 90.0f));
        rotate = glm::rotate(identityMatrix, glm::radians(20.0f * 0.05f), glm::vec3(0.0f, 1.0f, 0.0f));
        model = translate * scale;




        ////Map creation and deletion logic.
        //loop_timer++;
        //if (loop_timer % 10000 == 0){
        //    map_translate_position[0] += 0.0f;
        //    map_translate_position[1] += 0.0f;
        //    map_translate_position[2] += 1.0f;

        //    cout << "New position: " << map_translate_position[0] << endl;
        //}

        create_map(glm::vec3(0.0f, 0.0f, 0.0f), lightingShaderWithTexture);
        //create_map(glm::vec3(0.0f, 0.0f, 1000.0f), lightingShaderWithTexture);
        


        glm::mat4 modelMatrixForContainer = glm::mat4(1.0f);
        modelMatrixForContainer = glm::translate(identityMatrix, glm::vec3(0.0f, 3.0f, 2.0f));
       
        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    glDeleteVertexArrays(1, &cubeVAO);
    glDeleteVertexArrays(1, &lightCubeVAO);
    glDeleteBuffers(1, &cubeVBO);
    glDeleteBuffers(1, &cubeEBO);

    glfwTerminate();
    return 0;
}



//void drawDome(unsigned int& cubeVAO, BezierCurve& Dome, Octagon& base, Shader& lightingShader, glm::mat4 alTogether)
//{
//    glm::mat4 model = glm::mat4(1.0f);
//    glm::mat4 translate = glm::mat4(1.0f);
//    glm::mat4 identityMatrix = glm::mat4(1.0f);
//    glm::mat4 scale = glm::mat4(1.0f);
//    glm::mat4 rotate = glm::mat4(1.0f);
//
//
//
//    scale = glm::scale(identityMatrix, glm::vec3(4.0, 5.0, 4.0));
//    translate = glm::translate(identityMatrix, glm::vec3(3.5, 1.0, 3.5));
//    model = alTogether * translate * scale;
//    Dome.drawBezierCurve(lightingShader, model);
//
//    scale = glm::scale(identityMatrix, glm::vec3(3.0, 3.0, 3.0));
//    model = alTogether * scale;
//    base.drawOctagonWithMaterialisticProperty(lightingShader, model);
//
//}

//void drawSemiDome(unsigned int& cubeVAO, BezierCurve& spire, Octagon& base, Octagon& mid, Shader& lightingShader, glm::mat4 alTogether) {
//    glm::mat4 model = glm::mat4(1.0f);
//    glm::mat4 translate = glm::mat4(1.0f);
//    glm::mat4 identityMatrix = glm::mat4(1.0f);
//    glm::mat4 scale = glm::mat4(1.0f);
//    glm::mat4 rotate = glm::mat4(1.0f);
//
//    // Scale and translate the spire (narrow top)
//    scale = glm::scale(identityMatrix, glm::vec3(2.2, 4.5, 0.5));  // Smaller width for the spire
//    translate = glm::translate(identityMatrix, glm::vec3(1.8, -2.0, 1.8));  // Move the spire to the top
//    model = alTogether * translate * scale;
//    spire.drawBezierCurve(lightingShader, model);
//
//    // Scale and translate the base (larger octagon)
//    scale = glm::scale(identityMatrix, glm::vec3(2.0, 0.5, 2.0));  // Broader base
//    translate = glm::translate(identityMatrix, glm::vec3(-0.8, 0.5, 1.8));  // Position the base
//    model = alTogether * translate * scale;
//    base.drawOctagonWithMaterialisticProperty(lightingShader, model);
//
//    // Scale and translate the middle section (Mid-tier)
//    scale = glm::scale(identityMatrix, glm::vec3(1.8, 0.3, 1.8));  // Slightly thinner middle section
//    translate = glm::translate(identityMatrix, glm::vec3(-0.5, 2.5, 0.0));  // Positioned in the middle of the tower
//    model = alTogether * translate * scale;
//    mid.drawOctagonWithMaterialisticProperty(lightingShader, model);
//
//    // Adding cube shapes for detailing at the base (like columns or smaller structures)
//    scale = glm::scale(identityMatrix, glm::vec3(0.3, 1.5, 0.3));  // Small supporting cubes
//    translate = glm::translate(identityMatrix, glm::vec3(1.1, 1.0, 0.1));  // Positions for detailing
//    model = alTogether * translate * scale;
//    drawCube(cubeVAO, lightingShader, model, 0.9, 0.9, 0.9);
//
//    translate = glm::translate(identityMatrix, glm::vec3(2.2, 1.0, 0.1));
//    model = alTogether * translate * scale;
//    drawCube(cubeVAO, lightingShader, model, 0.9, 0.9, 0.9);
//
//    translate = glm::translate(identityMatrix, glm::vec3(3.2, 1.0, 1.1));
//    model = alTogether * translate * scale;
//    drawCube(cubeVAO, lightingShader, model, 0.9, 0.9, 0.9);
//
//    translate = glm::translate(identityMatrix, glm::vec3(3.2, 1.0, 2.2));
//    model = alTogether * translate * scale;
//    drawCube(cubeVAO, lightingShader, model, 0.9, 0.9, 0.9);
//
//    translate = glm::translate(identityMatrix, glm::vec3(2.2, 1.0, 3.2));
//    model = alTogether * translate * scale;
//    drawCube(cubeVAO, lightingShader, model, 0.9, 0.9, 0.9);
//
//    translate = glm::translate(identityMatrix, glm::vec3(1.1, 1.0, 3.2));
//    model = alTogether * translate * scale;
//    drawCube(cubeVAO, lightingShader, model, 0.9, 0.9, 0.9);
//
//    translate = glm::translate(identityMatrix, glm::vec3(0.1, 1.0, 1.1));
//    model = alTogether * translate * scale;
//    drawCube(cubeVAO, lightingShader, model, 0.9, 0.9, 0.9);
//
//    translate = glm::translate(identityMatrix, glm::vec3(0.1, 1.0, 2.2));
//    model = alTogether * translate * scale;
//    drawCube(cubeVAO, lightingShader, model, 0.9, 0.9, 0.9);
//}
//
