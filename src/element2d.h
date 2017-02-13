#pragma once
#include<GL/glew.h>
#include"helper_classes.h"



class Element2D
{
public:
	Element2D();
	~Element2D();
	virtual void render();
	virtual void setSize(float w, float h);
	virtual void setPos(float x, float y);
	virtual void setCol(GLfloat r,GLfloat g,GLfloat b,GLfloat a);

protected:
	Vector2 pos;
	Vector2 size;
	GLfloat* vertices;
	GLfloat r,g,b,a;
	GLfloat* texCoords;
	GLuint vertSize;
	GLuint* indices;
	GLuint indSize;

	GLuint VAO;
	GLuint VBO;
	GLuint EBO;
};
class Rect : public Element2D
{
public:
	//Rect();
	Rect(float posX, float posY, float sizeW, float sizeY);
	~Rect();
	void render();
private:

	

};