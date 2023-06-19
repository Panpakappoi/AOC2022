// AOCDAY4.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <fstream>
#include <utility>
#include <algorithm>
#include <vector>
#include <string>
#include <ranges>
#include <sstream>
//Want to go and extract the two numbers for each member in pair. 
// sep will be - and , 
// you will set the left value as min and right value as max
// you will store in pair then check if the A.min <= B.min and A.max >= B.max or
// something like that.


struct Elf {
    int32_t min;
    int32_t max;

    bool subSumes(const Elf& other) const {
        return min <= other.min && max >= other.max ||
            other.min <= min && other.max >= max ||
            min <= other.max && max >= other.min ||
            other.min <= max && other.max >= min;
    }
 
};

int countOverlaps(const std::vector<std::pair<Elf, Elf>>& vectpair)
{
    int overlaps = 0;
    for (auto c : vectpair) {
        if (c.first.subSumes(c.second))
            overlaps += 1;
    }
    return overlaps;
}

int main()
{   
    std::vector<Elf> ElfVector;
    std::vector<std::pair<Elf, Elf>> Interval;
    std::ifstream aocInput("Z:\\DL\\AOC4.txt");
    if (aocInput.fail())
    {
        std::cerr << "Failed to open file. \n";
        exit(0);
    }
    std::string line;
    while (std::getline(aocInput, line))
    {   
        std::stringstream ss(line);
        std::string token;
        std::string x;
        std::string y;
        size_t pos = 0;
        while (std::getline(ss, token, ',')) 
        {
            if((pos = token.find('-')) != std::string::npos) {
                x = token.substr(0, pos);
                y = token.substr(pos + 1);
                //std::cout << x << std::endl;
                //std::cout << y << std::endl;
                Elf z{ std::stoi(x),std::stoi(y)};
                ElfVector.emplace_back(z);
            }
            
        }
    }
    //for (auto iter: ElfVector) {
    //    std::cout << iter.min  << " " << iter.max << std::endl;
    //}

    for (size_t i = 0; i < ElfVector.size(); i += 2)
    {
        Interval.emplace_back(ElfVector[i], ElfVector[i + 1]);
    }
    int p = 0;
    for (const auto& interval : Interval)
    {   
        std::cout << "Pair: " << p << "(" << interval.first.min << " " 
            << interval.first.max << "), (" << interval.second.min << " " 
            << interval.second.max << ")" << std::endl;
        p++;
    }
    std::cout << countOverlaps(Interval);
    aocInput.close();
    return 0;
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
