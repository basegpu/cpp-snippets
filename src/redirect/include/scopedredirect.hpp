#pragma once

#include <fstream> 
#include <iostream> 
#include <string>

namespace redirect
{
    
    class ScopedRedirect
    {
    public:

        static void Test()
        {
            std::fstream file; 
            file.open("cout.txt", std::ios::out); 
            std::string line; 
          
            // Backup streambuffers of  cout 
            std::streambuf* stream_buffer_cout = std::cout.rdbuf();
          
            // Get the streambuffer of the file 
            std::streambuf* stream_buffer_file = file.rdbuf(); 
          
            // Redirect std::cout to file 
            std::cout.rdbuf(stream_buffer_file); 
          
            std::cout << "This line written to file" << std::endl; 
          
            // Redirect std::cout back to screen 
            std::cout.rdbuf(stream_buffer_cout); 
            std::cout << "This line is written to screen" << std::endl; 
          
            file.close(); 
        }
    };
}
