#pragma once

#include "..\Math\Algebra.h"
#include "Colour.h"
#include "ShaderProgram.h"

#define GLEW_STATIC
#include <GL/glew.h>

#include <vector>

class Texture;      // TODO should be specific per material, not per mesh

class Mesh
{
public:
    Mesh(std::string filename, const ShaderProgram & shaderProgram);

    void Render(Matrix4x4& transform);
    void Delete();

    void SetTexture(Texture* texture)       { m_texture = texture; }
    void SetColour(ColourRGB colour)        { m_colour = colour; }

private:

    Texture*    m_texture;          // TODO this should be per material
    ColourRGB   m_colour;           // TODO this should be per material

    GLint       m_uniModel;
    GLint       m_uniColour;

    GLuint      m_vao;
    GLuint      m_vboPosition;
    GLuint      m_vboNormal;
    GLuint      m_vboUV;
    GLuint      m_ebo;

    GLuint      m_shaderProgramID;
    GLint       m_positionAttrib;
    GLint       m_normalAttrib;
    GLint       m_texAttrib;

    GLfloat*    m_vertexPositionData;
    GLfloat*    m_vertexNormalData;
    GLfloat*    m_vertexUVData;
    GLsizei     m_vertexCount;

    GLuint*     m_elementData;
    GLsizei     m_elementDataCount;

    GLenum      m_drawMode;

    std::vector<Vector3> positions; // TODO don't need to store these
    std::vector<Vector3> normals;
    std::vector<Vector2> uvs;
    std::vector<GLuint>  indices;
};