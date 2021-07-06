#pragma once
#include "core.h"
#include <iostream>

namespace nc
{
	struct color
	{
		float R, G, B;

		color() : R{ 0 }, G{ 0 }, B{ 0 } {}
		color(float R, float G, float B) : R{ R }, G{ G }, B{ B } {}
		color(DWORD RGB) // DWORD ( x | b | g | r)
		{
			R = (RGB & 0xFF) /255.0f ;
			G = ((RGB >> 8) & 0xFF) /255.0f;
			B = ((RGB >> 16) & 0xFF) /255.0f;
		}
		color operator * (float s) const { return { R * s, G * s, B * s }; }
		operator DWORD() const { return ToRGB(); }
		DWORD ToRGB() const
		{
			BYTE red = static_cast<BYTE>( R * 255);
			BYTE green = static_cast<BYTE>(G * 255);
			BYTE blue = static_cast<BYTE>(B * 255);
			return (red | green << 8 | blue << 16);
		}


	};

}