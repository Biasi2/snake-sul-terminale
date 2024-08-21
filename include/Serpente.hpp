#ifndef SERPENTE_HPP
#define SERPENTE_HPP


#include <conio.h>
#include <Common.hpp>
#include <Corpo_serpente.hpp>
#include <vector>
#include <iostream>

using namespace std;

class Serpente
{
    public:
        Serpente();
        Serpente(int,int,int);


        //Metodi GETTER

        int getHeadX(){return headX;}
        int getHeadY(){return headY;}
        int getTailX(){return tailX;}
        int getTailY(){return tailY;}

        //Metodi SETTER

        void setHeadX(int headX){this->headX = headX;}
        void setHeadY(int headY){this->headY = headY;}

        void Reset();  //Resetta il serpente ripristinando i suoi valori
        void Update(bool&);  //Aggiorna il serpente di 1 tick

        bool checkIfThereIsCorpo(int,int); //Controlla se nelle coordinate date come parametri ci sia un pezzo di corpo

        bool gestioneMovimento();  //Gestisce tutto il movimento, cambiando anche la variabile direction
        bool move(int,int);        //Cambia di tot indicato nei parametri la posizione del serpente, segnandosi le precedenti nelle variabili Tail

        void addCorpo();  //Aggiunge un pezzo di corpo


    private:
        int headX,headY;  // Coordinate della testa che guida tutto il corpo
        int tailX,tailY;  // Coordinate della coda, o essenzialmente quelle precedenti della testa dopo un movimento

        int direction; //Direzione verso la quale il serpente si muove

        vector<Corpo_serpente> corpo;  //Array dinamico del corpo

        bool corpoManager();  //Metodo responsabile del movimento a catena del corpo
};

#endif // SERPENTE_HPP
