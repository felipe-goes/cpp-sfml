#pragma once

#include <ctime>
#include <iostream>
#include <sstream>
#include <vector>

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

  // Mouse positions
  sf::Vector2i mousePosWindow;
  sf::Vector2f mousePosView;

  // Resources
  sf::Font font;

  // Text
  sf::Text uiText;

  // Game logic
  bool endGame;
  unsigned int points;
  int health;
  float enemySpawnTimer;
  float enemySpawnTimerMax;
  unsigned int maxEnemies;
  bool mouseHeld;

  // Game objects
  std::vector<sf::RectangleShape> enemies;
  sf::RectangleShape enemy;

  // Private functions
  void initVariables(void);
  void initWindow(void);
  void initFonts(void);
  void initText(void);
  void initEnemies(void);

  void pollEvents(void);
  void updateMousePositions(void);
  void updateText(void);
  void updateEnemies(void);

  void renderText(sf::RenderTarget &target);
  void renderEnemies(sf::RenderTarget &target);
  void spawnEnemy(void);

public:
  // Constructors | Destructors
  Game();
  ~Game();

  // Functions
  void update(void);
  void render(void);

  // Accessors
  const bool running(void) const;
  const bool getEndGame(void) const;
};
