#include <SFML/Graphics.hpp>
#include "../include/tetrisPiece.h"
#include "../include/image_manager.h"
#include "../include/red.h"
#include "../include/blue.h"
#include "../include/green.h"
#include "../include/brown.h"
#include "../include/purple.h"
#include "../include/orange.h"
#include "../include/grey.h"
#include "../include/graphicEngine.h"

int main()
{
    // Create the main window
    sf::RenderWindow App(sf::VideoMode(400, 720), "Tetris");
    sf::Clock Clock;
    float Time;
    bool takeTurn = true;

    // Load graphic engine and Sprites
    graphicEngine ge;

	// Start the game loop
    while (App.IsOpened())
    {
        //put key listeners here
        sf::Event Event;
        while(App.GetEvent(Event)) {
            // Close window : exit
            if (Event.Type == sf::Event::Closed) {
                App.Close();
            }

            if (Event.Type == sf::Event::KeyPressed && (Event.Key.Code == sf::Key::Left)) {
                // left key is pressed: move our character
                if (ge.moveLeft(&App) == 0) {
                    App.Display();
                    App.Clear();
                }
            }

            if (Event.Type == sf::Event::KeyPressed && (Event.Key.Code == sf::Key::Up)) {
                // up key is pressed: move our character
                if (ge.turnPiece(&App) == 0) {
                    App.Display();
                    App.Clear();
                }
            }

            if (Event.Type == sf::Event::KeyPressed && (Event.Key.Code == sf::Key::Down)) {
                // down key is pressed: move our character
                if (ge.runTurn(&App) != 0) {
                    App.Close();
                }
                App.Display();
                App.Clear();
            }

            if (Event.Type == sf::Event::KeyPressed && (Event.Key.Code == sf::Key::Right)) {
                // right key is pressed: move our character
                if (ge.moveRight(&App) == 0) {
                    App.Display();
                    App.Clear();
                }
            }

        }
        Time = Clock.GetElapsedTime();
        if (Time > 0.75f) {
            takeTurn = true;
        }

        if (takeTurn == true) {
            // Process events
            if (ge.runTurn(&App) != 0) {
                App.Close();
            }
            App.Display();
            Clock.Reset();

            // Clear screen
            App.Clear();

            takeTurn = false;
        }

    }

    return EXIT_SUCCESS;
}

