#include <vector>
#include <string>

#define INSTANCE_TYPE std::pair<std::vector<double>, double>

void read_data_set(std::vector<INSTANCE_TYPE> &data_set, std::string file_path, int target_column_index);
void print_data_set(std::vector<INSTANCE_TYPE> &data_set);