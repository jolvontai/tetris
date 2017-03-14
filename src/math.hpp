#pragma once
#include<glm/glm.hpp>
#include<glm/gtc/matrix_transform.hpp>
#include<glm/gtc/type_ptr.hpp>
#include<math.h>

#define PI 3.14159265

class Vec2
{
public:
	float x;
	float y;
	Vec2(float x, float y) : x(x), y(y) {};
	Vec2() { x = 0; y = 0; }

	Vec2& operator+(Vec2 other)
	{
		x += other.x;
		y += other.y;
		return *this;
	}
	Vec2& operator-(Vec2 other)
	{
		x -= other.x;
		y -= other.y;
		return *this;
	}
	Vec2& operator=(float other)
	{
		x = y = other;
		return *this;
	}
	Vec2& operator+=(Vec2 other)
	{
		x += other.x;
		y += other.y;
		return *this;
	}
};
union Mat4{
	Mat4() {
		for(int i = 0; i < 16;i++)
			array[i] = 0;
	}
	float array[16];
	struct {
		float a1, b1, c1, d1;
		float a2, b2, c2, d2;
		float a3, b3, c3, d3;
		float a4, b4, c4, d4;
	}named;
	struct {
		float a[4];
		float b[4];
		float c[4];
		float d[4];
	}row;
};
struct Ortho{
	Ortho() 
	{
		for(int i = 0; i < 16;i++)
			array[i] = 0;
		array[10] = 1;
		array[12] = -1;
		array[13] = -1;
		array[15] = 1;
	}
	void resize(float screenX, float screenY)
	{
		float factor;
		if(screenX < screenY)
			factor = 2 / screenX;
		else
			factor = 2 / screenY;
		array[0] = factor;
		array[5] = factor;

	}
	float array[16] = {};	
};
union Mat2 {
	Mat2() {
		for(int i = 0; i < 4;i++)
			array[i] = 0;
	}
	float array[4];
	struct {
		float a1, a2;
		float b1, b2;

	}named;
};


class Transform
{
private:
	Vec2 scale;
	Vec2 translation;
	Vec2 pos;
	float lastR;
	Mat2 rotM;
	Mat4* transformation;
public:
	float rotation;

	Transform()
	{
		transformation = new Mat4();
		scale = 1;
		translation = 0;
		lastR = rotation = 0;
		Format();
		rotM.array[0] = 1;
		rotM.array[3] = 1;
	}
	const float* GetTransformation()
	{
		if(lastR != rotation)
			UpdateIdentity();
		return this->transformation->array;
	}
	void Translate(Vec2 pos)
	{
		this->pos = pos;
		UpdateIdentity();
	}
	void Scale(Vec2 size)
	{
		scale.x = size.x;
		scale.y = size.y;
		
		UpdateIdentity();
	}
	void Scale(float size)
	{
		scale = size;
		UpdateIdentity();
	}
	Vec2 GetScale() { return this->scale;}
	void Rotate(float degX/*, Vector2 point*/)
	{
		rotation += degX;
		ValD(rotation);	
		lastR = rotation;
		UpdateIdentity();
	}
	void Format() 
	{
		transformation->named.a1 = 1.0f;
		transformation->named.a2 = 0.0f;
		transformation->named.b1 = 0.0f;
		transformation->named.b2 = 1.0f;
		transformation->named.c3 = 1.0f;
		transformation->named.d4 = 1.0f;
	}
	
private:
	void UpdateIdentity()
	{
		Format();
		UpdateTranslation();
		UpdateRotation();
		UpdateScale();
		
		
	}
	void UpdateTranslation()
	{
		transformation->named.a4 = pos.x;
		transformation->named.b4 = pos.y;
	}
	void UpdateScale()
	{
		transformation->named.a1 *= scale.x;
		transformation->named.a2 *= scale.y;
		transformation->named.b1 *= scale.x;
		transformation->named.b2 *= scale.y;
	}
	void UpdateRotation()
	{
		transformation->named.a1 *= cos(rotation * (PI / 180));
		transformation->named.a2 = sin(rotation * (PI / 180));
		transformation->named.b1 = -sin(rotation * (PI / 180));
		transformation->named.b2 *= cos(rotation * (PI / 180));
	}


	void ValD(float& deg)
	{
			int helper = deg / 360;
			deg -= helper * 360;
			if(deg < 0)
				deg = 360+deg;		
	}
};
