#include <cmath>
#include <iostream>
#include "csvio.hpp"
#include "distances.hpp"


#define NORMALIZED_FILE_PATH "dataset-cancer-classification/normalized-data/cancer_train.csv"
#define NON_NORMALIZED_FILE_PATH "dataset-cancer-classification/non-normalized-data/cancer_train.csv"
#define NUMBER_OF_PARAMS 30
#define INSTANCE_TYPE std::pair<std::vector<double>, double>

int main () {
    int k = 0;
    std::vector<INSTANCE_TYPE> training_set;

    std::vector<double> test_instance_1 {0.50, 0.43};
    std::vector<double> test_instance_2 {1.00, 0.57};

    try {
        //read_data_set(training_set, NORMALIZED_FILE_PATH, NUMBER_OF_PARAMS);
        std::cout << manhattan_distance(test_instance_1, test_instance_2) << std::endl;
    }catch (std::runtime_error e) {
        std::cout << e.what() << std::endl;
        return 0;
    }

}


