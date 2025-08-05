#include "SDL2UIController.h"
#include <SDL_image.h>
#include <filesystem>
#include <iostream>
#include <thread>

#include "GameConfig.h"

#define WINDOW_WIDTH 1024
#define WINDOW_HEIGHT 768

using namespace std;

static const string PATH = "resources/";

SDL2UIController::~SDL2UIController() {

  cout << "Destroying Texture objects" << endl;
  backgroundTexture = Texture();

  if (renderer) {
    cout << "Destroying renderer" << endl;
    SDL_DestroyRenderer(renderer);
    renderer = nullptr;
  }
  if (window) {
    cout << "Destroying window" << endl;
    SDL_DestroyWindow(window);
    window = nullptr;
  }
  IMG_Quit();
  SDL_Quit();
}

SDL2UIController::SDL2UIController() : window(nullptr), renderer(nullptr) {
  if (!init()) {
    throw std::runtime_error("Failed to initialize UI");
  }

  isDragging = false;
  selectedUnitRect = nullptr;

  initLayout();
  loadTextures();

  renderThread = std::thread(&SDL2UIController::renderLoop, this, 8);
}

void SDL2UIController::closeThread() {
  renderThreadRunning = false;
  if (renderThread.joinable()) {
    renderThread.join();
  }
}
void SDL2UIController::initLayout() {
  backgroundRect = {0, 0, WINDOW_WIDTH/3*2, WINDOW_HEIGHT};
  sidepanelRect = {WINDOW_WIDTH/3*2, 0, WINDOW_WIDTH, WINDOW_HEIGHT};
}
void SDL2UIController::loadTextures() {
  backgroundTexture = loadTexture(PATH + "background.png");
  sidepanelTexture = loadTexture(PATH + "sidepanel.png");
}
void SDL2UIController::loadUnitTexture(const string& unitName) {
  unitsTextures.push_back(loadTexture(PATH + unitName+ ".png"));
}

Texture SDL2UIController::loadTexture(const string &filename) const {
  SDL_Texture *imgTexture = IMG_LoadTexture(renderer, filename.c_str());
  if (nullptr == imgTexture) {
    cout << "File not found: " << filename
         << " SDL_image Error: " << IMG_GetError() << endl;
  }
  return Texture(imgTexture);
}

bool SDL2UIController::init() {
  if (SDL_Init(SDL_INIT_VIDEO) != 0) {
    cout << "SDL_Init Error: " << SDL_GetError() << endl;
    return false;
  }
  if (!createWindow())
    return false;
  if (!createRenderer())
    return false;
  if (!initSDLImage())
    return false;
  return true;
}

