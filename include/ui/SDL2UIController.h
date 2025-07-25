#pragma once
#include <SDL_render.h>
#include <SDL_video.h>
#include <atomic>
#include <thread>

#include "IGameController.h"
#include "ISDL2UI.h"
#include "Texture.h"

class SDL2UIController : public ISDL2UI {
  IGameController *game;

  SDL_Window *window;
  SDL_Renderer *renderer;

  SDL_Rect backgroundRect;
  Texture backgroundTexture;

  std::thread renderThread;
  std::atomic<bool> renderThreadRunning = true;

  bool createWindow();
  bool createRenderer();
  static bool initSDLImage();

public:
  explicit SDL2UIController();
  ~SDL2UIController() override;
  bool init() override;
  void handleEvents() override;

  void drawBackground();

  void render() override;
  void renderLoop(int delay) override;
  Move getUserMove() override;
  void loadTextures() override;
  void closeThread() override;
  Texture loadTexture(const std::string &filename) const;

  void cleanup() override;
  void initLayout() override;
  // void setDragPiece(Unit* piece, const Position& pos) override;
  void clearDragPiece() override;
  void showMessage(const std::string &message) override;
  void setGameController(IGameController *gameController) override;
};
