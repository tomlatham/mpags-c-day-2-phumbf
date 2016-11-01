#include <string>
#include <vector>

#include "runCaesarCipher.hpp"

std::string runCaesarCipher(const std::string& inputText, const size_t key, const bool encrypt)
{
  // Create the alphabet container and output string
  const std::vector<char> abet{'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z'};
  typedef std::vector<char>::size_type size_type;

  std::string cenout{""};

      //loop over the input text
      for( const auto& elem : inputText )
      { 
           //loop over the alphabet
 	   for(size_type k{0}; k<26; ++k)
	   {
                   // For each input char find the corresponding position in the alphabet
		   if(elem == abet[k])
		   {   
                     //% for wrap around, determine new character and add to output string
			size_type i {k};
			if ( encrypt ) {
                            i = (k + key) % 26;
			} else {
			    i = (26 + k - key) % 26;
			}
                        cenout += abet[i];

			break;
		   }
           }

     
      }

 // Finally (after the loop), return the output string
 return cenout;

}
