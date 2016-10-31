#ifndef MPAGSCIPHER_RUNCAESARCIPHER_HPP
#define MPAGSCIPHER_RUNCAESARCIPHER_HPP

#include <string>

//Declare function processCommandLine
std::string runCaesarCipher(const std::string& inputText, const size_t key, bool encRequested, bool decRequested);

#endif // MPAGSCIPHER_RUNCAESARCIPHER_HPP
