#include <iostream>

using namespace std;

int main()
{
    std::string name;
    std::cout << "Bitte Name eintragen" << std::endl;
    std::cin>> name;
    std::cout << "Hallo " + name<<std::endl;
   
   
   return 0;

}