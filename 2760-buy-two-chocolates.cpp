#include <string>
#include <iostream>
#include <vector>

class Solution
{
public:
    /// @brief exactly two chocolates in such a way that you still have some non-negative leftover money.
    /// @param prices prices of various chocolates in a store; 2 <= prices.length <= 50; 1 <= prices[i] <= 100;
    /// @param money initial amount of money; 1 <= money <= 100
    /// @return the amount of money you will have leftover after buying the two chocolates
    int buyChoco(std::vector<int> &prices, int money)
    {
        int smallest = 101, secondSmallest = 101;
        for (int i = 0; i < prices.size(); i++)
        {
            int current = prices[i];
            if (current < smallest)
            {
                secondSmallest = smallest;
                smallest = current;
            }
            else if (current < secondSmallest)
            {
                secondSmallest = current;
            }
        }
        int total = smallest + secondSmallest;
        if (total <= money) // can buy
        {
            return money - total;
        }
        return money;
    }
};

int main()
{
    Solution s;
    std::vector<int> ex1 = {
        1,
        2,
        2,
    };
    std::cout << s.buyChoco(ex1, 3) << " expected: 0" << std::endl;
    std::vector<int> ex2 = {3, 2, 3};
    std::cout << s.buyChoco(ex2, 3) << " expected: 3" << std::endl;
    std::vector<int> ex3 = {98, 54, 6, 34, 66, 63, 52, 39};
    std::cout << s.buyChoco(ex3, 62) << " expected: 22" << std::endl;
    std::vector<int> ex4 = {69, 91, 78, 19, 40, 13};
    std::cout << s.buyChoco(ex4, 94) << " expected: 62" << std::endl;
}