#pragma once

int main(int argc, char* argv[]);

/// <summary>
/// This function extracts URLs from a file and returns them in a vector.
/// </summary>
/// <param name="file">
/// The file to extract URLs from. The file must be open before calling this function.
/// </param>
/// <returns>
/// A vector of strings, each string being a URL found in the file.
/// </returns>
static std::vector<std::string> extractUrls(std::ifstream& file);

/// <summary>
/// This function opens a URL in the default browser.
/// </summary>
/// <param name="url">
/// The URL to open.
/// </param>
static void openUrlInBrowser(std::string url);
