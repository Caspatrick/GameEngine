#include "Animation.h"

/*currently only accepts animations in one image file*/
Animation::Animation(std::string filepath, int _nImgsX, int _nImgsY) {
	nImgsX = _nImgsX;
	nImgsY = _nImgsY;

	tex.loadFromFile(filepath);
	
	size = tex.getSize();
	size.x /= nImgsX;
	size.y /= nImgsY;

}
Animation::Animation() {
	nImgsX = 0;
	nImgsY = 0;
}

void Animation::bindTexture(sf::RectangleShape* shape)
{
	shape->setTexture(&tex);
}

void Animation::setCurrentImage(int nx, int ny, sf::RectangleShape* shape) {
	curX = nx;
	curY = ny;
	sf::IntRect ir(size.x * nx, size.y * ny, size.x, size.y);
	shape->setTextureRect(ir);
}

//increase x index of current image by one; loop if higher than image count
void Animation::nextImage(sf::RectangleShape* shape) {
	int nx = (curX == nImgsX-1) ? 0 : curX + 1;
	setCurrentImage(nx, curY, shape);
}