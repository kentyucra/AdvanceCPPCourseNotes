#include <iostream>
#include <string>

void mightGoWrong()
{
    bool error1 = false;
    bool error2 = true;

    if (error1)
    {
        throw "Something went wrong";
    }

    if (error2)
    {
        throw std::string("Something else went wrong");
    }
}

int main()
{
    try
    {
        mightGoWrong();
    }
    catch (int e)
    {
        std::cout << "exception = " << e << std::endl;
    }
    catch (char const *e)
    {
        std::cout << "Error message = " << e << std::endl;
    }
    catch (std::string &e)
    {
        std::cout << "String Error message = " << e << std::endl;
    }

    // mightGoWrong();

    std::cout << "still running" << std::endl;
    return 0;
}
