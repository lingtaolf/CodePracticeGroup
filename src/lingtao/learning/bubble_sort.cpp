#include <iostream>
#include <vector>
#include <algorithm>

void bubbleSort(std::vector<int>& nums) {
    for (int i = nums.size() - 1; i > 0; --i) {
        for (int j = 0; j <= i - 1; ++j) {
            if (nums[j] > nums[j + 1])
                std::swap(nums[j], nums[j + 1]);
        }
    }

    std::cout << "After Sorting: "<<std::endl;;
    for (std::vector<int>::iterator it = nums.begin(); it != nums.end(); ++it) {
        std::cout<<*it<<" ";
    }
    std::cout<<std::endl;
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
    bubbleSort(nums);

    return 0;
}