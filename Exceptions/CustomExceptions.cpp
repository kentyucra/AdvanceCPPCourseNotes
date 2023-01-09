#include <iostream>
#include <exception>

class MyExecption : public std::exception
{
public:
    // **const throw()** means a function will not throw an expcetion, runtime checking
    virtual const char *what() const throw()
    {
        return "MyException: Something bad happened";
    }
};

class Test
{
public:
    void goesWrong()
    {
        throw MyExecption();
    }
};

int main()
{

    Test test;
    try
    {
        test.goesWrong();
    }
    catch (MyExecption &e)
    {
        std::cout << e.what() << std::endl;
    }
    return 0;
}