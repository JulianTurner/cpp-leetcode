#include <string>
#include <algorithm>
#include <iostream>

class Solution
{
public:
    /// @brief Given a string s of zeros and ones, return the maximum score after splitting the string into two non-empty substrings
    /// @param s The string s consists of characters '0' and '1' only; 2 <= s.length <= 500
    /// @return maximum score; left substring plus the number of ones in the right substring
    int
    maxScore(std::string s)
    {
        int maxScore = 0;
        for (int i = 1; i <= s.length() - 1; i++)
        {

            std::string left = s.substr(0, i);
            left.erase(std::remove(left.begin(), left.end(), '1'), left.end());
            std::string right = s.substr(i, s.length());
            right.erase(std::remove(right.begin(), right.end(), '0'), right.end());

            int currentScore = left.length() + right.length();
            if (currentScore > maxScore)
            {
                maxScore = currentScore;
            }
        }
        return maxScore;
    }
};

int main()
{
    Solution s;
    std::cout << s.maxScore("011101") << " expected: 5" << std::endl;
    std::cout << s.maxScore("00111") << " expected: 5" << std::endl;
    std::cout << s.maxScore("1111") << " expected: 3" << std::endl;
    std::cout << s.maxScore("00") << " expected: 1" << std::endl;
}
