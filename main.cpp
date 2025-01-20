#include <iostream>
#include "headers/main.h"

using namespace std;


int main()
{
    // GLFW: initialize and configure
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);


    // GLFW window creation
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

    IMGUI_CHECKVERSION();
    ImGui::CreateContext();
    ImGuiIO& io = ImGui::GetIO(); (void)io;

    // Setup Dear ImGui style
    ImGui::StyleColorsDark();

    // Setup Platform/Renderer bindings
    ImGui_ImplGlfw_InitForOpenGL(window, true);
    ImGui_ImplOpenGL3_Init("#version 330");

    // Load Custom Font
    ImFont* customFont = ImGui::GetIO().Fonts->AddFontFromFileTTF("resources/fonts/KirangHaerang-Regular.ttf", 24.0f);
    if (customFont == nullptr) {
        std::cerr << "Failed to load font!" << std::endl;
    }
 
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
    
    glm::vec4 mapAmbient = glm::vec4(0.0, 1.0, 0.8, 1.0);
    glm::vec4 mapDiffusive = glm::vec4(0.0, 1.0, 0.8, 1.0);
    glm::vec4 mapSpecular = glm::vec4(0.0, 1.0, 0.8, 1.0);
    float mapShiny = 32.0f;


	Cube airplane = Cube(mapAmbient, mapDiffusive, mapSpecular, mapShiny);


    int score_circle_generation_iter = 5000;
    float minimum_z_of_point_circles = MAP_SIZE.z; //starting with max possible.
    int gen_step = 0;
    int game_points = 0;
    std::vector<int> collided_cube_indices;

	//= loadTexture("textures/road.jpg");
    std::string roadDiffuseMapPath = "resources/road_texture_edited.png";
    std::string roadSpecularMapPath = "resources/road_texture_edited.png";
    unsigned int roadDiffMap = loadTexture(roadDiffuseMapPath.c_str(), GL_REPEAT, GL_REPEAT, GL_LINEAR_MIPMAP_LINEAR, GL_LINEAR);
    unsigned int roadSpecMap = loadTexture(roadSpecularMapPath.c_str(), GL_REPEAT, GL_REPEAT, GL_LINEAR_MIPMAP_LINEAR, GL_LINEAR);

    gSoundPlayer = new SoundPlayer();
    if (!gSoundPlayer->loadWavFile("resources/audio/sound2.wav")) {
        printf("Failed to load sound file!\n");
        delete gSoundPlayer;
        gSoundPlayer = nullptr;
        return -1;
    }

	make_textures();

    // render loop
    // -----------
    while (!glfwWindowShouldClose(window))
    {
        float currentFrame = static_cast<float>(glfwGetTime());
        deltaTime = currentFrame - lastFrame;
        lastFrame = currentFrame;

        processInput(window);

        // Start the frame
        ImGui_ImplOpenGL3_NewFrame();
        ImGui_ImplGlfw_NewFrame();
        ImGui::NewFrame();

        // Use the custom font for the score text
        ImGui::PushFont(customFont);  // Activate custom font

        ImGui::Begin("Score");
        ImGui::Text("\t%d\t", game_points);  // Render the score
        ImGui::End();

        ImGui::PopFont();  // Revert back to default font

        glClearColor(0.53f, 0.81f, 0.98f, 1.0f);
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
		
        //Drawing the airplane
        translate = glm::translate(identityMatrix, PLANE_TRANSLATE_VECTOR);
        scale = glm::scale(identityMatrix, PLANE_SIZE);
        model = translate * scale;
        airplane.drawCubeWithMaterialisticProperty(lightingShader, model);

        //constantly move forward
        float velocity = PLANE_SPEED * deltaTime;
        camera.ProcessKeyboard(FORWARD, deltaTime);
        PLANE_TRANSLATE_VECTOR.z -= velocity;


        //generate new buildings when starting out
        if (left_building_cube_positions.empty() && right_building_cube_positions.empty()) {
			generateNewBuildings(true);
        }

        //Generate Collision Cube/Sphere so user can get points.
		if (collision_cube_positions.empty() || PLANE_TRANSLATE_VECTOR.z < (minimum_z_of_point_circles + 2.0f)) { //if the plane is near the minimum z value of the point circles
            float minZPossible = PLANE_TRANSLATE_VECTOR.z - MAP_SIZE.z + 10.0f;
            float maxZPossible = PLANE_TRANSLATE_VECTOR.z - 10.0f;
            
            //clear every 2nd generation to eliminate instant cube being taken out of map.
            if (gen_step == 2) { // Remove the first half of the items
                size_t half_size = collision_cube_positions.size() / 2;
                collision_cube_positions.erase(collision_cube_positions.begin(), collision_cube_positions.begin() + half_size);
				collided_cube_indices.clear();
                gen_step = 0;
            }
            
            auto new_collision_cubes = generate_collision_cube_position(
                maxZPossible, minZPossible, 0.3f, 3.0f, PLANE_BOUNDARY.first, PLANE_BOUNDARY.second);

            // Add the new items to the existing collection
            collision_cube_positions.insert(collision_cube_positions.end(), new_collision_cubes.begin(), new_collision_cubes.end());
            gen_step++;

            for (const glm::vec3& position : collision_cube_positions) {
                if (position.z < minimum_z_of_point_circles) {
                    minimum_z_of_point_circles = position.z; // Update the minimum Z value
                }
            }
        }

        //draw all new cubes
        for (int i = 0; i < collision_cube_positions.size(); ++i) {
            // Get the position of the cube
            glm::vec3 cubePosition = collision_cube_positions[i];

            // Create the translation and scale matrices
            glm::mat4 translate = glm::translate(identityMatrix, cubePosition);
            glm::mat4 scale = glm::scale(identityMatrix, glm::vec3(0.5f, 0.5f, 0.5f));
            glm::mat4 model = translate * scale;

            // Create the Cube object with materialistic properties
            Cube collision_cube = Cube(
                glm::vec4(0.1, 0.9, 0.6, 1.0),
                glm::vec4(0.1, 0.9, 0.6, 1.0),
                glm::vec4(0.1, 0.9, 0.6, 1.0),
                80.0f
            );

            // Draw the cube with the lighting shader and the model matrix
            collision_cube.drawCubeWithMaterialisticProperty(lightingShader, model);
        }


        //collision
        for (int i = 0; i < collision_cube_positions.size(); ++i) {
            // Skip if we've already collided with this cube
            if (std::find(collided_cube_indices.begin(), collided_cube_indices.end(), i) != collided_cube_indices.end()) {
                continue;
            }

            const glm::vec3& cubePosition = collision_cube_positions[i];
            float cubeMinX = cubePosition.x - 0.25f;
            float cubeMaxX = cubePosition.x + 0.25f;
            float cubeMinY = cubePosition.y - 0.25f;
            float cubeMaxY = cubePosition.y + 0.25f;
            float cubeMinZ = cubePosition.z - 0.25f;
            float cubeMaxZ = cubePosition.z + 0.25f;

            float planeMinX = PLANE_TRANSLATE_VECTOR.x - (PLANE_SIZE.x / 2);
            float planeMaxX = PLANE_TRANSLATE_VECTOR.x + (PLANE_SIZE.x / 2);
            float planeMinY = PLANE_TRANSLATE_VECTOR.y - (PLANE_SIZE.y / 2);
            float planeMaxY = PLANE_TRANSLATE_VECTOR.y + (PLANE_SIZE.y / 2);
            float planeMinZ = PLANE_TRANSLATE_VECTOR.z - (PLANE_SIZE.z / 2);
            float planeMaxZ = PLANE_TRANSLATE_VECTOR.z + (PLANE_SIZE.z / 2);

            if (planeMaxX > cubeMinX && planeMinX < cubeMaxX &&
                planeMaxY > cubeMinY && planeMinY < cubeMaxY &&
                planeMaxZ > cubeMinZ && planeMinZ < cubeMaxZ) {
                // Add this cube's index to collided indices
                collided_cube_indices.push_back(i);
                collision_cube_positions[i] = glm::vec3(10.0f, 10.0f, 100.0f); //remove from screen effect.
                gSoundPlayer->requestPlay();
                game_points++;
                // Add your collision response here
            }
        }




        //prevent from going below the map
        if (PLANE_TRANSLATE_VECTOR.y < 0.1f) {
			PLANE_TRANSLATE_VECTOR.y = 0.1f;
        }
		//prevent from going above the map
        if (PLANE_TRANSLATE_VECTOR.y > 20.0f) {
            PLANE_TRANSLATE_VECTOR.y = 20.0f;
        }
		if (PLANE_TRANSLATE_VECTOR.x < PLANE_BOUNDARY.first) {
			PLANE_TRANSLATE_VECTOR.x = PLANE_BOUNDARY.first;
		}
		if (PLANE_TRANSLATE_VECTOR.x > PLANE_BOUNDARY.second) {
			PLANE_TRANSLATE_VECTOR.x = PLANE_BOUNDARY.second;
		}

        //std::cout << "PLANE Z " << PLANE_TRANSLATE_VECTOR.z << std::endl;
        //std::cout << "MAP Z " << MAP_TRANSLATE_VECTOR.z << std::endl;
        /*bool tr = int(PLANE_TRANSLATE_VECTOR.z) == 40;
        std::cout << int(PLANE_TRANSLATE_VECTOR.z) << std::endl;*/
        if (isPlaneAtNPercent()) {
            updateMapNewZPosition();
			generateNewBuildings(false);
        }

        // we now draw as many light bulbs as we have point lights.
        glBindVertexArray(lightCubeVAO);
        for (unsigned int i = 0; i < 0; i++)
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


        //Drawing the map cube
        create_map(MAP_SIZE, MAP_TRANSLATE_VECTOR, lightingShaderWithTexture, roadDiffMap, roadSpecMap, 32.0f);

        //draw building
        drawBuildings(lightingShaderWithTexture);


        LOOP_ITER++;

        ImGui::Render();
        ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());

        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    glDeleteVertexArrays(1, &cubeVAO);
    glDeleteVertexArrays(1, &lightCubeVAO);
    glDeleteBuffers(1, &cubeVBO);
    glDeleteBuffers(1, &cubeEBO);


    ImGui_ImplOpenGL3_Shutdown();
    ImGui_ImplGlfw_Shutdown();
    ImGui::DestroyContext();

    glfwTerminate();
    return 0;
}


