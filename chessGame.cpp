#include "chessGame.h"

ChessGame :: ChessGame() {

    // code here
    // declare begin places for figures
    chessBoard.insert(pair<Field, Figure>(new Field("a1"), new Rook("white")));
    chessBoard.insert(pair<Field, Figure>(new Field("h1"), new Rook("white")));
    chessBoard.insert(pair<Field, Figure>(new Field("a8"), new Rook("black")));
    chessBoard.insert(pair<Field, Figure>(new Field("h8"), new Rook("black")));

    chessBoard.insert(pair<Field, Figure>(new Field("b1"), new Knight("white")));
    chessBoard.insert(pair<Field, Figure>(new Field("g1"), new Knight("white")));
    chessBoard.insert(pair<Field, Figure>(new Field("b8"), new Knight("black")));
    chessBoard.insert(pair<Field, Figure>(new Field("g8"), new Knight("black")));

    chessBoard.insert(pair<Field, Figure>(new Field("c1"), new Bishop("white")));
    chessBoard.insert(pair<Field, Figure>(new Field("f1"), new Bishop("white")));
    chessBoard.insert(pair<Field, Figure>(new Field("c8"), new Bishop("black")));
    chessBoard.insert(pair<Field, Figure>(new Field("f8"), new Bishop("black")));

    chessBoard.insert(pair<Field, Figure>(new Field("d1"), new Queen("white")));
    chessBoard.insert(pair<Field, Figure>(new Field("d8"), new Queen("black")));

    chessBoard.insert(pair<Field, Figure>(new Field("e1"), new King("white")));
    chessBoard.insert(pair<Field, Figure>(new Field("e8"), new King("black")));


    for(int i = 0; i < 8; i++) {

        char whitePosX = 'a' + i, whitePosY = '2';
        char blackPosX = 'a' + i, blackPosY = '6';

        string whitePos, blackPos;

        whitePos[0] = whitePosX;
        whitePos[1] = whitePosY;

        blackPos[0] = blackPosX;
        blackPos[1] = blackPosY;

        chessBoard.insert(pair<Field, Figure>(new Field(whitePos), new Pawn("white")));
        chessBoard.insert(pair<Field, Figure>(new Field(blackPos), new Pawn("black")));
    }

    wonBlack = false;
    wonWhite = false;
    draw = false;
};

int ChessGame : currMove = 0;


void ChessGame :: startGame() {

    bool whiteCheckedBefore = false;
    bool blackCheckedBefore = false;

    while(!draw && !wonWhite && !wonBlack) {

        //CODE HERE !!!!!

        whiteCheckedBefore = isCheckWhite();
        blackCheckedBefore = isCheckBlack();

        bool isValid = false;
        while(!isValid) {

            string moveEntry;
            cout << "Unesite sledeci potez: ";
            getline(cin, moveEntry);

            isValid = true;


            bool stillCheckWhite = isCheckWhite();
            bool stillCheckBlack = isCheckBlack();

            if(currMove % 2 == 0 && stillCheckWhite && whiteCheckedBefore) {
                cout << "Nemoguc potez! Kralj belog je napadnut!" << endl;
                isValid = false;
            }
            if(currMove % 2 == 1 && stillCheckBlack && blackCheckedBefore) {
                cout << "Nemoguc potez! Kralj crnog je napadnut!" << endl;
                isValid = false;
            }
        }

        draw = isDraw();
        wonWhite = isWonWhite();
        wonBlack = isWonBlack();

        currMove++;
    }
    //if the number of last move was odd, then white wins, otherwise black wins

    if(wonWhite) {
        cout << "Igra se zavrsila pobedom belog!";
    }
    else if(wonBlack) {
        cout << "Igra se zavrsila nakon crnog!";
    }
    else {
        //it is draw since no one won
        cout << "Igra se zavrsila remijem!";
    }

    cout << "Game ended after " << currMove << " turns!" << endl;
}
