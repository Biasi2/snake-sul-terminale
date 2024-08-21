#include "metodiGenerali.hpp"

bool bordoKiller;

void metodiGenerali::menu(bool& exit){
    int selettoreNum = 0;

    char ch;
    bool firstIteration = false;

    do{
        if(kbhit() || !firstIteration){
            if(kbhit())ch = getch();

            //cout<<ch;

            if(ch == 'w' || ch == 'W') selettoreNum -= 1;
            else if(ch == 's' || ch == 'S') selettoreNum += 1;

            if(selettoreNum > 3) selettoreNum = 3;
            if(selettoreNum < 0) selettoreNum = 0;

            system("cls");
            for(int i=0;i<3;i++){
                if(selettoreNum == i) cout<<SELETTORE;

                if(i == 0) cout<<" SNAKE CLASSICO "<<endl;
                if(i == 1) cout<<" SNAKE MODERNO  "<<endl;
                if(i == 2) cout<<" ESCI           "<<endl;
            }
            firstIteration = true;
            cout<<"Premi W o S per selezionare";
        }
    }while(ch != 13);

    if(selettoreNum < 2) bordoKiller = selettoreNum;
    else exit = false;




}

void metodiGenerali::printMap(Serpente serpente,Mela mela){
    char ausBorder;
    if(bordoKiller) ausBorder = BORDO_KILLER;
    else            ausBorder = BORDO;

    for(int i=0;i<DIMX+2;i++){cout<<ausBorder;}
    cout<<endl;

    for(int i=0;i<DIMY+2;i++){
        cout<<ausBorder;
        for(int j=0;j<DIMX;j++){
            if(i == serpente.getHeadY() && j == serpente.getHeadX())
                cout<<TESTA_SERPENTE;
            else if(serpente.checkIfThereIsCorpo(j,i))
                cout<<CORPO_SERPENTE;
            else if((i == mela.getCoordY() && j == mela.getCoordX())&& mela.getIsActive())
                cout<<MELA;
            else
                cout<<VUOTO;
        }
        cout<<ausBorder<<endl;
    }

    for(int i=0;i<DIMX+2;i++){cout<<ausBorder;}
    cout<<endl;
}

