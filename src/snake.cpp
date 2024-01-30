#include "snake.h"
#include <raylib.h>
#include <raymath.h>

Snake::Snake(int cellSize, int offset) {
  this->cellSize = cellSize;
  this->offset = offset;
}

Snake::~Snake() {}

void Snake::Draw() {
  for (unsigned int i = 0; i < body.size(); i++) {
    int x = body[i].x;
    int y = body[i].y;
    Rectangle segment = Rectangle{(float)(offset + x * cellSize),
                                  (float)(offset + y * cellSize),
                                  (float)(cellSize), (float)(cellSize)};
    DrawRectangleRounded(segment, 0.5, 6, color);
  }
}

void Snake::Update() {
  body.push_front(Vector2Add(body[0], direction));
  if (addSegment == true) {
    addSegment = false;
  } else {
    body.pop_back();
  }
}

bool Snake::ElementInDeque(Vector2 element, std::deque<Vector2> deque) {
  for (unsigned int i = 0; i < deque.size(); i++) {
    if (Vector2Equals(deque[i], element))
      return true;
  }
  return false;
}

void Snake::Reset() {
  body = {Vector2{6, 9}, Vector2{5, 9}, Vector2{4, 9}};
  direction = {1, 0};
}