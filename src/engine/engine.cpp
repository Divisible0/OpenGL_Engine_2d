#include "engine/engine.h"

Engine::Engine() {

    if (!glfwInit()) {
        std::cout << "GLFW didn't start" << std::endl;
        exit(EXIT_FAILURE);
    }

    //glfw version 3.3, core profile
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);

    window = glfwCreateWindow(WIDTH, HEIGHT, "Hello World!", NULL, NULL);

    if (!window) {
        std::cout << "Window Failed" << std::endl;
        glfwTerminate();
        exit(EXIT_FAILURE);
    }

    glfwMakeContextCurrent(window);
    glfwSwapInterval(0);
    glewExperimental = GL_TRUE;
        
    GLenum glewStatus = glewInit();
    if (glewStatus != GLEW_OK && glewStatus != GLEW_ERROR_NO_GLX_DISPLAY) {
        std::cout << "GLEW didn't start: " << glewGetErrorString(glewStatus) << std::endl;
        exit(EXIT_FAILURE);
    }

    int fbWidth, fbHeight;
    glfwGetFramebufferSize(window, &fbWidth, &fbHeight);
    glViewport(0, 0, fbWidth, fbHeight);

    glClearColor(0.05f, 0.05f, 0.05f, 1.0f);

    shader = make_shader(
        "../shaders/vertex.txt",
        "../shaders/fragment.txt"
    );

    //you won't believe this but this makes a triangle!
    triangle = new Triangle();
    triangle_fan = new Triangle_Fan();
    circle = new Circle(0.25f, 32);
}

Engine::~Engine() {
    
    delete triangle;
    delete triangle_fan;
    delete circle;
    glDeleteProgram(shader);
    glfwTerminate(); 
}

void Engine::run() {
    lastFrameTime = glfwGetTime();
    while (!glfwWindowShouldClose(window)) {

        float currentTime = glfwGetTime();
        float deltaTime = currentTime - lastFrameTime;
        deltaTime = std::min(deltaTime, 0.1f);
        lastFrameTime = currentTime;

        glClear(GL_COLOR_BUFFER_BIT);
        glUseProgram(shader);
        draw(deltaTime); //completely useless but clean... er... maybe?
        glfwSwapBuffers(window);
        glfwPollEvents();
    }
}

void Engine::draw(float dt) {
    triangle->update(dt); //this updates the triangle every frame!
    triangle_fan->update(dt);
    circle->update(dt);
    triangle->draw(shader); //this? you guessed it. it draws the triangle.
    triangle_fan->draw(shader);
    circle->draw(shader);
}