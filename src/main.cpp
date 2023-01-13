// custom constant names for more clarity
#ifdef __MINGW32__
#define SFML
#endif
#ifdef __clang__
#define WASM
#endif

// SFML
#ifdef SFML
#include <drawing.hpp>
#endif

// WASM bindings
#ifdef WASM
#include <wasm-drawing.hpp>
#endif

// constants
const int windowWidth = 500;
const int windowHeight = 400;
const int gravity = -2;
const int jumpForce = 20;
const uint fps = 20;
const uint pauseTime = 1000 / fps;

// character that is in use
enum Character {
    King,
    Queen
};

// peasant heads (obstacles)
struct Obstacle {};

// stores the current state of the game
struct GameState {
    Character character;
    int y;
    int velocity;
    uint score;
};

// GameState instance
struct GameState state;

// main function is entry point
int main() {
    // creates window
    #ifdef SFML
    //RenderWindow window(VideoMode(500, 400), String("French Revolution Game"));
    #endif
    #ifdef WASM
    // wasm window implementation here
    #endif

    Sprite king = loadSprite("king.png");

    // main loop runs as long as window is open
    while (window.isOpen()) {
        // event loop
        Event event;
        while (window.pollEvent(event)) {
            if (event.type == event.Closed) {
                window.close();
            }
            if (event.type == event.KeyPressed) {
                if (event.key.code == Keyboard::Space) {
                    state.velocity = jumpForce;
                }
            }
        }

        // clears display
        window.clear();

        // drawing here
        drawSprite(king, 100, state.y, 61, 61, 0);

        // updates display
        window.display();
        pause(pauseTime);
    }

    // ends program with success
    return 0;
}
