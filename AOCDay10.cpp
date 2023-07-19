#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>
#include <regex>

int const CRT_END_LINE = 40;

void process_input() {
    std::ifstream aocInput;
    aocInput.open("AOCDay10.txt");
    if (aocInput.fail())
    {
        std::cout << "Error opening file";
        std::exit(-1);
    }
    int strength_sum = 0;
    int signal = 1;

    int pixel = 0;
    std::string image;
  

    int cycle = 1;
    for (std::string line; std::getline(aocInput, line);)
    {
        std::string instruction = line.substr(0, 4);
        for (int i = 0; i <= (instruction == "addx") ? 1 : 0; i++)
        {
            if (cycle == 20 || cycle == 60 || cycle == 100 ||
                cycle == 140 || cycle == 180 || cycle == 220 || cycle == 260)
            {
                strength_sum += signal * cycle;
                std::cout << signal << " " << cycle << '\n';
                std::cout << "Total signal = " << strength_sum << '\n';

            }
            if (std::abs(pixel - signal) <= 1)
                image += "#";
            else
                image += '.';
            
            ++pixel;
            if (pixel == CRT_END_LINE) {
                image += "\n";
                pixel = 0;
            }
            ++cycle;
        }
        if (instruction == "addx")
        {
            signal += std::stod(line.substr(5));
        }
    }
    std::cout << "Part 1 " << strength_sum << '\n';
    std::cout << image;
}
int main()
{
    process_input();
    
}

