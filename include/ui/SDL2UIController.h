#pragma once
#include <SDL_render.h>
#include <SDL_video.h>
#include <atomic>
#include <thread>
#include <vector>

#include "IGameController.h"
#include "ISDL2UI.h"
#include "Texture.h"

class SDL2UIController : public ISDL2UI {
  IGameController *game;

  SDL_Window *window;
  SDL_Renderer *renderer;

  SDL_Rect backgroundRect;
  Texture backgroundTexture;

  SDL_Rect sidepanelRect;
  Texture sidepanelTexture;

  std::vector<std::vector<SDL_Rect>> boardRectangles;

  std::vector<SDL_Rect> unitsRectangles;
  std::vector<Texture> unitsTextures;

  bool isDragging;
  SDL_Point originalPosition;
  SDL_Rect *selectedUnitRect;

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

  void loadBoard(const GameState &gameState);

  void drawBoard(const Board &board);

  void drawUnits();

  void loadUnits(const std::vector<__resharper_unknown_type> &units);

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
  bool isMouseInsideRect(int mouseX, int mouseY, SDL_Rect const& rect);
  void handleMouseDownEvent(const SDL_Event &e, bool &isDragging,SDL_Point &originalPosition);
  void handleMouseMotionEvent(const SDL_Event &e, const bool &isDragging);
  void handleMouseUpEvent(const SDL_Event &e, SDL_Point &originalPosition);
  //void setupBoard(const std::vector<Unit> &units );
};
