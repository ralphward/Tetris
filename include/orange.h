#ifndef ORANGE_H
#define ORANGE_H

class orange : public tetrisPiece
{
    public:
        orange();
        virtual ~orange();

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

#endif // ORANGE_H
