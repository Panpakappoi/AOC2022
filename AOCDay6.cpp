// AOCDay6.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <fstream>
#include <unordered_map>
#include <map>
#include <unordered_set>
#include <algorithm>
// Detect start of packet marker.
// Looking for a substr of 4 Characters that are all different
// You need to identify the first position where the four most 
// recently received char all different
// 
// 
// Needs to report the number of char from the beginning of the 
//buffer to the end of the first such four character marker.
//
//mjq jpqm gbljsphdztnvjfqwr
//
//First time a marker appears is after 7th character. on one ordering system
// answer in this case is 7
// 
// bvwbjplbgvbhsrlpgdmjqwftvncz 
// bvwb is not valid however vwbj is hence answer 5
// nppdvjthqldpwncqszvftbrmjlhg character 6
// nznrnfrfntjfmvfwmzdfjlvtqnbhcprsg character 10
// zcfzfwzzqfrljwzlrfnpqdbhtmscgvjw character 11

// Several ways to think about it.
// you can extract substrs begin index 0
// of 4 char, store them in sets, in look for the first occurance
// of a unique 4 char literal
// 

std::map<size_t, std::string> markercandidates;
//size_t start_of(const std::string& s, size_t offset = 4)
//{
//	std::unordered_map<char, size_t> cnt;
//	size_t i = 0;
//	for (; i < s.length(); i++) {
//		++cnt[s[i]];
//		if (i >= offset) {
//			--cnt[s[i - offset]];
//			if (cnt[s[i - offset]] == 0)
//				cnt.erase(s[i - offset]);
//		}
//		if (cnt.size() == offset) break;
//	}
//	return i + 1;
//}

bool hasUniqueCharacters(const std::string_view& str) {
	std::unordered_set<char> charSet;
	for (char c : str) {
		if (charSet.count(c) > 0) {
			return false;
		}
		charSet.insert(c);
	}
	return true;
}



void FindMarker(std::ifstream& aocInput) {
	size_t marker = 4;
	std::string line;
	while (std::getline(aocInput, line))
	{
		const int N = line.size();
		for (int i = 0; i < N; i++)
		{
			std::string chars = line.substr(i, marker);
			if (chars.length() == 4 && hasUniqueCharacters(chars))
				markercandidates.insert({ i, chars });
		}
	}
}

void FindMessage(std::ifstream& aocInput) {
	size_t marker = 14;
	std::string line;
	while (std::getline(aocInput, line))
	{
		const int N = line.size();
		for (int i = 0; i < N; i++)
		{
			std::string chars = line.substr(i, marker);
			if (chars.length() == 14 && hasUniqueCharacters(chars))
				markercandidates.insert({ i + 14, chars });
		}
	}
}

void ProcessInput(){
	std::ifstream aocInput;
	aocInput.open("AOCDay6.txt");
	if (aocInput.fail()) {
		std::cout << "Failed to open file : \n";
		std::exit(-1);
	}
	
	//FindMarker(aocInput);
	FindMessage(aocInput);
	for (auto c : markercandidates)
	{
		std::cout << c.first << " " << c.second << '\n';
	}


}





int main()
{
	ProcessInput();
}

