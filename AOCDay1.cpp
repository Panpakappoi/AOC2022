// AOCDay1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <algorithm>


void Day1_Solution_Part1() {
	std::ifstream aocInput;
	aocInput.open("C:\\Users\\j_cha\\Downloads\\AOCDay1.txt");
	if (aocInput.fail())
	{
		std::cout << "Could not open file.\n";
		exit(-1);
	}
	std::string line;

	std::vector<int> summation;
	std::vector<int> elf;
	std::vector<int> grouped_elves;
	int sum = 0;
	while (std::getline(aocInput, line)) {
		if (line.empty()) {
			int sum = 0;
			for (auto i = elf.begin(); i < elf.end(); i++)
				sum += *i;

			summation.emplace_back(sum);
			elf.clear();
		}
		if (!line.empty()) {
			elf.push_back(std::stoi(line));
		}
	}
	std::sort(summation.begin(), summation.end());

	for (auto i = summation.begin(); i != summation.end(); i++)
		std::cout << *i << '\n';
}

void Day1_Solution_Part2() {
	std::ifstream aocInput;
	aocInput.open("C:\\Users\\j_cha\\Downloads\\AOCDay1.txt");
	if (aocInput.fail())
	{
		std::cout << "Could not open file.\n";
		exit(-1);
	}
	std::string line;

	std::vector<int> summation;
	std::vector<int> elf;
	std::vector<int> grouped_elves;
	int sum = 0;
	while (std::getline(aocInput, line)) {
		if (line.empty()) {
			int sum = 0;
			for (auto i = elf.begin(); i < elf.end(); i++)
				sum += *i;

			summation.emplace_back(sum);
			elf.clear();
		}
		if (!line.empty()) {
			elf.push_back(std::stoi(line));
		}
	}
	std::sort(summation.begin(), summation.end());

	//for (auto i = summation.begin(); i != summation.end(); i++)
	//	std::cout << *i << '\n';
	sum = 0;
	for (auto i = summation.end() -1; i != summation.end() - 4; i--)
		sum += *i;
	std::cout << sum;
}


int main()
{
	Day1_Solution_Part1();
	Day1_Solution_Part2();
	
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
