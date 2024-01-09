// catapult.cpp : This file contains the 'main' function. Program execution begins and ends there.

// Library
#include <iostream>
#include <fstream>
#include <string>

int main(int argc, char *argv[])
{
	// Check that the filename is provided as a command line argument
	if (argc != 2)
	{
		std::cout << "Please provide a filename as a command line argument" << std::endl;
		return 1;	// Exit with error code
	}

	// Get the filename from the command line arguments
	char* fileName = argv[1];

	// Open the file
	std::ifstream file(fileName);
	if (!file.is_open())
	{
		std::cout << "Could not open file " << fileName << std::endl;
		return 1;	// Exit with error code
	}

	// Read and display the file contents
	std::string line;
	while (std::getline(file, line))
	{
		std::cout << line << std::endl;
	}

	// Close the file
	file.close();

	return 0;	// Exit successfully

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
