#include <iostream>
#include<vector>
#include <iomanip>
#include "Dataset.h"

Dataset::Dataset(int c,int r){

    
    dataset.resize(r);
    for(int i=0;i<dataset.size();i++){
        dataset.at(i).resize(c);
    }
}

Dataset::Dataset(const Dataset& other){
    dataset=other.dataset;
}
Dataset& Dataset::operator=(const Dataset& t){
    dataset=t.dataset;
}

Dataset::~Dataset(){
    std::cout<<"Destruktor aufgerufen"<< std::endl;
};

int Dataset::getValue(int c, int r){
    return dataset.at(r-1).at(c-1);
}

void Dataset::changeValue(int c, int r, int v){
    dataset.at(r).at(c) = v;
}

void Dataset::fill(my_Datagenerator* generator){
    for(int i=0;i<dataset.size();i++){
        for(int j=0;j<dataset.at(i).size();j++){
            dataset.at(i).at(j)= generator->getValue();
        }
    }
}

void Dataset::printData(){
    for(int i=0;i<dataset.size();i++){
        for(int j=0;j<dataset.at(i).size();j++){
        std::cout<< std::left << std::setw(20) << dataset.at(i).at(j);
            
        }
        std::cout<<std::endl;
    }
}
