#include <iostream>
#include <fstream>
#include <regex>
#include <string>
#include <vector>
#include <set>
#include <unordered_set>

struct rope {
    int first = 0;
    int second = 0;
};

std::vector<std::string> processInput(){
    std::ifstream aocInput;
    aocInput.open("AOCDay9.txt");
    if (aocInput.fail())
    {
        std::cout << "Failed to open file\n";
        std::exit(-1);
    }
    std::vector<std::string> directions;
    std::string line;
    while(std::getline(aocInput, line))
    {
        directions.emplace_back(line);
    }
    return directions;
}


void handle_truth(rope& head, rope& tail)
{
    if (std::abs(head.first - tail.first) >= 2) {
        tail.first += (head.first - tail.first) / 2;
        if (std::abs(head.second - tail.second) >= 2)
            tail.second += (head.second - tail.second) / 2;
        else
            tail.second += head.second - tail.second;
    }
    else if (std::abs(head.second - tail.second) >= 2) {
        tail.second += (head.second - tail.second) / 2;
        tail.first += head.first - tail.first;
    }

}

std::set<std::pair<int, int>> process_directions(std::vector<std::string>& directions)
{
    rope head{ 0,0 };
    rope tail{ 0,0 };
    std::set<std::pair<int, int>> visit;
    visit.emplace(std::make_pair(tail.first, tail.second));
    auto dir_pattern = std::regex{ R"((\w)\s(\d+))" };
    auto match = std::smatch{};
    for (int i = 0; i < directions.size(); i++)
    {
        if (std::regex_search(directions[i], match, dir_pattern))
        {
            if (match[1] == 'R')
            {
                for (int i = 0; i < std::stoi(match[2]); i++)
                {
                    head.second++;
                    handle_truth( head, tail);
                    visit.emplace(std::make_pair(tail.first, tail.second));
                }
            }

            else if (match[1] == 'L')
            {
                for (int i = 0; i < std::stoi(match[2]); i++)
                {
                    head.second--;
                    handle_truth(head, tail);
                    visit.emplace(std::make_pair(tail.first, tail.second));
                }
            }
            else if (match[1] == 'U')
            {
                for (int i = 0; i < std::stoi(match[2]); i++)
                {
                    head.first--;
                    handle_truth(head, tail);
                    visit.emplace(std::make_pair(tail.first, tail.second));
                }

            }
            else if (match[1] == 'D')
            {
                for (int i = 0; i < std::stoi(match[2]); i++)
                {
                    head.first++;
                    handle_truth(head, tail);
                    visit.emplace(std::make_pair(tail.first, tail.second));
                }
            }
        }
    }
    return visit;
}



int main()
{
    std::vector<std::string> directions = processInput();
    std::set<std::pair<int, int>> tail_visited = process_directions(directions);
    std::cout << tail_visited.size();
}