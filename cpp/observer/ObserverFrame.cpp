/**
 *Author: arqqqq
 *Date: 2022/4/10
 */
#include "ObserverFrame.h"

namespace observerframe{
    Observable::Observable(const std::string &name):__name(name),__observers(){}

    void Observable::addObserver(Observer *observer) {
        __observers.push_back(observer);
    }

    void Observable::removeObserver(Observer *observer) {
        std::vector<Observer*>::iterator it = __observers.begin();
        while(it != __observers.end()){
            if(*it == observer){
                __observers.erase(it);
                break;
            }
            it = it+1;
        }
    }

    std::string Observable::myName() const { return __name; }

    void Observable::notifyObservers(void *object) {
        for(auto &it: __observers){
            it->update(this, object);
        }
    }
}

WaterHeater1::WaterHeater1(): observerframe::Observable("WaterHeater1"),
                            __curr_temperature(25){}

int WaterHeater1::getTemperature() const { return __curr_temperature; }

void WaterHeater1::setTemperature(int t) {
    __curr_temperature = t;
    printf("CurrentTemperature %d'C\n", __curr_temperature);
    notifyObservers(this);
}

void WashingMode1::update(void *ob, void *object) {
    observerframe::Observable* it = (observerframe::Observable*)ob;
    if(it->myName() == "WaterHeater1"){
        WaterHeater1* it1 = (WaterHeater1*)it;
        int tem = it1->getTemperature();
        if(tem >= 50 && tem <= 70)
            printf("Di Di Di!\n The water has been boiled, the temperature is normal and it is time to take a bath\n");
    }
}

void DrinkingMode1::update(void *ob, void *object) {
    observerframe::Observable* it = (observerframe::Observable*)ob;
    if(it->myName() == "WaterHeater1"){
        WaterHeater1* it1 = (WaterHeater1*)it;
        int tem = it1->getTemperature();
        if(tem >= 100)
            printf("Di Di Di!\n The water is boiling, it can be used to drinking!\n");
    }
}
