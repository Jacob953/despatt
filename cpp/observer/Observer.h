/**
 * Author: arqqqq
 * Date: 2022/4/10
 */
#ifndef DESPATT_OBSERVER_H
#define DESPATT_OBSERVER_H

#include <vector>

/**
 * Case1 waterHeater
 */
class WaterHeater;
class Observer;

class WaterHeater{
public:
    WaterHeater();
public:
    int getTemperature() const;
    void setTemperature(int t);
    void addObserver(Observer* obs);
    void notifies();
private:
    std::vector<Observer*> __observer;
    int __curr_temperature;
};

class Observer{
public:
    virtual void update(const WaterHeater &wh) = 0;
};

class WashingMode: public Observer{
public:
    WashingMode() = default;
    void update(const WaterHeater &wh) override;
};

class DrinkingMode: public Observer{
public:
    DrinkingMode() = default;
    void update(const WaterHeater &wh) override;
};

#endif //DESPATT_OBSERVER_H
