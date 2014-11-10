#include "../include/tetrisPiece.h"
#include "../include/orange.h"

orange::orange()
{
    //ctor
    centerPiece = 14;
    pOne = 5;
    pTwo = 4;
    pThree = 14;
    pFour = 24;
}

orange::~orange()
{
    //dtor
}

int orange::createPiece(int arrChng[]){
    if (arrChng[pOne] != 0 || arrChng[pTwo] != 0 || arrChng[pThree] != 0 || arrChng[pFour] != 0)
        return 1;
    arrChng[pOne] = 6;
    arrChng[pTwo] = 6;
    arrChng[pThree] = 6;
    arrChng[pFour] = 6;
    return 0;
}

int orange::moveLeft(int arrChng[]){
    if (tetrisPiece::moveLeft(arrChng, &pOne, &pTwo, &pThree, &pFour, 6) == 0) {
            centerPiece = centerPiece - 1;
            return 0;
    }
    return 1;
}

int orange::moveRight(int arrChng[]){
    if (tetrisPiece::moveRight(arrChng, &pOne, &pTwo, &pThree, &pFour, 6) == 0) {
            centerPiece = centerPiece + 1;
            return 0;
    }
    return 1;

}

int orange::moveDown(int arrChng[]){
    if (tetrisPiece::moveDown(arrChng, &pOne, &pTwo, &pThree, &pFour, 6) == 0) {
            centerPiece = centerPiece + 10;
            return 0;
    }
    centerPiece = 14;
    pOne = 5;
    pTwo = 4;
    pThree = 14;
    pFour = 24;
    return 1;

}

int orange::turnPiece(int arrChng[]) {
    if (tetrisPiece::turnPiece(arrChng, &pOne, &pTwo, &pThree, &pFour, 6, centerPiece, 0) == 0) {
            return 0;
    }
    return 1;

}
