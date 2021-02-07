#include <cmath>
#include <iostream>
#include "csvio.hpp"
#include "knn.hpp"

#define NORMALIZED_FILE_PATH "dataset-cancer-classification/normalized-data/cancer_train.csv"
#define NON_NORMALIZED_FILE_PATH "dataset-cancer-classification/non-normalized-data/cancer_train.csv"
#define NORMALIZED_TEST_FILE_PATH "dataset-cancer-classification/normalized-data/cancer_test.csv"
#define NON_NORMALIZED_TEST_FILE_PATH "dataset-cancer-classification/non-normalized-data/cancer_test.csv"

int main()
{
    std::vector<INSTANCE_TYPE> training_set;
    std::vector<INSTANCE_TYPE> test_set;
    std::vector<INSTANCE_TYPE> results;
    std::string output_file_name("");

    int k = 0;
    char normalized = '\0';
    char distance_method = '\0';
    double hit_percentage = 0.0;


    std::cout << "--------------- WELCOME TO KNN ! ---------------" << std::endl;
    std::cout << "Dou you want to use the normalized dataset? Y(YES)/N(NO)" << std::endl;
    std::cin >> normalized;

    if (toupper(normalized) == 'Y')
    {
        output_file_name.append("normalized");
        std::cout << "Reading normalized training data (" << NORMALIZED_FILE_PATH << ")..." << std::endl;
        read_data_set(training_set, NORMALIZED_FILE_PATH);
        std::cout << "Reading normalized test data (" << NORMALIZED_TEST_FILE_PATH << ")..." << std::endl;
        read_data_set(test_set, NORMALIZED_TEST_FILE_PATH);
    }
    else
    {
        output_file_name.append("nonNormalized");
        std::cout << "Reading non normalized training data (" << NON_NORMALIZED_FILE_PATH << ")..." << std::endl;
        read_data_set(training_set, NON_NORMALIZED_FILE_PATH);
        std::cout << "Reading non normalized test data (" << NON_NORMALIZED_TEST_FILE_PATH << ")..." << std::endl;
        read_data_set(test_set, NON_NORMALIZED_TEST_FILE_PATH);
    }

    std::cout << "Insert the value of K" << std::endl;
    std::cin >> k;
    output_file_name.append("WithK");
    output_file_name.append(std::to_string(k));


    std::cout << "Choose distance method" << std::endl;
    std::cout << "E (Euclidean Distance) / M (Manhattan Distance)" << std::endl;
    std::cin >> distance_method;

    if (toupper(distance_method) == 'M')
    {
        output_file_name.append("Mahattan");
        std::cout << "Classifying data using " << k << " nearest neighbors and Manhattan Distance" << std::endl;
        classify_data_set(training_set, test_set, results, k, &manhattan_distance);
        hit_percentage = getPercentageOfHits(test_set, results);
        std::cout << "The percentage of hits for " << k << " neighbors and Manhattan Distance was " << hit_percentage << "%" << std::endl;
    }
    else
    {
        output_file_name.append("Euclidean");
        std::cout << "Classifying data using " << k << " nearest neighbors and Euclidean Distance" << std::endl;
        classify_data_set(training_set, test_set, results, k, &euclidean_distance);
        hit_percentage = getPercentageOfHits(test_set, results);
        std::cout << "The percentage of hits for " << k << " neighbors and Euclidean Distance was " << hit_percentage << "%" << std::endl;
    }

    output_file_name.append("output");

    std::cout << "Writing results..." << std::endl;
    write_data_set_to_file(output_file_name, results, hit_percentage);
    std::cout << "Done! :)" << std::endl;
}
