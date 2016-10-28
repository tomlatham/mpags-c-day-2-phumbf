#include <iostream>
#include <string>
#include <vector>

#include "runCaesarCipher.hpp"

std::string runCaesarCipher(const std::string& inputText, const size_t key, const bool encypt)

{  // Create the alphabet container and output string
   const std::vector<char> abet{'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z'};
   std::string outp{""};

// Loop over the input text
for (const auto& elem : inputText)
{
  for(j=0; j<26; j++)
   { 
     if(elem[j] == abet[j])
	{
	}
   }
}

// For each character find the corresponding position in the alphabet

// Apply the shift (+ve or -ve depending on encrypt/decrypt to the position, handling correctly
// potential wrap around

// Determine the new character and add it to the output string

// Finally (after the loop), return the output string
}
