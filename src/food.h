#ifndef H_FOOD
#define H_FOOD

#include "raylib.h"
#include <deque>

class Food {
  int cellSize;
  int cellCount;
  int offset;

public:
  Texture texture;
  Vector2 position;
  Image image;

  Food(int cellSize, int cellCount, int offset, std::deque<Vector2> snakeBody);
  ~Food();

  void Draw();
  bool ElementInDeque(Vector2 element, std::deque<Vector2> deque);
  Vector2 GenerateRandomCell();
  Vector2 GenerateRandomPos(std::deque<Vector2> snakeBody);
};

#endif // H_FOOD