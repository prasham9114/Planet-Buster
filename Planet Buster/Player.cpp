#include "Player.h"
using namespace sf;

void Player::initVariables()
{
	this->movementSpeed = 5.f;
	this->hpMax = 10;
	this->hp = this->hpMax;
}

void Player::initShape()
{
	// Customizing the player object
	this->shape.setFillColor(Color::Red);
	this->shape.setSize(Vector2f(50.f, 50.f));
	this->shape.setOutlineColor(Color::Blue);
	this->shape.setOutlineThickness(5.f);
	this->shape.setPosition(400.f,200.f);
}

Player::Player(float x , float y)
{
	this->initVariables();
	this->initShape();
}

Player::~Player()
{

}

void Player::updateWindowBoundsCollision(const sf::RenderTarget * target)
{
	// Left
	if (this->shape.getGlobalBounds().left <= 0.f)
	{
		this->shape.setPosition(10.f, this->shape.getGlobalBounds().top);
	}
	// Right
	else if (this->shape.getGlobalBounds().left + this->shape.getGlobalBounds().width >= target->getSize().x)
	{
		this->shape.setPosition(target->getSize().x - this->shape.getGlobalBounds().width, this->shape.getGlobalBounds().top);
	}
	// Top
	if (this->shape.getGlobalBounds().top <= 0.f)
	{
		this->shape.setPosition(this->shape.getGlobalBounds().left,10.f);
	}
	// Bottom
	else if (this->shape.getGlobalBounds().top + this->shape.getGlobalBounds().height >= target->getSize().y)
	{
		this->shape.setPosition(this->shape.getGlobalBounds().left,target->getSize().y - this->shape.getGlobalBounds().height );
	}
}

void Player::update(const sf::RenderTarget* target)
{
	// Input Movement
	this->updateInput();

	// Border Collision
	this->updateWindowBoundsCollision(target);
}

void Player::render(sf::RenderTarget* target)
{
	// Drawing the player
	target->draw(this->shape);
}

void Player::updateInput()
{
	// Keyboard input
	//Left
	if (Keyboard::isKeyPressed(Keyboard::A))
	{
		this->shape.move(-this->movementSpeed, 0.f);
	}
	//Right
	else if (Keyboard::isKeyPressed(Keyboard::D))
	{
		this->shape.move(this->movementSpeed, 0.f);
	}
	// Up
	if (Keyboard::isKeyPressed(Keyboard::W))
	{
		this->shape.move(0.f, -this->movementSpeed);
	}
	//Down
	else if (Keyboard::isKeyPressed(Keyboard::S))
	{
		this->shape.move(0.f,this->movementSpeed);
	}
}

void Player::takeDamage(const int damage)
{
	if (this->hp > 0)
	{
		this->hp -= damage;
	}

	if (this->hp < 0)
	{
		this->hp = 0;
	}
}

void Player::gainHealth(const int health)
{
	if (this->hp < this->getHpMax())
	{
		this->hp += health;
	}

	if (this->hp > this->hpMax)
	{
		this->hp = this->hpMax;
	}
}

const int& Player::getHp() const
{
	return this->hp;
}

const int& Player::getHpMax() const
{
	return this->hpMax;
}

const sf::RectangleShape Player::getShape() const
{
	return this->shape;
}
