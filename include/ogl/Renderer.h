#ifndef RENDERER_H
#define RENDERER_H
#pragma once



#include "ogl/VertexArray.h"
#include "ogl/IndexBuffer.h"
//#include "VertexBuffer.h"
//#include "VertexBufferLayout.h"
#include "ogl/Shader.h"


class Renderer
{
    public:
        Renderer();
        virtual ~Renderer();

        void Draw(const VertexArray& va, const IndexBuffer& ib, const Shader& shader) const;
        void Clear() const;

    protected:

    private:
};

#endif // RENDERER_H
