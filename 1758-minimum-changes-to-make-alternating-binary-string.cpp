#include <string>
#include <algorithm>
#include <iostream>

class Solution
{
public:
    /// @brief You are given a string s consisting only of the characters '0' and '1'.
    /// In one operation, you can change any '0' to '1' or vice versa.
    /// The string is called alternating if no two adjacent characters are equal.
    /// For example, the string "010" is alternating, while the string "0100" is not.
    /// Return the minimum number of operations needed to make s alternating.
    /// @param s consisting only of the characters '0' and '1'; 1 <= s.length <= 104
    /// @return minimum number of operations needed to make s alternating
    int minOperations(std::string s)
    {
        int zero_operations = 0, one_operations = 0;
        if (s.length() <= 1)
        {
            return 0;
        }

        for (int i = 0; i < s.length(); i++)
        {
            if (i % 2 == 0)
            {
                if (s[i] == '0')
                {
                    zero_operations++;
                }
                else
                {
                    one_operations++;
                }
            }
            else
            {
                if (s[i] == '1')
                {
                    zero_operations++;
                }
                else
                {
                    one_operations++;
                }
            }
        }

        return std::min(zero_operations, one_operations);
    }
};

int main()
{
    Solution s;
    std::cout << s.minOperations("0100") << " expected: 1" << std::endl;
    std::cout << s.minOperations("10") << " expected: 0" << std::endl;
    std::cout << s.minOperations("1111") << " expected: 2" << std::endl;
    std::cout << s.minOperations("0100") << " expected: 1" << std::endl;
    std::cout << s.minOperations("11") << " expected: 1" << std::endl;
}