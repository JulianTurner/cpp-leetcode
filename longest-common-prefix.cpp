#include <iostream>
#include <string>
#include <vector>

class Solution
{
public:
    /// @brief finds the longest common prefix string amongst an array of strings
    /// @param strs array of strings; 1 <= strs.length <= 200; 0 <= strs[i].length <= 200 strs[i]
    /// @return longest common prefix string
    std::string longestCommonPrefix(std::vector<std::string> &strs)
    {
        if (strs.size() == 1)
        {
            return strs[0];
        }

        std::string result = "";
        for (int i = 0; i < strs[0].length(); i++)
        {
            for (int j = 1; j < strs.size(); j++)
            {
                if (strs[j][i] != strs[0][i])
                {
                    return result;
                }
            }
            result += strs[0][i];
        }

        return result;
    }
};

int main()
{
    Solution s;
    std::vector<std::string> strs = {"flower", "flow", "flight"};
    std::cout << s.longestCommonPrefix(strs) << std::endl;
    std::vector<std::string> strs2 = {"dog", "racecar", "car"};
    std::cout << s.longestCommonPrefix(strs2) << std::endl;
}