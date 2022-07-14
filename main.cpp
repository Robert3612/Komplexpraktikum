#include <iostream>
#include<vector>
#include <fstream>
#include "Dataset.h"
#include <boost/program_options.hpp>
namespace po = boost::program_options;



int main(int argc, char **argv)

{
//Variable zum speichern der config Datei
std::string config_file;

//bestimmt alle flags welche in der command line benutzt werden können
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

//speichert erlaubte flags für config-file option
po::options_description config_file_options;
config_file_options.add(desc);

//setzt c und r so das keine flags(z.B. -r) geschrieben werden müssen
po::positional_options_description p;
p.add("culumn", 1);
p.add("row", 1);


po::variables_map vm;

//speichert command line arguments
po::store(po::command_line_parser(argc, argv).
          options(desc).positional(p).run(), vm);
po::notify(vm);   
int r,c,s;
char d;
if (vm.count("help")) {
    std::cout << desc << "\n";
    return 1;
}

//ändert output stream wenn flag gesetzt wurde
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

//nimmt parameter aus input-file wenn flag gesetzt wurde
if(vm.count("input")){
std::ifstream ifs(config_file.c_str());
store(parse_config_file(ifs, config_file_options), vm);
notify(vm);
}

//setzt r und c
if (!(vm.count("culumn")&& vm.count("row")) )
{   
    std::cout<< "r und c nicht gesetzt"<<std::endl;
    return 0;
}

c= vm["culumn"].as<int>();
r= vm["row"].as<int>();


my_Datagenerator generator;
//initialisiert generator jenachdem ob seed gesetzt wurde oder nicht
if(vm.count("seed")){
    my_Datagenerator help(vm["seed"].as<int>(),vm["distr"].as<char>() );
    generator=help;
}
else{
    my_Datagenerator help(vm["distr"].as<char>());
    generator=help;
}
    //initialisiert Dataset
    Dataset dataset(c,r );
    //füllt Dataset
    dataset.fill(&generator);
    //gibt alle Werte des Datasets aus
    dataset.printData();



   return 0;

}