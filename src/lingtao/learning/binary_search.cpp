#include <iostream>
#include <vector>


int binary_search(std::vector<int>* elements, int target) {
    int l = 0, r = elements->size() - 1;
    std::cout<<r<<std::endl;
    while (l < r) {
        int mid = l + ((r-l)/2);
        if (elements->at(mid) == target)
            return mid;
        
        if (elements->at(mid) > target)
            r = mid - 1;
        else
            l = mid + 1;
    }
    return -1;

}

int main() {
    std::vector<int> elements;
    elements.push_back(1);
    elements.push_back(2);
    elements.push_back(3);
    elements.push_back(4);
    elements.push_back(5);
    elements.push_back(6);
    elements.push_back(7);
    elements.push_back(8);
    elements.push_back(9);
    elements.push_back(10);

    int target = 5;

    int result = binary_search(&elements, target);
    if (result != -1)
        std::cout << "Element found at index: " << result << std::endl;
    else
        std::cout << "Element not found in the array." << std::endl;

    return 0;

}