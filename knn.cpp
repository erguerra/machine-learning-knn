#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <cmath>

#define NORMALIZED_FILE_PATH "dataset-cancer-classification/normalized-data/cancer_train.csv"
#define NON_NORMALIZED_FILE_PATH "dataset-cancer-classification/non-normalized-data/cancer_train.csv"
#define NUMBER_OF_PARAMS 30
#define INSTANCE_TYPE std::pair<std::vector<double>, double>


void read_data_set(std::vector<INSTANCE_TYPE> &data_set, std::string file_path);
void print_data_set(std::vector<INSTANCE_TYPE> &data_set);
double euclidean_distance(std::vector<double> point_a, std::vector<double> point_b);

int main () {
    int k = 0;
    std::vector<INSTANCE_TYPE> training_set;

    try {
        read_data_set(training_set, NORMALIZED_FILE_PATH);
    }catch (std::runtime_error e) {
        std::cout << e.what() << std::endl;
        return 0;
    }

    print_data_set(training_set);

}

void print_data_set(std::vector<INSTANCE_TYPE> &data_set){
    std::cout.precision(20);
    for(int i = 0; i < data_set.size(); i++){
        for(int j = 0; j < data_set[i].first.size(); j++){
            std::cout << data_set[i].first[j] << " ";
        }
        std::cout << data_set[i].second << std::endl; 
    }
}

void read_data_set(std::vector<INSTANCE_TYPE> &data_set, std::string file_path){
    
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
            if(target_reach_indicator == NUMBER_OF_PARAMS) {
                instance.second = std::stod(column_value);
                data_set.push_back(instance);
            }else {
                instance.first.push_back(std::stod(column_value));
            }
            target_reach_indicator++;
        }
    }
}

double euclidean_distance(std::vector<double> point_a, std::vector<double> point_b){
    int size = point_a.size();
    std::cout << size << std::endl;
    std::cout << point_b.size() << std::endl;
    if(size != point_b.size()) throw std::runtime_error("Points with different number of dimensions...");

    double summation = 0.0;

    for(int i = 0; i < size; i++){
        summation += pow((point_a[i] - point_b[i]), 2.0);
    }

    return sqrt(summation);
}

