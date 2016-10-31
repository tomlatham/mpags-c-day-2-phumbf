// Standard Library includes
#include <iostream>
#include <string>
#include <vector>
#include <fstream>

// For std::isalpha and std::isupper
#include <cctype>

//Include the headers for the separate functions
#include "TransformChar.hpp"
#include "processCommandLine.hpp"
#include "runCaesarCipher.hpp"


// Main function of the mpags-cipher program
int main(int argc, char* argv[])
{
  // Convert the command-line arguments into a more easily usable form
  const std::vector<std::string> args {argv, argv+argc};


  // Options that might be set by the command-line arguments
  bool helpRequested {false};
  bool versionRequested {false};
  bool encRequested {false};
  bool decRequested {false};
  std::string inputFileName {""};
  std::string outputFileName {""};

  // Initialize key
  size_t key{0};
  
  //Call process command line function and return true or false.
  bool allok = processCommandLine(args, helpRequested, versionRequested, encRequested, decRequested, inputFileName, outputFileName, key);  

  //If fails
  if(allok == false)
  {
  std::cout << "Command line error" << std::endl;
  return 1;
  }

  // Handle help, if requested
  if (helpRequested) 
  {
    // Line splitting for readability
    std::cout
      << "Usage: mpags-cipher [-i <file>] [-o <file>]\n\n"
      << "Encrypts/Decrypts input alphanumeric text using classical ciphers\n\n"
      << "Available options:\n\n"
      << "  -h|--help        Print this help message and exit\n\n"
      << "  --version        Print version information\n\n"
      << "  -i FILE          Read text to be processed from FILE\n"
      << "                   Stdin will be used if not supplied\n\n"
      << "  -o FILE          Write processed text to FILE\n"
      << "                   Stdout will be used if not supplied\n\n"
      << "  -encrypt         Activate encryption mode\n\n"
      << "  -decrypt         Activate decryption mode\n";
    // Help requires no further action, so return from main
    // with 0 used to indicate success
    return 0;
  }

  // Handle version, if requested
  // Like help, requires no further action,
  // so return from main with zero to indicate success
  if (versionRequested) 
  {
    std::cout << "0.1.0" << std::endl;
    return 0;
  }

  // Initialise variables for processing input text
  char inputChar {'x'};
  std::string inputText {""};

  // Read in user input from stdin/file if file is NOT empty
  if (!inputFileName.empty()) 
     {
       std::ifstream in_file {inputFileName};
       //Check if file ok to read from
       bool ok_to_read = in_file.good();
       if(ok_to_read)
    	  { 
     		while(in_file >> inputChar)
                {
	         inputText += transformChar(inputChar);
	        }
    	  }
      }

  // Loop over each character from user input if no input file exists
  // (until Return then CTRL-D (EOF) pressed)
  if (inputFileName.empty())
  {
  	while(std::cin >> inputChar)
  	{
		inputText += transformChar(inputChar);
  	}
  }	

  //Define final output string "run" and set it to the result of the Caesar function
  std::string run{""};
  run += runCaesarCipher(inputText, key, encRequested, decRequested);
  //Print both input and result
  std::cout << inputText << std::endl;
  std::cout << run << std::endl;

  // Check that file is opened and if so write result to file
  if (!outputFileName.empty()) 
      {
        std::ofstream out_file {outputFileName};
        bool ok_to_write = out_file.good();
        if(ok_to_write)
       	{
         out_file << run << std::endl;
        }

      }

  // No requirement to return from main, but we do so for clarity
  // and for consistency with other functions
  return 0;
}


