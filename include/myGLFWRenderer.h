#ifndef MYGLFWRENDERER_H
#define MYGLFWRENDERER_H

#include "ogl/CubeRenderer.h"
#include <GLFW/glfw3.h>

class myGLFWRenderer
{
    public:
        myGLFWRenderer(bool debugWindow);
        virtual ~myGLFWRenderer();

        void OnRender(glm::vec3 translation, glm::vec3 rotation);
        void SetParameter(/*float Fval, */glm::vec3 Tval);
        float GetParameterF();
        glm::vec3 GetParameterT();

        GLFWwindow* m_Window;


    protected:

    private:

        CubeRenderer* m_CubeRenderer;
        bool m_debugWindow;
};

#endif // MYGLFWRENDERER_H
