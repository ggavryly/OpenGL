#pragma once
#include "main.hpp"
#include "Shader.hpp"
struct Character {
	GLuint     TextureID; // ID текстуры глифа
	glm::ivec2 Size;      // Размеры глифа
	glm::ivec2 Bearing;   // Смещение верхней левой точки глифа
	GLuint     Advance;   // Горизонтальное смещение до начала следующего глифа
};

class Text
{
public:
	Text();
	void terminateFreeType();
	void bindText();
	void unbindText();
	void displayMessage(std::string const &message, Rect rect, glm::vec3 const  &color, float const & scale);
	void loadCharacters();
	Text(Text const &);
	virtual ~Text();

public:
	std::map<GLchar, Character>	Characters;
	Shader						shader;
	FT_Face						face;
	FT_Library					ft;
	int 						font_size;
	GLuint						VBO;
	GLuint						VAO;
public:

	int getFontSize() const;

	void setFontSize(int fontSize);
};

