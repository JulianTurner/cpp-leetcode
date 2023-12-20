#include <iostream>
#include <string>
#include <map>

class Solution
{
public:
    /// @brief converts a roman numeral to an integer
    /// @param s roman numeral string containing only the characters I, V, X, L, C, D and M and in the range [1, 3999]
    /// @return converted integer
    int romanToInt(std::string s)
    {
        std::map<char, int> romanMap = {
            {'I', 1}, {'V', 5}, {'X', 10}, {'L', 50}, {'C', 100}, {'D', 500}, {'M', 1000}};

        int result = 0;
        for (int i = s.length() - 1; i >= 0; i--)
        {
            if (i == s.length() - 1)
            {
                result += romanMap[s[i]];
            }
            else
            {
                if (romanMap[s[i]] < romanMap[s[i + 1]])
                {
                    result -= romanMap[s[i]];
                }
                else
                {
                    result += romanMap[s[i]];
                }
            }
        }

        return result;
    }
};

int main()
{
    Solution s;
    std::cout << s.romanToInt("III") << std::endl;
    std::cout << s.romanToInt("IV") << std::endl;
    std::cout << s.romanToInt("IX") << std::endl;
    std::cout << s.romanToInt("LVIII") << std::endl;
    std::cout << s.romanToInt("MCMXCIV") << std::endl;
    return 0;
}