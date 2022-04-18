/**
 * Author: arqqqq
 * Date: 2022/4/18
 */

#ifndef DESPATT_DECORATOR_H
#define DESPATT_DECORATOR_H
#include <string>
#include <memory>

using namespace std;

class Person{
public:
    Person(const string& name);
    string getName() const;
    virtual void wear();
private:
    string __name;
};

class Engineer: public Person{
public:
    Engineer(const string& name, const string& skill);
    string getSkill() const;
    void wear() override;
private:
    string __skill;
};

class Teacher: public Person{
public:
    Teacher(const string& name, const string& title);
    string getTitle() const;
    void wear() override;
private:
    string __title;
};

class ClothingDecorator: public Person{
public:
    ClothingDecorator(shared_ptr<Person> person);
    void wear() override;
private:
    shared_ptr<Person> __person;
};

class CasualPantDecorator: public ClothingDecorator{
public:
    CasualPantDecorator(shared_ptr<Person> person);
    void wear() override;
};

class BeltDecorator: public ClothingDecorator{
public:
    BeltDecorator(shared_ptr<Person> person);
    void wear() override;
};

class LeatherShoesDecorator: public ClothingDecorator{
public:
    LeatherShoesDecorator(shared_ptr<Person> person);
    void wear() override;
};

class KnittedSweaterDecorator: public ClothingDecorator{
public:
    KnittedSweaterDecorator(shared_ptr<Person> person);
    void wear() override;
};

class WhiteShirtDecorator: public ClothingDecorator{
public:
    WhiteShirtDecorator(shared_ptr<Person> person);
    void wear() override;
};

class GlassesDecorator: public ClothingDecorator{
public:
    GlassesDecorator(shared_ptr<Person> person);
    void wear() override;
};
#endif //DESPATT_DECORATOR_H
