#include <iostream>
#include <random>
#include <limits>
#include "my_Datagenerator.h"

my_Datagenerator::my_Datagenerator(){
  
    d='u';
    std::random_device  rand_dev;
    std::mt19937 generator( rand_dev() );
    rng=generator;
    getDistribution();
}
my_Datagenerator::my_Datagenerator(char dis){
  
    d=dis;
    std::random_device  rand_dev;
    std::mt19937 generator( rand_dev() );
    rng=generator;
    getDistribution();
}


my_Datagenerator::my_Datagenerator(int s, char dis){
d=dis;
std::mt19937 generator( s );
rng=generator;
getDistribution();
}


my_Datagenerator::my_Datagenerator(const my_Datagenerator& other){
rng= other.rng;
v=other.v;
d= other.d;
}
my_Datagenerator& my_Datagenerator::operator=(const my_Datagenerator& t){
rng= t.rng;
v=t.v;
d= t.d;
}

my_Datagenerator::~my_Datagenerator(){
    std::cout<<"Destruktor aufgerufen"<< std::endl;
};

void my_Datagenerator::getDistribution(){
    switch(d) {
  case 'u':    
  {
    std::uniform_int_distribution<int> dist5r(std::numeric_limits<int>::min(), std::numeric_limits<int>::max());
    v=dist5r;
    break;
  }
  case 'b':
  {
    std::bernoulli_distribution dist4r(0.5);
    v=dist4r;
    break;
  }
  case 'n':
  {
    std::normal_distribution<> dr{5,2};
    v= dr;
    break;
  }
  default:
  {
    std::uniform_int_distribution<int> dist5r(std::numeric_limits<int>::min(), std::numeric_limits<int>::max());
    v=dist5r;
    break;
  }
}
}

int my_Datagenerator::getValue(){

  switch(d) {
  case 'u':    
    return std::get<std::uniform_int_distribution<int>>(v)(rng);
    break;
  case 'b':
    return std::get<std::bernoulli_distribution>(v)(rng);
    break;
  case 'n':
    return std::get<std::normal_distribution<>>(v)(rng);
    break;
  default:
    return std::get<0>(v)(rng);
}
}

