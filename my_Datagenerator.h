#include <iostream>
#include <random>
#include <variant>
using Varient = std::variant<std::uniform_int_distribution<int>, std::bernoulli_distribution, std::normal_distribution<>, std::uniform_real_distribution<float>>;
// Klasse zum generieren zufälliger Werte
class my_Datagenerator
{
private:
    // Varient zum speichern der Distribution
    Varient v;
    // random generator für Distribution
    std::mt19937 rng;
    // speichert welche Distribution gerade verwendet wird
    char d;
    // wählt richtige Distribution für Varient aus
    void getDistribution();
    char t;

public:
    // default Konstruktor
    my_Datagenerator();
    // Konstruktor wenn d gegeben ist
    my_Datagenerator(char dis, char tis);
    // Konstruktor wenn d und s gegeben ist
    my_Datagenerator(int s, char dis, char);
    // Dekonstruktor
    ~my_Datagenerator();
    // copy Konstruktor
    my_Datagenerator(const my_Datagenerator &other);
    // copy assignment operator
    my_Datagenerator &operator=(const my_Datagenerator &t);
    // gibt einen random value zurück
    // benutzt explicit specializations für die Dataentypen welche gespeichert werden können
    template <typename T>
    T getValue();
};