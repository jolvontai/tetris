#pragma once
#include<GL/glew.h>
#include"math.hpp"


class Element2D
{
public:
	Element2D();
	~Element2D();
	virtual void render();
	virtual void setSize(float w, float h);
	virtual void setPos(float x, float y);
	virtual void setCol(GLfloat r,GLfloat g,GLfloat b,GLfloat a);
	Transform transform;
protected:
	Vector2 size;
	Vector2 pos;
	GLfloat* vertices;
	GLfloat r,g,b,a;
	GLfloat* texCoords;
	GLuint vertSize;
	GLuint* indices;
	GLuint indSize;
	
	GLuint VAO;
	GLuint VBO;
	GLuint EBO;
	GLuint tID;
};
class Rect : public Element2D
{
public:
	//Rect();
	Rect(float posX, float posY, float sizeW, float sizeY, GLuint tID);
	~Rect();
	void render();
private:

	

};