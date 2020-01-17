#pragma once
#include "main.hpp"
#include "Shader.hpp"

class Menu
{
	Menu();
	
	Menu(Menu const &);
	
	~Menu();
	
	void displayPauseMenu();
	void displayStartMenu();
	void displayUserDisplay();
	void displaySettings();

public:
//	Shader shaderProgram;
};


