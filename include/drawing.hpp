#include <iostream>
using namespace std;

#include <unistd.h>
#include <string.h>

#include <SFML/Graphics.hpp>
using namespace sf;

typedef unsigned int uint;

// game window
RenderWindow window;

// pauses for x milliseconds
void pause(uint x) {
    sleep(milliseconds(x));
}

// creates window
void createWindow(char* title, uint width, uint height) {
    RenderWindow window(VideoMode(width, height), title);
}

// loads sprite from image
Sprite loadSprite(const char* filename) {
    // stores texture
    Texture texture;
    texture.loadFromFile(filename);
    // if loading succeeded, create sprite object from texture
    Sprite sprite(texture);
    // sets origin to center
    sprite.setOrigin(Vector2f(sprite.getScale().x / 2, sprite.getScale().y / 2));
    // returns new sprite object
    return sprite;
}

// draws sprite with given information
void drawSprite(Sprite sprite, int x, int y, uint width, uint height, uint rotation) {
    // updates sprite information if necessary
    if (sprite.getPosition() != Vector2f(x, y)) sprite.setPosition(x, y);
    if (sprite.getScale() != Vector2f(width, height)) sprite.setScale(width, height);
    if (sprite.getRotation() != rotation) sprite.setRotation(rotation);

    // draws sprite
    window.draw(sprite);
}
