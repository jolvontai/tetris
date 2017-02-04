#pragma once
#include<GL\glew.h>
#include"helper_classes.h"


class Element2D
{
public:
	Element2D();
	~Element2D();
	virtual void render();
private:
	Vector2 pos;
	Vector2 size;
};
class Rect : public Element2D
{
public:
	Rect();
	~Rect();
	void render();
private:

};