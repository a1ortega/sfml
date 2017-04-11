
//
// Disclaimer:
// ----------
//
// This code will work only if you selected window, graphics and audio.
//
// Note that the "Run Script" build phase will copy the required frameworks
// or dylibs to your application bundle so you can execute it on any OS X
// computer.
//
// Your resource files (images, sounds, fonts, ...) are also copied to your
// application bundle. To get the path to these resources, use the helper
// function `resourcePath()` from ResourcePath.hpp
//

#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>

// Here is a small helper for you! Have a look.
#include "ResourcePath.hpp"

int main(int, char const**)
{
    
    
    
 //Init
    // Create the main window
    sf::RenderWindow window(sf::VideoMode(500, 500), "Battleship");

    // Set the Icon
    sf::Image icon;
    if (!icon.loadFromFile(resourcePath() + "players_ship_1-sheet0.png")) {
        return EXIT_FAILURE;
    }
    window.setIcon(icon.getSize().x, icon.getSize().y, icon.getPixelsPtr());

//Load Resources
    
    // Load a sprite to display
    sf::Texture texture;
    if (!texture.loadFromFile(resourcePath() + "tiledbackground.png")) {
        return EXIT_FAILURE;
    }
    
    sf::Sprite sprite(texture);
    
    
    // Load a sprite to display
    sf::Texture backgroundTile;
    if (!backgroundTile.loadFromFile(resourcePath() + "tiledbackground.png")) {
        return EXIT_FAILURE;
    }
    
    sf::Sprite backgroundSprite(backgroundTile);


    
    
    // Create a graphical text to display
    sf::Font font;
    if (!font.loadFromFile(resourcePath() + "sansation.ttf")) {
        return EXIT_FAILURE;
    }
    sf::Text text("Hello SFML", font, 50);
    text.setFillColor(sf::Color::Black);

    
    
    
    
    // Load a music to play
    sf::Music backgroundMusic;
    if (!backgroundMusic.openFromFile(resourcePath() + "navy.ogg")) {
        return EXIT_FAILURE;
    }
    
    
 ////******* MAIN GAME ******** /////

    // Play the music
    backgroundMusic.play();

    // Start the game loop
    while (window.isOpen())
    {
        // Process events
        sf::Event event;
        while (window.pollEvent(event))
        {
            // Close window: exit
            if (event.type == sf::Event::Closed) {
                window.close();
            }

            // Escape pressed: exit
            if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape) {
                window.close();
            }
        }

        // Clear screen
        window.clear();

        //Draw the sprite
        window.draw(backgroundSprite);

        // Draw the string
        window.draw(text);

        // Update the window
        window.display();
    }

    return EXIT_SUCCESS;
}
