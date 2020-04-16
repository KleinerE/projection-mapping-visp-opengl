#ifndef MYGLFWRENDERER_H
#define MYGLFWRENDERER_H

#include "ogl/CubeRenderer.h"

class myGLFWRenderer
{
    public:
        myGLFWRenderer();
        virtual ~myGLFWRenderer();

        void OnRender(glm::vec3 translation, glm::vec3 rotation);

        GLFWwindow* m_Window;

    protected:

    private:

        CubeRenderer* m_CubeRenderer;
};

#endif // MYGLFWRENDERER_H
