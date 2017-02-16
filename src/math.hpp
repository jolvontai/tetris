#pragma once
/*#include<glm/glm.hpp>
#include<glm/gtc/matrix_transform.hpp>
#include<glm/gtc/type_ptr.hpp>*/
#include<cmath>

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
	}
	Vector2& operator-(Vector2 other)
	{
		x -= other.x;
		y -= other.y;
	}
	Vector2& operator=(float other)
	{
		x = y = other;
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


class Transform
{
public:
	Mat4* trans = new Mat4();
	Transform() {
		format();
		scale = 1;
	}

	void format() {
		trans->named.a1 = 1.0f;
		trans->named.b2 = 1.0f;
		trans->named.c3 = 1.0f;
		trans->named.d4 = 1.0f;
	}
	void rotate(float degX, Vector2 point) {
		int tmp = PI;
		double temp = cos(1);
		trans->named.a1 = cos(1);
		trans->named.a2 = -sin(90);
		trans->named.b1 = sin(90);
		trans->named.b2 = cos(90);
	}
	
private:
	Vector2 scale;
};
