#pragma once


#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include <map>
#include <memory>
#include "glew.h"
#include "glfw3.h"
#include "math_3d.hpp"
#include <glm.hpp>
#include <GLUT/glut.h>
#include <gtc/matrix_transform.hpp>
#include "gtc/type_ptr.hpp"
#include "ft2build.h"
#include FT_FREETYPE_H
#include "SOIL.h"
struct Rect
{
	Rect() = default;
	Rect(float x0,float y0,float x1,float y1)
			: x0(x0)
			, y0(y0)
			, x1(x1)
			, y1(y1)
	{}
	float x0;
	float y0;
	float x1;
	float y1;
};