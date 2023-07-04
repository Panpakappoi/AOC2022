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
#include <stack>
#include <set>

struct Node {
	Node* parentPtr;
	std::vector<Node> encompassing;
	int32_t size;
};

struct File {
	std::string name;
	int32_t size;
	Node* enclosingDirectory;
};

std::vector<std::string> commandList;


std::set<Node> directory;
void processInput() {
	std::ifstream aocInput;
	aocInput.open("AOCDay7.txt");
	if (aocInput.fail())
	{
		std::cout << "Failed to open file\n";
		std::exit(-1);
	}
	std::string line;
	std::string currentDirectory;
	while (std::getline(aocInput, line))
	{
		if (line[0] == '$' && line[2] == 'c' && line[5] != '.') {
			currentDirectory = line.substr(5);
			std::cout << currentDirectory << '\n';
		}

		if (line[0] == '$' && line[2] == 'l' && line[3] == 's')
		{

		}
	}
	for (int i = 0; i < commandList.size(); i++)
	{
		std::cout << commandList[i] << " " << i <<std::endl;
	}
}


int main()
{
	processInput();
}

