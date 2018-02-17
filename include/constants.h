#pragma once

#include <cstdint>

constexpr uint32_t TILE_W = 16;
constexpr uint32_t TILE_H = 16;

constexpr uint32_t ONSCREEN_TILES_W = 20;
constexpr uint32_t ONSCREEN_TILES_H = 15;

//320
constexpr uint32_t KQ_SCREEN_W = TILE_W * ONSCREEN_TILES_W;

//240
constexpr uint32_t KQ_SCREEN_H = TILE_H * ONSCREEN_TILES_H;

//640
constexpr uint32_t KQ_SCALED_SCREEN_W = KQ_SCREEN_W * 2;

//480
constexpr uint32_t KQ_SCALED_SCREEN_H = KQ_SCREEN_H * 2;

// 352, or (320 + 16 + 16) == screen dimensions plus 1 tile on left and 1 tile on right
constexpr uint32_t SCREEN_W2 = (KQ_SCREEN_W + 2 * TILE_W);

// 272, or (240 + 16 + 16) == screen dimensions plus 1 tile on top and 1 tile on bottom.
constexpr uint32_t SCREEN_H2 = (KQ_SCREEN_H + 2 * TILE_H);

// The same blit() function was called all over the place, so this simplifies the call.
#define fullblit(a, b) blit((a), (b), 0, 0, 0, 0, SCREEN_W2, SCREEN_H2)
