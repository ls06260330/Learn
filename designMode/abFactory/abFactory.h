#ifndef __ABFACTORY_H__
#define __ABFACTORY_H__
#include <iostream>

class AbstractProductA
{
public:
    virtual ~AbstractProductA();
    virtual std::string UsefulFunctionA() const = 0;
};

class ConcreteProductA1 : public AbstractProductA
{
public:
    std::string UsefulFunctionA() const override;
};

class ConcreteProductA2 : public AbstractProductA
{
public:
    std::string UsefulFunctionA() const override;
};

class AbstractProductB
{
public:
    virtual ~AbstractProductB();
    virtual std::string UsefulFunctionB() const = 0;

    virtual std::string AnotherUsefulFunctionB(const AbstractProductA &collaborator) const = 0;
};

class ConcreteProductB1 : public AbstractProductB
{
public:
    std::string UsefulFunctionB() const override;
    std::string AnotherUsefulFunctionB(const AbstractProductA &collaborator) const;
};

class ConcreteProductB2 : public AbstractProductB
{
public:
    std::string UsefulFunctionB() const override;
    std::string AnotherUsefulFunctionB(const AbstractProductA &collaborator) const;
};

class AbstractFactory
{
public:
    virtual ~AbstractFactory();
    virtual AbstractProductA *CreateProductA() const = 0;
    virtual AbstractProductB *CreateProductB() const = 0;
};

class ConcreteFactory1 : public AbstractFactory
{
public:
    AbstractProductA *CreateProductA() const override;
    AbstractProductB *CreateProductB() const override;
};

class ConcreteFactory2 : public AbstractFactory
{
public:
    AbstractProductA *CreateProductA() const override;
    AbstractProductB *CreateProductB() const override;
};

#endif