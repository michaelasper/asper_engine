namespace engine {
class Game {
public:
  int Start();

private:
  bool Startup();
  bool ExitGame();
  bool Shutdown();
  void GameLoop();

  enum GameState {
    Uninitialized,
    Loading,
    Paused,
    ShowingMenu,
    Playing,
    Exiting
  };

  GameState _gameState;
};
} // namespace engine