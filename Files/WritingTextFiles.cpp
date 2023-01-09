#include <iostream>
#include <fstream>

int main()
{
    std::string outputFilename = "Files/text.txt";

    // std::ofstream outFile;
    std::fstream outFile;

    outFile.open(outputFilename, std::ios::out);

    if (outFile.is_open())
    {

        for (int i = 0; i < 10; i++)
        {
            outFile << i << " -> "
                    << "this is a line" << std::endl;
        }
        outFile << "Hello there" << std::endl;
        outFile << 123 << std::endl;
        outFile.close();
    }
    else
    {
        std::cout << "Could not create file: " << outputFilename << std::endl;
    }
    return 0;
}