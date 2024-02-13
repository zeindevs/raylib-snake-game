#include <raylib.h>

#include "game.hpp"

Color green = Color{173, 204, 96, 255};
Color darkGreen = Color{43, 51, 24, 255};

int cellSize = 20;
int cellCount = 20;
int offset = 30;

double lastUpdateTime = 0;

bool eventTriggered(double interval) {
  double currentTime = GetTime();
  if (currentTime - lastUpdateTime >= interval) {
    lastUpdateTime = currentTime;
    return true;
  }
  return false;
}

int main() {
  InitWindow(2 * offset + cellSize * cellCount, 2 * offset + cellSize * cellCount, "Snake Game!");
  SetTargetFPS(60);

  Game game = Game();
  Rectangle rectangle = Rectangle{
      (float)(offset - 5),
      (float)(offset - 5),
      (float)(cellSize * cellCount + 10),
      (float)(cellSize * cellCount + 10)};

  while (WindowShouldClose() == false) {
    BeginDrawing();

    // Update
    if (eventTriggered(0.2)) {
      game.Update();
    }

    // Controls
    if (IsKeyPressed(KEY_UP) && game.snake.direction.y != 1) {
      game.snake.direction = {0, -1};
      game.running = true;
    }
    if (IsKeyPressed(KEY_DOWN) && game.snake.direction.y != -1) {
      game.snake.direction = {0, 1};
      game.running = true;
    }
    if (IsKeyPressed(KEY_LEFT) && game.snake.direction.x != 1) {
      game.snake.direction = {-1, 0};
      game.running = true;
    }
    if (IsKeyPressed(KEY_RIGHT) && game.snake.direction.x != -1) {
      game.snake.direction = {1, 0};
      game.running = true;
    }

    // Drawing
    ClearBackground(green);
    DrawRectangleLinesEx(rectangle, 5, darkGreen);
    DrawText("Snake Game!", offset - 5, 5, 20, darkGreen);
    DrawText(
        TextFormat("%i", game.score),
        offset - 5,
        offset + cellSize * cellCount + 10,
        20,
        darkGreen);
    game.Draw();

    EndDrawing();
  }

  CloseWindow();

  return 0;
}