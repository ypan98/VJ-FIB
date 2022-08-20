#include <GL/glew.h>
#include <GL/gl.h>
#include "Circle.h"
#include <iostream>
#include <vector>
#include <msxml.h>


Circle* Circle::createCircle(float x, float y, float rad, ShaderProgram& program)
{
	Circle *circle = new Circle(x, y, rad, program);
	return circle;
}

Circle::Circle(float x, float y, float rad, ShaderProgram& program)
{
	vector<float> v;
	float last_x = x + rad;
	float last_y = y;
	for (double i = 0.1; i <= 2.1; i = i + 0.1)
	{
		v.push_back(x);
		v.push_back(y);
		v.push_back(last_x);
		v.push_back(last_y);
		v.push_back(x + rad * (float)cos(i*3.14));
		v.push_back(y + rad * (float)sin(i * 3.14));
		last_x = x + rad * (float)cos(i * 3.14);
		last_y = y + rad * (float)sin(i * 3.14);
	}


	float vertices[20*6];
	cout << v.size();
	std::copy(v.begin(), v.end(), vertices);

	AllocConsole();
	freopen("CONOUT$", "w", stdout);
	freopen("CONOUT$", "w", stderr);
	
	glGenVertexArrays(1, &vao);
	glBindVertexArray(vao);
	glGenBuffers(1, &vbo);
	glBindBuffer(GL_ARRAY_BUFFER, vbo);
	glBufferData(GL_ARRAY_BUFFER, 20*6*sizeof(float), vertices, GL_STATIC_DRAW);
	posLocation = program.bindVertexAttribute("position", 2);
}

void Circle::render() const
{
	glBindVertexArray(vao);
	glEnableVertexAttribArray(posLocation);
	glDrawArrays(GL_TRIANGLES, 0, 120);
}

void Circle::free()
{
	glDeleteBuffers(1, &vbo);
}
