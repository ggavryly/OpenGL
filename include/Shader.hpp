#pragma once
#include "main.hpp"

class Shader
{
public:
	Shader();
	Shader(const GLchar* vertexPath, const GLchar* fragmentPath);
	
	Shader(Shader const &) = default;
	
	~Shader();
public:
	// Идентификатор программы
	GLuint Program;
	// Использование программы
	void Use();
};


