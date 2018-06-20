#include "DebugDraw.h"

#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/ConvexShape.hpp>
#include <SFML/Graphics/CircleShape.hpp>
#include <SFML/Graphics/RectangleShape.hpp>

DebugDraw::DebugDraw(sf::RenderWindow* renderWindow)
{
	window = renderWindow;
}

DebugDraw::~DebugDraw()
{
	window = nullptr;
}

void DebugDraw::DrawPolygon(const b2Vec2* vertices, int32 vertexCount, const b2Color& color)
{
	sf::ConvexShape polygon;
	polygon.setPointCount(vertexCount);
	for (int32 i = 0; i < vertexCount; i++)
	{
		b2Vec2 vertex = vertices[i];
		polygon.setPoint(
			i, 
			sf::Vector2f(vertex.x * METERS_TO_PIXELS, vertex.y * METERS_TO_PIXELS)
		);
	}

	polygon.setOutlineColor(sf::Color(
		(sf::Uint8)(color.r * 255),
		(sf::Uint8)(color.g * 255),
		(sf::Uint8)(color.b * 255),
		(sf::Uint8)(color.a * 255)
	));
	polygon.setOutlineThickness(1.0f);
	polygon.setFillColor(sf::Color::Transparent);
	window->draw(polygon);
}

void DebugDraw::DrawSolidPolygon(const b2Vec2* vertices, int32 vertexCount, const b2Color& color)
{
	sf::ConvexShape polygon;
	polygon.setPointCount(vertexCount);
	for (int32 i = 0; i < vertexCount; i++)
	{
		b2Vec2 vertex = vertices[i];
		polygon.setPoint(
			i,
			sf::Vector2f(vertex.x * METERS_TO_PIXELS, vertex.y * METERS_TO_PIXELS)
		);
	}

	sf::Color polyColor(
		(sf::Uint8)(color.r * 255),
		(sf::Uint8)(color.g * 255),
		(sf::Uint8)(color.b * 255),
		(sf::Uint8)(color.a * 255)
	);

	polygon.setOutlineColor(polyColor);
	polygon.setOutlineThickness(1.0f);
	polygon.setFillColor(sf::Color(polyColor.r, polyColor.g, polyColor.b, 50));
	window->draw(polygon);
}

void DebugDraw::DrawCircle(const b2Vec2& center, float32 radius, const b2Color& color)
{
	sf::CircleShape circle;
	circle.setPosition(center.x * METERS_TO_PIXELS, center.y * METERS_TO_PIXELS);
	circle.setRadius(radius);
	circle.setOutlineThickness(1.0f);
	circle.setOutlineColor(sf::Color(
		(sf::Uint8)(color.r * 255),
		(sf::Uint8)(color.g * 255),
		(sf::Uint8)(color.b * 255),
		(sf::Uint8)(color.a * 255)
	));

	circle.setFillColor(sf::Color::Transparent);

	window->draw(circle);
}

void DebugDraw::DrawSolidCircle(const b2Vec2& center, float32 radius, const b2Vec2& axis, const b2Color& color)
{
	sf::CircleShape circle;
	circle.setPosition(center.x * METERS_TO_PIXELS, center.y * METERS_TO_PIXELS);
	circle.setRadius(radius * METERS_TO_PIXELS);
	circle.setOutlineThickness(1.0f);
	sf::Color circleColor(
		(sf::Uint8)(color.r * 255),
		(sf::Uint8)(color.g * 255),
		(sf::Uint8)(color.b * 255),
		(sf::Uint8)(color.a * 255)
	);
	circle.setOutlineColor(circleColor);
	circle.setFillColor(sf::Color(circleColor.r, circleColor.g, circleColor.b, 50));

	window->draw(circle);
}

void DebugDraw::DrawSegment(const b2Vec2& p1, const b2Vec2& p2, const b2Color& color)
{
	sf::Color lineColor(
		(sf::Uint8)(color.r * 255),
		(sf::Uint8)(color.g * 255),
		(sf::Uint8)(color.b * 255),
		(sf::Uint8)(color.a * 255)
	);

	sf::Vertex line[] = {
		sf::Vertex(
			sf::Vector2f(p1.x * METERS_TO_PIXELS, p1.y * METERS_TO_PIXELS), lineColor
		),
		sf::Vertex(
			sf::Vector2f(p2.x * METERS_TO_PIXELS, p2.y * METERS_TO_PIXELS), lineColor
		)
	};

	window->draw(line, 2, sf::PrimitiveType::Lines);
}

void DebugDraw::DrawTransform(const b2Transform& xf)
{
}

void DebugDraw::DrawPoint(const b2Vec2& p, float32 size, const b2Color& color)
{
	sf::RectangleShape point(
		sf::Vector2f(size * METERS_TO_PIXELS, size * METERS_TO_PIXELS)
	);
	point.setPosition(p.x * METERS_TO_PIXELS, p.y * METERS_TO_PIXELS);
	point.setOutlineThickness(0.f);
	point.setFillColor(sf::Color(
		(sf::Uint8)(color.r * 255),
		(sf::Uint8)(color.g * 255),
		(sf::Uint8)(color.b * 255),
		(sf::Uint8)(color.a * 255)
	));

	window->draw(point);
}