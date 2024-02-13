#include "food.hpp"

#include <raylib.h>
#include <raymath.h>

#include <deque>

#include "food_image.h"

Food::Food(int cellSize, int cellCount, int offset, std::deque<Vector2> snakeBody) {
  this->cellSize = cellSize;
  this->cellCount = cellCount;
  this->offset = offset;

  // Image image = LoadImage("assets/images/food.png");

  // ExportImageAsCode(image, "food_image.h");

  image = {0};
  image.format = FOOD_IMAGE_FORMAT;
  image.height = FOOD_IMAGE_HEIGHT;
  image.width = FOOD_IMAGE_WIDTH;
  image.data = FOOD_IMAGE_DATA;
  image.mipmaps = 1;

  texture = LoadTextureFromImage(image);
  position = GenerateRandomPos(snakeBody);
}

Food::~Food() {
  UnloadImage(image);
  UnloadTexture(texture);
}

void Food::Draw() {
  DrawTexture(texture, offset + position.x * cellSize, offset + position.y * cellSize, WHITE);
}

bool Food::ElementInDeque(Vector2 element, std::deque<Vector2> deque) {
  for (unsigned int i = 0; i < deque.size(); i++) {
    if (Vector2Equals(deque[i], element)) return true;
  }
  return false;
}

Vector2 Food::GenerateRandomCell() {
  float x = GetRandomValue(0, cellCount - 1);
  float y = GetRandomValue(0, cellCount - 1);
  return Vector2{x, y};
}

Vector2 Food::GenerateRandomPos(std::deque<Vector2> snakeBody) {
  Vector2 position = GenerateRandomCell();
  while (ElementInDeque(position, snakeBody)) {
    position = GenerateRandomCell();
  }
  return position;
}