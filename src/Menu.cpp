#include "Menu.hpp"
Menu::Menu()
{
	start_background.loadTexture("../textures/start_back.png", Rect(-1,1,1,-1));
	load_save_background.loadTexture("../textures/load_save_back.png", Rect(-1,1,1,-1));
	load_save_slot0.loadTexture("../textures/load_save_slot0.png", Rect(-0.763,0.43,-0.415,-0.01));
	load_save_slot1.loadTexture("../textures/load_save_slot1.png", Rect(-0.245,0.43,0.1,-0.01));
	load_save_slot2.loadTexture("../textures/load_save_slot0.png", Rect(0.27,0.43,0.615,-0.01));
	curr_start = 0;
	curr_load = 0;
	curr_save = 0;
	curr_exit = 0;
	curr_pause = 0;
}

Menu::Menu(Menu const &)
{}

Menu::~Menu()
{}

void Menu::chooseMenu(EMenu choose)
{
	switch (choose)
	{
		case EM_StartMenu :
			startMenu(abs(curr_start % ES_COUNT));
			break;
		case EM_LoadMenu :
			loadMenu(abs(curr_load % ELS_COUNT));
			break;
//		case ESaveMenu :
//			startMenu(EStartGame);
			break;
		case EM_PauseMenu :
//			startMenu(EStartGame);
			break;
		case EM_OptionsMenu :
//			startMenu(StartGame);
			break;
		case EM_Exit :
			// code;
			break;
	}
}

void Menu::renderText(int choose, int x, int y, std::string message, int curr)
{
	if (choose == curr)
		text.displayMessage(message, Rect(x,y,0,0), glm::vec3(0.8,0.0f,0.0f), 0.5);
	else
		text.displayMessage(message, Rect(x,y,0,0), glm::vec3(0.0,0.0f,0.0f), 0.5);
}

void Menu::startMenu(int choose)
{
	start_background.drawTexture();
	for (int i = 0; i < ES_COUNT; i++)
	{
		switch (EStartMenu(i))
		{
			case ES_StartGame:
				renderText(choose ,100,300, "Start Game", ES_StartGame);
				break;
			case ES_LoadGame:
				renderText(choose ,100,250, "Load Game", ES_LoadGame);
				break;
			case ES_SaveGame:
				renderText(choose ,100,200, "Save Game", ES_SaveGame);
				break;
			case ES_Options:
				renderText(choose ,100,150, "Options", ES_Options);
				break;
			case ES_Exit:
				renderText(choose ,100,100, "Exit", ES_Exit);
				break;
		}
	}
}

void Menu::loadMenu(int choose)
{
	load_save_background.drawTexture();
	load_save_slot0.drawTexture();
	load_save_slot1.drawTexture();
	load_save_slot2.drawTexture();
	renderText(0, 404, 455, "-Empty-", -1);
	renderText(false, 140, 455, "-Empty-", -1);
	renderText(false, 668, 455, "-Empty-", -1);
//	renderText("Empty", 500, 500);
//	renderText("Empty",);
//	for (int i = 0; i < ELS_COUNT; i++)
//	{
//		switch (ELoadSaveMenu(i))
//		{
//			case ELS_FIRST:
//				renderText(choose ,100,300, "Start Game", ELS_FIRST);
//				break;
//			case ELS_SECOND:
//				renderText(choose ,100,250, "Load Game", ELS_SECOND);
//				break;
//			case ELS_THIRD:
//				renderText(choose ,100,200, "Save Game", ELS_THIRD);
//				break;
//		}
//	}
}

