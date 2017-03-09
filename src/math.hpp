#pragma once
/*#include<glm/glm.hpp>
#include<glm/gtc/matrix_transform.hpp>
#include<glm/gtc/type_ptr.hpp>*/
#include<math.h>

#define PI 3.14159265

class Vector2
{
public:
	float x;
	float y;
	Vector2(float x, float y) : x(x), y(y) {};
	Vector2() { x = 0; y = 0; }

	Vector2& operator+(Vector2 other)
	{
		x += other.x;
		y += other.y;
		return *this;
	}
	Vector2& operator-(Vector2 other)
	{
		x -= other.x;
		y -= other.y;
		return *this;
	}
	Vector2& operator=(float other)
	{
		x = y = other;
		return *this;
	}
	Vector2& operator+=(Vector2 other)
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
		float a1, a2, a3, a4;
		float b1, b2, b3, b4;
		float c1, c2, c3, c4;
		float d1, d2, d3, d4;
	}named;
	struct {
		float a[4];
		float b[4];
		float c[4];
		float d[4];
	}row;
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
	Vector2 scale;
	Vector2 translation;
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
	void Translate(Vector2 pos)
	{
		transformation->named.a4 = pos.x;
		transformation->named.b4 = pos.y;
		UpdateIdentity();
	}
	void Scale(Vector2 size)
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
	Vector2 GetScale() { return this->scale;}
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
		transformation->named.a1 = cos(rotation * (PI / 180)) * scale.x;
		transformation->named.a2 = -sin(rotation * (PI / 180)) * scale.y;
		transformation->named.b1 = sin(rotation * (PI / 180)) * scale.x;
		transformation->named.b2 = cos(rotation * (PI / 180)) * scale.y;
	}


	void ValD(float& deg)
	{
			int helper = deg / 360;
			deg -= helper * 360;
			if(deg < 0)
				deg = 360+deg;		
	}
};
