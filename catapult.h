#pragma once

int main(int argc, char* argv[]);

/// <summary>
/// This function displays a help message to the user.
/// </summary>
static void displayHelp();

/// <summary>
/// This function extracts the locations from a file and returns them in a vector. A 
/// location can be a URL or a file path.
/// </summary>
/// <param name="file">
/// The file to extract locations from. The file must be open before calling this function.
/// </param>
/// <returns>
/// A vector of strings, each string being a location found in the file.
/// </returns>
static std::vector<std::string> extractLocations(std::ifstream& file);

/// <summary>
/// This function opens a location. A location can be a URL or a file path.
/// </summary>
/// <param name="location">
/// The location to open.
/// </param>
static void open(std::string location);
