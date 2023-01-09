#include <iostream>
#include <new>
#include <exception>

void goesWrong()
{
    bool error1Detected = true;
    bool error2Detected = false;

    if (error1Detected)
    {
        throw std::bad_alloc();
    }

    if (error2Detected)
    {
        throw std::exception();
    }
}

int main()
{

    try
    {
        goesWrong();
    }
    catch (std::bad_alloc &e)
    {
        std::cout << e.what() << std::endl;
    }
    catch (std::exception &e)
    {
        std::cout << "first exception" << std::endl;
        std::cout << e.what() << std::endl;
    }
    return 0;
}