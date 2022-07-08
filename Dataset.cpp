#include <iostream>
#include<vector>
#include "my_Datagenerator.cpp"

class Dataset{
private:
std::vector<std::vector<int>> dataset;
public:
Dataset(int c,int r){
    dataset.resize(r);
    for(int i=0;i<dataset.size();i++){
        dataset.at(i).resize(c);
    }
}

int getValue(int c, int r){
    return dataset.at(r).at(c);
}

void changeValue(int c, int r, int v){
    dataset.at(r).at(c) = v;
}

void fill(my_Datagenerator* generator){
    for(int i;i<dataset.size();i++){
        for(int j;j<dataset.at(i).size();i++){
            dataset.at(i).at(j)= generator->getValue();
        }
    }
}
};