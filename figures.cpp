#include "figure.h"

/*bool ::  isMovePossible(string start, string end) {

    Figure currFigure = ChessBoard[new Field(start)];

    if()
}*/

void ChessGame :: parseMove(string start, string end, int* startX, int* startY, int* endX, int* endY) {
    *startX = start[0] - 'a';
    *startY = start[1] - '0';
    *endX = end[0] - 'a';
    *endY = end[1] - '0';
}

