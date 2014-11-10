#ifndef PURPLE_H
#define PURPLE_H

class purple : public tetrisPiece
{
    public:
        purple();
        virtual ~purple();

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

#endif // PURPLE_H
