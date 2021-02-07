#include "knn.hpp"
#include <algorithm>

INSTANCE_TYPE classify_instance(INSTANCE_TYPE instance, std::vector<INSTANCE_TYPE> training_data_set, int k, std::function<double(std::vector<double>, std::vector<double>)> get_distance)
{

    std::vector<std::pair<double, double>> all_neighbors_distances;
    std::vector<double> classes{0.0, 1.0};

    double distance = 0.0;
    all_neighbors_distances.clear();
    unsigned i = 0;

    for (i = 0; i < (unsigned)training_data_set.size(); i++)
    {
        distance = get_distance(instance.first, training_data_set[i].first);
        all_neighbors_distances.push_back(std::make_pair(distance, training_data_set[i].second));
    }

    std::sort(all_neighbors_distances.begin(), all_neighbors_distances.end());

    std::vector<double> k_nearest_neighbors_labels;

    k_nearest_neighbors_labels.clear();

    for (i = 0; i < (unsigned)k; i++)
    {
        k_nearest_neighbors_labels.push_back(all_neighbors_distances[i].second);
    }

    std::vector<int> classes_votes(classes.size(), 0);

    for (i = 0; i < classes_votes.size(); i++)
    {
        classes_votes[i] = std::count(k_nearest_neighbors_labels.begin(), k_nearest_neighbors_labels.end(), classes[i]);
    }

    int most_voted_class = (double)(std::max_element(classes_votes.begin(), classes_votes.end()) - classes_votes.begin());

    return std::make_pair(instance.first, most_voted_class);
}

void classify_data_set(std::vector<INSTANCE_TYPE> training_data_set, std::vector<INSTANCE_TYPE> test_data_set, std::vector<INSTANCE_TYPE> &results, int k, std::function<double(std::vector<double>, std::vector<double>)> get_distance)
{
    results.clear();
    for (unsigned i = 0; i < (unsigned)test_data_set.size(); i++)
    {
        results.push_back(classify_instance(test_data_set[i], training_data_set, k, get_distance));
    }
}

double getPercentageOfHits(std::vector<INSTANCE_TYPE> test_data_set, std::vector<INSTANCE_TYPE> classified_data_set)
{
    int hits = 0.0;
    unsigned numberOfInstances = test_data_set.size();
    for (unsigned i = 0; i < numberOfInstances; i++)
    {
        if (test_data_set[i].second == classified_data_set[i].second)
        {
            hits++;
        }
    }
    return ((double)hits * 100) / (double)numberOfInstances;
}