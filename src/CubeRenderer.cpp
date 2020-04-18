#include "ogl/CubeRenderer.h"
#include <GL/glew.h>
#include "ogl/DebugManager.h"

#include "imgui/imgui.h"
#include "glm/gtx/euler_angles.hpp"



//namespace render {

    CubeRenderer::CubeRenderer()
        :   m_VertPositions     {   -1.f, -1.f, -1.f,  0.25f, 0.33f, // 0
                                     1.f, -1.f, -1.f,  0.5f,  0.33f, // 1
                                     1.f,  1.f, -1.f,  0.5f,  0.66f, // 2
                                    -1.f,  1.f, -1.f,  0.25f, 0.66f, // 3

                                     1.f, -1.f, -1.f,  0.5f,  0.33f, // 1
                                     1.f, -1.f,  1.f,  0.75f, 0.33f, // 5
                                     1.f,  1.f,  1.f,  0.75f, 0.66f, // 6
                                     1.f,  1.f, -1.f,  0.5f,  0.66f, // 2

                                     1.f, -1.f,  1.f,  0.75f, 0.33f, // 5
                                    -1.f, -1.f,  1.f,  1.0f,  0.33f, // 4
                                    -1.f,  1.f,  1.f,  1.0f,  0.66f, // 7
                                     1.f,  1.f,  1.f,  0.75f, 0.66f, // 6

                                    -1.f, -1.f,  1.f,  0.0f,  0.33f, // 4
                                    -1.f, -1.f, -1.f,  0.25f, 0.33f, // 0
                                    -1.f,  1.f, -1.f,  0.25f, 0.66f, // 3
                                    -1.f,  1.f,  1.f,  0.0f,  0.66f, // 7

                                    -1.f,  1.f, -1.f,  0.25f, 0.66f, // 3
                                     1.f,  1.f, -1.f,  0.5f,  0.66f, // 2
                                     1.f,  1.f,  1.f,  0.5f,  1.0f,  // 6
                                    -1.f,  1.f,  1.f,  0.25f, 1.0f,  // 7

                                    -1.f, -1.f,  1.f,  0.25f, 0.0f, // 4
                                     1.f, -1.f,  1.f,  0.5f,  0.0f, // 5
                                     1.f, -1.f, -1.f,  0.5f,  0.33f, // 1
                                    -1.f, -1.f, -1.f,  0.25f, 0.33f    }, // 0

            m_VertIndices       {   0, 1, 2,
                                    2, 3, 0,
                                    4, 5, 6,
                                    6, 7, 4,
                                    8, 9, 10,
                                    10, 11, 8,
                                    12, 13, 14,
                                    14, 15, 12,
                                    16, 17, 18,
                                    18, 19, 16,
                                    20, 21, 22,
                                    22, 23, 20     },

            m_VertexBuffer(m_VertPositions, sizeof(m_VertPositions)),
            m_IndexBuffer(m_VertIndices, (int)(sizeof(m_VertIndices)/sizeof(*m_VertIndices))),
            m_Shader("model/cube/Cube.shader"),
            m_Texture("model/cube/cubemap-wr.png"),
            //m_MatProj           {   glm::perspective(glm::radians(70.0f), 4.f/3.f, 0.01f, 10.0f) },
            m_MatProj           {   glm::perspective(42.0f, 16.f/9.f, 0.01f, 10.0f) },
            //m_MatView           {   glm::translate(glm::mat4(1.0f), glm::vec3(0.0f, 0.0f, 0.0f)) },
            m_MatView           {   glm::lookAt(glm::vec3(0.0f, 0.0f, 0.0f), glm::vec3(0.0f, 0.0f, 5.0f), glm::vec3(0.0f, 1.0f, 0.0f)) },
            m_Translation       {   glm::translate(glm::mat4(1.0f), glm::vec3(0.0f, 0.0f, 0.0f)) },
            m_Orientation       {   glm::eulerAngleXYZ(0.0f, 0.0f, 0.0f) },
            m_Scale             {   glm::scale(glm::mat4(1.0f), glm::vec3(0.092f, 0.092f, 0.022f)) },

            m_Procam_R          {   glm::mat4(1.0f)},
            m_Procam_T          {   glm::vec3(-0.0471192f, -0.0262709f, 0.0220152f)}
    {
        //ctor
        m_VertexLayout.Push(GL_FLOAT, 3);
        m_VertexLayout.Push(GL_FLOAT, 2);
        m_VertexArray.AddBuffer(m_VertexBuffer, m_VertexLayout);
        m_Shader.Bind();
        m_Texture.Bind(0);
        m_Shader.SetUniform1i("u_Texture", 0);
        std::cout << "Initialized CubeRenderer" << std::endl;

        glm::mat4 rmat = glm::mat4(1.0f);
        rmat[0][0] =  0.9985f;
        rmat[0][1] = -0.0040f;
        rmat[0][2] = -0.0037f;
        rmat[1][0] =  0.0038f;
        rmat[1][1] =  0.9970f;
        rmat[1][2] = -0.0067f;
        rmat[2][0] =  0.0039f;
        rmat[2][1] =  0.0066f;
        rmat[2][2] =  0.9971f;
        m_Procam_R = glm::transpose(rmat);
        glm::mat4 tmat = glm::translate(glm::mat4(1.0), m_Procam_T);
        m_MatView = tmat * rmat * m_MatView;

        m_Renderer.Clear();
    }

    CubeRenderer::~CubeRenderer()
    {
        //dtor
        //m_Renderer.Clear();

    }
