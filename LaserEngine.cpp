#include "Board.h"
#include "LaserEngine.h"
#include<iostream>
#include<tuple> // for tuple
using namespace std;
#include <vector>
LaserEngine::LaserEngine(Board &b) : board(b) {

}

void LaserEngine::lasery() {

    int height = board.getBoardHeight();
    int width = board.getBoardWidth();

    int wiersz1, kolumna1;


cout<<"previouslvl: "<<board.previousLvl<<"   lvl:"<<board.lvl<<endl;

    if(board.previousLvl !=board.lvl){

        gatesFlag=false;
    }

    if (!gatesFlag) {if(board.lvl==1)


    {cout<<"chuj\n";}

        gatesA.erase(gatesA.begin(),gatesA.end());
        gatesB.erase(gatesB.begin(),gatesB.end());
        gatesC.erase(gatesC.begin(),gatesC.end());
        gatesD.erase(gatesD.begin(),gatesD.end());



//        reciversA.erase(reciversA.begin(),reciversA.end());
//        reciversB.erase(reciversB.begin(),reciversB.end());
//        reciversC.erase(reciversC.begin(),reciversC.end());
//        reciversD.erase(reciversD.begin(),reciversD.end());


        cout<<"inicjalizuje wektor blokad"<<endl;

        int temporarygates;
        for (int wiersz = 0; wiersz < height; wiersz++) {                       //przypisanie wartości bloków
            for (int kolumna = 0; kolumna < width; kolumna++) {
                temporarygates = board.getFieldInfo(wiersz, kolumna);
                if (temporarygates == 8 || temporarygates == 9) {                    //przypisanie wartości blokadA (ON || OFF) tylko raz
                    gatesA.push_back(wiersz);
                    gatesA.push_back(kolumna);
                }
                if (temporarygates == 10 || temporarygates == 11) {                    //przypisanie wartości blokadB
                    gatesB.push_back(wiersz);
                    gatesB.push_back(kolumna);
                }
                if (temporarygates == 12 || temporarygates == 13) {                    //przypisanie wartości blokadC
                    gatesC.push_back(wiersz);
                    gatesC.push_back(kolumna);
                }
                if (temporarygates == 14 || temporarygates == 15) {                    //przypisanie wartości blokadD
                    gatesD.push_back(wiersz);
                    gatesD.push_back(kolumna);
                }
                           }
        }

        cout<<"podaje dlugosc wektora B: "<< gatesB.size()<<endl;
        cout<<"podaje dlugosc wektora A: "<< gatesA.size()<<endl;
        cout<<"podaje dlugosc wektora C: "<< gatesC.size()<<endl;
        cout<<"podaje dlugosc wektora D: "<< gatesD.size()<<endl;
        board.previousLvl = board.lvl;
        gatesFlag=true;
//cout<<gatesA.at(0)<<"chuj\n";


    }

    cout<<"previouslvl: "<<board.previousLvl<<"   lvl:"<<board.lvl<<endl;


    for (int wiersz = 0; wiersz < height; wiersz++) {       //przechodzenie przez laser i zerowanie stanu revicer
        for (int kolumna = 0; kolumna < width; kolumna++) {         //zerowanie laserów
            if (board.getFieldInfo(wiersz, kolumna) == 3 || board.getFieldInfo(wiersz, kolumna) == 22 ||
                board.getFieldInfo(wiersz, kolumna) == 1) { board.change(wiersz, kolumna, 2); }
            if (board.getFieldInfo(wiersz, kolumna) == 7) {
                board.change(wiersz, kolumna, 6);
            }
            if (board.getFieldInfo(wiersz, kolumna) == 17) {
                board.change(wiersz, kolumna, 16);
            }
            if (board.getFieldInfo(wiersz, kolumna) == 19) {
                board.change(wiersz, kolumna, 18);
            }
            if (board.getFieldInfo(wiersz, kolumna) == 21) {
                board.change(wiersz, kolumna, 20);
            }
        }
    }
    for (int g = 0; g < 4; g++) {


        for (int wiersz = 0; wiersz < height; wiersz++) {               //przypisanie współrzędnych rzutników lasera
            for (int kolumna = 0; kolumna < width; kolumna++) {

                if (board.getFieldInfo(wiersz, kolumna) == 5 && g == 0) {
                    wiersz1 = wiersz;
                    kolumna1 = kolumna;
                }
                if (board.getFieldInfo(wiersz, kolumna) == 23 && g == 1) {
                    wiersz1 = wiersz;
                    kolumna1 = kolumna;
                }
                if (board.getFieldInfo(wiersz, kolumna) == 24 && g == 2) {
                    wiersz1 = wiersz;
                    kolumna1 = kolumna;
                }
                if (board.getFieldInfo(wiersz, kolumna) == 25 && g == 3) {
                    wiersz1 = wiersz;
                    kolumna1 = kolumna;
                }
            }
        }
        if (g == 0) {
            for (int i = wiersz1; i < height - 2; i++) {    //rysowanie laser na dół

                if (board.getFieldInfo(i + 1, kolumna1) ==
                    6) {  //jeśli następne współrzędne to reciver A-> zaświeć reciver A
                    board.change(i + 1, kolumna1, 7);
                    break;
                }
                if (board.getFieldInfo(i + 1, kolumna1) == 16) {    //dla B
                    board.change(i + 1, kolumna1, 17);
                    break;
                }
                if (board.getFieldInfo(i + 1, kolumna1) == 18) {    //dla C
                    board.change(i + 1, kolumna1, 19);
                    break;
                }
                if (board.getFieldInfo(i + 1, kolumna1) == 20) {    //dla D
                    board.change(i + 1, kolumna1, 21);
                    break;
                }
                if (board.getFieldInfo(i + 1, kolumna1) ==
                    1) {     //jeśli następne współrzędne to inny laser pod kątem prostym...
                    board.change(i + 1, kolumna1, 22);      //...ustaw skrzyżowanie laserów
                    continue;
                }
                if (board.getFieldInfo(i + 1, kolumna1) ==
                    3) { continue; }     //jeśli laser o tej samej orientacji, nie rysuj
                if (board.getFieldInfo(i + 1, kolumna1) !=
                    2) { break; }        //jeśli następna kratka coś innego, przerwij rysowanie
                board.change(i + 1, kolumna1, 3);
            }
        }

        if (g == 1) {
            for (int i = kolumna1; i < width - 2; i++) {        //rysowanie laser na prawo

                if (board.getFieldInfo(wiersz1, i + 1) == 6) {
                    board.change(wiersz1, i + 1, 7);
                    break;
                }
                if (board.getFieldInfo(wiersz1, i + 1) == 16) {
                    board.change(wiersz1, i + 1, 17);
                    break;
                }
                if (board.getFieldInfo(wiersz1, i + 1) == 18) {
                    board.change(wiersz1, i + 1, 19);
                    break;
                }
                if (board.getFieldInfo(wiersz1, i + 1) == 20) {
                    board.change(wiersz1, i + 1, 21);
                    break;
                }
                if (board.getFieldInfo(wiersz1, i + 1) == 3) {
                    board.change(wiersz1, i + 1, 22);
                    continue;
                }
                if (board.getFieldInfo(wiersz1, i + 1) == 1) { continue; }
                if (board.getFieldInfo(wiersz1, i + 1) != 2) { break; }
                board.change(wiersz1, i + 1, 1);
            }
        }

        if (g == 2) {
            for (int i = wiersz1 - 1; i > 0; i--) {             //rysowanie laser w góre

                if (board.getFieldInfo(i, kolumna1) == 6) {
                    board.change(i, kolumna1, 7);
                    break;
                }
                if (board.getFieldInfo(i, kolumna1) == 16) {
                    board.change(i, kolumna1, 17);
                    break;
                }
                if (board.getFieldInfo(i, kolumna1) == 18) {
                    board.change(i, kolumna1, 19);
                    break;
                }
                if (board.getFieldInfo(i, kolumna1) == 20) {
                    board.change(i, kolumna1, 21);
                    break;
                }
                if (board.getFieldInfo(i, kolumna1) == 1) {
                    board.change(i, kolumna1, 22);
                    continue;
                }
                if (board.getFieldInfo(i, kolumna1) == 3) { continue; }

                if (board.getFieldInfo(i, kolumna1) != 2) { break; }
                board.change(i, kolumna1, 3);
            }
        }


        if (g == 3) {
            for (int i = kolumna1 - 1; i > 0; i--) {    //rysowanie laser na lewo

                if (board.getFieldInfo(wiersz1, i) == 6) {
                    board.change(wiersz1, i, 7);
                    break;
                }
                if (board.getFieldInfo(wiersz1, i) == 18) {
                    board.change(wiersz1, i, 19);
                    break;
                }
                if (board.getFieldInfo(wiersz1, i) == 20) {
                    board.change(wiersz1, i, 21);
                    break;
                }
                if (board.getFieldInfo(wiersz1, i) == 16) {
                    board.change(wiersz1, i, 17);
                    break;
                }
                if (board.getFieldInfo(wiersz1, i) == 3) {
                    board.change(wiersz1, i, 22);
                    continue;
                }
                if (board.getFieldInfo(wiersz1, i) == 1) { continue; }

                if (board.getFieldInfo(wiersz1, i) != 2) { break; }
                board.change(wiersz1, i, 1);
            }

        }
    }




    vector<int> lasersA;
    vector<int> lasersB;
    vector<int> lasersC;
    vector<int> lasersD;

    vector<int> player;


    vector<int> reciversA;
    vector<int> reciversB;
    vector<int> reciversC;
    vector<int> reciversD;

    int temporary;
    for (int wiersz = 0; wiersz < height; wiersz++) {                       //przypisanie wartości bloków
        for (int kolumna = 0; kolumna < width; kolumna++) {
            temporary = board.getFieldInfo(wiersz, kolumna);
            if (temporary == 6 || temporary == 7) {                    //przypisanie wartości reciverówA (OFF || ON)
                reciversA.push_back(wiersz);
                reciversA.push_back(kolumna);
            }

            if (temporary == 16 || temporary == 17) {                    //przypisanie wartości reciverówB
                reciversB.push_back(wiersz);
                reciversB.push_back(kolumna);
            }

            if (temporary == 18 || temporary == 19) {                    //przypisanie wartości reciverówC
                reciversC.push_back(wiersz);
                reciversC.push_back(kolumna);
            }

            if (temporary == 20 || temporary == 21) {                    //przypisanie wartości reciverówD
                reciversD.push_back(wiersz);
                reciversD.push_back(kolumna);
            }




            if (temporary == 4) {                    //przypisanie wartości gracza
                player.push_back(wiersz);
                player.push_back(kolumna);
            }


            if (temporary == 5) {                    //przypisanie wartości laseraA
                lasersA.push_back(wiersz);
                lasersA.push_back(kolumna);
            }

            if (temporary == 23) {                    //przypisanie wartości laseraB
                lasersB.push_back(wiersz);
                lasersB.push_back(kolumna);
            }

            if (temporary == 24) {                    //przypisanie wartości laseraC
                lasersC.push_back(wiersz);
                lasersC.push_back(kolumna);
            }

            if (temporary == 25) {                    //przypisanie wartości laseraD
                lasersD.push_back(wiersz);
                lasersD.push_back(kolumna);
            }


            if(temporary==8||temporary==9){
                zmiennaOdIlosciBlokad++;
            }
        }

    }



/////////////////////////////////////////////////
    bool isSomething=false;

    int wiersz_temp, kolumna_temp;
    bool bit=false;
    for (int i = 0; i < reciversA.size(); i += 2) {                         //moduł odpowiedzialny za przełączanie stanu blokady (ON || OFF)
        wiersz_temp = reciversA.at(i);
        kolumna_temp = reciversA.at(i + 1);

        if (board.getFieldInfo(wiersz_temp, kolumna_temp) == 7) {bit=true; cout<<"podnosze bit odbioru"<<endl;}
    }


    for (int i = 0; i < gatesA.size(); i += 2) {
        if(bit) {
            if(board.getFieldInfo(gatesA.at(i), gatesA.at(i + 1))==4||
               board.getFieldInfo(gatesA.at(i), gatesA.at(i + 1))==5||
               board.getFieldInfo(gatesA.at(i), gatesA.at(i + 1))==23||
               board.getFieldInfo(gatesA.at(i), gatesA.at(i + 1))==24||
               board.getFieldInfo(gatesA.at(i), gatesA.at(i + 1))==25||
                    board.getFieldInfo(gatesA.at(i), gatesA.at(i + 1))==27) {
                isSomething = true;//     cout << "wykryłem obiekt na polu" << endl;
            }
            if (!isSomething) {
                board.change(gatesA.at(i), gatesA.at(i + 1), 9);   //   cout << "zapalam pole" << endl;
            }

            isSomething = false;
        } else {

            board.change(gatesA.at(i), gatesA.at(i + 1), 8); //cout<<"gasze pole"<<endl;
        }
    }

    bit=false;          //wyzerowanie flag
    isSomething=false;

/////////////////////////////

    for (int i = 0; i < reciversB.size(); i += 2) {                   //zmiana stanu blokad dla B
        wiersz_temp = reciversB.at(i);
        kolumna_temp = reciversB.at(i + 1);

        if (board.getFieldInfo(wiersz_temp, kolumna_temp) == 17) {bit=true; cout<<"podnosze bit odbioru"<<endl;}
    }


    for (int i = 0; i < gatesB.size(); i += 2) {
        if (bit) {
            if (board.getFieldInfo(gatesB.at(i), gatesB.at(i + 1)) == 4 ||
                board.getFieldInfo(gatesB.at(i), gatesB.at(i + 1)) == 5 ||
                board.getFieldInfo(gatesB.at(i), gatesB.at(i + 1)) == 23 ||
                board.getFieldInfo(gatesB.at(i), gatesB.at(i + 1)) == 24 ||
                board.getFieldInfo(gatesB.at(i), gatesB.at(i + 1)) == 25 ||
                    board.getFieldInfo(gatesB.at(i), gatesB.at(i + 1))==27) {
                isSomething = true;//     cout << "wykryłem obiekt na polu" << endl;
            }
            if (isSomething==false) {
                board.change(gatesB.at(i), gatesB.at(i + 1), 11);   //   cout << "zapalam pole" << endl;
            }

            isSomething = false;
        } else {

            board.change(gatesB.at(i), gatesB.at(i + 1), 10); //cout<<"gasze pole"<<endl;
        }
    }
    bit=false;          //wyzerowanie flag
    isSomething=false;


/////////////////////////////

    for (int i = 0; i < reciversC.size(); i += 2) {                   //zmiana stanu blokad dla C
        wiersz_temp = reciversC.at(i);
        kolumna_temp = reciversC.at(i + 1);

        if (board.getFieldInfo(wiersz_temp, kolumna_temp) == 19) {bit=true; cout<<"podnosze bit odbioru"<<endl;}
    }

    for (int i = 0; i < gatesC.size(); i += 2) {
        if (bit) {
            if (board.getFieldInfo(gatesC.at(i), gatesC.at(i + 1)) == 4 ||
                board.getFieldInfo(gatesC.at(i), gatesC.at(i + 1)) == 5 ||
                board.getFieldInfo(gatesC.at(i), gatesC.at(i + 1)) == 23 ||
                board.getFieldInfo(gatesC.at(i), gatesC.at(i + 1)) == 24 ||
                board.getFieldInfo(gatesC.at(i), gatesC.at(i + 1)) == 25||
                    board.getFieldInfo(gatesC.at(i), gatesC.at(i + 1))==27) {
                isSomething = true;//     cout << "wykryłem obiekt na polu" << endl;
            }
            if (isSomething==false) {
                board.change(gatesC.at(i), gatesC.at(i + 1), 13);
                   cout << "zapalam pole C" << endl;
            }

            isSomething = false;
        } else {

            board.change(gatesC.at(i), gatesC.at(i + 1), 12); //cout<<"gasze pole"<<endl;
        }
    }
    bit=false;          //wyzerowanie flag
    isSomething=false;

/////////////////////////////

    for (int i = 0; i < reciversD.size(); i += 2) {                   //zmiana stanu blokad dla D
        wiersz_temp = reciversD.at(i);
        kolumna_temp = reciversD.at(i + 1);

        if (board.getFieldInfo(wiersz_temp, kolumna_temp) == 21) {bit=true; cout<<"podnosze bit odbioru"<<endl;}
    }


    for (int i = 0; i < gatesD.size(); i += 2) {
        if (bit) {
            if (board.getFieldInfo(gatesD.at(i), gatesD.at(i + 1)) == 4 ||
                board.getFieldInfo(gatesD.at(i), gatesD.at(i + 1)) == 5 ||
                board.getFieldInfo(gatesD.at(i), gatesD.at(i + 1)) == 23 ||
                board.getFieldInfo(gatesD.at(i), gatesD.at(i + 1)) == 24 ||
                board.getFieldInfo(gatesD.at(i), gatesD.at(i + 1)) == 25||
                    board.getFieldInfo(gatesD.at(i), gatesD.at(i + 1))==27) {
                isSomething = true;//     cout << "wykryłem obiekt na polu" << endl;
            }
            if (isSomething==false) {
                board.change(gatesD.at(i), gatesD.at(i + 1), 15);   //   cout << "zapalam pole" << endl;
            }

            isSomething = false;
        } else {

            board.change(gatesD.at(i), gatesD.at(i + 1), 14); //cout<<"gasze pole"<<endl;
        }
    }
 //   bit=false;          //wyzerowanie flag
//    isSomething=false;






   // bit=false;
    //cout<<"znoszę bit odbioru"<<endl;
/////////////////////////////////////////////////////
    cout<<"\n"<<endl;
}


