#pragma once
#include <SFML/Graphics.hpp>
#include <string>
#include <map>
class TextureHandler
{
private:
	std::map<std::string, sf::Texture> textures;

public:
	void addTexture(std::string name, std::string filepath);
	sf::Texture& getTexture(std::string name);
};


