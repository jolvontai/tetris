#include<GL/glew.h>


class Triangle
{
    public:
    Triangle();
    ~Triangle();
    GLfloat getVertices();
    private:
    GLfloat vertices;
    GLuint VBO;
    GLuint vertexShader;
};