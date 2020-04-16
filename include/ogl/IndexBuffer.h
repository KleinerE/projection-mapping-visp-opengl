#ifndef INDEXBUFFER_H
#define INDEXBUFFER_H



class IndexBuffer
{
    public:
        IndexBuffer(const unsigned int* data, unsigned int count);
        virtual ~IndexBuffer();

        void Bind() const;
        void Unbind() const;

        inline unsigned int GetCount()  const { return m_Count; }

    protected:

    private:
        unsigned int m_RendererID;
        unsigned int m_Count;
};

#endif // INDEXBUFFER_H
