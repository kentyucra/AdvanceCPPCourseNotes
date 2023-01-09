#include <iostream>
#include <map>

int main()
{
    std::map<std::string, int> ages;

    ages["Mike"] = 40;
    ages["Raj"] = 20;
    ages["Vicky"] = 30;

    ages["Mike"] = 70;

    // another way to insert a key and value to a map
    ages.insert(std::make_pair("Peter", 100));

    // Check if a key exist without inserting it by default to the map
    if (ages.find("Pepe") != ages.end())
    {
        std::cout << "Pepe key found on map" << std::endl;
    }
    else
    {
        std::cout << "Key not found!" << std::endl;
    }

    for (std::map<std::string, int>::iterator it = ages.begin(); it != ages.end(); it++)
    {
        // 2 ways of print the map
        std::pair<std::string, int> age = *it;
        std::cout << age.first << ": " << age.second << std::endl;
        std::cout << it->first << ": " << it->second << std::endl;
    }

    return 0;
}