#pragma once
#include<GL/glew.h>
#include"math.hpp"


class Element2D
{
public:
	Element2D();
	virtual ~Element2D();
	virtual void render();
	virtual void setSize(float w, float h);
	virtual void setPos(float x, float y);
	virtual void setCol(GLfloat r,GLfloat g,GLfloat b,GLfloat a);
	Transform transform;
protected:
	Vec2 size;
	Vec2 pos;
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
	float posX = 0;
	float posY = 0;
	void Biggen()
	{
		this->transform.Scale(1.5);
	}
	void Smallen()
	{
		this->transform.Scale(1.0f);
	}
	void RotateL()
	{
		this->transform.Rotate(-1.0f);
	}
	void MoveR()
	{
		this->transform.Translate(Vec2(posX,posY));
		posX += 5.0f;
	}
private:

	

};