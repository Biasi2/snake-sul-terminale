#include "Mela.hpp"


Mela::Mela()
{
    spawn();
    this->isActive = true;
}

Mela::Mela(int delay)
{
    this->delay = delay;
    this->isActive = true;
    spawn();
}

Mela::Mela(int x,int y,int delay)
{
    setCoordX(x);
    setCoordY(y);
    currentIteration = 0;
    this->delay = delay;
    this->isActive = true;
}

void Mela::spawn(){
    srand(time(0));

    currentIteration = 0;

    setCoordX(1+rand()%DIMX-1);
    setCoordY(1+rand()%DIMY-1);
    isActive = true;
}

void Mela::despawn(){
    isActive = false;
}

bool Mela::checkIfEaten(Serpente serpente){
    if(!isActive) return false;

    if(coordX == serpente.getHeadX() && coordY == serpente.getHeadY()){
        despawn();
        return true;
    }else return false;
}


void Mela::Update(){
    if(isActive) return;

    currentIteration++;

    if(currentIteration >= delay) spawn();
}


