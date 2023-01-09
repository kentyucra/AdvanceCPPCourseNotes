#include <iostream>
#include <map>

class Person
{
private:
    std::string name;
    int age;

public:
    Person() : name(""), age(0) {}

    // When you define a constructor you lose the default constructor
    Person(std::string name, int age) : name(name), age(age) {}

    void print() const
    {
        std::cout << name << ": " << age << std::endl;
    }
};

int main()
{
    std::map<int, Person> people;

    // No matter in which order you insert the keys
    // the keys will be sorted when you print using iterators
    people[50] = Person("Mike", 40);
    people[2] = Person("Vicky", 30);
    people[33] = Person("Raj", 20);

    for (std::map<int, Person>::iterator it = people.begin(); it != people.end(); it++)
    {
        std::cout << it->first << ": " << std::endl;
        (it->second).print();
    }
}