/*
    void CubeRenderer::OnUpdate(float deltaTime)
    {



    }
*/
    void CubeRenderer::OnRender()
    {
        m_Renderer.Clear();
        GLCALL(glClearColor(0.5f, 0.7f, 1.0f, 1.0f));

        m_Shader.Bind();

        {
        /*
            glm::mat4 model =   glm::scale(glm::rotate(glm::rotate(glm::rotate(glm::translate(glm::mat4(1.0f), m_Translation),
                                                                                m_Rotation.x, glm::vec3(1.0f, 0.0f, 0.0f)),
                                                                    m_Rotation.y, glm::vec3(0.0f, 1.0f, 0.0f)),
                                                        m_Rotation.z, glm::vec3(0.0f, 0.0f, 1.0f)),
                                            m_Scale);
        */
            glm::mat4 model = m_Translation * m_Orientation * m_Scale;
            glm::mat4 mvp = m_MatProj * m_MatView * model;
            m_Shader.SetUniformMat4f("u_MVP", mvp);
            m_Renderer.Draw(m_VertexArray, m_IndexBuffer, m_Shader);
        }
    }

    void CubeRenderer::OnImGuiRender()
    {

        ImGui::Begin("Cube Transform");                          // Create a window called "Hello, world!" and append into it.
        ImGui::SliderFloat3("translation", &m_TranslationVec.x, -.3f, .3f);
        //ImGui::SliderFloat4("rotation", &m_Orientation.x, -5.0f, 5.0f);
        //ImGui::SliderFloat3("scale", &m_Scale.x, 0.1f, 5.0f);
        ImGui::Text("Application average %.3f ms/frame (%.1f FPS)", 1000.0f / ImGui::GetIO().Framerate, ImGui::GetIO().Framerate);

        ImGui::End();
    }
/*
    void CubeRenderer::OnDestruct()
    {
        m_Renderer.Clear();
        glfwTerminate();
        delete this;
    }
*/
    void CubeRenderer::SetTransform(glm::vec3 translation, glm::vec3 euler)
    {
        m_Translation = glm::translate(glm::mat4(1.0f), translation);
        glm::mat4 Rx = glm::eulerAngleX(euler.x);
        glm::mat4 Ry = glm::eulerAngleY(euler.y);
        glm::mat4 Rz = glm::eulerAngleZ(euler.z);
        m_Orientation = Rz * Ry * Rx;

        //For Debug Purposes
        m_TranslationVec = translation;
    }
//}
