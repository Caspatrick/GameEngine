#pragma once
#include <SFML/Graphics.hpp>
#include <string>
#include <map>
class Animation
{
private:
	sf::Texture tex;
	sf::Vector2u size; //size of one image
	int nImgsX;        //number of images in the texture
	int nImgsY;
	int curX = 0;      //index of current image
	int curY = 0; 

public:
	Animation();
	Animation(std::string filepath, int _nImgsX, int _nImgsY);
	void bindTexture(sf::RectangleShape* shape);
	void setCurrentImage(int nx, int ny, sf::RectangleShape* shape);
	void nextImage(sf::RectangleShape* shape);
};


