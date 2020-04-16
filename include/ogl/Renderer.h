#ifndef RENDERER_H
#define RENDERER_H
#pragma once



#include "VertexArray.h"
#include "IndexBuffer.h"
//#include "VertexBuffer.h"
//#include "VertexBufferLayout.h"
#include "Shader.h"


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
