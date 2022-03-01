#pragma once
#include <SFML/Graphics.hpp>
#include "GameObject.h"
#include <string>
#include <vector>

/** Class Renderer
* keeps track of all objects in the window frame and handles what objects are rendered.	
*/
class Renderer
{
	sf::RenderWindow *window;
	std::vector<GameObject*> renderObjects;
	float framerate;
	sf::Clock clock;
	float deltaT = 0.0f;

public:
	//constructor
	//Renderer(int sizeX, int sizeY, std::string title);
	Renderer(sf::RenderWindow* _window, float _framerate);

	//add GameObject to be rendererd on the window
	void add(GameObject* obj);
	//render all objects
	void draw();
};

