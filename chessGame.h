#ifndef ChessGame h
#define ChessGame h

#include "figure.h"
#include "field.h"

#include <map>

using namespace std;

class ChessGame {

protected :

    bool wonWhite;
    bool wonBlack;
    bool draw;
    Figure whiteFigures;
    Figure blackFigures;

    map<Field, Figure> chessBoard;
public :

    static int currMove;

    ChessGame();
    void startGame();

// Check If :
    bool isDraw();
    bool isWonWhite();
    bool isWonBlack();
    // if king is under attack
    bool isCheckBlack();
    bool isCheckWhite();
//

};


#endif
