#ifndef BROWN_H
#define BROWN_H


class brown : public tetrisPiece
{
    public:
        brown();
        virtual ~brown();

        int turnPiece(int arrChng[]);
        int createPiece(int arrChng[]);
        int moveLeft(int arrChng[]);
        int moveRight(int arrChng[]);
        int moveDown(int arrChng[]);


    protected:
    private:
        int centerPiece;

        int pOne;
        int pTwo;
        int pThree;
        int pFour;
        int orientation;
};

#endif // BROWN_H
