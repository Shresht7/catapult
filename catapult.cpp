// Library
#include <iostream>
#include <fstream>
#include <string>
#include <regex>
#include <vector>
#include <filesystem>
#include "catapult.h"

// Platform-specific libraries
#ifdef _WIN32
	#include <Windows.h>
#else
	#include <cstdlib>
#endif

// VERSION
const std::string VERSION = "v0.2.1";

// A regular expression to match URLs
std::regex urlRegex("^https://[^\\s/$.?#].[^\\s]*$");

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

	// Display version if -v/--version is provided
	if (argc == 2 && (std::string(argv[1]) == "-v" || std::string(argv[1]) == "--version")) {
		std::cout << VERSION << std::endl;
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

	// Extract the locations from the file and open them
	for (std::string location : extractLocations(file))
	{
		open(location);
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
	std::cout << "Opens all URLs and filepaths in the specified file" << std::endl;
	std::cout << std::endl;
	std::cout << "Arguments:" << std::endl;
	std::cout << "  filename    The name of the file containing the paths/URLs to open" << std::endl;
	std::cout << std::endl;
	std::cout << "Options:" << std::endl;
	std::cout << "  -h, --help  Display this help message" << std::endl;
	std::cout << "  -v, --version  Display the version number" << std::endl;
}

static std::vector<std::string> extractLocations(std::ifstream& file)
{
	// A vector to store the locations
	std::vector<std::string> locations;

	// Read and process each line of the file
	std::string line;
	while (std::getline(file, line))
	{
		// Ignore comments (lines starting with '#')
		if (line[0] == '#')
		{
			continue;
		}
		// Add the URL to the vector
		else if (std::regex_match(line, urlRegex))
		{
			locations.push_back(line);
		}
		// Add valid file paths to the vector
		else if (std::filesystem::exists(line))
		{
			locations.push_back(line);
		}
	}

	// Return the vector of locations
	return locations;
}

static void open(std::string location)
{
	#ifdef _WIN32
		// On Windows, use the ShellExecute function
		ShellExecuteA(NULL, "open", location.c_str(), NULL, NULL, SW_SHOWNORMAL);
	#else
		// On Linux, use the system() function to open the location
		std::string command = "xdg-open " + location;
		system(command.c_str());
	#endif
}
