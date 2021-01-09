#ifndef field h
#define field h

class Field {
private :
    string fieldPos;
public :
    bool isFree;
    Field(string fieldPos) {
        this -> fieldPos = fieldPos;
        isFree = true;
    }
};

#endif
