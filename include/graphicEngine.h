#ifndef GRAPHICENGINE_H_INCLUDED
#define GRAPHICENGINE_H_INCLUDED

class graphicEngine {

    public:

        graphicEngine();
        ~graphicEngine();
        int runTurn(sf::RenderWindow*);
        int moveLeft(sf::RenderWindow*);
        int moveRight(sf::RenderWindow*);
        int turnPiece(sf::RenderWindow*);
        tetrisPiece * tp;
        red rd;
        blue bl;
        green gr;
        brown br;
        purple pu;
        orange ora;
        grey gry;

    private:
        int initialiseRandomPiece();
        int removeLine(int, int);

        sf::Sprite sprite;
        int* changeArray;
        int currentCenter;
        bool pieceStarted;
        image_manager img_mgr;
        std::string imgNames[9];

        static const int sizeX = 10;
        static const int sizeY = 18;

        void refreshScreen(sf::RenderWindow*);
};


#endif // GRAPHICENGINE_H_INCLUDED
