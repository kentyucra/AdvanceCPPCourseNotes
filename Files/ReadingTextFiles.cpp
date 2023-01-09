#include <iostream>
#include <fstream>
#include <string>

int main()
{
    std::string inFilename = "test.txt";

    std::fstream inFile;

    inFile.open(inFilename, std::ios::in);

    if (inFile.is_open())
    {

        std::string line;

        // We can also use `inFile` to see if there is anything else in the file
        // `while (inFile)`
        while (!inFile.eof())
        {
            getline(inFile, line);
            std::cout << line << std::endl;
        }

        std::cout << line << std::endl;

        inFile.close();
    }
    else
    {
        std::cout << "Cannot open file: " << inFilename << std::endl;
    }

    return 0;
}