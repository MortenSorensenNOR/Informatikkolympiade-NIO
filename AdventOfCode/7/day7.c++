#include <set>
#include <stack>
#include <vector>
#include <stdio.h>
#include <fstream>
#include <sstream>
#include <iostream>
#include <algorithm> 
#include <unordered_map>

using namespace std;

struct Dir
{
    string name;
    int size;
    int capacity;
    struct Dir **sub_dirs;
    struct Dir *parent_dir;

    long total;
};

void insert(Dir *dir, string name)
{
    if (dir->size == dir->capacity)
    {
        dir->capacity = (dir->size+1) * 2;
        dir->sub_dirs = (Dir **)realloc(dir->sub_dirs, dir->capacity * sizeof(Dir*));
    }

    Dir* sub_dir = (Dir*)calloc(1, sizeof(Dir));
    sub_dir->name = name;
    sub_dir->parent_dir = dir;

    dir->sub_dirs[dir->size++] = sub_dir;
}

Dir* find(Dir* dir, string name)
{
    for (int i = 0; i < dir->size; i++)
    {
        if (dir->sub_dirs[i]->name == name)
        {
            return dir->sub_dirs[i];
        }
    }

    return NULL;
}

long getTotal(Dir* dir)
{
    long total = dir->total;
    for (int i = 0; i < dir->size; i++)
    {
        total += getTotal(dir->sub_dirs[i]);
    }
    return total;
}

void freeDir(Dir *dir)
{
    for ( int i = 0; i < dir->size; i++ )
        freeDir( dir->sub_dirs[ i ] );

    free(dir);
}

void getSumOfDirs(Dir* root, long& cap, long& total)
{
    long current_dir_size = getTotal(root);
    if (current_dir_size < cap)
        total += current_dir_size;
    for (int i = 0; i < root->size; i++)
        getSumOfDirs(root->sub_dirs[i], cap, total);
}

void getAllDirSizes(Dir* root, vector<long>& dir_sizes)
{
    dir_sizes.push_back(getTotal(root));
    for (int i = 0; i < root->size; i++)
        getAllDirSizes(root->sub_dirs[i], dir_sizes);
}

int main()
{
    Dir* current_dir = NULL;
    Dir* root = (Dir*)calloc(1, sizeof(Dir));
    root->name = "/";

    string line;
    ifstream data_file;
    vector<string> lines;
    data_file.open("day7.txt");
    while(getline(data_file, line))
    {
        lines.push_back(line);
    }

    int idx = 0;
    while(idx < lines.size())
    {
        string line = lines[idx];
        stringstream ss(line);

        // Remove $
        string dollar;
        ss >> dollar;

        // Get Command
        string cmd;
        ss >> cmd;

        if (cmd == "cd")
        {
            // Enter new dir
            string name;
            ss >> name;

            if (name == "/")
            {
                current_dir = root;
            }
            else if (name == "..")
            {
                current_dir = current_dir->parent_dir;
            }
            else
            {
                current_dir = find(current_dir, name);
            }
            idx++;
        }
        else
        {
            // Listing dir elements
            while(++idx < lines.size())
            {
                line = lines[idx];
                if (line[0] == '$')
                    break;
                
                string first, name;
                stringstream lsStream(line);
                lsStream >> first >> name;

                if (first == "dir")
                {
                    insert(current_dir, name);
                }
                else 
                {
                    current_dir->total += atoi(first.c_str());
                }
            }

        }
    }

    long total = 0;
    long capacity = 100000;
    getSumOfDirs(root, capacity, total);
    printf("Sum of all directories with size under %d: %d\n", capacity, total);

    long free_space = 70000000 - getTotal(root);
    long needed_space = 30000000;

    vector<long> dir_sizes{};
    getAllDirSizes(root, dir_sizes);
    sort(dir_sizes.begin(), dir_sizes.end());
    
    for (int i = 0; i < dir_sizes.size(); i++)
    {
        if (dir_sizes[i] + free_space >= needed_space)
        {
            printf("Smallest dir to delete: %d\n", dir_sizes[i]);
            break;
        }
    }

    return 0;
}