#ifndef H_SNAKE
#define H_SNAKE

#include <deque>
#include <raylib.h>

class Snake {
private:
  int cellSize;
  int offset;
  Color color = Color{43, 51, 24, 255};

public:
  std::deque<Vector2> body = {Vector2{6, 9}, Vector2{5, 9}, Vector2{4, 9}};
  Vector2 direction = {1, 0};
  bool addSegment = false;

  Snake(int cellSize, int offset);
  ~Snake();

  void Draw();
  void Update();
  bool ElementInDeque(Vector2 element, std::deque<Vector2> deque);
  void Reset();
};

#endif // H_SNAKE