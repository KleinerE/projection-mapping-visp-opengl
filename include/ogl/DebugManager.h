#ifndef DEBUGMANAGER_H
#define DEBUGMANAGER_H

#include <iostream>
#include <assert.h>
#include <GL/glew.h>
#define ASSERT(x)   assert(x);
#define GLCALL(x)   GLClearError();\
                    x;\
                    ASSERT(GLLogCall( #x, __FILE__, __LINE__))

void GLClearError();

bool GLLogCall(const char* function, const char* file, int line);

template <typename T>
void GLDebugOut(const std::string& name, T value)
{
    std::cout << name << ": " << value << std::endl;
}

class DebugManager
{
    public:
        DebugManager();
        virtual ~DebugManager();

    protected:

    private:
};

#endif // DEBUGMANAGER_H
