#include <iostream>
#include <algorithm>


void insertSort(std::vector<int>* nums) {
    for (int i = 1; i < nums->size(); ++i) {
        int current_num = nums->at(i), move_index = i - 1, current_index = i;

        while (move_index >= 0) {
            if (current_num  < nums->at(move_index)) {
                std::cout<<"swap : "<<(*nums)[move_index]<<" - "<< (*nums)[current_index]<<std::endl;
                std::swap((*nums)[move_index], (*nums)[current_index]);
                current_index = move_index;
            }
            --move_index;
            std::cout<<"current sort"<<std::endl;
            for (int x = 0; x <= i; ++x) {
                std::cout<<(*nums)[x]<<" ";
            }
            std::cout<<std::endl;
        }
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

    insertSort(&nums);

    std::cout << "After Sorting: "<<std::endl;;

    for (std::vector<int>::iterator it = nums.begin(); it != nums.end(); ++it)
    {
        std::cout <<*it<<" ";
    }

    return 0;
}