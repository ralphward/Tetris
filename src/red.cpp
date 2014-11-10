#include "../include/tetrisPiece.h"
#include "../include/red.h"

red::red()
{
    orientation = 0;
    centerPiece = 24;
    pOne = 4;
    pTwo = 14;
    pThree = 24;
    pFour = 34;
    //ctor
}

red::~red()
{
    //dtor
}

int red::createPiece(int arrChng[]){
    if (arrChng[pOne] != 0 || arrChng[pTwo] != 0 || arrChng[pThree] != 0 || arrChng[pFour] != 0)
        return 1;
    arrChng[pOne] = 1;
    arrChng[pTwo] = 1;
    arrChng[pThree] = 1;
    arrChng[pFour] = 1;
    return 0;
}

int red::moveLeft(int arrChng[]){
    if (tetrisPiece::moveLeft(arrChng, &pOne, &pTwo, &pThree, &pFour, 1) == 0) {
            centerPiece = centerPiece - 1;
            return 0;
    }
    return 1;
}

int red::moveRight(int arrChng[]){
    if (tetrisPiece::moveRight(arrChng, &pOne, &pTwo, &pThree, &pFour, 1) == 0) {
            centerPiece = centerPiece + 1;
            return 0;
    }
    return 1;

}

int red::moveDown(int arrChng[]){
    if (tetrisPiece::moveDown(arrChng, &pOne, &pTwo, &pThree, &pFour, 1) == 0) {
            centerPiece = centerPiece + 10;
            return 0;
    }
    orientation = 0;
    centerPiece = 24;
    pOne = 4;
    pTwo = 14;
    pThree = 24;
    pFour = 34;
    return 1;

}

int red::turnPiece(int arrChng[]) {
    if (orientation == 0) {
        if (tetrisPiece::turnPiece(arrChng, &pOne, &pTwo, &pThree, &pFour, 1, centerPiece, 0) == 0) {
                orientation = 1;
                return 0;
        }
    } else {
        if (tetrisPiece::turnPiece(arrChng, &pOne, &pTwo, &pThree, &pFour, 1, centerPiece, 1) == 0) {
                orientation = 0;
                return 0;
        }

    }
    return 1;

}
