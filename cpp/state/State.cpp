/**
 * Author: arqqqq
 * Date: 2022/4/12
 */

#include <iostream>
#include "State.h"

State::State(const std::string &name):__name(name){}

std::string State::getStateName() const { return __name; }

SolidState::SolidState(const std::string &name): State(name){}

void SolidState::behavior(const Water *water) {
    printf("I have a high and cold personality! current temperature: %d 'C, I am as strong as steel, like a cold-blooded animal, please use me to smash people, hehe...\n", water->getTemperature());
}

LiquidState::LiquidState(const std::string &name): State(name){}

void LiquidState::behavior(const Water *water) {
    printf("I have a gentle personality! current temperature: %d 'C, I can nourish all things, and drinking me will make you more energetic...\n", water->getTemperature());
}

GaseousState::GaseousState(const std::string &name): State(name){}

void GaseousState::behavior(const Water *water) {
    printf("I have a warm personality! current temperature: %d 'C, Flying into the sky is my lifelong dream, in which you will not see my existence, I will reach the realm of no self...\n", water->getTemperature());
}

Water::Water(int temperature):__state(nullptr){
    setTemperature(temperature);
}

void Water::setState(std::shared_ptr<State> state) {
    this->__state = state;
}

void Water::changeState(std::shared_ptr<State> state) {
    if(__state != nullptr){
        printf("From %s to %s\n", __state->getStateName().c_str(), state->getStateName().c_str());
    }else{
        printf("Initialize of the state %s\n", state->getStateName().c_str());
    }
    __state = state;
}

int Water::getTemperature() const { return __temperature; }

void Water::setTemperature(int temperature) {
    __temperature = temperature;
    if(__temperature <= 0)
        changeState(std::shared_ptr<State>((State*)new SolidState("Solid")));
    else if(__temperature <= 100)
        changeState(std::shared_ptr<State>((State*)new LiquidState("Liquid")));
    else
        changeState(std::shared_ptr<State>((State*)new GaseousState("Gaseous")));
}

void Water::riseTemperature(int step) {
    setTemperature(__temperature + step);
}

void Water::reduceTemperature(int step) {
    setTemperature(__temperature - step);
}

void Water::behavior() {
    if(__state != nullptr)
        __state->behavior(this);
}
