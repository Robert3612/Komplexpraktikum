#include <iostream>
#include <vector>
#include <iomanip>
#include "Dataset.h"

template <typename T>
Dataset<T>::Dataset(int c, int r)
{

    dataset.resize(r);
    for (int i = 0; i < dataset.size(); i++)
    {
        dataset.at(i).resize(c);
    }
}
template <typename T>
Dataset<T>::Dataset(const Dataset<T> &other)
{
    dataset = other.dataset;
}

template <typename T>
Dataset<T> &Dataset<T>::operator=(const Dataset<T> &t)
{
    dataset = t.dataset;
}

template <typename T>
Dataset<T>::~Dataset()
{
    std::cout << "Destruktor aufgerufen" << std::endl;
};

template <typename T>
T Dataset<T>::getValue(int c, int r)
{
    return dataset.at(r - 1).at(c - 1);
}

template <typename T>
void Dataset<T>::changeValue(int c, int r, T v)
{
    dataset.at(r).at(c) = v;
}

template <typename T>
void Dataset<T>::fill(my_Datagenerator *generator)
{
    for (int i = 0; i < dataset.size(); i++)
    {
        for (int j = 0; j < dataset.at(i).size(); j++)
        {
            dataset.at(i).at(j) = generator->getValue<T>();
        }
    }
}

template <typename T>
void Dataset<T>::printData()
{
    for (int i = 0; i < dataset.size(); i++)
    {
        for (int j = 0; j < dataset.at(i).size(); j++)
        {
            std::cout << std::left << std::setw(20) << dataset.at(i).at(j);
        }
        std::cout << std::endl;
    }
}

// notwendig zum kompilieren
template class Dataset<int>;
template class Dataset<std::string>;
template class Dataset<float>;