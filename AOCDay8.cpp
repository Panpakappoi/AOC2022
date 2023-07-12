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
#include <utility>

using tree_row = std::vector<int>;
using tree_grid = std::vector<tree_row>;

std::vector<std::vector<int>> process_test_input() {
	std::ifstream aocInput("input.txt.txt");
	if (aocInput.fail())
	{
		std::cout << "Failed to open file\n";
		std::exit(-1);
	}
	tree_grid grid;
	std::string line;
	std::vector<int> testInput;
	while(std::getline(aocInput, line)){
		tree_row current;
		for (auto c : line)
		{
			current.emplace_back(c - '0');
		}
		grid.emplace_back(current);
	}
	return grid;
}

void tree_visibility(std::vector<std::vector<int>>& grid)
{
	auto x_max = grid.size();
	auto y_max = grid[0].size();
	auto visibility = 2 * x_max + 2 * (y_max - 2);

	static constexpr auto update_max = 
		[](size_t& max, int& current){if (current > max) max = current; };
	for (size_t x = 1; x < x_max - 1; x++) 
	{ // start from 1 because we iterate over inner trees
		for (size_t y = 1; y < y_max - 1; y++)
		{ // same deal here
			size_t m_left = grid[0][y]; // initialize to 0 and whatever y
			for (auto i = 1; i < x; ++i)
				update_max(m_left, grid[i][y]);
			if (m_left < grid[x][y]) { 
				++visibility;
				continue;
			}

			size_t m_right = grid[x+1][y];
			for (auto j = x+1; j < x_max; ++j)
				update_max(m_right, grid[j][y]);
			if (m_right < grid[x][y]) {
				++visibility;
				continue;
			}

			size_t m_above = grid[x][0];
			for (auto z = 1; z < y; ++z)
				update_max(m_above, grid[x][z]);
			if (m_above < grid[x][y]) {
				++visibility;
				continue;
			}
			size_t m_below = grid[x][y+1];
			for (auto k = y+1; k < y_max; ++k)
				update_max(m_below, grid[x][k]);
			if (m_below < grid[x][y]) {
				++visibility;
				continue;
			}
		}
	}
	std::cout << visibility << '\n';
}

std::vector<std::vector<int>> process_Input() {
	std::ifstream aocInput("AOCDay8.txt");
	if (aocInput.fail())
	{
		std::cout << "Failed to open file.\n";
		std::exit(-1);
	}
	tree_grid grid;
	std::string line;
	while (std::getline(aocInput, line))
	{
		tree_row current;
		for (auto c : line)
		{
			current.emplace_back(c - '0');
		}
		grid.emplace_back(current);
	}
	return grid;
}



int main() {
	auto test = process_test_input();
	tree_visibility(test);
	auto aocInput = process_Input();
	tree_visibility(aocInput);

}