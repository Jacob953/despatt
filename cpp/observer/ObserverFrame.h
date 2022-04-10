/**
 * Author: arqqqq
 * Date: 2022/4/10
 */

#ifndef DESPATT_OBSERVERFRAME_H
#define DESPATT_OBSERVERFRAME_H

/**
 * Case2 base on observer frame
 */
#include <vector>
#include <string>

namespace observerframe{

    class Observer;


    /**
     * Tips:
     *      This is a real frame that can use in c++ project, but it also has a lot of defects, if you have any question of suggestion
     *      please contact me on github,or email: 2058084624@qq.com to me, i am look forward to head you!
     * UML:
     *                  Observable
     * + string __name                              |           class name
     * + vector<Observer*> __observers              |           list of observers
     * ----------------------
     * + bool addObserver(Observer *&observer)      |           append observer, if observer has in list, return false, else return true
     * + bool removeObserver(Observer *&observer)   |           remove observer, if remove it, return true, else return false
     * + void notifyObservers(void* object = NULL)  |           notify observer
     * + string myName()                            |           return class name
     */
    class Observable{
    public:
        void addObserver(Observer *observer);
        void removeObserver(Observer *observer);
        std::string myName() const;
        virtual void notifyObservers(void* object = nullptr);
    protected:
        Observable(const std::string &name);
    private:
        const std::string __name;
        std::vector<Observer*> __observers;
    };

    class Observer{
    public:
        virtual void update(void* ob, void* object) = 0;
    };
}

/**
 * Real Test Case
 */
class WaterHeater1: public observerframe::Observable{
public:
    WaterHeater1();
    int getTemperature() const;
    void setTemperature(int t);
private:
    int __curr_temperature;
};

class WashingMode1: public observerframe::Observer{
public:
    void update(void *ob, void *object) override;
};

class DrinkingMode1:public observerframe::Observer{
public:
    void update(void *ob, void *object) override;
};
#endif //DESPATT_OBSERVERFRAME_H
