#include "Game.h"
#include <sstream>
using namespace sf;
using namespace std;

// Initializing Variables
void Game::initVariable()
{
	this->endGame = false;
	this->spawnTimerMax = 10.f;
	this->spawnTimer = this->spawnTimerMax;
	this->maxPlanets = 10;
	this->points = 0;
}

void Game::initFont()
{
	if (!this->font.loadFromFile("C:/Users/Prasham Desai/Desktop/Coding/C++ Games/The-Last-Block/x64/Debug/fonts/KnightWarrior-w16n8.otf"))
	{
		cout << "Could not load font\n";
	}
}

void Game::initText()
{
	// Setting the text and customizing it

	// HP text
	this->hpText.setFont(this->font);
	this->hpText.setCharacterSize(30);
	this->hpText.setFillColor(sf::Color::Green);
	this->hpText.setPosition(635.f, 10.f);
	
	// Points text
	this->pointsText.setFont(this->font);
	this->pointsText.setCharacterSize(30);
	this->pointsText.setFillColor(sf::Color::Blue);
	this->pointsText.setPosition(10.f, 10.f);
	
	// Game Over text
	this->gameOverText.setFont(this->font);
	this->gameOverText.setCharacterSize(100);
	this->gameOverText.setFillColor(sf::Color::Red);
	this->gameOverText.setPosition(200.f, 230.f);
}

// Initializing functions
void Game::initWindow()
{
	this->videoMode = VideoMode(800, 600); // window size
	this->window = new RenderWindow(this->videoMode, "Planet Buster", Style::Close | Style::Titlebar);
	this->window->setFramerateLimit(60);
	this->logo.loadFromFile("C:/Users/Prasham Desai/Desktop/Coding/C++ Games/Planet Buster/x64/Debug/images/logo.JPG");
	this->window->setIcon(this->logo.getSize().x, this->logo.getSize().y , this->logo.getPixelsPtr());
}


// Constructors and Destructors 
Game::Game()
{
	this->initVariable();
	this->initWindow();
	this->initFont();
	this->initText();
}

Game::~Game()
{
	delete this->window;
}


void Game::pollEvents()
{
	while (this->window->pollEvent(this->ev))
	{
		switch (this->ev.type)
		{
		case Event::Closed:
			this->window->close(); //close button of window
			break;
		
		case Event::KeyPressed:
			if(this->ev.key.code == Keyboard::Escape) // Comparing ev keycode to the Escape button
			this->window->close();
			break;
		default:
			break;
		}
	}
}

const bool Game::running() const
{
	return this->window->isOpen();
}

void Game::updateCollision()
{
	// Check the collision 
	for (size_t i = 0; i < this->planets.size(); i++)
	{
		if (this->player.getShape().getGlobalBounds().intersects(this->planets[i].getShape().getGlobalBounds()))
		{
			switch (this->planets[i].getType())
			{
				case planetType::DEFAULT :
						//Add Points
						this->points++;
					break;

				case planetType::DAMAGING :
						//Damage Player
					this->player.takeDamage(1);
					if (this->player.getHp() <= 0)
					{
						endGame = true;
					}
					break;
				
				case planetType::HEALING :
						//Heal Player
					this->player.gainHealth(1);
					break;
			}

			//Remove the ball
			this->planets.erase(this->planets.begin() + i);
		}
	}
}

void Game::update()
{
	this->pollEvents();

	if (!this->endGame)
	{
		this->player.update(this->window);
		// Spawning the Planets
		this->spawnPlanets();

		// Destroying the Planets
		this->updateCollision();

		// Updating and setting the text
		this->updateUI();
		return;
	}
	else if (this->endGame)
	{
		this->gameOver(this->window);
	}

}

void Game::render()
{
	// Clearing the old Frame
	this->window->clear();

	// Draw the new Frame
	this->player.render(this->window);

	for(auto i : this->planets)
	{
		i.render(this->window);
	}

	// Render the text
	this->renderUI(this->window);

	// Display the new Frame
	if (!this->endGame)
	{
		this->window->display();
	}
}

void Game::spawnPlanets()
{
	// Timer
	if (this->spawnTimer < this->spawnTimerMax)
	{
		this->spawnTimer += 1.f;
	}
	else
	{
		if (this->planets.size() < this->maxPlanets)
		{
			this->planets.push_back(Planets(*this->window,this->randPlanetsType()));
			this->spawnTimer = 0.f;
		}
	}
}

const int Game::randPlanetsType()
{
	int type = planetType::DEFAULT;
	int randValue = rand() % 100 + 1;

	if (randValue > 70 && randValue < 90)
	{
		type = planetType::DAMAGING;
	}
	else if (randValue > 90 && randValue < 100)
	{
		type = planetType::HEALING;
	}

	return type;
}

void Game::renderUI(sf::RenderTarget* target)
{
	target->draw(this->pointsText);
	target->draw(this->hpText);
}

void Game::updateUI()
{
	stringstream  ssHP;
	ssHP << "Health: " << this->player.getHp() << "/"
		<< this->player.getHpMax();

	this->hpText.setString(ssHP.str());

	stringstream  ssP;
	ssP << "Points: " << this->points;

	this->pointsText.setString(ssP.str());
}

void Game::gameOver(sf::RenderTarget* target)
{

	// Clearing the frame
	this->window->clear();


	// Making the game over frame
	stringstream  ssGO;
	ssGO << "GAME OVER";

	this->gameOverText.setString(ssGO.str());

	// Drawing the frame
	target->draw(this->gameOverText);


	// Displaying the frame
	this->window->display();
}
