#include "game.h"
#include "raylib.h"
#include "wav1.h"
#include "wav2.h"
#include <deque>
#include <raymath.h>

Game::Game() {
  InitAudioDevice();

  // wav1 = LoadWave("assets/sounds/eat.wav");
  // wav2 = LoadWave("assets/sounds/wall.wav");

  // ExportWaveAsCode(wav1, "wav1.h");
  // ExportWaveAsCode(wav2, "wav2.h");

  wav1.frameCount = WAV1_FRAME_COUNT;
  wav1.sampleRate = WAV1_SAMPLE_RATE;
  wav1.sampleSize = WAV1_SAMPLE_SIZE;
  wav1.channels = WAV1_CHANNELS;
  wav1.data = WAV1_DATA;

  wav2.frameCount = WAV2_FRAME_COUNT;
  wav2.sampleRate = WAV2_SAMPLE_RATE;
  wav2.sampleSize = WAV2_SAMPLE_SIZE;
  wav2.channels = WAV2_CHANNELS;
  wav2.data = WAV2_DATA;

  eatSound = LoadSoundFromWave(wav1);
  wallSound = LoadSoundFromWave(wav2);
}

Game::~Game() {
  UnloadWave(wav1);
  UnloadWave(wav2);
  UnloadSound(eatSound);
  UnloadSound(wallSound);
  CloseAudioDevice();
}

void Game::Draw() {
  food.Draw();
  snake.Draw();
}

void Game::Update() {
  if (running) {
    snake.Update();
    CheckCollisionWithFood();
    CheckCollisionWithEdges();
    CheckCollisionWithTail();
  }
}

void Game::CheckCollisionWithFood() {
  if (Vector2Equals(snake.body[0], food.position)) {
    food.position = food.GenerateRandomPos(snake.body);
    snake.addSegment = true;
    score++;
    PlaySound(eatSound);
  }
}

void Game::CheckCollisionWithEdges() {
  if (snake.body[0].x == cellCount || snake.body[0].x == -1) {
    GameOver();
  }
  if (snake.body[0].y == cellCount || snake.body[0].y == -1) {
    GameOver();
  }
}

void Game::CheckCollisionWithTail() {
  std::deque<Vector2> headlessBody = snake.body;
  headlessBody.pop_front();
  if (snake.ElementInDeque(snake.body[0], headlessBody)) {
    GameOver();
  }
}

void Game::GameOver() {
  snake.Reset();
  food.position = food.GenerateRandomPos(snake.body);
  running = false;
  score = 0;
  PlaySound(wallSound);
}