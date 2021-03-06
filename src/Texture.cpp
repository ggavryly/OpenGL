#include "Texture.hpp"

Texture::Texture(std::string const &path, Rect const &rect)
{
	shader = Shader("../shaders/vertex_shader_texture", "../shaders/fragment_shader_texture");
	shader.Use();
	loadTexture(path, rect);
}

Texture::Texture(Texture const &)
{}

Texture::Texture()
{
	shader = Shader("../shaders/vertex_shader_texture", "../shaders/fragment_shader_texture");
	shader.Use();
}

Texture::~Texture()
{
//	unloadTexture();
}

void Texture::unloadTexture()
{
	SOIL_free_image_data(image);
	glDeleteBuffers(1, &VBO);
	glDeleteVertexArrays(1, &VAO);
	glDeleteBuffers(1, &EBO);
	glDeleteTextures(1, &texture);
}

void Texture::loadTexture(std::string const &path, Rect const &rect)
{
	if (texture != -1)
		unloadTexture();
	GLfloat vertices[] = {
			rect.x1,  rect.y0, 0.0f,   1.0f, 1.0f,   // Верхний правый
			rect.x1, rect.y1, 0.0f,   1.0f, 0.0f,   // Нижний правый
			rect.x0, rect.y1, 0.0f,  0.0f, 0.0f,   // Нижний левый
			rect.x0,  rect.y0, 0.0f,  0.0f, 1.0f    // Верхний левый
	};
	GLuint indices[] = {
			0, 1, 3,
			1, 2, 3
	};
	texture_rect = rect;
	glGenBuffers(1, &VBO);
	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
	glGenVertexArrays(1, &VAO);
	glBindVertexArray(VAO);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 5 * sizeof(GLfloat), (GLvoid*)0);
	glEnableVertexAttribArray(0);
	glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 5 * sizeof(GLfloat), (GLvoid*)(3 * sizeof(float)));
	glEnableVertexAttribArray(1);
	glGenBuffers(1, &EBO);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);
	image = SOIL_load_image(path.c_str(),&width, &height, 0, SOIL_LOAD_RGB);
	glGenTextures(1, &texture);
	glBindTexture(GL_TEXTURE_2D, texture);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, image);
	glGenerateMipmap(GL_TEXTURE_2D);
}

void Texture::bindTexture()
{
	shader.Use();
	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glBindVertexArray(VAO);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
	glBindTexture(GL_TEXTURE_2D, texture);
}

void Texture::unbindTexture()
{
	glBindBuffer(GL_ARRAY_BUFFER, 0);
	glBindVertexArray(0);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
	glBindTexture(GL_TEXTURE_2D, 0);
}

void Texture::drawTexture()
{
	bindTexture();
	glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
	unbindTexture();
}

void Texture::changePosition(Rect const &rect)
{
	GLfloat vertices[] = {
			rect.x1,  rect.y0, 0.0f,   1.0f, 1.0f,   // Верхний правый
			rect.x1, rect.y1, 0.0f,   1.0f, 0.0f,   // Нижний правый
			rect.x0, rect.y1, 0.0f,  0.0f, 0.0f,   // Нижний левый
			rect.x0,  rect.y0, 0.0f,  0.0f, 1.0f    // Верхний левый
	};
	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
	glBindBuffer(GL_ARRAY_BUFFER, 0);
}

const Rect &Texture::getTextureRect() const
{
	return texture_rect;
}

void Texture::setTextureRect(const Rect &textureRect)
{
	texture_rect = textureRect;
}

GLuint Texture::getVbo() const
{
	return VBO;
}

GLuint Texture::getVao() const
{
	return VAO;
}

GLuint Texture::getTexture() const
{
	return texture;
}

