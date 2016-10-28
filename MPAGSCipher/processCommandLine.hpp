#ifndef MPAGSCIPHER_PROCESSCOMMANDLINE_HPP
#define MPAGSCIPHER_PROCESSCOMMANDLINE_HPP

#include <string>

//Declare function processCommandLine
bool processCommandLine(const std::vector<std::string>& args, bool& helpRequested, bool& versionRequested, std::string& inputFileName, std::string& outputFileName);

#endif // MPAGSCIPHER_PROCESSCOMMANDLINE_HPP
