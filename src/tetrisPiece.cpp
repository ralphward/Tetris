#include "../include/tetrisPiece.h"

tetrisPiece::tetrisPiece()
{
    //ctor
}

tetrisPiece::~tetrisPiece()
{
    //dtor
}

int tetrisPiece::moveLeft(int arrChng[], int *pOne, int *pTwo, int *pThree, int *pFour, int pieceNum) {
    if ((arrChng[*pOne - 1] == 0 || *pOne - 1 == *pTwo || *pOne - 1 == *pThree || *pOne - 1 == *pFour)
    && (arrChng[*pTwo - 1] == 0 || *pTwo - 1 == *pOne || *pTwo - 1 == *pThree || *pTwo - 1 == *pFour)
    && (arrChng[*pThree - 1] == 0 || *pThree - 1 == *pOne || *pThree - 1 == *pTwo || *pThree - 1 == *pFour)
    && (arrChng[*pFour - 1] == 0 || *pFour - 1 == *pOne || *pFour - 1 == *pTwo || *pFour - 1 == *pThree)
    && *pOne % 10 != 0 &&  *pTwo % 10 != 0 &&  *pThree % 10 != 0 &&  *pFour % 10 != 0) {

        arrChng[*pOne] = 0;
        arrChng[*pTwo] = 0;
        arrChng[*pThree] = 0;
        arrChng[*pFour] = 0;
        --*pOne;
        --*pTwo;
        --*pThree;
        --*pFour;
        arrChng[*pOne] = pieceNum;
        arrChng[*pTwo] = pieceNum;
        arrChng[*pThree] = pieceNum;
        arrChng[*pFour] = pieceNum;
        return 0;
    } else {
        return 1;
    }
}

int tetrisPiece::moveRight(int arrChng[], int *pOne, int *pTwo, int *pThree, int *pFour, int pieceNum) {
    if ((arrChng[*pOne + 1] == 0 || *pOne + 1 == *pTwo || *pOne + 1 == *pThree || *pOne + 1 == *pFour)
    && (arrChng[*pTwo + 1] == 0 || *pTwo + 1 == *pOne || *pTwo + 1 == *pThree || *pTwo + 1 == *pFour)
    && (arrChng[*pThree + 1] == 0 || *pThree + 1 == *pOne || *pThree + 1 == *pTwo || *pThree + 1 == *pFour)
    && (arrChng[*pFour + 1] == 0 || *pFour + 1 == *pOne || *pFour + 1 == *pTwo || *pFour + 1 == *pThree)
    && (*pOne + 1) % 10 != 0 &&  (*pTwo + 1) % 10 != 0 &&  (*pThree + 1) % 10 != 0 &&  (*pFour + 1) % 10 != 0) {
        arrChng[*pOne] = 0;
        arrChng[*pTwo] = 0;
        arrChng[*pThree] = 0;
        arrChng[*pFour] = 0;
        ++*pOne;
        ++*pTwo;
        ++*pThree;
        ++*pFour;
        arrChng[*pOne] = pieceNum;
        arrChng[*pTwo] = pieceNum;
        arrChng[*pThree] = pieceNum;
        arrChng[*pFour] = pieceNum;
        return 0;
    } else {
        return 1;
    }

    return 0;
}

int tetrisPiece::moveDown(int arrChng[], int *pOne, int *pTwo, int *pThree, int *pFour, int pieceNum) {
    if ((arrChng[*pOne + 10] == 0 || *pOne + 10 == *pTwo || *pOne + 10  == *pThree || *pOne + 10 == *pFour)
    && (arrChng[*pTwo + 10] == 0 || *pTwo + 10 == *pOne || *pTwo + 10 == *pThree || *pTwo + 10 == *pFour)
    && (arrChng[*pThree + 10] == 0 || *pThree + 10 == *pOne || *pThree + 10 == *pTwo || *pThree + 10 == *pFour)
    && (arrChng[*pFour + 10] == 0 || *pFour + 10 == *pOne || *pFour + 10 == *pTwo || *pFour + 10 == *pThree)
    && ((*pOne + 10) < 180 && (*pTwo + 10) < 180 &&  (*pThree + 10) < 180 && (*pFour + 10) < 180)) {
        arrChng[*pOne] = 0;
        arrChng[*pTwo] = 0;
        arrChng[*pThree] = 0;
        arrChng[*pFour] = 0;
        *pOne = *pOne + 10;
        *pTwo = *pTwo + 10;
        *pThree = *pThree + 10;
        *pFour = *pFour + 10;
        arrChng[*pOne] = pieceNum;
        arrChng[*pTwo] = pieceNum;
        arrChng[*pThree] = pieceNum;
        arrChng[*pFour] = pieceNum;
        return 0;
    } else {
        return 1;
    }

}

int tetrisPiece::turnPiece(int arrChng[], int *pOne, int *pTwo, int *pThree, int *pFour, int pieceNum, int centerPiece, int direction) {
    int tmpArray[4], origArray[4];
    origArray[0] = *pOne;
    origArray[1] = *pTwo;
    origArray[2] = *pThree;
    origArray[3] = *pFour;

    for (int i = 0; i < 4; ++i) {
        // make sure it isn't the centerPiece as this wont move
        if (origArray[i] != centerPiece) {
            int xDif, yDif, yNew, xNew, newPiece;

            xDif = (origArray[i] % 10) - (centerPiece % 10);
            yDif = ((origArray[i] - (origArray[i] % 10)) / 10) - ((centerPiece - (centerPiece % 10)) / 10);
            yNew = xDif;
            xNew = yDif;
            if (direction == 0) { //anti-clockwise
                yNew = yNew * (-1);
            } else {
                xNew = xNew * (-1);
            }
            newPiece = centerPiece + xNew + (yNew * 10);
            tmpArray[i] = newPiece;
        } else {
            tmpArray[i] = centerPiece;
        }
    }

    for (int i = 0; i < 4; ++i) {
        if (tmpArray[i] % 10 < 2 && origArray[i] % 10 > 8) {
            return 1;
        } else if (origArray[i] % 10 < 2 && tmpArray[i] % 10 > 8) {
            return 1;
        } else if (arrChng[tmpArray[i]] == 0 && tmpArray[i] < 180) {
            // block we're moving to is empty and available
        } else if (tmpArray[i] == origArray[0] || tmpArray[i] == origArray[1] || tmpArray[i] == origArray[2] || tmpArray[i] == origArray[3] ) {

        } else {
            return 1;
        }
    }

    arrChng[tmpArray[0]] = arrChng[tmpArray[0]] + pieceNum;
    arrChng[origArray[0]] = arrChng[origArray[0]] - pieceNum;
    arrChng[tmpArray[1]] = arrChng[tmpArray[1]] + pieceNum;
    arrChng[origArray[1]] = arrChng[origArray[1]] - pieceNum;
    arrChng[tmpArray[2]] = arrChng[tmpArray[2]] + pieceNum;
    arrChng[origArray[2]] = arrChng[origArray[2]] - pieceNum;
    arrChng[tmpArray[3]] = arrChng[tmpArray[3]] + pieceNum;
    arrChng[origArray[3]] = arrChng[origArray[3]] - pieceNum;

    *pOne = tmpArray[0];
    *pTwo = tmpArray[1];
    *pThree = tmpArray[2];
    *pFour = tmpArray[3];

    return 0;
}
