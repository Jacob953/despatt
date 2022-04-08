/**
 * Author: arqqqq
 * Date: 2022/4/8
 */

#ifndef DESPATT_FACTORY_H
#define DESPATT_FACTORY_H
#include <string>

/**
 * Case1 Coffee
 */
class Coffee{
public:
    Coffee(const std::string name);

    std::string getName() const;

    virtual std::string getTaste() const;
private:
    std::string __name;
};

class CoffeeLatte: public Coffee{
public:
    CoffeeLatte(const std::string name);

    std::string getTaste() const override;
};

class MochaCoffee: public Coffee{
public:
    MochaCoffee(const std::string name);

    std::string getTaste() const override;

};

enum CoffeeStyle{
    Latte,
    Mocha
};

class CoffeeMaker{
public:
    static Coffee* makeCoffee(CoffeeStyle coffee);
};

/**
 * Case2 Expand Simple Factory
 */
 enum PenType{
    PenTypeLine,
    PenTypeRect,
    PenTypeEllipse
 };

 /* Pen */
 class Pen{
 public:
    Pen(const std::string name);

    std::string getName() const;

    virtual std::string getType() const = 0;

    std::string id() const;
 private:
     std::string __name;
 };

 /* Line Pen */
 class LinePen: public Pen{
 public:
    LinePen(std::string name);

     std::string getType() const override;
 };

 /* Rect Pen */
 class RectanglePen: public Pen{
 public:
     RectanglePen(std::string name);

     std::string getType() const override;
 };

 /* Oval Pen */
 class EllipsePen: public Pen{
 public:
     EllipsePen(std::string name);

     std::string getType() const override;
 };

#include<map>
 /* Pen Factory */
 class PenFactory{
 public:
     PenFactory();

     Pen* createPen(PenType pt);

     /* This method if match will return the pointer if not, return NULL*/
//     Pen* getSingleObj(PenType p, std::string name);

     ~PenFactory();
 private:
    std::map<PenType, Pen*> __pens;
 };


#endif //DESPATT_FACTORY_H
