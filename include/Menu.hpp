#pragma once
#include "main.hpp"
#include "Text.hpp"
#include "Texture.hpp"
#include "Animation.hpp"

enum EMenu
{
	EM_PauseMenu,
	EM_StartMenu,
	EM_LoadMenu,
	EM_SaveMenu,
	EM_DieMenu,
	EM_UserDisplay,
	EM_OptionsMenu,
	EM_Exit
};

enum EStartMenu
{
	ES_StartGame,
	ES_LoadGame,
	ES_SaveGame,
	ES_Options,
	ES_Exit,
	ES_COUNT = 5
};

enum EPopUp
{
	EP_YES,
	EP_NO
};

enum ELoadSaveMenu
{
	ELS_FIRST = 0,
	ELS_SECOND = 1,
	ELS_THIRD = 2,
	ELS_COUNT = 3
};
enum EOptions
{
	EO_FULLSCREEN,
	EO_AUDIO,
	EO_BIND_UP,
	EO_BIND_DOWN,
	EO_BIND_LEFT,
	EO_BIND_RIGHT,
	EO_BIND_ATTACK,
	EO_WINDOW_SIZE_640x480,
	EO_WINDOW_SIZE_800x600,
	EO_WINDOW_SIZE_1024x768,
	EO_WINDOW_SIZE_1440x900,
	EO_WINDOW_SIZE_2560x1440,
};

class Menu
{
public:
	Menu();
	
	Menu(Menu const &);
	
	~Menu();
	
	void chooseMenu(EMenu);
	void pauseMenu();
	void startMenu(int);
	void loadMenu(int);
	void SaveMenu();
	void DieMenu();
	void UserDisplay();
	void Settings();
	void renderText(int choose, int x, int y, std::string message, int curr);

private:
	int 					curr_start;
	int 					curr_pause;
	bool 					options_fullscreen;
	bool 					options_audio;
	int						options_resolution;
	int 					options_move_up;
	int 					options_move_down;
	int 					options_move_left;
	int 					options_move_right;
	int 					options_attack;
	int 					curr_load;
	int 					curr_save;
	int 					curr_exit;
	Texture					start_background;
	Texture					load_save_background;
	Texture					load_save_slot0;
	Texture					load_save_slot1;
	Texture					load_save_slot2;
	Texture					hud_background;
	Texture					pause_background;
	Texture					option_background;
	Text					text;
};


