#include <vector>
#include "my_Datagenerator.h"

// Klasse zum speichern zufälliger Werte
template <typename T>
class Dataset
{
private:
    // speichert generierte Werte
    std::vector<std::vector<T>> dataset;

public:
    // Konstruktor mit Werten für Spalten und Reihen
    Dataset(int c, int r);
    // copy Konstruktor
    Dataset(const Dataset &other);
    // copy assignment operator
    Dataset &operator=(const Dataset &t);
    // Dekonstruktor
    ~Dataset();
    //ändert einen bestimmten Wert in der Matrix
    void changeValue(int c, int r, T v);
    // gibt einen bestimmten Wert aus der Matrix zurück
    T getValue(int c, int r);
    // füllt die Matrix mit zufälligen Werten
    void fill(my_Datagenerator *generator);
    // gibt alle Werte der Matrix aus
    void printData();
};