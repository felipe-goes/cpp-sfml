#include "Game.hpp"

int main()
{
  // Init game engine
  Game game = Game();

  // Game loop
  while (game.running())
  {
    // Functions
    game.update();
    game.render();
  }

  // End of application
  return 0;
}
