#include "../include/tetrisPiece.h"
#include "../include/brown.h"

brown::brown()
{
    //ctor
    orientation = 0;
    centerPiece = 14;
    pOne = 5;
    pTwo = 15;
    pThree = 14;
    pFour = 24;

}

brown::~brown()
{
    //dtor
}

int brown::createPiece(int arrChng[]){
    if (arrChng[pOne] != 0 || arrChng[pTwo] != 0 || arrChng[pThree] != 0 || arrChng[pFour] != 0)
        return 1;
    arrChng[pOne] = 4;
    arrChng[pTwo] = 4;
    arrChng[pThree] = 4;
    arrChng[pFour] = 4;
    return 0;
}

int brown::moveLeft(int arrChng[]){
    if (tetrisPiece::moveLeft(arrChng, &pOne, &pTwo, &pThree, &pFour, 4) == 0) {
            centerPiece = centerPiece - 1;
            return 0;
    }
    return 1;

}

int brown::moveRight(int arrChng[]){
    if (tetrisPiece::moveRight(arrChng, &pOne, &pTwo, &pThree, &pFour, 4) == 0) {
            centerPiece = centerPiece + 1;
            return 0;
    }
    return 1;

}

int brown::moveDown(int arrChng[]){
    if (tetrisPiece::moveDown(arrChng, &pOne, &pTwo, &pThree, &pFour, 4) == 0) {
            centerPiece = centerPiece + 10;
            return 0;
    }
    orientation = 0;
    centerPiece = 14;
    pOne = 5;
    pTwo = 15;
    pThree = 14;
    pFour = 24;
    return 1;

}

int brown::turnPiece(int arrChng[]) {
    if (orientation == 0) {
        if (tetrisPiece::turnPiece(arrChng, &pOne, &pTwo, &pThree, &pFour, 4, centerPiece, 0) == 0) {
                orientation = 1;
                return 0;
        }
    } else {
        if (tetrisPiece::turnPiece(arrChng, &pOne, &pTwo, &pThree, &pFour, 4, centerPiece, 1) == 0) {
                orientation = 0;
                return 0;
        }

    }
    return 1;
}