/*
    Process Input
*/


void framebuffer_size_callback(GLFWwindow* window, int width, int height)
{
    // make sure the viewport matches the new window dimensions; note that width and
    // height will be significantly larger than specified on retina displays.
    glViewport(0, 0, width, height);
}


// glfw: whenever the mouse moves, this callback is called
// -------------------------------------------------------
void mouse_callback(GLFWwindow* window, double xposIn, double yposIn)
{
    float xpos = static_cast<float>(xposIn);
    float ypos = static_cast<float>(yposIn);

    if (firstMouse)
    {
        lastX = xpos;
        lastY = ypos;
        firstMouse = false;
    }

    float xoffset = xpos - lastX;
    float yoffset = lastY - ypos; // reversed since y-coordinates go from bottom to top

    lastX = xpos;
    lastY = ypos;

    camera.ProcessMouseMovement(xoffset, yoffset);
}

// glfw: whenever the mouse scroll wheel scrolls, this callback is called
// ----------------------------------------------------------------------
void scroll_callback(GLFWwindow* window, double xoffset, double yoffset)
{
    std::cout << "scrolling " << std::endl;
    camera.ProcessMouseScroll(static_cast<float>(yoffset));
}


void processInput(GLFWwindow* window)
{
    float velocity = PLANE_SPEED * deltaTime;
    if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
        glfwSetWindowShouldClose(window, true);

    /*if (glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS) {
        camera.ProcessKeyboard(FORWARD, deltaTime);
        PLANE_TRANSLATE_VECTOR.z -= velocity;
    }*/
    /*if (glfwGetKey(window, GLFW_KEY_S) == GLFW_PRESS) {
        camera.ProcessKeyboard(BACKWARD, deltaTime);
        PLANE_TRANSLATE_VECTOR.z += velocity;
    }*/
    if (glfwGetKey(window, GLFW_KEY_A) == GLFW_PRESS) {
        //camera.ProcessKeyboard(LEFT, deltaTime);
        PLANE_TRANSLATE_VECTOR.x -= velocity * 3;
    }
    if (glfwGetKey(window, GLFW_KEY_D) == GLFW_PRESS) {
        //camera.ProcessKeyboard(RIGHT, deltaTime);
        PLANE_TRANSLATE_VECTOR.x += velocity * 3;
    }
    if (glfwGetKey(window, GLFW_KEY_L) == GLFW_PRESS) {
        camera.ProcessKeyboard(YAWR, deltaTime);
    }
    if (glfwGetKey(window, GLFW_KEY_J) == GLFW_PRESS) {
        camera.ProcessKeyboard(YAWL, deltaTime);
    }
    if (glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS) {
        //camera.ProcessKeyboard(PITCHU, deltaTime * 3);
        PLANE_TRANSLATE_VECTOR.y += velocity * 3;
    }
    if (glfwGetKey(window, GLFW_KEY_S) == GLFW_PRESS) {
        //camera.ProcessKeyboard(PITCHD, deltaTime);
        PLANE_TRANSLATE_VECTOR.y -= velocity * 3;
    }
}


