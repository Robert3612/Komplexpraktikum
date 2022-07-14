# Komplexpraktikum
Das ist das Repository für das Komplexpraktikum DB-systemarchitektur.

Voraussetungen:
mind. C++17
boost library
    https://www.boost.org/users/download/
    oder auch für Linux:
    sudo apt install libboost-all-dev
    sudo apt install aptitude
    aptitude search boost

kompilieren mit:
g++ my_Datagenerator.cpp Dataset.cpp main.cpp -lboost_program_options

Programm:
das Programm kann mit mehreren flags gestartet werden:
"help,h"    stellt alle möglichen flags dar
"culumn,c"  legt Anzahl der Spalten fest, wird benötigt, auch ohne Benutztung des Flags -c nutzbar
"row,r"     legt Anzahl der Reihen fest, wird benötigt, auch ohne Benutztung des Flags -r nutzbar
"distr,d"   legt die distribution für die random numbers fest, u=uniform, b=bernoulli, n=normal, standart ist u
"seed,s"    legt seed für distribution fest
"input,i"   legt config-Datei fest von welcher die Variablen gelesen werden, hat Vorrang zu normalen line input
"output,o"  legt Datei fest in welche gesamte Ausgabe geschrieben wird

