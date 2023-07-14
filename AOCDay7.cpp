// cd means change directory
// cd x moves in one level
// cd .. moves out one level
// cd / switches the current directory to the outermost directory
// ls means list, prints all files and directories immediately
// number means ssize, with the chars afterwards the specific file
// dir xyz, means that current directory contains a directory named xyz
// 
// Example
// $ cd /                             - / (dir)
// $ ls                                 - a (dir)
// dir a                                  - e (dir)
// 14848514 b.txt                           - i (file, size=584)
// 8504156 c. dat                         - f (file, size=29116)
// dir d                                  - g (file, size=2557)
// $ cd a                                 - h.lst (file, size=62596)
// $ ls                                 - b.txt (file, size=14848514)
// dir e                                - c.dat (file, size=8504156)
// 29116 f                              - d (dir)
// 2557 g                                 - j (file, size=4060174)
// 62596 h.lst                            - d.log (file, size=8033020)
// $cd e                                  - d.ext (file, size=5626152)
// $ls                                    - k (file, size=7214296)
// 584 i
// $ cd ..
// $ cd ..
// $ cd d
// ls
// 4060174 j 
// 8033020 d.log
// 5626152 d.ext
// 7214296 k

// determine the total size of all directories
// total size of a directory is a sum of the sizes of the files
// directly or indirectly
// find at most 100_000 calculate the suim of their total sizes

// We can use a 2d vector for the file path? 

// SO....We can use a stack to keep track of the file
// path?
// After you've done that, you can extract the elements of the filepath
// and then 

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <regex>

using namespace std::string_literals;
struct File {
	std::string name;
	size_t size = 0;
};

struct Directory {
	std::string name;
	Directory* parentPtr = nullptr;
	std::vector<Directory> child_Directories;
	std::vector<File> files;
	size_t size = 0;
};


void calculateDirectorySize(Directory& directory, size_t &size) {
	for (const auto& file : directory.files) {
		std::cout << file.size << ' ' << file.name << '\n';
		directory.size += file.size;
	}
	for (auto& subdir : directory.child_Directories) {
		calculateDirectorySize(subdir, size);
		directory.size += subdir.size;
	}
	if (directory.size <= 100000)
	{
		size += directory.size;
	}
	std::cout << size << '\n';
}
	

auto text{
R"(
$ cd /
$ ls
dir a
14848514 b.txt
8504156 c. dat 
dir d          
$ cd a         
$ ls           
dir e          
29116 f        
2557 g         
62596 h.lst    
$ cd e          
$ ls            
584 i
$ cd ..
$ cd ..
$ cd d
$ ls
4060174 j 
8033020 d.log
5626152 d.ext
7214296 k
)"s};

Directory process_Commands(const std::vector<std::string> & input) {
	auto change_directory = std::regex(R"(^.\scd\s(\w+))");
	auto parse_ls = std::regex(R"(^.\s(ls))") ;
	auto previous_directory = std::regex(R"(^.\scd\s\.\.)");
	auto file_parse = std::regex(R"((\d+)\s(\w+[\.\w+]?))");
	auto directory_create = std::regex(R"(dir\s+(\w+))");
	auto match = std::smatch{};
	
	Directory master;
	master.name = "\\";

	Directory* currentDirectory = &master;
	for (size_t i = 0; i < input.size(); i++)
	{
		if (std::regex_search(input[i], match, parse_ls)){
			std::cout << match[1] << '\n';
			int j = i+1;
			while (input[j][0] != '$')
			{	
				if (std::regex_search(input[j], match,file_parse))
				{	
					std::cout << "Create file " << match[2] << '\n';
					File currentFile;
					currentFile.name = match[2];
					currentFile.size = std::stoi(match[1]);
					currentDirectory->files.emplace_back(currentFile);
				}

				
				if (std::regex_search(input[j], match, directory_create))
				{	
					std::cout << "Create directory: " << match[1] << '\n';
					Directory newDirectory;
					newDirectory.name = match[1];
					newDirectory.parentPtr = currentDirectory;
					currentDirectory->child_Directories.emplace_back(newDirectory);
				}
				if (j == 1040)
					break;
				j++;
			}
		}
		if (std::regex_search(input[i], match, change_directory))
		{
			std::cout << "CD " << match[1] << '\n';
			std::string directoryName = match[1];
			for (auto& directory : currentDirectory->child_Directories)
				if (directory.name == directoryName)
				{
					currentDirectory = &directory;
				}
		}

		if (std::regex_search(input[i], match, previous_directory))
		{   
			std::cout << "cd .. " << '\n';
			currentDirectory = currentDirectory->parentPtr;
		}
	}
	return master;
}
std::vector<std::string> processInput() {
	std::ifstream aocInput;
	aocInput.open("AOCDay7.txt");
	if (aocInput.fail())
	{
		std::cout << "Failed to open file\n";
		std::exit(-1);
	}
	std::string line;
	std::vector<std::string> commandList;
	while (std::getline(aocInput, line))
	{
		commandList.emplace_back(line);
	}
	return commandList;
}

int main()
{
	auto commandList = processInput();
	auto master = process_Commands(commandList);
	size_t eligible_directory = 0;
	calculateDirectorySize(master, eligible_directory);

}

