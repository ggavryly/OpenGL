#pragma once
#include "Texture.hpp"

class Animation
{
public:
	Animation();
	void loadAnimation(std::string const & path, int count_frames, Rect const &, int frequency);
	Animation(std::string const &, int count_frames, Rect const &, int frequency);
	void renderAnimation();
	~Animation();

private:
	std::vector<Texture>	animation;
	double					curr_time;
	double					last_time;
	int 					curr_frame = 0;
	int 					frequency;
};


