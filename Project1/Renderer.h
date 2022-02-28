#pragma once
#include <SFML/Graphics.hpp>
#include "GameObject.h"
#include <string>
#include <vector>
class Renderer
{
	sf::RenderWindow *window;
	std::vector<GameObject*> renderObjects;

public:
	Renderer(int sizeX, int sizeY, std::string title);
	Renderer(sf::RenderWindow* _window);

	void add(GameObject* obj);
	void draw();
};

