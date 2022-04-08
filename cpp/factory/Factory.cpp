/**
* Author: arqqqq
 * Date: 2022/4/8
*/

#include "Factory.h"

/* Coffee */
Coffee::Coffee(const std::string name): __name(name){}

std::string Coffee::getName() const { return __name; }

std::string Coffee::getTaste() const {
    return "Coffee: taste flavor, a bit bitter";
}

/* CoffeeLatte */
CoffeeLatte::CoffeeLatte(const std::string name): Coffee(name){}

std::string CoffeeLatte::getTaste() const {
    return "light and mellow";
}

/* MochaCoffee */
MochaCoffee::MochaCoffee(const std::string name): Coffee(name){}

std::string MochaCoffee::getTaste() const {
    return "silky smooth and full-bodied";
}

/* Coffee Maker */
Coffee *CoffeeMaker::makeCoffee(CoffeeStyle coffee) {
    switch (coffee) {
        case Latte:{
            return new CoffeeLatte("Latte Coffee");
        }
        case Mocha:{
            return new MochaCoffee("Mocha Coffee");
        }
        default:{
            return new Coffee("Coffee");
        }
    }
}

/**
 * Case 2 Expand Simple Factory
 */
#include <sstream>
#define EnumToStr(enumType) #enumType

/* Pen */
Pen::Pen(const std::string name): __name(name){}

std::string Pen::getName() const { return __name; }

std::string Pen::id() const {
    std::stringstream ss;
    ss<<this;
    return ss.str();
}


/* Line Pen */
LinePen::LinePen(std::string name): Pen(name){}

std::string LinePen::getType() const { return EnumToStr(PenTypeLine); }

/* RectanglePen */
RectanglePen::RectanglePen(std::string name): Pen(name){}

std::string RectanglePen::getType() const { return EnumToStr(PenTypeRect); }

/* EllipsePen */
EllipsePen::EllipsePen(std::string name): Pen(name){}

std::string EllipsePen::getType() const { return EnumToStr(PenTypeEllipse); }

/* Pen Factory */
PenFactory::PenFactory() {
    __pens = {};
}

Pen *PenFactory::createPen(PenType pt) {
    if(__pens.find(pt) == __pens.end()){
        switch (pt) {
            case PenTypeLine:{
                __pens.insert({pt, new LinePen("Line Pen")});
                break;
            }
            case PenTypeRect:{
                __pens.insert({pt, new RectanglePen("Rectangle Pen")});
                break;
            }
            case PenTypeEllipse:{
                __pens.insert({pt, new EllipsePen("Oval Pen")});
                break;
            }
            default:{
                __pens.insert({pt, NULL});
                break;
            }
        }
    }
    return __pens[pt];
}


/* The d constructor it will delete the pointer */
PenFactory::~PenFactory() {
    auto it = __pens.begin();
    while(it != __pens.end()){
        delete it->second;
        it++;
    }
}
