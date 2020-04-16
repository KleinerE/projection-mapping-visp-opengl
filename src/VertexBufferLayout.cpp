#include "VertexBufferLayout.h"
#include "Renderer.h"
#include "DebugManager.h"

VertexBufferLayout::VertexBufferLayout()
{
    //ctor
    m_Stride=0;
}

VertexBufferLayout::~VertexBufferLayout()
{
    //dtor
}


void VertexBufferLayout::Push(unsigned int type, unsigned int count)
{
    switch(type)
    {
        case GL_FLOAT:
            m_Elements.push_back( { count, GL_FLOAT, GL_FALSE });
            m_Stride += count * VertexBufferElement::GetSizeOfType(GL_FLOAT);
            break;

        case GL_UNSIGNED_INT:
            m_Elements.push_back( { GL_UNSIGNED_INT, count, GL_FALSE } );
            m_Stride += count * VertexBufferElement::GetSizeOfType(GL_UNSIGNED_INT);
            break;

        case GL_UNSIGNED_BYTE:
            m_Elements.push_back( { GL_UNSIGNED_BYTE, count, GL_TRUE } );
            m_Stride += count * VertexBufferElement::GetSizeOfType(GL_UNSIGNED_BYTE);
            break;
    }
}
