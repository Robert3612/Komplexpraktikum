#include <iostream>
#include<vector>
#include <random>
#include <limits>


 class BaseDistribution{

public:
 template<typename T>
T getDistibution(){

 };
};

class UniversalDistribution : public BaseDistribution{
private:
std::uniform_int_distribution<int> dist5;
public:
UniversalDistribution(){
    std::uniform_int_distribution<int> dist5r(std::numeric_limits<int>::min(), std::numeric_limits<int>::max());
    dist5=dist5r;
}

std::uniform_int_distribution<int> getDistibution(){
return dist5;
 };
};

class NormalDistribution : public BaseDistribution{
private:
std::normal_distribution<> dist5;
public:
NormalDistribution(){
    std::normal_distribution<> dr{5,2};
    dist5=dr;
}

std::normal_distribution<> getDistibution(){
return dist5;
 };
};

class BernoulliDistribution : public BaseDistribution{
private:
std::bernoulli_distribution dist5;
public:
BernoulliDistribution(){
    std::bernoulli_distribution dr(0.5);
    dist5=dr;
}

std::bernoulli_distribution getDistibution(){
return dist5;
 };
};