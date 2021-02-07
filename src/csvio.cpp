#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>
#include "csvio.hpp"

void print_data_set(std::vector<INSTANCE_TYPE> &data_set)
{
    std::cout.precision(20);
    for (int i = 0; i < data_set.size(); i++)
    {
        for (int j = 0; j < data_set[i].first.size(); j++)
        {
            std::cout << data_set[i].first[j] << " ";
        }
        std::cout << data_set[i].second << std::endl;
    }
}

void read_data_set(std::vector<INSTANCE_TYPE> &data_set, std::string file_path)
{

    std::ifstream file_input(file_path);
    std::string column_value;
    std::string line;
    INSTANCE_TYPE instance;

    if (!file_input.is_open())
        throw std::runtime_error("Could not open file...");

    std::getline(file_input, line);

    data_set.clear();

    while (getline(file_input, line))
    {
        instance.first.clear();
        instance.second = 0.0;
        std::stringstream ss(line);

        while (getline(ss, column_value, ','))
        {
            instance.first.push_back(std::stod(column_value));
        }

        if (instance.first.empty())
        {
            throw std::runtime_error("Could not read instance...");
        }
        else
        {
            instance.second = instance.first.back();
            instance.first.pop_back();
            data_set.push_back(instance);
        }
    }

    file_input.close();
}

void write_data_set_to_file(std::vector<INSTANCE_TYPE> data_set)
{
    std::ofstream file_output("output.csv");
    if (!file_output.is_open())
        throw std::runtime_error("Could not open file...");
    for (unsigned i = 0; i < data_set.size(); i++)
    {
        for (unsigned j = 0; j < data_set[i].first.size(); j++)
        {
            file_output << std::setprecision(20) << data_set[i].first[j] << ",";
        }
        file_output << data_set[i].second << "\n";
    }

    file_output.close();
}
