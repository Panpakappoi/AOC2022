
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <stack>
#include <ranges>
//    [G] [R]                 [P]    
//    [H] [W]     [T] [P]     [H]    
//    [F] [T] [P] [B] [D]     [N]    
//[L] [T] [M] [Q] [L] [C]     [Z]    
//[C] [C] [N] [V] [S] [H]     [V] [G]
//[G] [L] [F] [D] [M] [V] [T] [J] [H]
//[M] [D] [J] [F] [F] [N] [C] [S] [F]
//[Q] [R] [V] [J] [N] [R] [H] [G] [Z]
// 1   2   3   4   5   6   7   8   9 

struct Extractor {
    uint32_t amount;
    size_t source;
    size_t destination;
};

//Matrix transpose, you want to take it and flip it.
// read from bottom up and put in stacks.
// Calculate the character position.
// String of each line and calculate the character position of each stack

void CrateMover9000(std::vector<Extractor>& instructions, std::vector<std::vector<char>>& state)
{
        for (int i = 0; i < instructions.size(); i++)
        {
            int amount = instructions[i].amount;
            int s = instructions[i].source;
            int d = instructions[i].destination;

            for (int j = 0; j < amount; j++)
            {
                state[d].insert(state[d].begin(), state[s][0]);
                state[s].erase(state[s].begin() + 0);
            }
    }
}

void CrateMover9001(std::vector<Extractor>& instructions, 
    std::vector<std::vector<char>>& state)
{
    for (int i = 0; i < instructions.size(); i++)
    {
        int amount = instructions[i].amount;
        int s = instructions[i].source;
        int d = instructions[i].destination;
        for (int j = amount - 1; j >= 0; j--)
        {
            state[d].insert(state[d].begin(), state[s][j]);
            state[s].erase(state[s].begin() + j);
        }
    }

}


std::vector<Extractor> parseInstructions(std::ifstream& inFile) {
    std::vector<Extractor> instructions;
    std::string word;
    Extractor target;
    while (inFile >> word >> target.amount >>
        word >> target.source >> word >> target.destination) {
        --target.source; //zero base
        --target.destination; // zero base
        std::cout << target.amount << " " << target.source << " " << target.destination << "\n";
        instructions.emplace_back(target);
    }

    return instructions;
}


std::vector < std::vector<char >> Parse_Initial_Crates(std::ifstream& inFile) {
    std::vector<std::vector<char>> result;
    std::string line;
    bool done = false;
    while (std::getline(inFile, line) && !done)
    {
        for (size_t i = 0; i < line.length(); i++)
        {
            if (std::isdigit(line[i]))
            {
                done = true;
                break;
            }
            if (!std::isupper(line[i]))
                continue;
            size_t stack = (i - 1) / 4;
            if (result.size() <= stack)
                result.resize(stack + 1);
            result[stack].push_back(line[i]);
        }
    }
    return result;
}

void Extract_Relevant_Instruction() {
    std::ifstream aocInput;
    aocInput.open("AOCDay5.txt");
    if (aocInput.fail())
    {
        std::cout << "Failed to open file\n";
        std::exit(-1);
    }
    
    std::vector<std::vector<char>> result = Parse_Initial_Crates(aocInput);
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < result[i].size(); j++)
        {
            std::cout << result[i][j] << " ";
        }
       std::cout << std::endl;
    }
    std::vector<Extractor> instruction_set = parseInstructions(aocInput);
    CrateMover9001(instruction_set, result);
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < result[i].size(); j++)
        {
            std::cout << result[i][j] << " ";
        }
        std::cout << std::endl;
    }
    aocInput.close();
}



int main()
{
    Extract_Relevant_Instruction();
    
}

