//
// Created by 20580 on 2022/4/8.
//

#include "Factory.h"
#include <iostream>

/**
 * Test with case 1, coffee
 * Output:
 *      Latte Coffee it is ready for you, taste: light and mellow Please enjoy slowly
 *      Mocha Coffee it is ready for you, taste: silky smooth and full-bodied Please enjoy slowly
 */
void test1(){
    Coffee *latte = CoffeeMaker::makeCoffee(Latte);
    printf("%s it is ready for you, taste: %s Please enjoy slowly\n", latte->getName().c_str(), latte->getTaste().c_str());
    Coffee *mocha = CoffeeMaker::makeCoffee(Mocha);
    printf("%s it is ready for you, taste: %s Please enjoy slowly\n", mocha->getName().c_str(), mocha->getTaste().c_str());
    delete latte;
    delete mocha;
}

/**
 * Test with case 2, Expand Simple Factory
 * Output:
 *      Create:        Line Pen, Object Id:        0x8819a0, Type:     PenTypeLine
 *      Create:   Rectangle Pen, Object Id:        0x881578, Type:     PenTypeRect
 *      Create:   Rectangle Pen, Object Id:        0x881578, Type:     PenTypeRect
 *      Create:        Oval Pen, Object Id:        0x8815c0, Type:  PenTypeEllipse
 */
void test2(){
    PenFactory factory = PenFactory();

    LinePen* linePen = (LinePen*)factory.createPen(PenTypeLine);
    printf("Create: %15s, Object Id: %15s, Type: %15s\n", linePen->getName().c_str(),
           linePen->id().c_str(), linePen->getType().c_str());

    RectanglePen* rectPen = (RectanglePen*)factory.createPen(PenTypeRect);
    printf("Create: %15s, Object Id: %15s, Type: %15s\n", rectPen->getName().c_str(),
           rectPen->id().c_str(), rectPen->getType().c_str());

    RectanglePen* rectPen2 = (RectanglePen*)factory.createPen(PenTypeRect);
    printf("Create: %15s, Object Id: %15s, Type: %15s\n", rectPen2->getName().c_str(),
           rectPen2->id().c_str(), rectPen2->getType().c_str());

    EllipsePen* ellipsePen = (EllipsePen*)factory.createPen(PenTypeEllipse);
    printf("Create: %15s, Object Id: %15s, Type: %15s\n", ellipsePen->getName().c_str(),
           ellipsePen->id().c_str(), ellipsePen->getType().c_str());
 }

int main(int argc, char *argv[]){
    test1();
    test2();
}
