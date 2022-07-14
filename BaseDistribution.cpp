#include <iostream>
#include<vector>
#include <random>
#include <limits>
#include <variant>

using Varient = std::variant<std::monostate,std::uniform_int_distribution<int>,std::bernoulli_distribution, std::normal_distribution<>>;
class BaseDistribution{
private:
char d;
Varient v;
public:
BaseDistribution(){
    d='u';
}
BaseDistribution(char di){
d=di;
}
BaseDistribution(const BaseDistribution& other){
v= other.v;
d= other.d;
}
BaseDistribution& operator=(const BaseDistribution& t){
v= t.v;
d= t.d;
}

~BaseDistribution(){
    std::cout<<"Destruktor aufgerufen"<< std::endl;
};
void getDistribution(){
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

std::variant<std::monostate,std::uniform_int_distribution<int>,std::bernoulli_distribution, std::normal_distribution<>> getVariant(){
    return v;
}


};