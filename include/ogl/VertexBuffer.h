#ifndef VERTEXBUFFER_H
#define VERTEXBUFFER_H


class VertexBuffer
{
    public:
        //VertexBuffer();
        VertexBuffer(const void* data, unsigned int size);
        virtual ~VertexBuffer();

        void Bind() const;
        void Unbind() const;

    protected:

    private:
        unsigned int m_RendererID;
};

#endif // VERTEXBUFFER_H
