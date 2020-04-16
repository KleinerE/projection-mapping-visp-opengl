#include "myGLFWRenderer.h"

myGLFWRenderer::myGLFWRenderer()
//:   m_Window {nullptr}, m_CubeRenderer {nullptr}
{

    if (!glfwInit())
        std::cout << "ERROR INITIALIZING GLFW LIBRARY" << std::endl;
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
        // Create a windowed mode window and its OpenGL context
    //m_Window = glfwCreateWindow(640, 480, "Cube Render", NULL, NULL);
    m_Window = glfwCreateWindow(640, 360, "Cube Render", NULL, NULL);
    if (!m_Window)
    {
        glfwTerminate();
        std::cout << "ERROR INITIALIZING GLFW WINDOW" << std::endl;
    }
        // Make the window's context current
    glfwMakeContextCurrent(m_Window);
    glfwSwapInterval(1);
    if (glewInit() != GLEW_OK)
        std::cout << "Error!" << std::endl;
    const char* glsl_version = "#version 130";
    std::cout << glGetString(GL_VERSION) << std::endl;

    m_CubeRenderer = new CubeRenderer();
}

myGLFWRenderer::~myGLFWRenderer()
{
    //dtor
    glfwTerminate();
}

void myGLFWRenderer::OnRender(glm::vec3 translation, glm::vec3 rotation)
{
    if (!glfwWindowShouldClose(m_Window))
    {
         glfwPollEvents();
         m_CubeRenderer->OnRender(translation, rotation);
         glfwSwapBuffers(m_Window);
    }
}
