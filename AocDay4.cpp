// AocDay4.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <fstream>
#include <string>
#include <vector>


struct Elf {
    int lower_bound;
    int upper_bound;
};


std::vector<std::pair<Elf, Elf>> elfAssignment;


int Count_Complete_Overlap(std::vector<std::pair<Elf, Elf>>& Elves)
{
    int total_Subsume = 0;
    for (int i = 0; i < Elves.size(); i++)
    {
        if (Elves[i].second.lower_bound >= Elves[i].first.lower_bound &&
            Elves[i].second.upper_bound <= Elves[i].first.upper_bound || 
            Elves[i].first.lower_bound >= Elves[i].second.lower_bound &&
            Elves[i].first.upper_bound <= Elves[i].second.upper_bound)
            total_Subsume += 1;
    }
    return total_Subsume;
}


void Day4SolutionPart1() {
    std::ifstream aocInput;
    aocInput.open("C:\\Users\\j_cha\\Downloads\\AOCDay4.txt");
    if (aocInput.fail())
    {
        std::cout << "Failed to open file \n";
        std::exit(-1);
    }
    std::string line;
    while (aocInput >> line) {
        size_t pos = line.find(',');
        std::string token1 = line.substr(0, pos);
        std::string token2 = line.substr(pos + 1);
        size_t pos_a = token1.find('-');
        size_t pos_b = token2.find('-');
        int lower_a = std::stoi(token1.substr(0, pos_a));
        int higher_a = std::stoi(token1.substr(pos_a +1));
        int lower_b = std::stoi(token2.substr(0, pos_b));
        int higher_b = std::stoi(token2.substr(pos_b + 1));
        Elf lhs;
        Elf rhs;
        lhs.lower_bound = lower_a;
        lhs.upper_bound = higher_a;
        rhs.lower_bound = lower_b;
        rhs.upper_bound = higher_b;
        elfAssignment.emplace_back(lhs, rhs);
     }
    std::cout << Count_Complete_Overlap(elfAssignment) << '\n';
}



int main()
{
    Day4SolutionPart1();
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