bool SDL2UIController::createRenderer() {
  if (!window)
    return false;
  renderer = SDL_CreateRenderer(
      window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
  if (renderer == nullptr) {
    cout << "SDL_CreateRenderer Error: " << SDL_GetError() << endl;
    return false;
  }
  return true;
}
bool SDL2UIController::createWindow() {
  window = SDL_CreateWindow("Stratego", SDL_WINDOWPOS_CENTERED,
                            SDL_WINDOWPOS_CENTERED, WINDOW_WIDTH, WINDOW_HEIGHT,
                            SDL_WINDOW_SHOWN);
  if (window == nullptr) {
    cout << "SDL_CreateWindow Error: " << SDL_GetError() << endl;
    return false;
  }
  return true;
}
bool SDL2UIController::initSDLImage() {
  int imgFlags = IMG_INIT_PNG | IMG_INIT_JPG;
  ;
  if (!(IMG_Init(imgFlags) & imgFlags)) {
    cout << "SDL_image could not initialize! SDL_image Error: "
         << IMG_GetError() << endl;
    return false;
  }
  return true;
}


void SDL2UIController::handleEvents() {
  SDL_Event e;

  while (SDL_PollEvent(&e) != 0) {
    if (e.type == SDL_QUIT) {

      renderThreadRunning = false;
      if (renderThread.joinable()) {
        renderThread.join();
      }
      game->stopGame();
      break;
    }
    if (e.type == SDL_MOUSEBUTTONDOWN) {
      handleMouseDownEvent(e, isDragging, originalPosition);
      break;
    }

    if (e.type == SDL_MOUSEMOTION) {
      handleMouseMotionEvent(e, isDragging);
      break;
    }

    if (e.type == SDL_MOUSEBUTTONUP) {
      handleMouseUpEvent(e, originalPosition);
      break;
    }
  }
}
void SDL2UIController::drawBackground() {
  backgroundTexture.render(renderer, &backgroundRect);
  sidepanelTexture.render(renderer, &sidepanelRect);
}

void SDL2UIController::render() {
  SDL_RenderClear(renderer);
  drawBackground();
  drawBoard();
  drawUnits();
  SDL_RenderPresent(renderer);
}

void SDL2UIController::setupBoard(const vector<Unit> &units, Player currentPlayer) {
  loadUnits(units);
}

void SDL2UIController::loadBoard() {
  boardRectangles.resize(GameConfig::ROWS);
  for (int row = 0; row < GameConfig::ROWS; row++) {
    boardRectangles[row].resize(GameConfig::COLS);
    for (int col = 0; col < GameConfig::COLS; col++) {
      boardRectangles[row][col] = {col*WINDOW_WIDTH/3*2/10, row*WINDOW_HEIGHT/10, WINDOW_WIDTH/3*2/10, WINDOW_HEIGHT/10};
    }
  }
}

void SDL2UIController::drawUnits() {
  for (int i = 0; i < unitsRectangles.size(); i++) {
      unitsTextures[i].render(renderer, &unitsRectangles[i]);
  }
}

void SDL2UIController::loadUnits(const vector<Unit> &units) {
  int xPos = WINDOW_WIDTH/3*2;
  int yPos = WINDOW_HEIGHT/12*2;
  int unitWidth = 64;
  int unitHeight = 64;
  int padding = 5;

  for (const Unit &unit : units) {
    if ((xPos+unitWidth) % WINDOW_WIDTH >= 1) {
      xPos = WINDOW_WIDTH/3*2;
      yPos += padding + unitWidth ;
    }
    unitsRectangles.push_back({xPos, yPos, unitWidth, unitHeight});
    unitsTextures.push_back(loadTexture(unit.getName()));
    xPos += padding + unitWidth ;
  }
}



void SDL2UIController::renderLoop(int delay) {
  while (renderThreadRunning) {
    render();
    this_thread::sleep_for(chrono::milliseconds(delay));
  }
  cout << "Render thread ended" << endl;
}

Move SDL2UIController::getUserMove() {
  Move move;
  return move;
}

void SDL2UIController::cleanup() {}

void SDL2UIController::clearDragPiece() {}

void SDL2UIController::showMessage(const std::string &message) {}

void SDL2UIController::setGameController(IGameController *gameController) {
  game = gameController;
}

bool SDL2UIController::isMouseInsideRect(int const mouseX, int const mouseY, SDL_Rect const& rect) {
  return (mouseX > rect.x &&
          mouseX < rect.x + rect.w &&
          mouseY > rect.y &&
          mouseY < rect.y + rect.h);
}
void SDL2UIController::handleMouseDownEvent(const SDL_Event &e, bool &isDragging,
                              SDL_Point &originalPosition) {
  int const mouseX = e.button.x;
  int const mouseY = e.button.y;

  if (!unitsRectangles.empty())
    for (auto &unitRectangle: unitsRectangles) {
      if (isMouseInsideRect(mouseX, mouseY, unitRectangle)) {
        isDragging = true;
        selectedUnitRect = &unitRectangle;
        originalPosition = {selectedUnitRect->x, selectedUnitRect->y};
        break;
      }
    }
}

void SDL2UIController::handleMouseMotionEvent(const SDL_Event &e, const bool &isDragging) {
  int const mouseX = e.motion.x;
  int const mouseY = e.motion.y;

  if (isDragging && selectedUnitRect != nullptr) {
    selectedUnitRect->x = mouseX - selectedUnitRect->w / 2;
    selectedUnitRect->y = mouseY - selectedUnitRect->h / 2;
  }
}

void SDL2UIController::handleMouseUpEvent(const SDL_Event &e, SDL_Point &originalPosition) {
  if (selectedUnitRect != nullptr) {
    isDragging = false;
    selectedUnitRect = nullptr;
    originalPosition = {0, 0};
  }
}
