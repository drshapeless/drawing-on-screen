#include "game.hh"
#include "config.hh"
#include "helpers.hh"

#include <stdlib.h>
#include <time.h>
#include <vector>

void Game::init() {
    // make snake_head at the middle of the screen, facing up
    snake_head = (GRID_HEIGHT / 2 * GRID_WIDTH) + (GRID_WIDTH / 2);
    // make three block body
    snake_body.clear();
    snake_body.push_back(snake_head + GRID_WIDTH);
    snake_body.push_back(snake_head + GRID_WIDTH * 2);
    snake_body.push_back(snake_head + GRID_WIDTH * 3);

    // a random position for apple
    srand(time(NULL));
    apple = rand() % (GRID_WIDTH * GRID_HEIGHT);

    face_direction = DIRECTION_UP;
    dead = false;
}

void Game::tick() {
    int next_head;
    switch (face_direction) {
    case 0: // up
        if (snake_head < GRID_WIDTH) {
            dead = true;
            return;
        }
        next_head = snake_head - GRID_WIDTH;
        break;
    case 1: // right
        if ((snake_head % GRID_WIDTH) == GRID_WIDTH - 1) {
            dead = true;
            return;
        }
        next_head = snake_head + 1;
        break;
    case 2: // down
        if (snake_head >= (GRID_WIDTH * (GRID_HEIGHT - 1))) {
            dead = true;
            return;
        }
        next_head = snake_head + GRID_WIDTH;
        break;
    case 3: // left
        if ((snake_head % GRID_WIDTH) == 0) {
            dead = true;
            return;
        }
        next_head = snake_head - 1;
        break;
    default:
        error_log("something is wrong about the direction");
        break;
    }

    for (auto body : snake_body) {
        if (next_head == body) {
            dead = true;
            return;
        }
    }

    snake_body.push_front(snake_head);
    snake_head = next_head;

    if (next_head == apple) {
        generate_new_apple();
    } else {
        snake_body.pop_back();
    }
}

void Game::change_direction(uint8_t direction) {
    switch (direction) {
    case DIRECTION_UP:
        if (face_direction == DIRECTION_DOWN ||
            face_direction == DIRECTION_UP) {
            return;
        }
        break;
    case DIRECTION_RIGHT:
        if (face_direction == DIRECTION_LEFT ||
            face_direction == DIRECTION_RIGHT) {
            return;
        }
        break;
    case DIRECTION_DOWN:
        if (face_direction == DIRECTION_UP ||
            face_direction == DIRECTION_DOWN) {
            return;
        }
        break;
    case DIRECTION_LEFT:
        if (face_direction == DIRECTION_LEFT ||
            face_direction == DIRECTION_RIGHT) {
            return;
        }
        break;
    }

    face_direction = direction;
}

void Game::generate_new_apple() {
    std::vector<bool> blocks = {};
    for (int i = 0; i < GRID_WIDTH * GRID_HEIGHT; i++) {
        blocks.push_back(false);
    }

    for (auto body : snake_body) {
        blocks.at(body) = true;
    }

    blocks.at(snake_head) = true;

    std::vector<uint32_t> empty_blocks = {};
    for (int i = 0; i < GRID_WIDTH * GRID_HEIGHT; i++) {
        if (blocks.at(i) == false) {
            empty_blocks.push_back(i);
        }
    }

    int index = rand() % empty_blocks.size();

    apple = empty_blocks.at(index);
}
