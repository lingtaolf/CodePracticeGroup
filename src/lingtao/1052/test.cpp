#include <vector>
#include <iostream>

using namespace std;

int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int minutes) {
    int max_save_customers;
    for (int g : grumpy)
    {
        int start = g - minutes + 1;
        int end = g + minutes - 1;

        for (int begin = start; begin <= g; ++begin)
        {
            int count = 0;
            int sum;
            while (count < minutes)
            {
                sum += customers[begin + count];
                ++count;
            }
            max_save_customers = sum > max_save_customers ? sum : max_save_customers;
        }
    }

    return max_save_customers;
}

int main()
{
    vector<int> intput_vector;
    vector<int> intput_grumpy;

    intput_vector.emplace_back(0);
    intput_vector.emplace_back(1);
    intput_vector.emplace_back(2);
    intput_vector.emplace_back(3);
    intput_vector.emplace_back(4);
    intput_vector.emplace_back(5);
    intput_vector.emplace_back(6);

    intput_grumpy.emplace_back(3);
    intput_grumpy.emplace_back(5);

    std::cout<<maxSatisfied(intput_vector, intput_grumpy, 2)<<std::endl;


}
