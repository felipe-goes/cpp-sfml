#include "Game.hpp"

// Constructors | Destructors
Game::Game()
{
  initVariables();
  initWindow();
}

Game::~Game() { delete this->window; }

void Game::initVariables(void) { this->window = nullptr; }

void Game::initWindow(void)
{
  this->videoMode.height = 480;
  this->videoMode.width = 600;

  this->window = new sf::RenderWindow(videoMode, "My first game",
                                      sf::Style::Titlebar | sf::Style::Close);
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
void Game::update(void) { pollEvent(); }

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

  this->window->display(); // Tell app that window is done drawing
}
