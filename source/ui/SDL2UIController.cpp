#include "SDL2UIController.h"
#include <SDL_image.h>
#include <filesystem>
#include <iostream>
#include <thread>
using namespace std;
#define WINDOW_WIDTH 1024
#define WINDOW_HEIGHT 768

static const std::string PATH = "../../resources/";
// static auto const PATH = (filesystem::current_path() /
// "resources\\").u8string();
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
  backgroundRect = {0, 0, WINDOW_WIDTH, WINDOW_HEIGHT};
}
void SDL2UIController::loadTextures() {
  backgroundTexture = loadTexture(PATH + "background.png");
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
  }
}
void SDL2UIController::drawBackground() {
  backgroundTexture.render(renderer, &backgroundRect);
}

void SDL2UIController::render() {
  SDL_RenderClear(renderer);
  drawBackground();
  SDL_RenderPresent(renderer);
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
