#pragma once

#include <glmlv/filesystem.hpp>
#include <glmlv/GLFWHandle.hpp>
#include <glmlv/GLProgram.hpp>

class Application
{
public:
    Application(int argc, char** argv);

	~Application();

    int run();
private:
    const size_t m_nWindowWidth = 1280;
    const size_t m_nWindowHeight = 720;
    glmlv::GLFWHandle m_GLFWHandle{ m_nWindowWidth, m_nWindowHeight, "forward-renderer" }; // Note: the handle must be declared before the creation of any object managing OpenGL resource (e.g. GLProgram, GLShader)

    const glmlv::fs::path m_AppPath;
    const std::string m_AppName;
    const std::string m_ImGuiIniFilename;
    const glmlv::fs::path m_ShadersRootPath;
    
    GLuint m_frVBO[2] = {0};
    GLuint m_frIBO[2] = {0};
    GLuint m_frVAO[2] = {0};
    
    GLuint ulocMVPMat = 0;
	GLuint ulocMVMat = 0;
	GLuint ulocNormMat = 0;

    glmlv::GLProgram m_program;
};
