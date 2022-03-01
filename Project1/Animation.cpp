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

/*start animation at current image.
	nx, ny: index of current image;
	shape: pointer to the shape it gets drawn on
*/
void Animation::setCurrentImage(int nx, int ny, sf::RectangleShape* shape) {
	curX = nx;
	curY = ny;
	int flipint = flipH ? 1 : 0;
	sf::IntRect ir(size.x * (nx+flipint), size.y * ny, (flipH ? -1 : 1) * size.x, size.y);
	shape->setTextureRect(ir);
}

//increase x index of current image by one; loop if higher than image count
void Animation::nextImage(sf::RectangleShape* shape) {
	int nx = (curX == nImgsX-1) ? 0 : curX + 1;
	setCurrentImage(nx, curY, shape);
}

void Animation::flipHorizontally(bool _flipH) {
	flipH = _flipH;
}