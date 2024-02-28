#include <iostream>
#include <vector>

bool check(const std::vector<int>& nums) 
{
    int count = 0;
    for (int i = 1; i < nums.size(); i++) 
    {
        if (nums[i] < nums[i - 1])
            count++;
    }
    if (nums[nums.size() - 1] > nums[0])
        count++;

    return count <= 1;
}

int main()
{
    std::vector<int> v;
    v.push_back(3);
    v.push_back(4);
    v.push_back(5);
    // v.push_back(1);
    // v.push_back(2);

    bool ans = check(v);
    if (ans)
    {
        std::cout << "It is a sorted and rotated array." << std::endl;
    }
     else
    {
        std::cout << "It is not a sorted and rotated array." << std::endl;
    }

    return 0;
}

