#include <vector>
#include <string>

#define INSTANCE_TYPE std::pair<std::vector<double>, double>

void read_data_set(std::vector<INSTANCE_TYPE> &data_set, std::string file_path);
void write_data_set_to_file(std::string file_name, std::vector<INSTANCE_TYPE> data_set, double hit_percentage);
void print_data_set(std::vector<INSTANCE_TYPE> &data_set);