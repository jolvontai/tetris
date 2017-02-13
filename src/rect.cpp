#include "element2d.h"


Rect::Rect(float posX, float posY, float sizeW, float sizeY)
{
	float helperX = posX - (sizeW / 2);
	float helperY = posY - (sizeY / 2);
	vertices = new GLfloat[24] {
		helperX + sizeW, helperY, 0.0f,			1.0f, 0.0f, 0.0f,
		helperX + sizeW, helperY + sizeY ,0.0f,	0.0f, 1.0f, 0.0f,
		helperX, helperY + sizeY , 0.0f,		0.0f, 0.0f, 1.0f,
		helperX, helperY, 0.0f,					1.0f, 1.0f, 0.0f
	};
	vertSize = 24;
	indices = new GLuint[6]{
		0,1,3,
		1,2,3
	};
	texCoords = new GLfloat[8]{
		0.0f, 0.0f,
		1.0f, 0.0f,
		1.0f, 1.0f,
		0.0f, 1.0f
	};

	indSize = 6;

	glGenVertexArrays(1, &VAO);
	glGenBuffers(1, &VBO);
	glGenBuffers(1, &EBO);

	glBindVertexArray(VAO);
	
	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glBufferData(GL_ARRAY_BUFFER, vertSize * sizeof(GLfloat), vertices, GL_STATIC_DRAW);
	
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, indSize * sizeof(GLuint), indices, GL_STATIC_DRAW);

	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(GLfloat), (GLvoid*)0);
	glEnableVertexAttribArray(0);

	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(GLfloat), (GLvoid*)0);
	glEnableVertexAttribArray(1);

	glBindVertexArray(0);

}
Rect::~Rect()
{
	delete vertices;
	delete indices;
	glDeleteVertexArrays(1, &VAO);
	glDeleteBuffers(1, &VBO);
	glDeleteBuffers(1, &EBO);
}

void Rect::render()
{
	glBindVertexArray(VAO);
	glDrawElements(GL_TRIANGLES, indSize, GL_UNSIGNED_INT, 0);
	glBindVertexArray(0);
}
