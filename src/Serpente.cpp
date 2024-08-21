#include "Serpente.hpp"


Serpente::Serpente()
{
    tailX = 0;
    tailY = 0;
    setHeadX(DIMX/2);
    setHeadY(DIMY/2);
    direction = 1;
}

Serpente::Serpente(int x,int y,int direction)
{
    tailX = 0;
    tailY = 0;
    setHeadX(x);
    setHeadY(y);
    this->direction = direction;
}

bool Serpente::gestioneMovimento(){
    char ch;
    bool aus;

    if(kbhit()){
        ch = getch();

        switch(ch){
        case 'a':  //Left
        case 'A':
            direction = 0;
            break;
        case 'w':  //Up
        case 'W':
            direction = 1;
            break;
        case 's':  //Down
        case 'S':
            direction = 2;
            break;
        case 'd':   //Right
        case 'D':
            direction = 3;
            break;
        }
    }

    switch(direction){
    case 0:
        aus = move(-1,0);
        break;
    case 1:
        aus = move(0,-1);
        break;
    case 2:
        aus = move(0,1);
        break;
    case 3:
        aus = move(1,0);
        break;
    }

    return aus;
}

bool  Serpente::move(int x,int y){
    bool touchedBorder = false;

    tailX = headX;
    tailY = headY;

    headX += x;
    headY += y;


    if(headX > DIMX){ headX = 0; touchedBorder = true;}
    else if(headX < 0){ headX = DIMX-1; touchedBorder = true;}

    if(headY > DIMY+1){ headY = 0;touchedBorder = true;}
    else if(headY < 0){ headY = DIMY+1;touchedBorder = true;}

    if(touchedBorder && bordoKiller) return false;
    else                             return true;
}

void Serpente::Reset(){
    setHeadX(DIMX/2);
    setHeadY(DIMY/2);
    direction = 1;
    corpo.clear();
}

void Serpente::Update(bool& gamestatus){
    if(!gestioneMovimento() || !corpoManager())
        gamestatus = false;
}

void Serpente::addCorpo(){
    int ausX,ausY;

    if(corpo.size() == 0){ausX = tailX; ausY = tailY;}
    else{ausX = tailX; ausY = tailY;}

    Corpo_serpente ausCorpo(ausX,ausY);

    corpo.push_back(ausCorpo);
}

bool Serpente::checkIfThereIsCorpo(int x,int y){
    if(corpo.size() == 0) return false;

    for(int i=0;i<corpo.size();i++){
        if(corpo[i].getCoordX() == x && corpo[i].getCoordY() == y)return true;
    }

    return false;
}

bool Serpente::corpoManager(){
    if(corpo.size() == 0) return true;

    bool x = true;

    int prevX[2],prevY[2];

    prevX[1] = tailX;
    prevY[1] = tailY;


    for(int i=0;i<corpo.size();i++){
        if(i == corpo.size()-1){
            tailX = prevX[(int)x];
            tailY = prevY[(int)x];

        }

        x = !x;

        //cout<<endl<<corpo[i].getCoordX() << " || "<< corpo[i].getCoordY()<<endl;

        prevX[(int)x] = corpo[i].getCoordX();
        prevY[(int)x] = corpo[i].getCoordY();

        corpo[i].setCoordX(prevX[(int)!x]);
        corpo[i].setCoordY(prevY[(int)!x]);

        if(corpo[i].getCoordX() == headX && corpo[i].getCoordY() == headY) return false;

    }
    return true;
}
