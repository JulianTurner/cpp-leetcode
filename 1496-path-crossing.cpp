#include <iostream>
#include <tuple>
#include <set>

class Solution
{
public:
    /// @brief Given a string path, where path[i] = 'N', 'S', 'E' or 'W', each representing moving one unit north, south, east, or west, respectively. You start at the origin (0, 0) on a 2D plane and walk on the path specified by path. Return true if the path crosses itself at any point, that is, if at any time you are on a location you have previously visited.Return false otherwise.
    /// @param path  a string path, where path[i] = 'N', 'S', 'E' or 'W', each representing moving one unit north, south, east, or west, respectively
    /// @return Return true if the path crosses itself at any point, that is, if at any time you are on a location you have previously visited. Return false otherwise.
    bool isPathCrossing(std::string path)
    {
        std::tuple<int, int> current_position = {0, 0};
        std::set<std::tuple<int, int>> visited_positions;
        visited_positions.insert(current_position);

        for (int i = 0; i < path.length(); i++)
        {
            switch (path[i])
            {
            case 'N':
                std::get<1>(current_position) += 1;
                break;
            case 'S':
                std::get<1>(current_position) -= 1;
                break;
            case 'E':
                std::get<0>(current_position) += 1;
                break;
            case 'W':
                std::get<0>(current_position) -= 1;
                break;
            default:
                break;
            }
            if (visited_positions.find(current_position) == visited_positions.end())
            {
                visited_positions.insert(current_position);
            }
            else
            {
                return true;
            }
        }

        return false;
    }
};

int main()
{
    Solution s;
    std::cout << s.isPathCrossing("NES") << " expected: false" << std::endl;
    //  std::cout << s.isPathCrossing("NESWW") << " expected: true" << std::endl;
}