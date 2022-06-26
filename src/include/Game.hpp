#pragma once

#include <ctime>
#include <iostream>
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
  void initWindow(void);
  void initVariables(void);
  void initEnemies(void);

  void pollEvent(void);
  void updateMousePositions(void);

  void updateEnemies(void);
  void renderEnemies(void);
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
