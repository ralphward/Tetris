#include "../include/tetrisPiece.h"
#include "../include/green.h"

green::green()
{
    //ctor
    orientation = 0;
    centerPiece = 14;
    pOne = 3;
    pTwo = 13;
    pThree = 14;
    pFour = 24;
}

green::~green()
{
    //dtor
}

int green::createPiece(int arrChng[]){
    if (arrChng[pOne] != 0 || arrChng[pTwo] != 0 || arrChng[pThree] != 0 || arrChng[pFour] != 0)
        return 1;
    arrChng[pOne] = 3;
    arrChng[pTwo] = 3;
    arrChng[pThree] = 3;
    arrChng[pFour] = 3;
    return 0;
}

int green::moveLeft(int arrChng[]){
    if (tetrisPiece::moveLeft(arrChng, &pOne, &pTwo, &pThree, &pFour, 3) == 0) {
            centerPiece = centerPiece - 1;
            return 0;
    }
    return 1;

}

int green::moveRight(int arrChng[]){
    if (tetrisPiece::moveRight(arrChng, &pOne, &pTwo, &pThree, &pFour, 3) == 0) {
            centerPiece = centerPiece + 1;
            return 0;
    }
    return 1;

}

int green::moveDown(int arrChng[]){
    if (tetrisPiece::moveDown(arrChng, &pOne, &pTwo, &pThree, &pFour, 3) == 0) {
            centerPiece = centerPiece + 10;
            return 0;
    }
    orientation = 0;
    centerPiece = 14;
    pOne = 3;
    pTwo = 13;
    pThree = 14;
    pFour = 24;
    return 1;

}

int green::turnPiece(int arrChng[]) {
    if (orientation == 0) {
        if (tetrisPiece::turnPiece(arrChng, &pOne, &pTwo, &pThree, &pFour, 3, centerPiece, 0) == 0) {
                orientation = 1;
                return 0;
        }
    } else {
        if (tetrisPiece::turnPiece(arrChng, &pOne, &pTwo, &pThree, &pFour, 3, centerPiece, 1) == 0) {
                orientation = 0;
                return 0;
        }

    }
    return 1;
}
