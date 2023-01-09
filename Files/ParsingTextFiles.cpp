#include <iostream>
#include <fstream>
#include <string>

int main()
{
    std::string filename = "stats.txt";
    std::fstream input;

    input.open(filename, std::ios::in);

    if (input.is_open())
    {
        while (input)
        {
            std::string line;

            std::getline(input, line, ':');

            int population;
            input >> population;

            // We can also read all the left whitespace with `input >> ws`
            // input.get();
            input >> std::ws;

            if (!input)
                break;

            // std::cout << "input = " << (bool)input << std::endl;
            std::cout << line << " -- " << population << std::endl;
        }
        input.close();
    }
    else
    {
    }
    return 0;
}