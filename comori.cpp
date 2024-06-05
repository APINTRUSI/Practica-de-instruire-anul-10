#include "comori.h"
#include <bits/stdc++.h>
#include <conio.h>
using namespace std;

int n, x[9][1001];


void comenzi() {
    do {
        cout << "Pentru comanda dorita selectati cifra corespunzatoare:" << endl;
        cout << "0. Opreste compilarea/rularea" << endl;
        cout << "1. Extinde traseul spre comoara, descris in fisierul Comori.in, cu o noua indicatie" << endl;
        cout << "2. Exclude ultima indicatie din traseul spre comori, descris in fisierul Comori.in" << endl;
        cout << "3. Determina numarul total de pasi necesar de efectuat conform traseului descris in fisierul de intrare" << endl;
        cout << "4. Determina numarul schimbarilor de directie din traseul descris de pirati" << endl;
        cout << "5. Creează fișierul text UnPas.txt prin copiere din fișierul Comori.in a liniilor pentru care p=1" << endl;
//        cout << "6. Afișează pe ecran lista codurilor direcțiilor deplasărilor în ordinea descendentă a numărului lor de apariție în traseului spre comoară; datele se vor sorta prin metoda numărării" << endl;
//        cout << "7. Găsește în planul cartezian un dreptunghi de arie minimală ce conține în întregime traseul spre comoară; laturile dreptunghiului vor fi paralele cu axele de coordonate respective. La ecran se va afișa aria S și coordonatele colțurilor stânga-sus și dreapta-jos ale dreptunghiului găsit" << endl;


        cin >> n;
        switch (n) {
            case 0:
                break;
            case 1:{
                citire();
                extinde_traseul();
                break;}
            case 2:{
                citire();
                exclude_ultima_indicatie();
                break;}
            case 3:{
                citire();
                numar_total_de_pasi();
                break;}
            case 4:{
                citire();
                numar_total_de_schimbari_de_directii();
                    break;}
            case 5:{
                citire();
                break;}

            default:
                cout << "Numarul trebuie sa corespunda cerintei de mai sus" << endl;
                break;
        }
    } while (n != 0);
}


void citire(){
    ifstream Cin("Comori.in");
    Cin >> n;
    for(int i=0; i<n; i++){
        Cin >> x[i][0] >> x[i][1];
    }
    Cin.close();
}

void extinde_traseul(){
    ofstream Cout("Comori.in");
    cout << "Noile tale indicatii:\n";
    cout << "Directia: ";
    cin >> x[n][0];
    cout << "Pasi: ";
    cin >> x[n][1];
    Cout << ++n << "\n";
    for(int i=0; i<n; i++){
        Cout << x[i][0] << " " << x[i][1] << "\n";
    }
    Cout.close();
    cout << "Traseul spre comoara a fost extins cu o indicatie";
}

void exclude_ultima_indicatie(){
    ofstream Cout("Comori.in");
    Cout << --n << "\n";
    for(int i=0; i<n; i++){
        Cout << x[i][0] << " " << x[i][1] << "\n";
    }
    x[n][0] = 0;
    x[n][1] = 0;
    Cout.close();
    cout << "Ultima indicatie din traseu spre comoara a fost exclusa";
}

void numar_total_de_pasi(){
    int k = 0;
    for(int i=0; i<n ;i++){
        k += x[i][1];
    }
    cout << "Numarul total de pasi: " << k << "\n";
}

void numar_total_de_schimbari_de_directii(){
    int k = 0;
    for(int i=0; i<n ;i++){
        k += x[i][0];
    }
    cout << "Numarul schimbarilor de directie: " << k << "\n";
}