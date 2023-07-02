// AOCDay2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <fstream>
#include <map>
#include <vector>
#include <algorithm>
#include <sstream>


// Strategy guide 
// R P S
// A B C Elf  
// X Y Z Player
// is the sum of your scores for each round. 
// 1 Point for X 2 Point for Y 3 point for Scissors
// Outcome of the Round 0 if you lost, 3, if the round was a draw, 6 if you won.

// AX = 1 + 3 AY = 2+ 6 AZ = 3 + 0
// BX = 1 + 0 BY = 2 + 3 BZ = 3 + 6
// CX = 1 + 6 CY = 2 + 0 CZ = 3 + 3;

// X means you need to lose, Y means draw, Z means win
// AX = 3 + 0 AY = 1 + 3 AZ = 2 + 6
// BX = 1 + 0 BY = 2 + 3 BZ = 3 + 6
// CX = 2 + 0 CY = 3 + 3 CZ  = 1 + 6






void Day2SolutionPart1() {
    std::map<std::string, int> outcome = { { "AX", 4 }, {"AY", 8}, {"AZ", 3},
        {"BX", 1}, {"BY", 5}, {"BZ", 9}, {"CX", 7}, {"CY", 2}, {"CZ", 6}
    };
    std::ifstream AocInput;
    AocInput.open("C:\\Users\\j_cha\\Downloads\\AOCDay2.txt");
    if (AocInput.fail()) {
        std::cout << "Failed to open file";
        std::exit(-1);
    }
    std::vector<std::pair<char, char>> strategy;
    char a;
    char b;
    std::string line;
    while (AocInput.peek() != EOF) {
        AocInput >> a >> b;
        std::cout << a << b <<"\n";
        strategy.emplace_back(a, b);
    }

    strategy.pop_back();
    int sum = 0;

    for (int i = 0; i != strategy.size(); i++) {
        std::string key = "";
        key += strategy[i].first;
        key += strategy[i].second;
        sum += outcome[key];
    }

    std::cout << sum;
    AocInput.close();

}
// X means you need to lose, Y means draw, Z means win
// AX = 3 + 0 AY = 1 + 3 AZ = 2 + 6
// BX = 1 + 0 BY = 2 + 3 BZ = 3 + 6
// CX = 2 + 0 CY = 3 + 3 CZ  = 1 + 6

void Day2SolutionPart2() {
    std::map<std::string, int> outcome{
        {"AX", 3}, {"AY", 4 } , {"AZ",8 },
        {"BX", 1}, {"BY", 5} , {"BZ", 9},
        {"CX", 2}, {"CY", 6}, {"CZ", 7}
    };
    std::ifstream AocInput;
    AocInput.open("C:\\Users\\j_cha\\Downloads\\AOCDay2.txt");
    if (AocInput.fail()) {
        std::cout << "Failed to open file";
        std::exit(-1);
    }
    std::vector<std::pair<char, char>> strategy;
    char a;
    char b;
    std::string line;
    while (AocInput.peek() != EOF) {
        AocInput >> a >> b;
        std::cout << a << b << "\n";
        strategy.emplace_back(a, b);
    }

    strategy.pop_back();
    int sum = 0;

    for (int i = 0; i != strategy.size(); i++) {
        std::string key = "";
        key += strategy[i].first;
        key += strategy[i].second;
        sum += outcome[key];
    }

    std::cout << sum;
    AocInput.close();

}


int main()
{
    Day2SolutionPart1();
    Day2SolutionPart2();
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
