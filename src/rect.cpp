#include "element2d.h"
#include <iostream>

Rect::Rect(float posX, float posY, float sizeW, float sizeY,GLuint tID)
{
	this->tID = tID;
	float helperX = posX - (sizeW / 2);
	float helperY = posY - (sizeY / 2);
	vertices = new GLfloat[32] {
		helperX + sizeW, helperY, 0.0f,			1.0f, 0.0f, 0.0f,	1.0f, 1.0f,
		helperX + sizeW, helperY + sizeY ,0.0f,	0.0f, 1.0f, 0.0f,	1.0f, 0.0f,
		helperX, helperY + sizeY , 0.0f,		0.0f, 0.0f, 1.0f,	0.0f, 0.0f,
		helperX, helperY, 0.0f,					1.0f, 1.0f, 0.0f,	0.0f, 1.0f
	};
	transform.Format();
	vertSize = 32;
	indices = new GLuint[6]{
		0,1,3,
		1,2,3
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

	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(GLfloat), (GLvoid*)0);
	glEnableVertexAttribArray(0);

	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(GLfloat), (GLvoid*)(3 * sizeof(GLfloat)));
	glEnableVertexAttribArray(1);

	glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, 8 * sizeof(GLfloat), (GLvoid*)(6 * sizeof(GLfloat)));
	glEnableVertexAttribArray(2);
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
	glActiveTexture(GL_TEXTURE0);
	glBindTexture(GL_TEXTURE_2D, tID);
	glBindVertexArray(VAO);
	glDrawElements(GL_TRIANGLES, indSize, GL_UNSIGNED_INT, 0);
	glBindVertexArray(0);
}
