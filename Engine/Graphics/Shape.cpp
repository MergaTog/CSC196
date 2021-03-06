#include "Shape.h"

namespace nc
{
	void Shape::Draw(Core::Graphics& graphics, Vector2 position, float scale)
	{
		graphics.SetColor(color);

		for (size_t i = 0; i < points.size() - 1; i++)
		{
			nc::Vector2 p1 = ((points[i] * scale) + position);
			nc::Vector2 p2 = ((points[i + 1] * scale) + position);

			graphics.DrawLine(p1.x, p1.y, p2.x, p2.y);
		}
	}
}
