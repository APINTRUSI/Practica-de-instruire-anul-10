#include "comori.h"
#include <bits/stdc++.h>
#include <conio.h>
using namespace std;

int n, x[9][1001];


void comenzi() {
    do {
        cout << "\nPentru comanda dorita selectati cifra corespunzatoare:" << endl;
        cout << "0. Opreste compilarea/rularea" << endl;
        cout << "1. Extinde traseul spre comoara, descris in fisierul Comori.in, cu o noua indicatie" << endl;
        cout << "2. Exclude ultima indicatie din traseul spre comori, descris in fisierul Comori.in" << endl;
        cout << "3. Determina numarul total de pasi necesar de efectuat conform traseului descris in fisierul de intrare" << endl;
        cout << "4. Determina numarul schimbarilor de directie din traseul descris de pirati" << endl;
        cout << "5. Creeaza fisierul text UnPas.txt prin copiere din fisierul Comori.in a liniilor pentru care p=1" << endl;
        cout << "6. Afiseaza pe ecran lista codurilor directiilor deplasarilor in ordinea descendenta a numarului lor de aparitie in traseului spre comoara; datele se vor sorta prin metoda numararii" << endl;
        cout << "7. Gaseste in planul cartezian un dreptunghi de arie minimala ce contine in intregime traseul spre comoara; laturile dreptunghiului vor fi paralele cu axele de coordonate respective. La ecran se va afisa aria S si coordonatele colturilor stanga-sus si dreapta-jos ale dreptunghiului gasit" << endl;
        cout << "8. Determina punctul in care este ascunsa comoara" << endl;

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
                numar_total_de_schimbari();
                break;}
            case 5:{
                citire();
                unPas();
                break;}
            case 6:{
                citire();
                sortare_directii();
                break;}
            case 7:{
                citire();
                gaseste_dreptunghi();
                break;}
            case 8:{
                citire();
                determinare_comoara();
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

void numar_total_de_schimbari(){
    int k = 0;
    for(int i=0; i<n ;i++){
        k += x[i][0];
    }
    cout << "Numarul schimbarilor de directie: " << k << "\n";
}

void unPas(){
    ofstream Cout("UnPas.txt");
    for(int i=0; i<n; i++){
        if(x[i][1] == 1)
            Cout << x[i][0] << " " << x[i][1] << "\n";
    }
    Cout.close();
    cout << "Fisierul UnPas.txt a fost creat";
}

void sortare_directii() {
    int frecventa[9] = {0};

    for (int i = 0; i < n; i++) {
        frecventa[x[i][0]]++;
    }

    vector<pair<int, int>> direcții_frecvente;
    for (int i = 1; i <= 8; i++) {
        if (frecventa[i] > 0) {
            direcții_frecvente.push_back({frecventa[i], i});
        }
    }

    sort(direcții_frecvente.rbegin(), direcții_frecvente.rend());

    cout << "Codurile directiilor in ordinea descendenta a numarului lor de aparitie:\n";
    for (auto &p : direcții_frecvente) {
        cout << p.second << ' ';
    }
    cout << '\n';
}

void gaseste_dreptunghi() {
    int x_curent = 0, y_curent = 0;
    int x_min = 0, x_max = 0, y_min = 0, y_max = 0;

    for (int i = 0; i < n; i++) {
        int directie = x[i][0];
        int pasi = x[i][1];

        for (int j = 0; j < pasi; j++) {
            switch (directie) {
                case 1: y_curent++; break;
                case 2: x_curent++; y_curent++; break;
                case 3: x_curent++; break;
                case 4: x_curent++; y_curent--; break;
                case 5: y_curent--; break;
                case 6: x_curent--; y_curent--; break;
                case 7: x_curent--; break;
                case 8: x_curent--; y_curent++; break;
            }

            x_min = min(x_min, x_curent);
            x_max = max(x_max, x_curent);
            y_min = min(y_min, y_curent);
            y_max = max(y_max, y_curent);
        }
    }

    int lungime = x_max - x_min + 1;
    int latime = y_max - y_min + 1;
    int aria = lungime * latime;

    cout << "Aria S: " << aria << "\n";
    cout << "Coordonatele colturilor stanga-sus si dreapta-jos: (" << x_min << ", " << y_max << ") si (" << x_max << ", " << y_min << ")\n";
}

void determinare_comoara() {
    int x_curent = 0, y_curent = 0;

    for (int i = 0; i < n; i++) {
        int directie = x[i][0];
        int pasi = x[i][1];

        switch (directie) {
            case 1: y_curent += pasi; break;
            case 2: x_curent += pasi; y_curent += pasi; break;
            case 3: x_curent += pasi; break;
            case 4: x_curent += pasi; y_curent -= pasi; break;
            case 5: y_curent -= pasi; break;
            case 6: x_curent -= pasi; y_curent -= pasi; break;
            case 7: x_curent -= pasi; break;
            case 8: x_curent -= pasi; y_curent += pasi; break;
        }
    }

    cout << "Coordonatele punctului in care este ascunsa comoara: (" << x_curent << ", " << y_curent << ")\n";
}