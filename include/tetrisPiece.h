#ifndef TETRISPIECE_H
#define TETRISPIECE_H

#define LEFT 1
#define RIGHT 2
#define DOWN 3

class tetrisPiece
{
    public:
        tetrisPiece();
        virtual ~tetrisPiece();

        virtual int createPiece(int arrChng[]) = 0;
        virtual int turnPiece(int arrChng[]) = 0;
        virtual int moveLeft(int arrChng[]) = 0;
        virtual int moveRight(int arrChng[]) = 0;
        virtual int moveDown(int arrChng[]) = 0;

        int moveLeft(int arrChng[], int *pOne, int *pTwo, int *pThree, int *pFour, int pieceNum);
        int moveRight(int arrChng[], int *pOne, int *pTwo, int *pThree, int *pFour, int pieceNum);
        int moveDown(int arrChng[], int *pOne, int *pTwo, int *pThree, int *pFour, int pieceNum);
        int turnPiece(int arrChng[], int *pOne, int *pTwo, int *pThree, int *pFour, int pieceNum, int centerPiece, int direction);

    protected:

    private:
        //bool checkPiece(int direction, int pc)

};

#endif // TETRISPIECE_H
