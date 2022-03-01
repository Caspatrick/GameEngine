#include "GameObject.h"

GameObject::GameObject(sf::Vector2f _size, sf::Vector2f _pos) {
	size = _size;
	shape = sf::RectangleShape(size);
	/*texture = sf::Texture();
	texture.loadFromFile(texture_file);
	shape.setTexture(&texture);*/
	shape.setPosition(_pos);
	shape.setOrigin(0.5f * size);
}

void GameObject::move(float x, float y) {
	shape.move(movingSpeed*x, movingSpeed*y);
}
void GameObject::move(sf::Vector2f dir) {
	shape.move(movingSpeed*dir);
}

void GameObject::addAnimation(std::string name, std::string filename, int nImgsX, int nImgsY){
	Animation anim(filename, nImgsX, nImgsY);
	animations[name] = anim;
}

sf::Vector2f GameObject::getPos() {
	return shape.getPosition();
}

void GameObject::playAnimation(std::string name, int textureLine) {
	Animation& anim = animations.at(name);
	if (curAnimation != name) {
		anim.bindTexture(&shape);
		curAnimation = name;
	}
	anim.setCurrentImage(0, textureLine, &shape);
}

void GameObject::update()
{
	Animation& anim = animations.at(curAnimation);
	anim.nextImage(&shape);
}
