#include <iostream>
#include <Serpente.hpp>
#include <Mela.hpp>
#include <metodiGenerali.hpp>
#include <Windows.h>


using namespace std;

int main()
{
    Serpente serpente;     //Dichiara l'oggetto del serpente
    Mela mela(10);         //Dichiara l'oggetto della mela, con relativo parametro di delay di spawn
    bool gameRunning = true;
    bool gameStatus = true;

    /*
     gameRunning = variabile booleana che serve per dire se il gioco deve
                   continuare a girare o chiudersi, viene settata dal metodo metodiGenerali::menu()

     gameStatus = indica se il serpente sia morto o no, facendo ritornare al menu
    */

    do{
        metodiGenerali::menu(gameRunning); //Contiene tutto il codice del menu principale
        if(!gameRunning) return 0;         //Controla se sia stata scelta l'opzione "EXIT"
        serpente.Reset();  //Resetta il serpente, resettando il suo corpo e mettendolo al centro
        gameStatus = true;
        do{
            system("cls");  //Cancella lo schermo, questo per una esperienza visiva migliore
            if(mela.checkIfEaten(serpente)) serpente.addCorpo();  //Controlla se è stata mangiata una mela e aggiunge un pezzo di corpo se si
            mela.Update();   //aggiorna il delay della mela
            serpente.Update(gameStatus);  //aggiorna il serpente ogni iterazione
            metodiGenerali::printMap(serpente,mela); //stampa a schermo tutta la mappa del gioco
            Sleep(150);  //Delay, senza di esso girerebbe più velocemente ma con un sfarfallio alto
        }while(gameStatus);
    }while(gameRunning);
    return 0;
}
