#ifndef TESTCUBE_H
#define TESTCUBE_H

#include "Test.h"

#include "Renderer.h"
#include "VertexBufferLayout.h"
#include "Texture.h"

#include "glm/glm.hpp"
#include "glm/gtc/matrix_transform.hpp"

namespace test {

    class TestCube : public Test
    {
        public:
            TestCube();
            ~TestCube();

            void OnUpdate(float deltaTime);
            void OnRender();
            void OnImGuiRender();
            void OnDestruct();

        private:
            float m_VertPositions[5 * 4 * 6];
            unsigned int m_VertIndices[6 * 6];

            VertexArray m_VertexArray;
            VertexBuffer m_VertexBuffer; //(positions, 4 * 4 * sizeof(float));
            VertexBufferLayout m_VertexLayout;
            IndexBuffer m_IndexBuffer; //(indices, 6);
            Shader m_Shader; //("res/Basic.shader");
            Texture m_Texture; //("res/batman-logo-1.png");
            Renderer m_Renderer;

            glm::mat4 m_MatProj, m_MatView; // glm::ortho(-2.0f, 2.0f, -1.5f, 1.5f, -1.0f, 1.0f);
            glm::vec3 m_Translation, m_RotationAngles, m_Scale;
            //glm::mat4 view = glm::translate(glm::mat4(1.0f), glm::vec3(0.0f, 0.0f, 0.0f));

    };


}

#endif // TESTCUBE_H
