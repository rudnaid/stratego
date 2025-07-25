#pragma once
#include <SDL_image.h>

class Texture {
  SDL_Texture *texture;

public:
  Texture();
  ~Texture();
  explicit Texture(SDL_Texture *texture);
  Texture(const Texture &other) = delete;
  Texture &operator=(const Texture &other) = delete;
  Texture(Texture &&other) noexcept;
  Texture &operator=(Texture &&other) noexcept;
  void render(SDL_Renderer *renderer, const SDL_Rect *rect) const;
};
