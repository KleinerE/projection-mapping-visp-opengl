#ifndef TESTCUBE_H
#define TESTCUBE_H


#include "ogl/Renderer.h"
#include "ogl/VertexBufferLayout.h"
#include "ogl/Texture.h"

#include <iostream>

#include "glm/glm.hpp"
#include "glm/gtc/matrix_transform.hpp"
#include "glm/gtx/quaternion.hpp"

//namespace render {

    class CubeRenderer
    {
        public:
            CubeRenderer();
            virtual ~CubeRenderer();

            //void OnUpdate(float deltaTime);
            void OnRender();
            void OnImGuiRender();

            void SetTransform(glm::vec3 translation, glm::vec3 euler);
            void SetParameter(/*float Fval, */glm::vec3 Tval);
            //void OnDestruct();

            float m_fovy;
            glm::vec3 m_Procam_T, m_DeltaT;

        private:

            float m_VertPositions[5 * 4 * 6];
            unsigned int m_VertIndices[6 * 6];

            VertexArray m_VertexArray;
            VertexBuffer m_VertexBuffer;
            VertexBufferLayout m_VertexLayout;
            IndexBuffer m_IndexBuffer;
            Shader m_Shader;
            Texture m_Texture;
            Renderer m_Renderer;

            glm::mat4 m_MatProj, m_MatView;
            glm::mat4 m_Translation, m_Scale, m_Orientation;
            glm::vec3 m_TranslationVec, m_RotationVec;

            glm::mat4 m_Procam_R;




    };


//}

#endif // TESTCUBE_H
