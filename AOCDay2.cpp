// This is a personal academic project. Dear PVS-Studio, please check it.

// PVS-Studio Static Code Analyzer for C, C++, C#, and Java: https://pvs-studio.com
#include <fstream>
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <map>


char itoc(int i) {
    return static_cast<int>(i + '0');
}

int ctoi(char c) {
    return static_cast<char>(c - '0');
}

int main()
{
    std::ifstream strategy("C:\\Users\\j_cha\\Downloads\\AOC2.txt");
    if (strategy.fail())
    {
        std::cout << "Failed to open file.\n";
        exit(1);
    }

    // R P S
    // A B C 
    // X Y Z
    // 1 2 3
    // shape + outcome
    // AX BY CZ 3
    // BX CY AZ 0
    // BZ AY CX 6

    // AX BX CX = AZ(rs) BX(pr) CY(sp) 0
    // AY BY CY = AX(rr) BY(pp) CZ (ss)3 
    // AZ BZ CZ = AY(rp) BZ(ps) CX (sr)6
    // So you have to be able to modulate the values we can calculate one score
    // easily, however we need to be able to 



    int score = 0;
    char a, b, c;
    std::string line;
    while (std::getline(strategy, line)) {
        a = char(line[0]);
        c = char(line[2]);
        std::string outcome = std::string(1, a) + std::string(1, c);
        std::cout << outcome << '\n';
        /*if (outcome == "AX" || outcome == "BY" || outcome == "CZ")
            score += 3;
        else if (outcome == "AY" || outcome == "BZ" || outcome == "CX")
            score += 6;
        else if (outcome == "BX" || outcome == "CY" || outcome == "AZ")
            score += 0;
        if (c == 'X')
            score += 1;
        else if (c == 'Y')
            score += 2;
        else if (c == 'Z')
            score += 3;*/
        if (outcome == "AX")
            score += 3;
        else if (outcome == "CX")
            score += 2;
        else if (outcome == "BX")
            score += 1;
        else if (outcome == "AY")
            score += 4;
        else if (outcome == "BY")
            score += 5;
        else if (outcome == "CY")
            score += 6;
        else if (outcome == "AZ")
            score += 8;
        else if (outcome == "BZ")
            score += 9;
        else if (outcome == "CZ")
            score += 7;
    }
    
    std::cout << score;
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
