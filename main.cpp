#include <iostream>
#include "main.h"

using namespace std;

int main()
{

    // glfw: initialize and configure
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);


    // glfw window creation
    GLFWwindow* window = glfwCreateWindow(SCR_WIDTH, SCR_HEIGHT, "CSE 4208: Computer Graphics Laboratory", NULL, NULL);
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
    Shader lightingShader("vertexShaderForPhongShading.vs", "fragmentShaderForPhongShading.fs");
    //Shader lightingShader("vertexShaderForGouraudShading.vs", "fragmentShaderForGouraudShading.fs");
    Shader ourShader("vertexShader.vs", "fragmentShader.fs");

    // set up vertex data (and buffer(s)) and configure vertex attributes

    glm::vec4 domeAmbient = glm::vec4(1.0, 1.0, 0.8, 1.0);
    glm::vec4 domeDiffusive = glm::vec4(1.0, 1.0, 0.8, 1.0);
    glm::vec4 domeSpecular = glm::vec4(1.0, 1.0, 0.8, 1.0);
    float domeShiny = 32.0f;

    BezierCurve dome = BezierCurve(domeVerties, 75, domeAmbient, domeDiffusive, domeSpecular, domeShiny,0);
    BezierCurve semiDome = BezierCurve(semiDomeVerties, 54, domeAmbient, domeDiffusive, domeSpecular, domeShiny,0);
    BezierCurve minar = BezierCurve(minarVertices, 60, domeAmbient, domeDiffusive, domeSpecular, domeShiny,0);

    glm::vec4 cylinderAmbient = glm::vec4(0.1, 0.9, 0.1, 1.0);
    glm::vec4 cylinderDiffusive = glm::vec4(0.1, 0.9, 0.1, 1.0);
    glm::vec4 cylinderSpecular = glm::vec4(0.0, 0.9, 0.0, 1.0);
    float cylinderShiny = 12.0f;
    BezierCurve greencylinder = BezierCurve(solinoidVertices, 66, cylinderAmbient, cylinderDiffusive, cylinderSpecular, cylinderShiny,0);

    cylinderAmbient = glm::vec4(0.7, 0.3, 0.3, 1.0);
    cylinderDiffusive = glm::vec4(0.7, 0.3, 0.3, 1.0);
    cylinderSpecular = glm::vec4(0.7, 0.3, 0.3, 1.0);
    BezierCurve greycylinder = BezierCurve(solinoidVertices, 66, cylinderAmbient, cylinderDiffusive, cylinderSpecular, cylinderShiny,0);
    
    glm::vec4 treeAmbient = glm::vec4(0.0, 0.9, 0.0, 1.0);
    glm::vec4 treeDiffusive = glm::vec4(0.0, 0.9, 0.0, 1.0);
    glm::vec4 treeSpecular = glm::vec4(0.0, 1.0, 0.0, 1.0);
    float treeShiny = 12.0f;
    BezierCurve tree = BezierCurve(treeVertices, 138, treeAmbient, treeDiffusive, treeSpecular, treeShiny, 0);


    BezierCurve dome2 = BezierCurve(domeVerties, 75, domeAmbient, domeDiffusive, domeSpecular, domeShiny, 1);

    glm::vec4 octAmbient = glm::vec4(0.5, 0.5, 0.5, 1.0);
    glm::vec4 octDiffusive = glm::vec4(0.5, 0.5, 0.5, 1.0);
    glm::vec4 octSpecular = glm::vec4(0.7, 0.7, 0.7, 1.0);
    float octShiny = 32.0f;

    glm::vec4 octWhite = glm::vec4(0.7, 0.7, 0.7, 1.0);
    glm::vec4 octGrey = glm::vec4(0.7, 0.3, 0.3, 1.0);

    Octagon oct1 = Octagon(octAmbient, octDiffusive, octSpecular, octShiny);
    Octagon oct2 = Octagon(octWhite, octWhite, octWhite, octShiny);
    Octagon oct3 = Octagon(octGrey, octGrey, octGrey, octShiny);


    unsigned int cubeVAO, cubeVBO, cubeEBO;
    glGenVertexArrays(1, &cubeVAO);
    glGenBuffers(1, &cubeVBO);
    glGenBuffers(1, &cubeEBO);

    glBindVertexArray(cubeVAO);

    glBindBuffer(GL_ARRAY_BUFFER, cubeVBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(cube_vertices), cube_vertices, GL_STATIC_DRAW);

    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, cubeEBO);
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
    // note that we update the lamp's position attribute's stride to reflect the updated buffer data
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);

    string diffuseMapPath = "resources/rsz_11field_image.jpg";
    string specularMapPath = "resources/rsz_11field_image.jpg";


    unsigned int diffMap = loadTexture(diffuseMapPath.c_str(), GL_REPEAT, GL_REPEAT, GL_LINEAR_MIPMAP_LINEAR, GL_LINEAR);
    unsigned int specMap = loadTexture(specularMapPath.c_str(), GL_REPEAT, GL_REPEAT, GL_LINEAR_MIPMAP_LINEAR, GL_LINEAR);
    Sphere sphere = Sphere(diffMap,specMap,0,0,2,1);

    Cube texcube = Cube(diffMap, specMap, 32.0f, 0.0f, 0.0f, 1.0f, 1.0f);

    //glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
    Shader lightingShaderWithTexture("vertexShaderForPhongShadingWithTexture.vs", "fragmentShaderForPhongShadingWithTexture.fs");
    //Shader ourShader("vertexShader.vs", "fragmentShader.fs");

    diffuseMapPath = "resources/rsz_1texture-grass-field.jpg";
    specularMapPath = "resources/rsz_1texture-grass-field.jpg";


    diffMap = loadTexture(diffuseMapPath.c_str(), GL_CLAMP_TO_EDGE, GL_CLAMP_TO_EDGE, GL_LINEAR_MIPMAP_LINEAR, GL_LINEAR);
    specMap = loadTexture(specularMapPath.c_str(), GL_CLAMP_TO_EDGE, GL_CLAMP_TO_EDGE, GL_LINEAR_MIPMAP_LINEAR, GL_LINEAR);
    Cube cube = Cube(diffMap, specMap, 32.0f, 0.0f, 0.0f, 2.0f, 2.0f);
    

    diffuseMapPath = "resources/sky.jpg";
    specularMapPath = "resources/sky.jpg";


    diffMap = loadTexture(diffuseMapPath.c_str(), GL_REPEAT, GL_REPEAT, GL_LINEAR_MIPMAP_LINEAR, GL_LINEAR);
    specMap = loadTexture(specularMapPath.c_str(), GL_REPEAT, GL_REPEAT, GL_LINEAR_MIPMAP_LINEAR, GL_LINEAR);
    Cube texcube2 = Cube(diffMap, specMap, 32.0f, 0.0f, 0.0f, 1.0f, 1.0f);

    

    //ourShader.use();
    //lightingShader.use();

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
        //translateMatrix = glm::translate(identityMatrix, glm::vec3(10, 20, 10));
        //rotateXMatrix = glm::rotate(identityMatrix, glm::radians(rotateAngle_X), glm::vec3(1.0f, 0.0f, 0.0f));
        //rotateYMatrix = glm::rotate(identityMatrix, glm::radians(rotateAngle_Y), glm::vec3(0.0f, 1.0f, 0.0f));
        //rotateZMatrix = glm::rotate(identityMatrix, glm::radians(rotateAngle_Z), glm::vec3(0.0f, 0.0f, 1.0f));
        //scaleMatrix = glm::scale(identityMatrix, glm::vec3(0.1, 0.1, 0.1));
        model =  identityMatrix;
        lightingShader.setMat4("model", model);


        //scale = glm::scale(identityMatrix, glm::vec3(4.0, 4.0, 4.0));
        //dome2.drawBezierCurve(lightingShader, scale);

        model = identityMatrix;
        //drawLake(cubeVAO, lightingShader, model);
        drawField(cubeVAO, lightingShader, model);
        drawFloor(cubeVAO, lightingShader, model);

        rotate = glm::rotate(identityMatrix, glm::radians(180.0f), glm::vec3(0.0f, 1.0f, 0.0f));
        translate = glm::translate(identityMatrix, glm::vec3(0.0, 0.0, 133.0));
        model = translate * rotate;
        drawField(cubeVAO, lightingShader, model);

         

        //Tajmahal design
        translate = glm::translate(identityMatrix, glm::vec3(0.0, 2.0, -8.0));
        scale = glm::scale(identityMatrix, glm::vec3(1.0, 1.3, 1.0));
        next = scale * translate;
        //drawTajmahal(cubeVAO, lightingShader, next);
        //central dome
        translate = glm::translate(identityMatrix, glm::vec3(-3.5f, 12.0f, -24.5f));
        scale = glm::scale(identityMatrix, glm::vec3(1.0, 1.0, 1.0));
        model = next * translate * scale;
        //drawDome(cubeVAO, dome, oct2, lightingShader, model);
        //SDFL
        translate = glm::translate(identityMatrix, glm::vec3(-10.0f, 12.0f, -16.0f));
        scale = glm::scale(identityMatrix, glm::vec3(1.5, 1.5, 1.5));
        model = next * translate * scale;
        //drawSemiDome(cubeVAO, semiDome, oct2, oct2, lightingShader, model);
        //SDFR
        translate = glm::translate(identityMatrix, glm::vec3(5.0f, 12.0f, -16.0f));
        scale = glm::scale(identityMatrix, glm::vec3(1.5, 1.5, 1.5));
        model = next * translate * scale;
        //drawSemiDome(cubeVAO, semiDome, oct2, oct2, lightingShader, model);
        //SDBL
        translate = glm::translate(identityMatrix, glm::vec3(-10.0f, 12.0f, -31.5f));
        scale = glm::scale(identityMatrix, glm::vec3(1.5, 1.5, 1.5));
        model = next * translate * scale;
        //drawSemiDome(cubeVAO, semiDome, oct2, oct2, lightingShader, model);
        //SDBR
        translate = glm::translate(identityMatrix, glm::vec3(5.0f, 12.0f, -31.5f));
        scale = glm::scale(identityMatrix, glm::vec3(1.5, 1.5, 1.5));
        model = next * translate * scale;
        //drawSemiDome(cubeVAO, semiDome, oct2, oct2, lightingShader, model);


        //Minar right
        translate = glm::translate(identityMatrix, glm::vec3(1.5, 0.0, -2.5));
        model = next * translate;
        drawMinar(cubeVAO, minar, semiDome, oct3, oct2, lightingShader, model);
        //Minar left
        translate = glm::translate(identityMatrix, glm::vec3(-22.5, 0.0, -2.5));
        model = next * translate;
        //drawMinar(cubeVAO, minar, semiDome, oct3, oct2, lightingShader, model);
        //Minar right back
        translate = glm::translate(identityMatrix, glm::vec3(17.5, 0.0, -42.5));
        model = next * translate;
        //drawMinar(cubeVAO, minar, semiDome, oct3, oct2, lightingShader, model);
        //Minar left back
        translate = glm::translate(identityMatrix, glm::vec3(-22.5, 0.0, -42.5));
        model = next * translate;
        //drawMinar(cubeVAO, minar, semiDome, oct3, oct2, lightingShader, model);

        //drawNarrowMinarTogether(cubeVAO, minar, semiDome, oct3, oct2, lightingShader, next);
        


        model = identityMatrix;
       

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
        //drawFieldWithTexture(lightingShaderWithTexture, model);


        translate = glm::translate(identityMatrix, glm::vec3(0.0f, 0.0f, 30.0f));
        scale = glm::scale(identityMatrix, glm::vec3(90.0f, 90.0f, 90.0f));
        rotate = glm::rotate(identityMatrix, glm::radians(20.0f * 0.05f), glm::vec3(0.0f, 1.0f, 0.0f));
        model = translate * scale;
        //sphere.drawSphereWithTexture(lightingShaderWithTexture, model);;

       




        translate = glm::translate(identityMatrix, glm::vec3(-57.0f, -5.0f, -57.0f));
        scale = glm::scale(identityMatrix, glm::vec3(114.0f, 114.0f, 1.0f));
        model = translate * scale;
        texcube.drawCubeWithTexture(lightingShaderWithTexture, model);

        translate = glm::translate(identityMatrix, glm::vec3(57.0f, -5.0f, -57.0f));
        scale = glm::scale(identityMatrix, glm::vec3(1.0f, 114.0f, 114.0f));
        model = translate * scale;
        texcube.drawCubeWithTexture(lightingShaderWithTexture, model);
        
        translate = glm::translate(identityMatrix, glm::vec3(-57.0f, -5.0f, -57.0f));
        scale = glm::scale(identityMatrix, glm::vec3(1.0f, 114.0f, 114.0f));
        model = translate * scale;
        texcube.drawCubeWithTexture(lightingShaderWithTexture, model);
        
        translate = glm::translate(identityMatrix, glm::vec3(57.0f, -5.0f, -57.0f));
        scale = glm::scale(identityMatrix, glm::vec3(1.0f, 114.0f, 114.0f));
        model = translate * scale;
        texcube.drawCubeWithTexture(lightingShaderWithTexture, model);

        translate = glm::translate(identityMatrix, glm::vec3(-57.0f, -5.0f, 57.0f));
        scale = glm::scale(identityMatrix, glm::vec3(1.0f, 114.0f, 114.0f));
        model = translate * scale;
        texcube.drawCubeWithTexture(lightingShaderWithTexture, model);

        translate = glm::translate(identityMatrix, glm::vec3(57.0f, -5.0f, 57.0f));
        scale = glm::scale(identityMatrix, glm::vec3(1.0f, 114.0f, 114.0f));
        model = translate * scale;
        texcube.drawCubeWithTexture(lightingShaderWithTexture, model);

        translate = glm::translate(identityMatrix, glm::vec3(-57.0f, -5.0f, 138.0f));
        scale = glm::scale(identityMatrix, glm::vec3(114.0f, 114.0f, 1.0f));
        model = translate * scale;
        texcube.drawCubeWithTexture(lightingShaderWithTexture, model);

        translate = glm::translate(identityMatrix, glm::vec3(-57.0f, 100.0f, -57.0f));
        scale = glm::scale(identityMatrix, glm::vec3(190.0f, 1.0f, 200.0f));
        model = translate * scale;
        texcube2.drawCubeWithTexture(lightingShaderWithTexture, model);

        glm::mat4 modelMatrixForContainer = glm::mat4(1.0f);
        modelMatrixForContainer = glm::translate(identityMatrix, glm::vec3(0.0f, 3.0f, 2.0f));
        //cube.drawCubeWithTexture(lightingShaderWithTexture, modelMatrixForContainer);
        // glfw: swap buffers and poll IO events (keys pressed/released, mouse moved etc.)
        // -------------------------------------------------------------------------------
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

