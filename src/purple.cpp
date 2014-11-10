#include "../include/tetrisPiece.h"
#include "../include/purple.h"

purple::purple()
{
    centerPiece = 15;
    pOne = 4;
    pTwo = 5;
    pThree = 15;
    pFour = 25;
    //ctor
}

purple::~purple()
{
    //dtor
}

int purple::createPiece(int arrChng[]){
    if (arrChng[pOne] != 0 || arrChng[pTwo] != 0 || arrChng[pThree] != 0 || arrChng[pFour] != 0)
        return 1;
    arrChng[pOne] = 5;
    arrChng[pTwo] = 5;
    arrChng[pThree] = 5;
    arrChng[pFour] = 5;
    return 0;
}

int purple::moveLeft(int arrChng[]){
    if (tetrisPiece::moveLeft(arrChng, &pOne, &pTwo, &pThree, &pFour, 5) == 0) {
            centerPiece = centerPiece - 1;
            return 0;
    }
    return 1;
}

int purple::moveRight(int arrChng[]){
    if (tetrisPiece::moveRight(arrChng, &pOne, &pTwo, &pThree, &pFour, 5) == 0) {
            centerPiece = centerPiece + 1;
            return 0;
    }
    return 1;

}

int purple::moveDown(int arrChng[]){
    if (tetrisPiece::moveDown(arrChng, &pOne, &pTwo, &pThree, &pFour, 5) == 0) {
            centerPiece = centerPiece + 10;
            return 0;
    }
    centerPiece = 15;
    pOne = 4;
    pTwo = 5;
    pThree = 15;
    pFour = 25;
    return 1;

}

int purple::turnPiece(int arrChng[]) {
    if (tetrisPiece::turnPiece(arrChng, &pOne, &pTwo, &pThree, &pFour, 5, centerPiece, 0) == 0) {
            return 0;
    }
    return 1;

}
