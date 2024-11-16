#pragma once
#include "Planets.h"
class Player
{
	private:

		// Creating the player shape
		sf::RectangleShape shape;
		float movementSpeed;
		int hp;
		int hpMax;
		

		void initVariables();
		void initShape();

	public:

		// Constructors and Destructors
		Player(float x = 0.f, float y = 0.f);
		virtual ~Player();
	
		// Functions
		void updateWindowBoundsCollision(const sf::RenderTarget* target);
		void update(const sf::RenderTarget* target);
		void render(sf::RenderTarget* target); // sending a window target in form of a pointer
		void updateInput();
		void takeDamage(const int damage);
		void gainHealth(const int health);


		//Accessors
		const int& getHp() const;
		const int& getHpMax() const;
		const sf::RectangleShape getShape() const;
};

