#include "factoryMethod.h"

Product::~Product()
{
    std::cout << "~Product()" << std::endl;
}

std::string ConcreteProduct1::Operation() const
{
    return "{Result of the ConcreteProduct1}";
}

std::string ConcreteProduct2::Operation() const
{
    return "{Result of the ConcreteProduct2}";
}

Creator::~Creator()
{
    std::cout << "~Creator()" << std::endl;
}

std::string Creator::SomeOperation() const
{
    Product* product = this->FactoryMethod();
    std::string result = "Creator: The same creator's code has just worked with " + product->Operation();
    delete product;
    return result;
}

Product* ConcreteCreator1::FactoryMethod() const
{
    return new ConcreteProduct1();
}

Product* ConcreteCreator2::FactoryMethod() const
{
    return new ConcreteProduct2();
}