#ifndef BLUE_H
#define BLUE_H

class blue : public tetrisPiece
{
    public:
        blue();
        virtual ~blue();

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

#endif // BLUE_H
