#include <iostream>
#include<vector>
#include <random>
#include <limits>

class my_Datagenerator{
private:
std::random_device dev;
std::mt19937 rng;
std::uniform_int_distribution<std::mt19937::result_type> dist6; 
public:
my_Datagenerator(){
    std::random_device  rand_dev;
    std::mt19937 generator( rand_dev() );
    rng=generator;

std::uniform_int_distribution<std::mt19937::result_type> dist5(std::numeric_limits<int>::min(), std::numeric_limits<int>::max());
dist6=dist5;
}

my_Datagenerator(int s){

std::mt19937 generator( s );
rng=generator;
std::uniform_int_distribution<std::mt19937::result_type> dist5(std::numeric_limits<int>::min(), std::numeric_limits<int>::max());
dist6=dist5;
}

int getValue(){
    dist6(rng);
}

void changeValue(int c, int r, int v){
   
}
};