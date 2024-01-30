#ifndef H_GAME
#define H_GAME

#include "food.h"
#include "raylib.h"
#include "snake.h"

class Game {
public:
  int cellSize = 20;
  int cellCount = 20;
  int offset = 30;
  int score = 0;
  bool running = true;
  Wave wav1;
  Wave wav2;
  Sound eatSound;
  Sound wallSound;

  Snake snake = Snake(cellSize, offset);
  Food food = Food(cellSize, cellCount, offset, snake.body);

  Game();
  ~Game();

  void Draw();
  void Update();
  void CheckCollisionWithFood();
  void CheckCollisionWithEdges();
  void CheckCollisionWithTail();
  void GameOver();
};

#endif // H_GAME