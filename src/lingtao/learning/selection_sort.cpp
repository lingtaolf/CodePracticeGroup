#include <iostream>
#include <utility>
#include <vector>
#include <algorithm>


void selectionSort(std::vector<int>& nums)
{
    

    for (int current_index = 0; current_index < nums.size() - 1; current_index++) {
        int min_index = current_index;
        for (int i = current_index + 1; i < nums.size(); i++)
        {
            if (nums.at(i) < nums.at(min_index)) 
                min_index = i;
                
        }
        std::swap(nums[current_index], nums[min_index]);
    }
    std::cout << "After Sorting: "<<std::endl;

    for (std::vector<int>::iterator it = nums.begin(); it != nums.end(); ++it)
    {
        std::cout <<*it<<" ";
    }
}

int main() {
    std::vector<int> nums;
    nums.push_back(5);
    nums.push_back(3);
    nums.push_back(9);
    nums.push_back(2);
    nums.push_back(10);
    nums.push_back(6);
    nums.push_back(1);
    nums.push_back(4);
    nums.push_back(8);
    nums.push_back(7);

    std::cout << "Before Sorting: "<<std::endl;;

    for (std::vector<int>::iterator it = nums.begin(); it != nums.end(); ++it)
    {
        std::cout <<*it<<" ";
    }

    std::cout<<std::endl;

    selectionSort(nums);

}

