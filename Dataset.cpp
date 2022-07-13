#include <iostream>
#include<vector>
#include <iomanip>  
#include <fstream>
#include "my_Datagenerator.cpp"
#include <boost/program_options.hpp>
namespace po = boost::program_options;

class Dataset{
private:
std::vector<std::vector<int>> dataset;
public:
Dataset(int c,int r){
    /**std::vector<int> temp(c,0);
    std::vector<std::vector<int>> temp2(r, temp);
    dataset = temp2;**/
    
    dataset.resize(r);
    for(int i=0;i<dataset.size();i++){
        dataset.at(i).resize(c);
    }
}

Dataset(const Dataset& other){
    dataset=other.dataset;
}
Dataset& operator=(const Dataset& t){
    dataset=t.dataset;
}

~Dataset(){
    std::cout<<"Destruktor aufgerufen"<< std::endl;
};

int getValue(int c, int r){
    return dataset.at(r-1).at(c-1);
}

void changeValue(int c, int r, int v){
    dataset.at(r).at(c) = v;
}

void fill(my_Datagenerator* generator){
    for(int i=0;i<dataset.size();i++){
        for(int j=0;j<dataset.at(i).size();j++){
            dataset.at(i).at(j)= generator->getValue();
        }
    }
}

void printData(){
    for(int i=0;i<dataset.size();i++){
        for(int j=0;j<dataset.at(i).size();j++){
        std::cout<< std::left << std::setw(20) << dataset.at(i).at(j);
            
        }
        std::cout<<std::endl;
    }
}
};



int main(int argc, char **argv)

{
    std::string config_file;
    /**   int c,r;
    if(!checkParams(argc, argv, &c,&r)){
        std::cout<<"Parameter fehlen"<<std::endl;
    return 0;
    }**/
    
   
/**
    char d = *argv[3];
    
    my_Datagenerator generator(d);
    Dataset dataset(c,r);
    dataset.fill(&generator);
    dataset.printData();
    std::cout << dataset.getValue(1,2)<<std::endl;**/


po::options_description desc("Allowed options");
desc.add_options()
    ("help,h", "produce help message")
    ("culumn,c", po::value<int>(), "set c")
    ("row,r", po::value<int>(), "set r")
    ("distr,d", po::value<char>()->default_value('u'), "set distribution")
    ("seed,s", po::value<int>(), "set seed for distribution")
    ("input,i", po::value<std::string>(&config_file), "set config-file")
    ("output,o",po::value<std::string>(), "write every output into file")
;
po::options_description cmdline_options;
cmdline_options.add(desc);

po::options_description config_file_options;
config_file_options.add(desc);

po::positional_options_description p;
p.add("culumn", -1);
p.add("row", -1);

po::variables_map vm;
po::store(po::command_line_parser(argc, argv).
          options(desc).positional(p).run(), vm);
po::notify(vm);   
int r,c,s;
char d;
if (vm.count("help")) {
    std::cout << desc << "\n";
    return 1;
}
std::streambuf * buf;
std::ofstream of;

if(vm.count("output")) {
    of.open(vm["output"].as<std::string>());
    buf = of.rdbuf();
} else {
    buf = std::cout.rdbuf();
}
std::ostream out(buf);
std::cout.rdbuf(out.rdbuf());
if(vm.count("input")){
std::ifstream ifs(config_file.c_str());
store(parse_config_file(ifs, config_file_options), vm);
notify(vm);
}

if (!(vm.count("culumn")&& vm.count("row")) )
{   
    std::cout<< "r und c nicht gesetzt"<<std::endl;
    return 0;
}

c= vm["culumn"].as<int>();
r= vm["row"].as<int>();



my_Datagenerator generator;
if(vm.count("seed")){
    my_Datagenerator help(vm["seed"].as<int>(),vm["distr"].as<char>() );
    generator=help;
}
else{
    my_Datagenerator help(vm["distr"].as<char>());
    generator=help;
    std::cout<<vm["distr"].as<char>();
}
    Dataset dataset(c,r );
    dataset.fill(&generator);
    dataset.printData();
    std::cout << dataset.getValue(1,2)<<std::endl;
    //std::cout<< vm["input-file"].as< std::vector<int> >() << "\n";




   return 0;

}