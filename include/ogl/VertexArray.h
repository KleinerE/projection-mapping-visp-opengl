#ifndef VERTEXARRAY_H
#define VERTEXARRAY_H


#include "VertexBuffer.h"


class VertexBufferLayout;

class VertexArray
{
    public:
        VertexArray();
        virtual ~VertexArray();

        void AddBuffer(const VertexBuffer& vb, const VertexBufferLayout& layout);

        void Bind() const;
        void Unbind() const;

    protected:

    private:
        unsigned int m_RendererID;
};

#endif // VERTEXARRAY_H
