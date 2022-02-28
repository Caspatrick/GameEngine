#include "TextureHandler.h"

void TextureHandler::addTexture(std::string name, std::string filepath) {
	sf::Texture tex;
	tex.loadFromFile(filepath);
	textures[name] = tex;
}

sf::Texture& TextureHandler::getTexture(std::string name) {
	return textures.at(name);
}