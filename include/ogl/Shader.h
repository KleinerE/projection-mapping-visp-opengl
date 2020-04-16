#ifndef SHADER_H
#define SHADER_H

#include <string>
#include <fstream>
#include <sstream>
#include <unordered_map>

#include <glm/glm.hpp>

struct ShaderProgramSource
{
    std::string VertexSource;
    std::string FragmentSource;
};


class Shader
{
    public:
        Shader(const std::string& filepath);
        virtual ~Shader();

        void Bind() const;
        void Unbind() const;

        //Set uniforms
        void SetUniformMat4f(const std::string& name, const glm::mat4& mat);
        void SetUniform4f(const std::string& name, float v0, float v1, float v2, float v3);
        void SetUniform1f(const std::string& name, float value);
        void SetUniform1i(const std::string& name, int value);

    protected:

    private:
        std::string m_FilePath;
        unsigned int m_RendererID;
        std::unordered_map<std::string, int> m_UniformLocationCache;

        unsigned int GetUniformLocation(const std::string& name);
        unsigned int CreateShader(const std::string& vertexShader, const std::string& fragmentShader);
        unsigned int CompileShader(unsigned int type, const std::string& source);
        ShaderProgramSource ParseShader(const std::string& filepath);

};

#endif // SHADER_H
