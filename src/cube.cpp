/*
 * cube.cpp
 *
 *  Created on: Nov 25, 2013
 *      Author: leo
 */

#include "cube.h"
#include <iostream>
using namespace std;


GLfloat cube::side_vertices[] = {
		// front base cube
		-0.5, -0.5,  0.5,
		 0.5, -0.5,  0.5,
		 0.5,  0.5,  0.5,
		-0.5,  0.5,  0.5,
		// back base cube
		-0.5, -0.5, -0.5,
		 0.5, -0.5, -0.5,
		 0.5,  0.5, -0.5,
		-0.5,  0.5, -0.5,

		// starting the side vertices
		-0.45f, -0.45f, -0.5001f,
		 0.45f, -0.45f, -0.5001f,
		 0.45f,	 0.45f, -0.5001f,
		 0.45f,  0.45f, -0.5001f,
		-0.45f,  0.45f, -0.5001f,
		-0.45f, -0.45f, -0.5001f,

		-0.45f, -0.45f,  0.5001f,
		 0.45f, -0.45f,  0.5001f,
		 0.45f,  0.45f,  0.5001f,
		 0.45f,  0.45f,  0.5001f,
		-0.45f,  0.45f,  0.5001f,
		-0.45f, -0.45f,  0.5001f,

		-0.5001f,  0.45f,  0.45f,
		-0.5001f,  0.45f, -0.45f,
		-0.5001f, -0.45f, -0.45f,
		-0.5001f, -0.45f, -0.45f,
		-0.5001f, -0.45f,  0.45f,
		-0.5001f,  0.45f,  0.45f,

	 	 0.5001f,  0.45f,  0.45f,
		 0.5001f,  0.45f, -0.45f,
		 0.5001f, -0.45f, -0.45f,
		 0.5001f, -0.45f, -0.45f,
		 0.5001f, -0.45f,  0.45f,
		 0.5001f,  0.45f,  0.45f,

		-0.45f, -0.5001f, -0.45f,
		 0.45f, -0.5001f, -0.45f,
		 0.45f, -0.5001f,  0.45f,
		 0.45f, -0.5001f,  0.45f,
		-0.45f, -0.5001f,  0.45f,
		-0.45f, -0.5001f, -0.45f,

		-0.45f,  0.5001f, -0.45f,
		 0.45f,  0.5001f, -0.45f,
		 0.45f,  0.5001f,  0.45f,
		 0.45f,  0.5001f,  0.45f,
		-0.45f,  0.5001f,  0.45f,
		-0.45f,  0.5001f, -0.45f,

};

GLfloat cube::side_colors[] = {
		// front base cube
		0.0, 0.0, 0.0,
		0.0, 0.0, 0.0,
		0.0, 0.0, 0.0,
		0.0, 0.0, 0.0,
		// back base cube
		0.0, 0.0, 0.0,
		0.0, 0.0, 0.0,
		0.0, 0.0, 0.0,
		0.0, 0.0, 0.0,

		// starting the side colors

		1.0, 1.0, 0.0,  //yellow
		1.0, 1.0, 0.0,  //yellow
		1.0, 1.0, 0.0,  //yellow
		1.0, 1.0, 0.0,  //yellow
		1.0, 1.0, 0.0,  //yellow
		1.0, 1.0, 0.0,  //yellow

		1.0, 1.0, 1.0,  //white
		1.0, 1.0, 1.0,  //white
		1.0, 1.0, 1.0,  //white
		1.0, 1.0, 1.0,  //white
		1.0, 1.0, 1.0,  //white
		1.0, 1.0, 1.0,  //white

		1.0, 0.5, 0.0, //orange
		1.0, 0.5, 0.0, //orange
		1.0, 0.5, 0.0, //orange
		1.0, 0.5, 0.0, //orange
		1.0, 0.5, 0.0, //orange
		1.0, 0.5, 0.0, //orange

		1.0, 0.0, 0.0,  //red
		1.0, 0.0, 0.0,  //red
		1.0, 0.0, 0.0,  //red
		1.0, 0.0, 0.0,  //red
		1.0, 0.0, 0.0,  //red
		1.0, 0.0, 0.0,  //red

		0.0, 1.0, 0.0,  //green
		0.0, 1.0, 0.0,  //green
		0.0, 1.0, 0.0,  //green
		0.0, 1.0, 0.0,  //green
		0.0, 1.0, 0.0,  //green
		0.0, 1.0, 0.0,  //green

		0.0, 0.0, 1.0,  //blue
		0.0, 0.0, 1.0,  //blue
		0.0, 0.0, 1.0,  //blue
		0.0, 0.0, 1.0,  //blue
		0.0, 0.0, 1.0,  //blue
		0.0, 0.0, 1.0,  //blue

};

GLushort cube::base_elements[] = {
		// front
		0, 1, 2, 2, 3, 0,
		// top
		3, 2, 6, 6, 7, 3,
		// back
		7, 6, 5, 5, 4, 7,
		// bottom
		4, 5, 1, 1, 0, 4,
		// left
		4, 0, 3, 3, 7, 4,
		// right
		1, 5, 6, 6, 2, 1, };

cube::cube(GLuint program, int offset_index) {
	// base cube elements
	glGenBuffers(1, &base_elements_ibo);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, base_elements_ibo);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(base_elements), base_elements, GL_STATIC_DRAW);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);


	// side vertices
	glGenBuffers(1, &pos_vbo);
	glBindBuffer(GL_ARRAY_BUFFER, pos_vbo);
	glBufferData(GL_ARRAY_BUFFER, sizeof(side_vertices), side_vertices, GL_STATIC_DRAW);

	GLint pos_attrib = glGetAttribLocation(program, "vPosition");
	glEnableVertexAttribArray(pos_attrib);
	glVertexAttribPointer(pos_attrib, 3, GL_FLOAT, GL_FALSE, 0,  0);

	// side colors
	glGenBuffers(1, &col_vbo);
	glBindBuffer(GL_ARRAY_BUFFER, col_vbo);
	glBufferData(GL_ARRAY_BUFFER, sizeof(side_colors), side_colors, GL_STATIC_DRAW);

	GLint col_attrib = glGetAttribLocation(program, "in_Color");
	glEnableVertexAttribArray(col_attrib);
	glVertexAttribPointer(col_attrib, 3, GL_FLOAT, GL_FALSE, 0, 0);

}

cube::cube() {
	col_vbo = pos_vbo = base_elements_ibo =-1;
}

cube::~cube() {
	glDeleteBuffers(1, &pos_vbo);
	glDeleteBuffers(1, &col_vbo);
	glDeleteBuffers(1, &base_elements_ibo);
}

void cube::draw(){
	//	 draw base using buffer element
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, base_elements_ibo);
	int size;  glGetBufferParameteriv(GL_ELEMENT_ARRAY_BUFFER, GL_BUFFER_SIZE, &size);
	glDrawElements(GL_TRIANGLES, size/sizeof(GLushort), GL_UNSIGNED_SHORT, 0);
	// draw sides
	glDrawArrays(GL_TRIANGLES, 8,36); // first 8 elements are used to draw the base cube
}
