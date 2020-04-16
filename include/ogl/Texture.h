#ifndef TEXTURE_H
#define TEXTURE_H

#include "DebugManager.h"

class Texture
{
    public:
        Texture(const std::string& filePath);
        virtual ~Texture();

        void Bind(unsigned int slot = 0) const;
        void Unbind() const;

        inline int GetWidth() const { return m_Width; }
        inline int GetHeight() const { return m_Height; }

    protected:

    private:
        unsigned int m_RendererID;
        std::string m_FilePath;
        unsigned char* m_LocalBuffer;
        int m_Width, m_Height, m_BPP;

};

#endif // TEXTURE_H
