#include <iostream>
#include <string>
#include <fstream>

// This is to avoid padding on the struct
// Change size of packing
#pragma pack(push, 1)
struct Person
{
    char name[50]; // 50 bytes
    int age;       // 4 bytes
    double height; // 8 bytes
};
#pragma pack(pop)

int main()
{
    Person someone = {"frodo", 220, 0.9};

    std::cout << sizeof(Person) << std::endl;

    std::string filename = "test.bin";

    // -----------------For writing

    std::ofstream outputFile;

    outputFile.open(filename, std::ios::binary);

    if (outputFile.is_open())
    {
        // instead of using the old way to do the cast
        // we can also use `reinterpret_cast<char *>`
        outputFile.write((char *)&someone, sizeof(Person));
        outputFile.close();
    }
    else
    {
        std::cout << "Could not create file " << filename << std::endl;
    }

    // --------------------For reading

    std::ifstream inputFile;

    inputFile.open(filename, std::ios::binary);

    Person someoneelse;

    if (inputFile.is_open())
    {

        inputFile.read(reinterpret_cast<char *>(&someoneelse), sizeof(someoneelse));
        inputFile.close();
    }
    else
    {
        std::cout << "Could not read from " << filename << std::endl;
    }

    std::cout << "name = " << someoneelse.name << std::endl;

    return 0;
}