#ifndef CORPO_SERPENTE_HPP
#define CORPO_SERPENTE_HPP


class Corpo_serpente
{
    public:
        Corpo_serpente();
        Corpo_serpente(int,int);

        void setCoordX(int coordX){this->coordX = coordX;}
        void setCoordY(int coordY){this->coordY = coordY;}
        int getCoordX(){return coordX;}
        int getCoordY(){return coordY;}
    private:
        int coordX,coordY;
};

#endif // CORPO_SERPENTE_HPP
