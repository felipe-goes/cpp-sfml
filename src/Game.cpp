#include "Game.hpp"

// Constructors | Destructors
Game::Game()
{
  initVariables();
  initWindow();
  initEnemies();
}

Game::~Game() { delete this->window; }

void Game::initVariables(void)
{
  this->window = nullptr;

  // Game logic
  this->endGame = false;
  this->points = 0;
  this->health = 10;
  this->enemySpawnTimerMax = 10.f;
  this->enemySpawnTimer = this->enemySpawnTimerMax;
  this->maxEnemies = 10;
  this->mouseHeld = false;
}

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
  // this->enemy.setOutlineColor(sf::Color::Green);
  // this->enemy.setOutlineThickness(1.f);
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

void Game::updateMousePositions(void)
{
  /*
    @return void

    Updates the mouse positions:
    - Mouse position relative to window (Vector2i)
  */

  this->mousePosWindow = sf::Mouse::getPosition(*this->window);
  this->mousePosView = this->window->mapPixelToCoords(this->mousePosWindow);
}

void Game::renderEnemies()
{
  // Rendering all the enemies
  for (auto &e : this->enemies)
  {
    this->window->draw(e);
  }
}

void Game::updateEnemies()
{
  /*
    @return void

    Updates the enemy spawn timer and spawns enemies
    when the total amount of enemies is smaller than
    the maximum. Moves the enemies downwards.
    Removes the enemies at the edge of the screen. // ToDo
  */

  // Updating the timer for enemy spawning
  if (this->enemies.size() < this->maxEnemies)
  {
    // Spawn the enemy and reset the timer
    if (this->enemySpawnTimer >= this->enemySpawnTimerMax)
    {
      this->spawnEnemy();
      this->enemySpawnTimer = 0.f;
    }
    else
      this->enemySpawnTimer += 1.f;
  }

  // Moving and updating the enemies
  for (int i = 0; i < this->enemies.size(); i++)
  {
    this->enemies[i].move(0.f, 5.f);

    // If the enemy is past the bottom of the screen
    if (this->enemies[i].getPosition().y > this->window->getSize().y)
    {
      this->enemies.erase(this->enemies.begin() + i);
      this->health -= 1;
      std::cout << "Health: " << this->health << std::endl;
    }
  }

  // Check if clicked upon
  if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
  {
    if (!this->mouseHeld)
    {
      this->mouseHeld = true;
      bool deleted = false;
      for (size_t i = 0; i < this->enemies.size() && !deleted; i++)
      {
        if (this->enemies[i].getGlobalBounds().contains(this->mousePosView))
        {
          // Delete the enemy
          deleted = true;
          this->enemies.erase(this->enemies.begin() + i);

          // Gain points
          this->points += 1.f;
          std::cout << "Points: " << this->points << std::endl;
        }
      }
    }
  }
  else
  {
    this->mouseHeld = false;
  }
}

void Game::spawnEnemy()
{
  /*
    @return void

    Spawns enemies and sets their colors and positions.
    - Sets a random position.
    - Sets random color.
    - Adds enemy to the vector.
  */

  this->enemy.setPosition(
    static_cast<float>(rand() % static_cast<int>((this->window->getSize().x -
                                                  this->enemy.getSize().x))),
    0.f);

  this->enemy.setFillColor(sf::Color::Green);

  // Spawn the enemy
  this->enemies.push_back(this->enemy);

  // Remove the enemies at end of screen
}

// Accessors
const bool Game::running(void) const { return this->window->isOpen(); }
const bool Game::getEndGame(void) const { return this->endGame; };

// Functions
void Game::update(void)
{
  pollEvent();

  if (!this->endGame)
  {
    updateMousePositions();
    updateEnemies();
  }

  // End game condition
  if (this->health <= 0)
    this->endGame = true;
}

void Game::render(void)
{
  /*
    @return void

    Renders the game objects.
    - clear old frame
    - render objects
    - display framde in window
  */

  this->window->clear(sf::Color::Blue); // Window Clear old frame

  // Draw game objects
  this->renderEnemies();

  this->window->display(); // Tell app that window is done drawing
}
