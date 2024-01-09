// catapult.cpp : This file contains the 'main' function. Program execution begins and ends there.

// Library
#include <iostream>
#include <fstream>
#include <string>
#include <regex>
#include <vector>
#include "catapult.h"

// Platform-specific libraries
#ifdef _WIN32
	#include <Windows.h>
#endif

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

	// Extract the URLs from the file
	std::vector<std::string> urls = extractUrls(file);

	// Open each URL in the default browser
	for (std::string url : urls)
	{
		// ? May need to add a delay here to avoid opening too many browser tabs at once
		openUrlInBrowser(url);
	}

	// Close the file
	file.close();

	return 0;	// Exit successfully

}

static std::vector<std::string> extractUrls(std::ifstream& file)
{
	// A vector to store the URLs
	std::vector<std::string> urls;

	// Read and process each line of the file
	std::string line;
	while (std::getline(file, line))
	{
		// Create a regular expression to match URLs
		std::regex urlRegex("(https?://[^\\s/$.?#].[^\\s]*)");

		// Search for matches in the current line
		std::smatch matches;
		if (std::regex_search(line, matches, urlRegex))
		{
			// Extract the URL from the match
			std::string url = matches.str(1);

			// Add the URL to the vector
			urls.push_back(url);
		}
	}

	// Return the vector of URLs
	return urls;
}

static void openUrlInBrowser(std::string url)
{
	#ifdef _WIN32
		// On Windows, use the ShellExecute function
		ShellExecuteA(NULL, "open", url.c_str(), NULL, NULL, SW_SHOWNORMAL);
	#else
		// TODO: Implement for other operating systems
		std::cerr << "Cannot open URL on this operating system" << std::endl;
	#endif
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
