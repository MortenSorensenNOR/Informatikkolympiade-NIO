#include <vector>
#include <stdio.h>
#include <fstream>
#include <sstream>
#include <iostream>
#include <unordered_map>

using namespace std;

vector<vector<int>> read_file()
{
    vector<vector<int>> data;

    string line;
    ifstream data_file;
    string path = "day4.txt";
    data_file.open(path);

    if (data_file.is_open())
    {
        while (std::getline(data_file, line))
        {
            vector<int> set_pair_data;

            string id_set_pair;
            istringstream pair_ss(line);
            while (std::getline(pair_ss, id_set_pair, ','))
            {
                string id_set;
                istringstream set_ss(id_set_pair);
                while(getline(set_ss, id_set, '-'))
                {
                    set_pair_data.push_back(stoi(id_set.c_str()));
                }
            }
            data.push_back(set_pair_data);
        }
        data_file.close();
    }
    else
    {
        printf("Could not open file %s", path);
        return {};
    }

    return data;
}

int main()
{
    int fully_contained_pairs = 0;
    vector<vector<int>> idSetPairs = read_file();
    for (int i = 0; i < idSetPairs.size(); i++)
    {
        int s1 = idSetPairs[i][0], e1 = idSetPairs[i][1]; 
        int s2 = idSetPairs[i][2], e2 = idSetPairs[i][3];

        if ((s1 >= s2 && e1 <= e2) || (s2 >= s1 && e2 <= e1))
            fully_contained_pairs++;
    }
    printf("Number of fully contained pairs: %d\n", fully_contained_pairs);
    
    int overlaping_pairs = 0;
    for (int i = 0; i < idSetPairs.size(); i++)
    {
        int s1 = idSetPairs[i][0], e1 = idSetPairs[i][1]; 
        int s2 = idSetPairs[i][2], e2 = idSetPairs[i][3];

        if ((s1 >= s2 && s1 <= e2) || (e1 >= s2 && e1 <= e2))
            overlaping_pairs++;
        else if ((s2 >= s1 && s2 <= e1) || (e2 >= s1 && e2 <= e1))
            overlaping_pairs++;
    }
    printf("Number of overlaping pairs: %d\n", overlaping_pairs);

    return 0;
}