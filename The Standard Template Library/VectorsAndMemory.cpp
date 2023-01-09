#include <iostream>
#include <vector>

int main()
{
    std::vector<double> numbers(0);

    std::cout << "Size: " << numbers.size() << std::endl;

    int capacity = numbers.capacity();
    std::cout << "Capacity: " << capacity << std::endl;

    for (int i = 0; i < 10000; i++)
    {
        if (numbers.capacity() != capacity)
        {
            capacity = numbers.capacity();
            std::cout << "Capacity: " << capacity << std::endl;
        }

        numbers.push_back(i);
    }

    // Change the internal variable inside the class Vector
    // All other representation keeps the same
    numbers.resize(100);
    std::cout << numbers[2] << std::endl;
    std::cout << "Size: " << numbers.size() << std::endl;
    std::cout << "Capacity: " << numbers.capacity() << std::endl;

    // Will increase the capacity of the Vector,
    // just in case the reserve value asked is bigger than the current capacity
    numbers.reserve(100000);
    std::cout << "Size: " << numbers.size() << std::endl;
    std::cout << "Capacity: " << numbers.capacity() << std::endl;
}