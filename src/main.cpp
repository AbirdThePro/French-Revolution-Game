// SFML
#ifdef __MINGW32__
#include <drawing.hpp>
#endif
#ifndef __clang__
#include <wasm-drawing.hpp>
#endif

// main function is entry point
int main() {
    // creates window
    RenderWindow window(sf::VideoMode(200, 200), "SFML works!");

    // creates circle and sets color to green
    CircleShape shape(100.f);
    shape.setFillColor(sf::Color::Green);

    // main loop runs as long as window is open
    while (window.isOpen()) {
        // event loop
        Event event;
        while (window.pollEvent(event)) {
            if (event.type == event.Closed) {
                window.close();
            }
        }

        // clears display
        window.clear();

        // draws circle
        window.draw(shape);

        // updates display
        window.display();
    }

    // ends program with success
    return 0;
}
