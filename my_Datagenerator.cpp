#include <iostream>
#include <random>
#include <limits>
#include "my_Datagenerator.h"

my_Datagenerator::my_Datagenerator()
{

  d = 'u';
  t = 'i';
  std::random_device rand_dev;
  std::mt19937 generator(rand_dev());
  rng = generator;
  getDistribution();
}
my_Datagenerator::my_Datagenerator(char dis, char tis)
{
  t = tis;
  d = dis;
  std::random_device rand_dev;
  std::mt19937 generator(rand_dev());
  rng = generator;
  getDistribution();
}

my_Datagenerator::my_Datagenerator(int s, char dis, char tis)
{
  d = dis;
  t = tis;
  std::mt19937 generator(s);
  rng = generator;
  getDistribution();
}

my_Datagenerator::my_Datagenerator(const my_Datagenerator &other)
{
  rng = other.rng;
  v = other.v;
  d = other.d;
  t = other.t;
}
my_Datagenerator &my_Datagenerator::operator=(const my_Datagenerator &o)
{
  rng = o.rng;
  v = o.v;
  d = o.d;
  t = o.t;
}

my_Datagenerator::~my_Datagenerator()
{
  std::cout << "Destruktor aufgerufen" << std::endl;
};

void my_Datagenerator::getDistribution()
{
  switch (t)
  {
  case 's':
  {
    std::uniform_int_distribution<int> dist5r(0, 62);
    v = dist5r;
    return;
  }
  case 'f':
  {
    std::uniform_real_distribution<float> dist3r(std::numeric_limits<float>::min(), std::numeric_limits<float>::max());
    v = dist3r;
    return;
  }
  default:
    break;
  }

  switch (d)
  {
  case 'u':
  {
    std::uniform_int_distribution<int> dist5r(std::numeric_limits<int>::min(), std::numeric_limits<int>::max());
    v = dist5r;
    break;
  }
  case 'b':
  {
    std::bernoulli_distribution dist4r(0.5);
    v = dist4r;
    break;
  }
  case 'n':
  {
    std::normal_distribution<> dr{5, 2};
    v = dr;
    break;
  }
  default:
  {
    std::uniform_int_distribution<int> dist5r(std::numeric_limits<int>::min(), std::numeric_limits<int>::max());
    v = dist5r;
    break;
  }
  }
}

template <>
int my_Datagenerator::getValue<int>()
{

  switch (d)
  {
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
template <>
std::string my_Datagenerator::getValue<std::string>()
{
  std::string possible_characters = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
  std::string ret = "";
  std::uniform_int_distribution<int> help = std::get<std::uniform_int_distribution<int>>(v);
  for (int i = 0; i < 5; i++)
  {
    int random_index = help(rng); // get index between 0 and possible_characters.size()-1
    ret += possible_characters[random_index];
  }
  return ret;
}

template <>
float my_Datagenerator::getValue<float>()
{
  return std::get<std::uniform_real_distribution<float>>(v)(rng);
}
