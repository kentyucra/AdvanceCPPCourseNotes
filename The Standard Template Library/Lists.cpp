#include <iostream>
#include <list>

int main()
{
    std::list<int> numbers;

    numbers.push_back(1);
    numbers.push_back(2);
    numbers.push_back(3);

    numbers.push_front(-1);
    numbers.push_front(-2);
    numbers.push_front(-3);

    // -3 -> -2 -> -1 -> 1 -> 2 -> 3

    // Insert elements before an iterator
    std::list<int>::iterator it = numbers.begin();
    it++;
    numbers.insert(it, 100);

    // -3 -> 100 -> -2 -> -1 -> 1 -> 2 -> 3

    // Delete the element inserted before from the list
    std::list<int>::iterator eraseIt = numbers.begin();
    eraseIt++;
    numbers.erase(eraseIt);

    // -3 -> -2 -> -1 -> 1 -> 2 -> 3

    for (std::list<int>::iterator it = numbers.begin(); it != numbers.end(); it++)
    {
        std::cout << *it << " -> ";
    }
    std::cout << std::endl;

    // Add and remove items on a list while looping over it
    for (std::list<int>::iterator it = numbers.begin(); it != numbers.end();)
    {
        if (*it == 2)
        {
            numbers.insert(it, 234);
        }

        if (*it == 1)
        {
            it = numbers.erase(it);
        }
        else
        {
            it++;
        }
    }

    // -3 -> -2 -> -1 -> 234 -> 2 -> 3

    for (std::list<int>::iterator it = numbers.begin(); it != numbers.end(); it++)
    {
        std::cout << *it << " -> ";
    }
    std::cout << std::endl;

    return 0;
}