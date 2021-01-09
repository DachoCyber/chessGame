#ifndef figure h
#define figure h

#include "chessGame.h"

class Figure : public ChessGame {

public :

    void parseMove(string start, string end, int* startX, int* startY, int* endX, int* endY);
    virtual void move(string start, string end);
    virtual bool isMovePossible(string start, string end);
};


class Pawn : public Figure {
public :

    void move(string start, string end) override;
    bool isMovePossible(string start, string end) override;
};

class Rook : public Figure {
public :

    void move(string start, string end) override;
    bool isMovePossible(string start, string end) override;
};

class Bishop : public Figure {
public :

    void move(string start, string end) override;
    bool isMovePossible(string start, string end) override;

};

class Knight : public Figure {
public :

    void move(string start, string end) override;
    bool isMovePossible(string start, string end) override;
};

class King : public Figure {
public :

    void move(string start, string end) override;
    bool isMovePossible(string start, string end) override;
};

class Queen : public Figure {
public :

    void move(string start, string end) override;
    bool isMovePossible(string start, string end) override;
};

#endif
