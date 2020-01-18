#include "Animation.hpp"

Animation::Animation()
{}

Animation::~Animation()
{}

Animation::Animation(std::string const &path, int count_frames, Rect const &rect, int freq)
{
	loadAnimation(path, count_frames, rect, freq);
}

void Animation::loadAnimation(std::string const &path, int count_frames, Rect const &rect, int freq)
{
	frequency = freq;
	std::string tmp = path;
	std::string tmp_path = path;
	for (int i = 0; i < count_frames; i++)
	{
		std::stringstream ss;
		ss << i;
		tmp = ss.str();
		animation.emplace_back(tmp_path + tmp + std::string(".png"), rect);
	}
}

void Animation::renderAnimation()
{
	curr_time = glfwGetTime();
	if (curr_time - last_time > frequency)
	{
		curr_frame = curr_frame > animation.size() ? 0 : curr_frame + 1;
		animation[curr_frame].drawTexture();
		last_time = curr_time;
	}
	else
		animation[curr_frame].drawTexture();
}

