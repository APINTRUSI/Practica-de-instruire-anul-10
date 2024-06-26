﻿# Practica-de-instruire-anul-10
Să găsești o comoară ascunsă de către pirați este simplu dacă ai o hartă, care este însoțită de un algoritm ce descrie deplasarea spre comoară. De obicei, indicațiile presupun deplasări cu un anumit număr de pași în una din direcțiile numerotate conform 1 (x, y+1), 2 (x+1, y+1), 3 (x+1, y), 4 (x+1, y-1), 5 (x, y-1), 6 (x-1, y-1), 7 (x-1, y), 8 (x-1, y+1). Un pas ne duce întotdeauna dintr-un punct de coordonate întregi în alt punct de coordonate întregi. Deci dacă la un moment dat suntem în punctul de coordonate (X, Y), deplasarea cu 1 pas în una dintre cele 8 direcții ne duce în unul dintre punctele de coordonate întregi. 
Informațiile despre traseul spre comoară sunt înregistrate în fișierul de intrare Comori.in, care conține pe prima linie naturalul n, reprezentând numărul de indicații. Următoarele n linii conțin câte o indicație pe o linie, sub forma a două numere naturale d și p separate printr-un spațiu, unde d este codul direcției, iar p numărul de pași.
Să se creeze o aplicație care să realizeze la solicitarea utilizatorului, următoarele prescripții:
1. Extinde traseul spre comoară, descris în fișierul Comori.in, cu o indicație;
2. Exclude ultima indicație din traseul spre comori, descris în fișierul Comori.in;
3. Determină numărul total de pași necesar de efectuat conform traseului descris în fișierul de intrare
4. Determină numărul schimbărilor de direcție din traseul descris de pirați;
5. Creează fișierul text UnPas.txt prin copiere din fișierul Comori.in a liniilor pentru care p=1;
6. Afișează pe ecran lista codurilor direcțiilor deplasărilor în ordinea descendentă a numărului lor de apariție în traseului spre comoară; datele se vor sorta prin metoda numărării;
7. Găsește în planul cartezian un dreptunghi de arie minimală ce conține în întregime traseul spre comoară; laturile dreptunghiului vor fi paralele cu axele de coordonate respective. La ecran se va afișa aria S și coordonatele colțurilor stânga-sus și dreapta-jos ale dreptunghiului găsit.
8. Rezolvă problema. Scrieți un subprogram, care, după indicațiile piraților determină punctul în care este ascunsă comoara. Se consideră că axa Ox e îndreptată spre est, iar Oy spre nord. Inițial căutătorul de comori se află în originea sistemului de coordonate (punctul de coordonate (0,0)).
