#ifndef DEBUGDRAW_H
#define DEBUGDRAW_H

#include <Box2D/Box2D.h>

// You may need to change this based on your implementation
// 1 meter is 100 pixel
const float METERS_TO_PIXELS = 100.f;
// 0.1 meter is 1 pixel
const float PIXELS_TO_METERS = 0.01f;

namespace sf
{
class RenderWindow;
}

class DebugDraw : public b2Draw
{
private:
	sf::RenderWindow *window;

public:
	DebugDraw(sf::RenderWindow *window);
	~DebugDraw();

	void DrawPolygon(const b2Vec2 *vertices, int32 vertexCount, const b2Color &color);
	void DrawSolidPolygon(const b2Vec2 *vertices, int32 vertexCount, const b2Color &color);
	void DrawCircle(const b2Vec2 &center, float32 radius, const b2Color &color);
	void DrawSolidCircle(const b2Vec2 &center, float32 radius, const b2Vec2 &axis, const b2Color &color);
	void DrawSegment(const b2Vec2 &p1, const b2Vec2 &p2, const b2Color &color);
	void DrawTransform(const b2Transform &xf);
	void DrawPoint(const b2Vec2 &p, float32 size, const b2Color &color);
};

#endif