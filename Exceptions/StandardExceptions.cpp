#include <new>
#include <iostream>

class CangoWrong
{
public:
    CangoWrong()
    {
        while (true)
        {
            char *pMemory = new char[999999999999999];
        }
    }
};

int main()
{
    try
    {
        CangoWrong wrong;
    }
    catch (std::bad_alloc &e)
    {
        std::cout << "bad_allow exception happening" << std::endl;
        std::cout << e.what() << std::endl;
    }

    std::cout << "still running" << std::endl;
    return 0;
}