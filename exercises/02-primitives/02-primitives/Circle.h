#ifndef _CIRCLE_INCLUDE
#define _CIRCLE_INCLUDE


#include "ShaderProgram.h"
class Circle
{
	public:
		static Circle* createCircle(float x, float y, float rad, ShaderProgram& program);

		Circle(float x, float y, float rad, ShaderProgram& program);

		void render() const;
		void free();

	private:
		GLuint vao;
		GLuint vbo;
		GLint posLocation;
};




#endif