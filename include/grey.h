#ifndef GREY_H
#define GREY_H


class grey : public tetrisPiece
{
    public:
        grey();
        virtual ~grey();

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

#endif // GREY_H
