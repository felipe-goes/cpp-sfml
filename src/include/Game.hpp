#pragma once

#include <iostream>

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>

class Game
{
private:
  // Variables
  // Window
  sf::RenderWindow *window;
  sf::VideoMode videoMode;
  sf::Event ev;

  // Game objects
  sf::RectangleShape enemy;

  // Private functions
  void initWindow(void);
  void initVariables(void);
  void pollEvent(void);
  void initEnemies(void);

public:
  // Constructors | Destructors
  Game();
  ~Game();

  void render(void);
  void update(void);

  const bool running(void) const;
};
