#include <iostream>
#include <fstream>
#include <sstream>
#include "csvio.hpp"

void print_data_set(std::vector<INSTANCE_TYPE> &data_set){
    std::cout.precision(20);
    for(int i = 0; i < data_set.size(); i++){
        for(int j = 0; j < data_set[i].first.size(); j++){
            std::cout << data_set[i].first[j] << " ";
        }
        std::cout << data_set[i].second << std::endl; 
    }
}

void read_data_set(std::vector<INSTANCE_TYPE> &data_set, std::string file_path, int target_column_index){
    
    std::ifstream file_input(file_path);
    std::string column_value;
    std::string line;
    INSTANCE_TYPE instance;
    int target_reach_indicator = 0;

    if(!file_input.is_open()) throw std::runtime_error("Could not open file..."); 

    std::getline(file_input, line);

    data_set.clear();

    while(getline(file_input, line)){
        instance.first.clear();
        instance.second = 0;
        target_reach_indicator = 0;
        std::stringstream ss(line);
        
        while(getline(ss, column_value, ',')){
            if(target_reach_indicator == target_column_index) {
                instance.second = std::stod(column_value);
                data_set.push_back(instance);
            }else {
                instance.first.push_back(std::stod(column_value));
            }
            target_reach_indicator++;
        }
    }
}
