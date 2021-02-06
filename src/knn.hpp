#include "distances.hpp"

#define INSTANCE_TYPE std::pair<std::vector<double>, double>


INSTANCE_TYPE classify_instance(INSTANCE_TYPE instance, std::vector<INSTANCE_TYPE> training_data_set, int k);
void classify_data_set(std::vector<INSTANCE_TYPE> training_data_set, std::vector<INSTANCE_TYPE> test_data_set, std::vector<INSTANCE_TYPE> &results, int k);

