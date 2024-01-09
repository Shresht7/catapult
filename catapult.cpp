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

// ====
// MAIN
// ====

int main(int argc, char *argv[])
{
	// Display help message if no arguments provided or if -h/--help is provided
	if (argc == 1 || (argc == 2 && (std::string(argv[1]) == "-h" || std::string(argv[1]) == "--help"))) {
		displayHelp();
		return 0;
	}

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
		std::cerr << "Error: Unable to open file: '" << fileName << "'" << std::endl << std::endl;
		displayHelp();
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

// ----------------
// HELPER FUNCTIONS
// ----------------

static void displayHelp()
{
	std::cout << "Usage: catapult.exe [filename]" << std::endl;
	std::cout << "Opens all URLs in the specified file in the default browser" << std::endl;
	std::cout << std::endl;
	std::cout << "Arguments:" << std::endl;
	std::cout << "  filename    The name of the file containing the URLs to open" << std::endl;
	std::cout << std::endl;
	std::cout << "Options:" << std::endl;
	std::cout << "  -h, --help  Display this help message" << std::endl;
}

static std::vector<std::string> extractUrls(std::ifstream& file)
{
	// A vector to store the URLs
	std::vector<std::string> urls;

	// Read and process each line of the file
	std::string line;
	while (std::getline(file, line))
	{
		// Ignore comments (lines starting with '#')
		if (line[0] == '#')
		{
			continue;
		}

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
