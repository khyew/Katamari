#pragma once

#define GLEW_STATIC
#include <GL/glew.h>

#include <fstream>

class Texture
{
public:
    Texture(std::string filename);

    void BindTexture();
    void FreeTexture();

    static Texture* DefaultTexture();

private:
    GLuint      m_id;
    std::string m_filename;

    static Texture* m_defaultTexture;
};