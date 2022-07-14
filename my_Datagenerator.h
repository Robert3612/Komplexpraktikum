#include <iostream>
#include <random>
#include <variant>
using Varient = std::variant<std::uniform_int_distribution<int>,std::bernoulli_distribution, std::normal_distribution<>>;
//Klasse zum generieren zufälliger Werte
class my_Datagenerator{
private:
//Varient zum speichern der Distribution
Varient v;
//random generator für Distribution
std::mt19937 rng;
//speichert welche Distribution gerade verwendet wird
char d;
//wählt richtige Distribution für Varient aus
void getDistribution();
public:
// default Konstruktor
my_Datagenerator();
// Konstruktor wenn d gegeben ist
my_Datagenerator(char dis);
// Konstruktor wenn d und s gegeben ist
my_Datagenerator(int s, char dis);
// Dekonstruktor
~my_Datagenerator();
// copy Konstruktor
my_Datagenerator(const my_Datagenerator& other);
// copy assignment operator
my_Datagenerator& operator=(const my_Datagenerator& t);
//gibt einen random value zurück
int getValue();
};