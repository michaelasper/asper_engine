#include "include/Game.h"
namespace engine {
int engine::Game::Start() {

  if (_gameState != Uninitialized) {
    return -1;
  }

  if (!Startup()) {
    Shutdown();
    return -2;
  }

  return 0;
}

bool engine::Game::Startup() {
  if (_gameState != Uninitialized) {
    return false;
  }

  _gameState = Loading;

  return true;
}

bool engine::Game::Shutdown() {
  _gameState = Exiting;
  return true;
}

bool engine::Game::ExitGame() {
  if (_gameState == Exiting) {
    return true;
  }
  return false;
}

void engine::Game::GameLoop() {}
} // namespace engine