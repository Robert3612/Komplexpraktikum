#include <iostream>
#include<vector>
#include <random>
#include <limits>


class my_Datagenerator{
private:
/**
using uniform_distribution =
typename std::conditional_t<
std::is_floating_point_v<D>,
std::uniform_real_distribution<D>,
typename std::conditional_t<
std::is_integral_v<D>,
std::uniform_int_distribution<D>,
void
>
>;**/

std::mt19937 rng;
std::uniform_int_distribution<int> dist5;
std::bernoulli_distribution dist4;
std::normal_distribution<> distn;
char d;
public:

my_Datagenerator(){
  
    d='u';
    std::random_device  rand_dev;
    std::mt19937 generator( rand_dev() );
    rng=generator;
    getDistribution();
}

my_Datagenerator(char di){
  
    d=di;
    std::random_device  rand_dev;
    std::mt19937 generator( rand_dev() );
    rng=generator;
    getDistribution();
}


my_Datagenerator(int s, char di){
d=di;
std::mt19937 generator( s );
rng=generator;
getDistribution();
}


my_Datagenerator(const my_Datagenerator& other){
rng= other.rng;
dist5=other.dist5;
dist4=other.dist4;
distn=other.distn;
d= other.d;
}
my_Datagenerator& operator=(const my_Datagenerator& t){
rng= t.rng;
dist5=t.dist5;
dist4=t.dist4;
distn=t.distn;
d= t.d;
}

~my_Datagenerator(){
    std::cout<<"Destruktor aufgerufen"<< std::endl;
};

void getDistribution(){

    std::uniform_int_distribution<int> dist5r(std::numeric_limits<int>::min(), std::numeric_limits<int>::max());
    dist5=dist5r;

    std::bernoulli_distribution dist4r(0.5);
   dist4=dist4r;

    std::normal_distribution<> dr{5,2};
    distn=dr;


}




int getValue(){
  switch(d) {
  case 'u':    
    return dist5(rng);
    break;
  case 'b':
    return dist4(rng);
    break;
  case 'n':
    return distn(rng);
    break;
  default:
    return dist5(rng);
}
}
};