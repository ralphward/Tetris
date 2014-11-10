#include "../include/tetrisPiece.h"
#include "../include/grey.h"

grey::grey()
{
    //ctor
    centerPiece = 14;
    pOne = 4;
    pTwo = 13;
    pThree = 14;
    pFour = 15;
}

grey::~grey()
{
    //dtor
}

int grey::createPiece(int arrChng[]){
    if (arrChng[pOne] != 0 || arrChng[pTwo] != 0 || arrChng[pThree] != 0 || arrChng[pFour] != 0)
        return 1;
    arrChng[pOne] = 7;
    arrChng[pTwo] = 7;
    arrChng[pThree] = 7;
    arrChng[pFour] = 7;
    return 0;
}

int grey::moveLeft(int arrChng[]){
    if (tetrisPiece::moveLeft(arrChng, &pOne, &pTwo, &pThree, &pFour, 7) == 0) {
            centerPiece = centerPiece - 1;
            return 0;
    }
    return 1;
}

int grey::moveRight(int arrChng[]){
    if (tetrisPiece::moveRight(arrChng, &pOne, &pTwo, &pThree, &pFour, 7) == 0) {
            centerPiece = centerPiece + 1;
            return 0;
    }
    return 1;

}

int grey::moveDown(int arrChng[]){
    if (tetrisPiece::moveDown(arrChng, &pOne, &pTwo, &pThree, &pFour, 7) == 0) {
            centerPiece = centerPiece + 10;
            return 0;
    }
    centerPiece = 14;
    pOne = 4;
    pTwo = 13;
    pThree = 14;
    pFour = 15;
    return 1;

}

int grey::turnPiece(int arrChng[]) {
    if (tetrisPiece::turnPiece(arrChng, &pOne, &pTwo, &pThree, &pFour, 7, centerPiece, 0) == 0) {
            return 0;
    }
    return 1;

}
