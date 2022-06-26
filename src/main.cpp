#include "Game.hpp"

int main()
{
  // Init srand
  std::srand(static_cast<unsigned>(time(NULL)));

  // Init game engine
  Game game = Game();

  // Game loop
  while (game.running() && !game.getEndGame())
  {
    // Functions
    game.update();
    game.render();
  }

  // End of application
  return 0;
}
