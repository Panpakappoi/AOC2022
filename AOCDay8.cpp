// 3 0 3 7 3
// 2 5 5 1 2
// 6 5 3 3 2
// 3 3 5 4 9
// 3 5 3 9 0


// Its kind of like a Matrix Graph problem right. You kind of are using DFS because you check in 4
// directions. Except instead of having some sort of open path, its about comparing values in 4 direc
// line. 
// The tricky part I suppose is trying to determine for all 4 coordinates to what is visible?
// All the perimeter are visible, and that can be reduced down to SIZE_OF_ARRAY * 2 + 2(SIZE OF ARRAY -2)
// Have to subtract 4 because of the overlaps. 

// so then you have to index from y = 1, and row 1 because everything in row 0 is alreadywithin the
// set of trees that are visible. but you still utilize the outsides trees to calculate the visible. 

// upper left 5 is visible from top and left but not down and bottom. + 1
// top middle 5 is visible from right and top. Top right 1 is not visible from any direction
// left middle 5 is visible but only from right. 
// 


#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <array>
#include <set>




const size_t SIZE_OF_ARRAY{ 5 };
const size_t SIZE_OF_SEARCH{ 4 };

std::vector<std::vector<size_t>> processInput() {
    std::vector<std::vector<size_t>> grid;

    std::ifstream aocInput;
    aocInput.open("input.txt.txt");
    if (aocInput.fail())
    {
        std::cout << "Could not open file";
        std::exit(-1);
    }
    std::string line;
    for (size_t i = 0; i < SIZE_OF_ARRAY; i++) {
        std::getline(aocInput, line);
        for (auto i : line)
        {
            if (i < '0' || i > '9')
                throw std::runtime_error("Parsing went horribly wrong");
            grid.emplace_back(i);
        }
    }
    return grid;
}


void calculate_visibility(std::vector<std::vector<size_t>>& grid)
{
    size_t visible = 2 * SIZE_OF_ARRAY + 2 * (SIZE_OF_ARRAY - 2);


    static constexpr auto new_max =
        [](size_t& max, size_t& current) { if (current > max)max = current; };


    for (size_t i = 1; i < SIZE_OF_ARRAY - 1; i++) {
        for (size_t j = 1; j < SIZE_OF_ARRAY - 1; j++) {
            size_t top_Row = grid[0][j];
            for (auto x = 0; x < i; x++)
                new_max(top_Row, grid[x][j]);
            if (top_Row < grid[i][j])
            {
                ++visible;
            }
        }
    }
}
int main()
{
    auto grid = processInput();
    calculate_visibility(grid);
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
