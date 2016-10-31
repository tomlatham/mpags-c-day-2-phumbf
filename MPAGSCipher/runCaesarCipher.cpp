#include <iostream>
#include <string>
#include <vector>
#include "runCaesarCipher.hpp"

std::string runCaesarCipher(const std::string& inputText, const size_t key, bool encRequested, bool decRequested)

{  // Create the alphabet container and output string
   const std::vector<char> abet{'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z'};
   std::string cenout{""};
   // Convert input into vector of chars and define the size of the vector
   std::vector<char> element(inputText.begin(), inputText.end());
   typedef std::vector<std::string>::size_type size_type;
   const size_type insize {element.size()};

   // If Encryption mode 
   if(encRequested)
   {
      //loop over the input text
      for(unsigned int j=0; j<insize; ++j)
      { 
        //Set/reset i to zero
        int i{0};

           //loop over the alphabet
 	   for(int k=0; k<26; ++k)
	   {
                   // For each input char find the corresponding position in the alphabet
		   if(element[j] == abet[k])
		   {   
                     //% for wrap around, determine new character and add to output string
                        i = (k + key) % 26;
                        cenout += abet[i];
		   }
           }

     
      }
   }   

   // If decryption mode
   else if(decRequested)
   {
      //loop over the input text
      for(unsigned int j=0; j<insize; ++j)
      { 
        //Set/reset i to zero
        int i{0};

           //loop over the alphabet
 	   for(int k=0; k<26; ++k)
	   {
                // For each character find the corresponding position in the alphabet
		if(element[j] == abet[k])
		{   
                     //% for wrap around, determine new character and add to output string
                     //add on 26 to take into account possible negative number during decryption
                     i = (26 + k - key) % 26;
                     cenout += abet[i];
		}
           }

     
      }
   }   


 // Finally (after the loop), return the output string
 return cenout;

}
