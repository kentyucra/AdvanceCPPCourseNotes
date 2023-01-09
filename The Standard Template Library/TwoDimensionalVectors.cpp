#include <iostream>
#include <vector>

int main()
{
    std::vector<std::vector<int>> grid(3, std::vector<int>(4, 7));

    grid[1].push_back(8);

    for (size_t row = 0; row < grid.size(); row++)
    {
        for (size_t col = 0; col < grid[row].size(); col++)
        {
            std::cout << grid[row][col] << " ";
        }
        std::cout << std::endl;
    }
}