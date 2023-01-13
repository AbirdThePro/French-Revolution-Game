#include <iostream>
using namespace std;

#include <SFML/Graphics.hpp>
using namespace sf;

// loads sprite from image
Sprite loadSprite(char* filename) {
    // stores texture
    Texture texture;
    // attempts to load from the file
    if (!texture.loadFromFile(filename)) {
        // if it cannot load, print an error message
        cout << "Unable to load image " << filename << endl;
        return;
    }
    // if loading succeeded, return sprite object from texture
    return Sprite(texture);
}

// draws sprite with given information
void drawSprite(RenderWindow window, Sprite sprite, int x, int y, int width, int height, int rotation) {
    // updates sprite information if necessary
    if (sprite.getPosition() != Vector2f(x, y)) sprite.setPosition(x, y);
    if (sprite.getScale() != Vector2f(width, height)) sprite.setScale(width, height);
    if (sprite.getRotation() != rotation) sprite.setRotation(rotation);

    // draws sprite
    window.draw(sprite);
}
