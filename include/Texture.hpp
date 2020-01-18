#pragma once
#include "main.hpp"
#include "Shader.hpp"

class Texture
{
public:
	Texture(std::string const & path, Rect const &rect);
	Texture();

	Texture(Texture const &);

	void loadTexture(std::string const & path, Rect const &rect);
	void unloadTexture();

	void bindTexture();
	void unbindTexture();
	void drawTexture();

	~Texture();
public:
	const Rect &getTextureRect() const;

	void setTextureRect(const Rect &textureRect);

	GLuint getVbo() const;

	GLuint getVao() const;

	GLuint getEbo() const;

private:

	Rect			texture_rect;
	Shader			shader;
	int				width;
	int 			height;
	unsigned char*	image;
	GLuint			VBO;
	GLuint			VAO;
	GLuint			EBO;
	GLuint			texture = -1;
public:
	GLuint getTexture() const;
};


