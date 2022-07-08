#include <iostream>
#include<vector>
#include "Dataset.cpp"
#include "my_Datagenerator.cpp"


int main()
{
    my_Datagenerator generator(34);
    std::cout<<generator.getValue();
    Dataset dataset(3,3);
    dataset.fill(&generator);
    std::cout<< dataset.getValue(2,1);
    std::cout<< dataset.getValue(1,1);

   
   return 0;

}