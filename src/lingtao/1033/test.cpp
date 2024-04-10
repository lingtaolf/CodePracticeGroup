#include <vector>
#include <iostream>

using namespace std;

int getMax(int a, int b)
{
    return a > b? a : b;
}

int getMin(int a, int b)
{
    return a > b? b : a;
}

vector<int> numMovesStones(int a, int b, int c) {
    int max = getMax(getMax(a,b), c);
    int min = getMin(getMin(a,b), c);
    int mid;

    if (a != max && a != min)
        mid = a;
    else if (b != max && b != min)
        mid = b;
    else
        mid = c;

    std::cout<<"min:"<<min<<std::endl<<"mid:"<<mid<<std::endl<<"max:"<<max<<std::endl;

    /*最大的情况可以按照下面的方式考虑
         a         b                        c
     ————|————|————|————|————|————|————|————|————>
    0    1    2    3    4    5    6    7    8
    例如上面的这种情况，考虑最大的移动次数，第一步肯定是要把移动
    的点往距离大的两个点之间移动。所以要把a往b和c之间移动。因为
    要实现最大的移动次数，所以每次移动一步即可。
                   b    a                   c
     ————|————|————|————|————|————|————|————|————>
    0    1    2    3    4    5    6    7    8
    那么接下来只需要轮流移动b和a就可以了，所以最大的移动次数就是b和c之间的距离。
    以上，max_move_times = D(max, min) - 2 

    */

    int max_move_times = max - min - 2;
    /*
    最少的移动次数，只有三种可能，一种是不用移动，一种是移动一次，最多的情况是移动两次 ;
    */
    int min_move_times = 0;
    if ((max - min) == 2)
        min_move_times = 0;
    else if ((mid - min) == 1 || (max - mid) == 1 || (mid - min) == 2 || (max - mid) == 2)
        min_move_times = 1;
    else
        min_move_times = 2;
    
    vector<int> res;
    res.emplace_back(min_move_times);
    res.emplace_back(max_move_times);

    return res;
}

int main(void)
{
    const auto & res = numMovesStones(1, 5, 4); 
    for (int e : res)
        std::cout<<e<<std::endl;

}