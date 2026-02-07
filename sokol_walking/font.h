#pragma once
#ifndef CMN_FONT_STRUCT_H
#define CMN_FONT_STRUCT_H

#include "texture_utils.h"

namespace cmn
{
	struct Font
	{
		sg_view tex{};

		int char_w = 0, char_h = 0;
		int num_x = 1, num_y = 1;

		Font() {}

		Font(const std::string& f, int w, int h)
		{
			sg_view new_tex{}; 
			if (bmakeTextureFromFile(new_tex, f)) tex = new_tex;

			char_w = w, char_h = h;

			sg_image img = sg_query_view_image(tex);
			num_x = sg_query_image_width(img) / char_w;
			num_y = sg_query_image_height(img) / char_h;
		}

		//region of texture given character
		void getRegion(char c, float& l, float& t, float& r, float& b) const {
			int k = c - 32;
			int i = k % num_x, j = k / num_x;

			float x1 = 1.f / num_x, y1 = 1.f / num_y;
			l = x1 * i, t = y1 * j;
			r = x1 * (1 + i), b = y1 * (1 + j);
		}
	};
}
#endif // !CMN_FONT_STRUCT_H
