#include <SFML/Graphics.hpp>
#include <cstdlib>
#include <ctime>
#include <string>
#include "../include/tetrisPiece.h"
#include "../include/red.h"
#include "../include/blue.h"
#include "../include/green.h"
#include "../include/brown.h"
#include "../include/purple.h"
#include "../include/orange.h"
#include "../include/grey.h"
#include "../include/image_manager.h"
#include "../include/graphicEngine.h"

graphicEngine::graphicEngine() {

    // changeArray is the quasi 2D array that holds our board information
    // various numbers represent different colors
    // Haven't done an Array of arrays so we can guarentee contigous memory
    //  - in restrospect removing lines would've been much easier if I had of used a traditional 2D array
    changeArray = new int[sizeX * sizeY];

    for(int i = 0; i < sizeX * sizeY; i++) {
        changeArray[i] = 0;
    }
    pieceStarted = false;
    // white pieces in the array are not utilised yet but could be in the future
    imgNames[0] = "./images/white.bmp";
    imgNames[1] = "./images/red.bmp";
    imgNames[2] = "./images/blue.bmp";
    imgNames[3] = "./images/green.bmp";
    imgNames[4] = "./images/brown.bmp";
    imgNames[5] = "./images/purple.bmp";
    imgNames[6] = "./images/orange.bmp";
    imgNames[7] = "./images/grey.bmp";
    imgNames[8] = "./images/white.bmp";

}

graphicEngine::~graphicEngine() {

    delete[] changeArray;
    delete[] imgNames;
}

int graphicEngine::initialiseRandomPiece() {
    // create a random piece here
    srand((unsigned)time(0));
    int rand_num = rand() % 7 + 1;

    if (rand_num == 1) {
        tp = &rd;
    } else if (rand_num == 2) {
        tp = &bl;
    } else if (rand_num == 3) {
        tp = &gr;
    } else if (rand_num == 4) {
        tp = &br;
    } else if (rand_num == 5) {
        tp = &pu;
    } else if (rand_num == 6) {
        tp = &ora;
    } else if (rand_num == 7) {
        tp = &gry;
    }

    if (tp->createPiece(changeArray) == 1) {
        // Game Over
        return 1;
    }

    pieceStarted = true;
    return 0;
}


int graphicEngine::runTurn(sf::RenderWindow *App) {
    bool lineCleared;
    bool thisLineCleared;
    int numRemoved;

    numRemoved = 0;

    if (pieceStarted == false) {
        if (initialiseRandomPiece() != 0) {
            // return failed to end game
            return 1;
        }
    } else {
        if (tp->moveDown(changeArray) == 1) {
            pieceStarted = false;

            // Check for a completed line here
            // search from the bottom up though so we don't have to loop through the entire array more than once
            lineCleared = false;
            for (int i = sizeY; i != 0; --i) {
                thisLineCleared = true;

                for (int j = 0; j < sizeX; j++) {
                    if (changeArray[(i * 10) + j] == 0) {
                        thisLineCleared = false;
                    }
                }
                if (thisLineCleared == true) {
                    lineCleared = true;
                    numRemoved++;
                }
                if (lineCleared == true) {
                    numRemoved = removeLine(i, numRemoved);
                }
            }

        }
    }
    refreshScreen(App);
    return 0;
}

int graphicEngine::removeLine(int LineNo, int numRemoved) {
    // This is a recursive function that removes the lineNo given and ensures it doesn't fill the removed line with another filled line
    bool repeat;

    repeat = true;
    for (int p = 0; p < sizeX; p++) {
        if (LineNo - numRemoved < 0) {
            for (int p = 0; p < sizeX; p++) {
                changeArray[(LineNo * 10) + p] = 0;
                repeat = false;
            }
        } else {
            changeArray[(LineNo * 10) + p] = changeArray[((LineNo * 10) - (numRemoved * 10)) + p];
            if (changeArray[(LineNo * 10) + p] == 0) {
                repeat = false;
            }
        }
    }
    if (repeat == true) {
        return removeLine(LineNo, numRemoved + 1);
    } else {
        return numRemoved;
    }

}

void graphicEngine::refreshScreen(sf::RenderWindow *App) {
    for (int i = 0; i < sizeY; i++) {
        for (int j = 0; j < sizeX; j++) {
            if (changeArray[(i * 10) + j] != 0) {
                sprite.SetImage(img_mgr.get_image(imgNames[changeArray[(i * 10) + j]]));
                sprite.SetX(j * 40);
                sprite.SetY(i * 40);
                App->Draw(sprite);
            }
        }
    }
}

int graphicEngine::moveLeft(sf::RenderWindow *App) {
    if (pieceStarted == true) {
        tp->moveLeft(changeArray);
        refreshScreen(App);
        return 0;
    } else {
        return 1;
    }
}

int graphicEngine::moveRight(sf::RenderWindow *App) {
    if (pieceStarted == true) {
        tp->moveRight(changeArray);
        refreshScreen(App);
        return 0;
    } else {
        return 1;
    }
}

int graphicEngine::turnPiece(sf::RenderWindow *App) {
    if (pieceStarted == true) {
        tp->turnPiece(changeArray);
        refreshScreen(App);
        return 0;
    } else {
        return 1;
    }
}

