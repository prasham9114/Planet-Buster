#pragma once

#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Network.hpp>
#include <SFML/Window.hpp>

enum planetType { DEFAULT = 0, DAMAGING, HEALING, NROFTYPE };
class Planets
{
	
	 private:
		 sf::CircleShape shape;
		 void initShape(const sf::RenderWindow& window);
		 int type;
		 int maxHpBalls;
		 int hpBalls;
		 int maxDamagingBalls;
		 int damagingBalls;
	
	public:
		Planets(const sf::RenderWindow& window, int type);
		virtual ~Planets();

		//Accessor
		const sf::CircleShape& getShape() const;
		const int& getType() const;
		const int& getHpBalls() const;
		const int& getDamagingBalls() const;

		//Functions 
		void initVariables();
		void update();
		void render(sf::RenderTarget* target);
};

