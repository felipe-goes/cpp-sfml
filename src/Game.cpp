#include "Game.hpp"

// Constructors | Destructors
Game::Game()
{
  initVariables();
  initWindow();
  initEnemies();
}

Game::~Game() { delete this->window; }

void Game::initVariables(void) { this->window = nullptr; }

void Game::initWindow(void)
{
  this->videoMode.height = 480;
  this->videoMode.width = 600;

  this->window = new sf::RenderWindow(videoMode, "My first game",
                                      sf::Style::Titlebar | sf::Style::Close);

  this->window->setFramerateLimit(60);
}

void Game::initEnemies()
{
  this->enemy.setPosition(10.f, 10.f);
  this->enemy.setSize(sf::Vector2f(100.f, 100.f));
  this->enemy.setScale(sf::Vector2f(0.5f, 0.5f));
  this->enemy.setFillColor(sf::Color::Cyan);
  this->enemy.setOutlineColor(sf::Color::Green);
  this->enemy.setOutlineThickness(1.f);
}

void Game::pollEvent(void)
{
  // Event polling
  while (this->window->pollEvent(this->ev))
  {
    switch (this->ev.type)
    {
    case sf::Event::Closed:
      this->window->close();
      break;

    case sf::Event::KeyPressed:
      if (this->ev.key.code == sf::Keyboard::Escape)
        this->window->close();
      break;
    }
  }
}

// Accessors
const bool Game::running(void) const { return this->window->isOpen(); }

// Functions
void Game::update(void)
{
  pollEvent();

  // Update mouse position
  // Relative to the screen
  // std::cout << "Mouse pos: " << sf::Mouse::getPosition().x << " "
  //           << sf::Mouse::getPosition().y << std::endl;
  // Relative to the window
  std::cout << "Mouse pos: " << sf::Mouse::getPosition(*this->window).x << " "
            << sf::Mouse::getPosition(*this->window).y << std::endl;
}

void Game::render(void)
{
  /*
    @return void
    - clear old frame
    - render objects
    - display framde in window

    Renders the game objects.
  */

  this->window->clear(sf::Color::Blue); // Window Clear old frame

  // Draw game objects
  this->window->draw(this->enemy);

  this->window->display(); // Tell app that window is done drawing
}
