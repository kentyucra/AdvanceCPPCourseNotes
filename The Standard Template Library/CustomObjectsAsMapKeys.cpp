#include <iostream>
#include <map>

class Person
{
private:
    std::string name;
    int age;

public:
    // Default contructor
    Person() : name(""), age(0) {}

    Person(const Person &other)
    {
        std::cout << "Copy constructor running!" << std::endl;
        name = other.name;
        age = other.age;
    }

    // When you define a constructor you lose the default constructor
    Person(std::string name, int age) : name(name), age(age) {}

    void print() const
    {
        std::cout << name << ": " << age << std::endl;
    }

    // Operator overloading
    // this function is also used to compare if 2 keys are the same
    bool operator<(const Person &other) const
    {
        // We are adding this so we can consider also age part of the key
        if (name == other.name)
            return age < other.age;
        return name < other.name;
    }
};

int main()
{
    std::map<Person, int> people;

    // No matter in which order you insert the keys
    // the keys will be sorted when you print using iterators
    people[Person("Mike", 40)] = 50;
    people[Person("Mike", 433)] = 123;
    people[Person("Vicky", 30)] = 20;
    people[Person("Raj", 20)] = 33;

    for (std::map<Person, int>::iterator it = people.begin(); it != people.end(); it++)
    {
        std::cout << it->second << ": " << std::endl;
        // the key of a map is a const, you can not invoque no const function on a const variable
        (it->first).print();
    }
}