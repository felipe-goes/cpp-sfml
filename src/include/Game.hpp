#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

class Game
{
private:
  sf::RenderWindow *window;
  sf::VideoMode videoMode;
  sf::Event ev;

  void initWindow(void);
  void initVariables(void);
  void pollEvent(void);

public:
  Game();
  ~Game();

  void render(void);
  void update(void);

  const bool running(void) const;
};
