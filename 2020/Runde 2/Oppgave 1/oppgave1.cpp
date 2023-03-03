#include <iostream>
#include <vector>
#include <algorithm>

int main()
{
    int N;
    std::cin >> N;

    std::vector<int> nums;
    for (int i = 0; i < N; i++)
    {
        std::string t;
        std::cin >> t;
        nums.push_back(std::stoi(t));
    }

    std::sort(nums.begin(), nums.end());

    int lowest_num = -1;
    for (int i = 0; i < N; i++)
    {
        if (nums[i] != nums[i+1] && nums[i] != nums[i-1])
        {
            lowest_num = nums[i];
            break;
        }
    }

    std::cout << lowest_num;

    return 0;
}