void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods)
{
    if (key == GLFW_KEY_1 && action == GLFW_PRESS)
    {
        if (pointLightOn)
        {
            pointlight1.turnOff();
            pointlight2.turnOff();
            pointlight3.turnOff();
            pointlight4.turnOff();
            pointLightOn = !pointLightOn;
        }
        else
        {
            pointlight1.turnOn();
            pointlight2.turnOn();
            pointlight3.turnOn();
            pointlight4.turnOn();
            pointLightOn = !pointLightOn;
        }
    }


    else if (glfwGetKey(window, GLFW_KEY_2) == GLFW_PRESS)
    {
        if (specularToggle)
        {

            pointlight1.turnSpecularOff();
            pointlight2.turnSpecularOff();
            pointlight3.turnSpecularOff();
            pointlight4.turnSpecularOff();

            specularToggle = !specularToggle;
        }
        else
        {

            pointlight1.turnSpecularOn();
            pointlight2.turnSpecularOn();
            pointlight3.turnSpecularOn();
            pointlight4.turnSpecularOn();
            specularToggle = !specularToggle;
        }
    }

    else if (glfwGetKey(window, GLFW_KEY_3) == GLFW_PRESS)
    {
        if (diffuseToggle)
        {

            pointlight1.turnDiffuseOff();
            pointlight2.turnDiffuseOff();
            pointlight3.turnDiffuseOff();
            pointlight4.turnDiffuseOff();
            diffuseToggle = !diffuseToggle;
        }
        else
        {

            pointlight1.turnDiffuseOn();
            pointlight2.turnDiffuseOn();
            pointlight3.turnDiffuseOn();
            pointlight4.turnDiffuseOn();
            diffuseToggle = !diffuseToggle;
        }
    }

    else if (glfwGetKey(window, GLFW_KEY_4) == GLFW_PRESS)
    {
        if (ambientToggle)
        {

            pointlight1.turnAmbientOff();
            pointlight2.turnAmbientOff();
            pointlight3.turnAmbientOff();
            pointlight4.turnAmbientOff();
            ambientToggle = !ambientToggle;
        }
        else
        {

            pointlight1.turnAmbientOn();
            pointlight2.turnAmbientOn();
            pointlight3.turnAmbientOn();
            pointlight4.turnAmbientOn();
            ambientToggle = !ambientToggle;
        }
    }

    else if (glfwGetKey(window, GLFW_KEY_5) == GLFW_PRESS)
    {
        if (spotLightOn)
        {

            spotlight.turnOff();
            spotLightOn = !spotLightOn;
        }
        else
        {
            spotlight.turnOn();
            spotLightOn = !spotLightOn;
        }
    }

    else if (glfwGetKey(window, GLFW_KEY_N) == GLFW_PRESS)
    {
        if (dayLightOn)
        {

            daylight.turnOff();
            dayLightOn = false;
        }
        else
        {
            daylight.turnOn();
            dayLightOn = true;
        }
    }

    else if (glfwGetKey(window, GLFW_KEY_M) == GLFW_PRESS)
    {
        if (moonLightOn)
        {

            moonlight.turnOff();
            moonLightOn = !moonLightOn;
        }
        else
        {
            moonlight.turnOn();
            moonLightOn = !moonLightOn;
        }
    }
}