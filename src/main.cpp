#include <cmath>
#include <iostream>
#include "csvio.hpp"
#include "knn.hpp"


#define NORMALIZED_FILE_PATH "dataset-cancer-classification/normalized-data/cancer_train.csv"
#define NON_NORMALIZED_FILE_PATH "dataset-cancer-classification/non-normalized-data/cancer_train.csv"
#define NORMALIZED_TEST_FILE_PATH "dataset-cancer-classification/normalized-data/cancer_test.csv"
#define NON_NORMALIZED_TEST_FILE_PATH "dataset-cancer-classification/non-normalized-data/cancer_test.csv"
#define NUMBER_OF_PARAMS 30
#define K 5

int main () {
    std::vector<INSTANCE_TYPE> training_set;
    std::vector<INSTANCE_TYPE> test_set;
    std::vector<INSTANCE_TYPE> results;

    try {
        read_data_set(training_set, NORMALIZED_FILE_PATH, NUMBER_OF_PARAMS);
        read_data_set(test_set, NORMALIZED_TEST_FILE_PATH, NUMBER_OF_PARAMS);
    }catch (std::runtime_error e) {
        std::cout << e.what() << std::endl;
        return 0;
    }

    classify_data_set(training_set, test_set, results, K);

    print_data_set(results);

}


