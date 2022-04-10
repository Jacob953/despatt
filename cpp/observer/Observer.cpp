/**
 * Author: arqqqq
 * Date: 2022/4/10
 */

#include "Observer.h"
#include <iostream>

WaterHeater::WaterHeater():__observer(), __curr_temperature(25){}

int WaterHeater::getTemperature() const { return __curr_temperature; }

void WaterHeater::setTemperature(int t) {
    __curr_temperature = t;
    printf("CurrentTemperature %d'C\n", __curr_temperature);
    notifies();
}

void WaterHeater::addObserver(Observer *obs) { __observer.push_back(obs); }

void WaterHeater::notifies() {
    for(Observer *&ob: __observer){
        ob->update(*this);
    }
}

void WashingMode::update(const WaterHeater &wh) {
    int tem = wh.getTemperature();
    if(tem >= 50 && tem <= 70)
        printf("Di Di Di!\n The water has been boiled, the temperature is normal and it is time to take a bath\n");
}

void DrinkingMode::update(const WaterHeater &wh) {
    int tem = wh.getTemperature();
    if(tem >= 100)
        printf("Di Di Di!\n The water is boiling, it can be used to drinking!\n");
}
