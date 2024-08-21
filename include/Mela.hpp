#ifndef MELA_HPP
#define MELA_HPP

#include <stdlib.h>
#include <time.h>
#include <Common.hpp>

#include <Serpente.hpp>


class Mela
{
    public:
        Mela();
        Mela(int,int,int);
        Mela(int);

        int getCoordX(){return coordX;}
        int getCoordY(){return coordY;}
        void setCoordX(int coordX){this->coordX = coordX;}
        void setCoordY(int coordY){this->coordY = coordY;}


        bool getIsActive(){return isActive;}

        void Update();

        void spawn();
        void despawn();

        bool checkIfEaten(Serpente);

    private:
        int coordX,coordY,delay;
        bool isActive;
        int currentIteration;
};

#endif // MELA_HPP
