// AOCDay1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>


int main()
{   

    std::ifstream ifa;
    ifa.open("C:\\Users\\j_cha\\Downloads\\data.text");
    if (!ifa.is_open())
        std::cout << "Failed to open the file." << std::endl;
    std::string line;
    std::vector<std::vector<int>> groups;
    std::vector<int> currentGroup;
    while(std::getline(ifa, line)) {
        if (line.empty()) {
            if (!currentGroup.empty()) {
                groups.push_back(currentGroup);
                currentGroup.clear();
            }
        }
        else {
            int number = std::stoi(line);
            currentGroup.push_back(number);
        }
    }

    ifa.close();
    std::vector<int> collapsedGroups;
    for (const auto& group : groups) {
        int sum = 0;
        for (int number : group) {
            sum += number;
        }
        collapsedGroups.push_back(sum);
    }
    
    std::sort(collapsedGroups.begin(), collapsedGroups.end());
    std::cout << collapsedGroups.back();

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
