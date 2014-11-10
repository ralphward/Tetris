#include "../include/tetrisPiece.h"
#include "../include/blue.h"

blue::blue()
{
    //ctor
    centerPiece = 14;
    pOne = 4;
    pTwo = 5;
    pThree = 14;
    pFour = 15;
}

blue::~blue()
{
    //dtor
}

int blue::createPiece(int arrChng[]){
    if (arrChng[pOne] != 0 || arrChng[pTwo] != 0 || arrChng[pThree] != 0 || arrChng[pFour] != 0)
        return 1;
    arrChng[pOne] = 2;
    arrChng[pTwo] = 2;
    arrChng[pThree] = 2;
    arrChng[pFour] = 2;
    return 0;
}

int blue::moveLeft(int arrChng[]){
    if (tetrisPiece::moveLeft(arrChng, &pOne, &pTwo, &pThree, &pFour, 2) == 0) {
            centerPiece = centerPiece - 1;
            return 0;
    }
    return 1;
}

int blue::moveRight(int arrChng[]){
    if (tetrisPiece::moveRight(arrChng, &pOne, &pTwo, &pThree, &pFour, 2) == 0) {
            centerPiece = centerPiece + 1;
            return 0;
    }
    return 1;

}

int blue::moveDown(int arrChng[]){
    if (tetrisPiece::moveDown(arrChng, &pOne, &pTwo, &pThree, &pFour, 2) == 0) {
            centerPiece = centerPiece + 10;
            return 0;
    }
    centerPiece = 14;
    pOne = 4;
    pTwo = 5;
    pThree = 14;
    pFour = 15;
    return 1;

}

int blue::turnPiece(int arrChng[]) {
    return 1;

}
