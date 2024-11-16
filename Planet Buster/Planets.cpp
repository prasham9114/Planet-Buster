#include "Planets.h"

void Planets::initShape(const sf::RenderWindow& window)
{
	this->shape.setRadius(static_cast<float>(rand() % 30 + 10));
	sf::Color color;
	
	switch (this->type)
	{
		case DEFAULT:
			color = sf::Color(rand() % 255 + 1, rand() % 255 + 1, rand() % 255 + 1);
			this->shape.setOutlineColor(sf::Color::White);
			this->shape.setOutlineThickness(2.f);
			break;

		case DAMAGING:
			color = sf::Color::Red;
			this->shape.setOutlineColor(sf::Color::Magenta);
			this->shape.setOutlineThickness(3);
			break;
		
		case HEALING:
			color = sf::Color::Green;
			this->shape.setOutlineColor(sf::Color::Cyan);
			this->shape.setOutlineThickness(3);
			break;
	}

	this->shape.setFillColor(color);
	this->shape.setPosition(
		sf::Vector2f(
			static_cast<float>(rand() % window.getSize().x - this->shape.getGlobalBounds().width),
			static_cast<float>((rand() % window.getSize().y - this->shape.getGlobalBounds().height)
			)
		)
	);
}

Planets::Planets(const sf::RenderWindow& window, int type)
	:type(type) // this->type = type;
{ 
	this->initVariables();
	this->initShape(window);
}

Planets::~Planets()
{

}

const sf::CircleShape& Planets::getShape() const
{
	return this->shape;
}

const int& Planets::getType() const
{
	return this->type;
}

const int& Planets::getHpBalls() const
{
	return this->hpBalls;
}

const int& Planets::getDamagingBalls() const
{
	return this->damagingBalls;
}

void Planets::initVariables()
{
	this->maxHpBalls = 3;
	this->hpBalls = this->maxHpBalls;
	this->maxDamagingBalls = 5;
	this->damagingBalls = this->maxDamagingBalls;
}

void Planets::update()
{

}

void Planets::render(sf::RenderTarget* target)
{
	target->draw(this->shape);
}
