// AOCDay3Self.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <map>
#include <string>
#include <fstream>
#include <vector>
int step2(std::map<char, int>& priority, std::ifstream& input) 
{   
    int score = 0;
    std::vector<std::string> StoringLines;
    std::string line;
    while (std::getline(input, line))
    {   
        char commonChar;
        StoringLines.emplace_back(line);
        if (StoringLines.size() == 3) {
            std::string& firstLine = StoringLines[0];
            std::string& secondLine = StoringLines[1];
            std::string& thirdLine= StoringLines[2];

            for (char c : firstLine) {
                if (secondLine.find(c) != std::string::npos && thirdLine.find(c) != std::string::npos)
                {
                    commonChar = c;
                }
            }
            score += priority[commonChar];
            StoringLines.clear();
        }
    }
    
    return score;
}

int main()
{   
    int score = 0;
    std::map<char, int> priorityValue{ {'a', 1}, {'b', 2}, {'c',3}, {'d',4}, {'e', 5}, {'f', 6},
    {'g',7}, {'h', 8}, {'i', 9}, {'j', 10}, {'k', 11}, {'l', 12}, {'m', 13} , {'n', 14}, {'o', 15},
    {'p', 16}, {'q',17}, {'r', 18}, {'s', 19}, {'t', 20}, {'u', 21}, {'v', 22}, {'w', 23}, {'x', 24},
    {'y',25}, {'z', 26}, {'A', 27}, {'B', 28}, {'C',29}, {'D',30}, {'E', 31}, {'F', 32},
    {'G', 33}, {'H', 34}, {'I', 35}, {'J', 36}, {'K', 37}, {'L', 38}, {'M', 39} , {'N', 40}, {'O', 41},
    {'P', 42}, {'Q',43}, {'R', 44}, {'S', 45}, {'T', 46}, {'U', 47}, {'V', 48}, {'W', 49}, {'X', 50},
    {'Y', 51}, {'Z', 52} };

    std::ifstream aocInput;
    aocInput.open("C:\\Users\\j_cha\\Downloads\\AOC3.txt");
    if (aocInput.fail())
    {
        std::cout << "Your thing failed.";
        exit(0);
    }
    /*
    std::string line;
    
    while (std::getline(aocInput, line))
    {
        char token;
        std::string firstHalf = line.substr(0, line.length() / 2);
        std::string secondHalf = line.substr(line.length() / 2, line.length() / 2);
        for (int i = 0; i < firstHalf.length(); i++)
        {
            for (int j = 0; j < secondHalf.length(); j++) {
                if (firstHalf[i] == secondHalf[j]) 
                {
                    token = firstHalf[i];
                    std::cout << token << '\n';
                }
            }
        }
        score += priorityValue[token];
    }


    std::cout << score << "\n";
    return 0;*/
    std::cout << step2(priorityValue, aocInput);
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
