/*
Emily Vorng - CSCI151
URL Parser
Prompts the user for a URL then breaks and prints it out three parts
in order of scheme, authority, and path
*/

#include <iostream>
#include <string>

using namespace std::string_literals;

int main() {
    // Prompts the user for a URL
    std::cout << "Please enter a URL: "s;
    std::string url;
    std::cin >> url;

    // Declares string variables for all of the URL parts
    std::string scheme;
    std::string authority;
    std::string path;

    int authorityStart = 0;
    int pathStart = 0;

    // Calculates where the scheme ends and creates a substring of the scheme
    for(int schemeEnd = 0; 0 < url.size(); schemeEnd++) {
        if(url.at(schemeEnd) == ':') {
            scheme = url.substr(0, schemeEnd + 1);
            authorityStart = schemeEnd + 1;
            break;
        }
    }

    // Ensures that the end of the scheme is where the authority starts
    for(int testAuthority = authorityStart; testAuthority < url.size() - 1; testAuthority++) {
        if(url.at(testAuthority) == '/' && url.at(testAuthority + 1) == '/') {
            break;
        } else {
            authorityStart = testAuthority;
        }
    }

    // Calculates where the authority ends and creates a substring of the authority 
    for(int authorityEnd = authorityStart + 2; authorityEnd < url.size(); authorityEnd++) {
        if(url.at(authorityEnd) == '/') {
            authority = url.substr(authorityStart, authorityEnd - authorityStart);
            pathStart = authorityEnd;
            break;
        }
    }

    // Ensures that the end of the authority is where the path starts
    for(int testPath = pathStart; testPath < url.size() - 1; testPath++) {
        if(url.at(testPath) == '/') {
            break;
        } else {
            pathStart = testPath;
        }
    }

    // Creates a substring of the path
    path = url.substr(pathStart, url.size());

    // Prints out the parts of the URL
    std::cout << "scheme = "s << scheme << "\n"s;
    std::cout << "authority = "s << authority << "\n"s;
    std::cout << "path = "s << path << "\n"s;

}