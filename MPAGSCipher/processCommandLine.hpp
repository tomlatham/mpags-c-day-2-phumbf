#ifndef MPAGSCIPHER_PROCESSCOMMANDLINE_HPP
#define MPAGSCIPHER_PROCESSCOMMANDLINE_HPP

#include <string>
#include <vector>

//Declare function processCommandLine
bool processCommandLine(const std::vector<std::string>& args, bool& helpRequested, bool& versionRequested, bool& encrypt, std::string& inputFileName, std::string& outputFileName, size_t& key);

#endif // MPAGSCIPHER_PROCESSCOMMANDLINE_HPP
