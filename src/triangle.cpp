#include "triangle.h"
#version 320 core

layout (location = 0) in vec3 position;

Triangle::Triangle()
{
    gl_Position = vec4(position.x,position.y,position.z,1.0);
    vertexShader = glCreateShader(GL_VERTEX_SHADER);
    glShaderSource(vertexShader, 1, &vertexShaderSource, NULL);
    glCompileShader(vertexShader);
    this->vertices[] = {
		-0.5f, -0.5f, 0.0f,
		 0.5f, -0.5f, 0.0f,
		 0.0f,  0.5f, 0.0f
	};
    glGenBuffers(1,&VBO);
    glBindBuffer(GL_ARRAY_BUFFER, VBO);
     
    glBufferData(GL_ARRAY_BUFFER, sizeof(this->vertices), vertices, GL_STaTIC_DRAW);

}
Triangle::~Triangle()
{

}
GLfloat Triangle::getVertices()
{
    return this->vertices;
}