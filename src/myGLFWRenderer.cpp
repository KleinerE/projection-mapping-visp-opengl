#include "myGLFWRenderer.h"

#include "imgui/imgui.h"
#include "imgui/imgui_impl_glfw.h"
#include "imgui/imgui_impl_opengl3.h"

myGLFWRenderer::myGLFWRenderer()
//:   m_Window {nullptr}, m_CubeRenderer {nullptr}
{

    if (!glfwInit())
        std::cout << "ERROR INITIALIZING GLFW LIBRARY" << std::endl;
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

        // Get second monitor
    int monitorsCount, monitorW, monitorH;
    GLFWmonitor** monitors = glfwGetMonitors(&monitorsCount);
    GLFWmonitor* activeMonitor = monitors[monitorsCount - 1];
    const GLFWvidmode* vm = glfwGetVideoMode(activeMonitor);
    monitorW = vm->width;
    monitorH = vm->height;
    std::cout << "Monitors: " << monitorsCount  << std::endl;
        // Create a windowed mode window and its OpenGL context
    //m_Window = glfwCreateWindow(640, 480, "Cube Render", NULL, NULL);
    m_Window = glfwCreateWindow(monitorW, monitorH, "my GLFW Renderer", activeMonitor, NULL);
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

    // Setup Dear ImGui context
    ImGui::CreateContext();
    ImGuiIO& io = ImGui::GetIO(); (void)io;
    ImGui::StyleColorsDark();
    //ImGui::StyleColorsClassic();
    ImGui_ImplGlfw_InitForOpenGL(m_Window, true);
    ImGui_ImplOpenGL3_Init(glsl_version);
}

myGLFWRenderer::~myGLFWRenderer()
{
    //dtor
    ImGui_ImplOpenGL3_Shutdown();
    ImGui_ImplGlfw_Shutdown();
    ImGui::DestroyContext();
    glfwTerminate();
}

void myGLFWRenderer::OnRender(glm::vec3 translation, glm::vec3 rotation)
{
    if (!glfwWindowShouldClose(m_Window))
    {
        glfwPollEvents();
        m_CubeRenderer->SetTransform(translation, rotation);
        m_CubeRenderer->OnRender();

        ImGui_ImplOpenGL3_NewFrame();
        ImGui_ImplGlfw_NewFrame();
        ImGui::NewFrame();
        m_CubeRenderer->OnImGuiRender();
        ImGui::Render();
        ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());

        glfwSwapBuffers(m_Window);
    }
}
