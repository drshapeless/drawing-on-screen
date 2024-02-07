#ifndef GAME_HH
#define GAME_HH

#include <deque>

enum SnakeDirection {
    DIRECTION_UP,
    DIRECTION_RIGHT,
    DIRECTION_DOWN,
    DIRECTION_LEFT,
};

struct Game {
public:
    std::deque<uint32_t> snake_body = {};
    uint32_t snake_head = 0;
    // 0 up, 1 right, 2 down, 3 left
    uint8_t face_direction = DIRECTION_UP;
    uint32_t apple = 0;
    bool dead = false;

    void init();
    void tick();
    void change_direction(uint8_t direction);

private:
    void generate_new_apple();
};

#endif // GAME_HH
