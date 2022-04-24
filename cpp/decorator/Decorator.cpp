/**
 * Author: arqqqq
 * Date: 2022/4/18
 */

#include "Decorator.h"
#include <iostream>

/* Class Person */
Person::Person(const string &name):__name(name){}

string Person::getName() const { return __name; }

void Person::wear() { printf("My wear is\n"); }

/* Class Engineer */
Engineer::Engineer(const string &name, const string &skill): Person(name), __skill(skill){}

string Engineer::getSkill() const { return __skill; }

void Engineer::wear() {
    printf("I am %s engineer %s\n", __skill.c_str(), getName().c_str());
    Person::wear();
}

/* Class Teacher */
Teacher::Teacher(const string &name, const string &title): Person(name), __title(title){}

string Teacher::getTitle() const { return __title; }

void Teacher::wear() {
    printf("I am %s %s\n", getName().c_str(), __title.c_str());
    Person::wear();
}

/* Class ClothingDecorator */
ClothingDecorator::ClothingDecorator(shared_ptr<Person> person): Person(""){
    __person = std::move(person);
}

void ClothingDecorator::wear() {
    if( __person != nullptr )
        __person->wear();
}

/* Class CasualPantDecorator */
CasualPantDecorator::CasualPantDecorator(shared_ptr<Person> person): ClothingDecorator(person){}

void CasualPantDecorator::wear() {
    ClothingDecorator::wear();
    printf("A pair of khaki slacks\n");
}

/* Class BeltDecorator */
BeltDecorator::BeltDecorator(shared_ptr<Person> person): ClothingDecorator(person){}

void BeltDecorator::wear() {
    ClothingDecorator::wear();
    printf("A black belt with silver pin buckles\n");
}

/* Class LeatherShoesDecorator */
LeatherShoesDecorator::LeatherShoesDecorator(shared_ptr<Person> person): ClothingDecorator(person){}

void LeatherShoesDecorator::wear() {
    ClothingDecorator::wear();
    printf("A pair of dark casual leather shoes\n");
}

/* Class KnittedSweaterDecorator */
KnittedSweaterDecorator::KnittedSweaterDecorator(shared_ptr<Person> person): ClothingDecorator(person){}

void KnittedSweaterDecorator::wear() {
    ClothingDecorator::wear();
    printf("A fuchsia knit sweater\n");
}

/* Class WhiteShirtDecorator */
WhiteShirtDecorator::WhiteShirtDecorator(shared_ptr<Person> person): ClothingDecorator(person){}

void WhiteShirtDecorator::wear() {
    ClothingDecorator::wear();
    printf("A white shirt\n");
}

/* Class GlassesDecorator */
GlassesDecorator::GlassesDecorator(shared_ptr<Person> person): ClothingDecorator(person){}

void GlassesDecorator::wear() {
    ClothingDecorator::wear();
    printf("A pair of square black-rimmed glasses\n");
}
