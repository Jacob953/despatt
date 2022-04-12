/**
 * Author: arqqqq
 * Date: 2022/4/12
 */

#include "StateFrame.h"

/* Begin namespace StateFrame */
template<class T, class U>
StateFrame::Context<T, U>::Context():__states(),
                                __currState(nullptr){};

template<class T, class U>
void StateFrame::Context<T, U>::addState(std::shared_ptr<State<T, U>> state) {
    auto it = std::find(__states.cbegin(), __states.cend(), state);
    if(it == __states.end())
        __states.push_back(state);
}

template<class T, class U>
bool StateFrame::Context<T, U>::changeState(std::shared_ptr<State<T, U>> state) {
    if(__states.size() == 0)
        return false;
    else if(__currState == nullptr)
        printf("Initialized state to %s\n", state->getStateName().c_str());
    else{
        printf("From %s to %s\n", __currState->getStateName().c_str(), state->getStateName().c_str());
    }
    __currState = state;
    addState(state);
    return true;
}

template<class T, class U>
const StateFrame::State<T, U> *StateFrame::Context<T, U>::getState() const{
    return __currState;
}

template<class T, class U>
T StateFrame::Context<T, U>::_getStateInfo() const {
    return __stateInfo;
}

template<class T, class U>
void StateFrame::Context<T, U>::_setStateInfo(T info) {
    __stateInfo = info;
    for(const auto& it: __states){
        if(it->isMatch(info)){
            changeState(it);
            return;
        }
    }
}

template<class T, class U>
StateFrame::State<T, U>::State(const std::string &name):__name(name){}

template<class T, class U>
std::string StateFrame::State<T, U>::getStateName() const { return __name; }
/* End namespace StateFrame */


using CreateState = std::shared_ptr<StateFrame::State<int, Water1>>;
using Spointer = StateFrame::State<int, Water1>*;

Water1::Water1(){
    addState(CreateState((Spointer)new SolidState1("Solid")));
    addState(CreateState((Spointer)new LiquidState1("Liquid")));
    addState(CreateState((Spointer)new GaseousState1("Gaseous")));
    setTemperature(25);
}

void Water1::setTemperature(int t) {
    _setStateInfo(t);

}

int Water1::getTemperature() const {
    return _getStateInfo();
}

void Water1::riseTemperature(int step) {
    setTemperature(_getStateInfo() + step);
}

void Water1::reduceTemperature(int step) {
    setTemperature(_getStateInfo() - step);
}

void Water1::behavior() const {
    if(__currState != nullptr)
        __currState->behavior((Water1*)this);
}

SolidState1::SolidState1(const std::string &name): StateFrame::State<int, Water1>(name){}

bool SolidState1::isMatch(int stateinfo) const { return stateinfo <= 0; }

void SolidState1::behavior(Water1 *u) const {
    printf("I have a high and cold personality! current temperature: %d 'C, I am as strong as steel, like a cold-blooded animal, please use me to smash people, hehe...\n", u->getTemperature());
}

LiquidState1::LiquidState1(const std::string &name): StateFrame::State<int, Water1>(name){}

bool LiquidState1::isMatch(int stateinfo) const { return stateinfo > 0 && stateinfo < 100; }

void LiquidState1::behavior(Water1 *u) const {
    printf("I have a gentle personality! current temperature: %d 'C, I can nourish all things, and drinking me will make you more energetic...\n", u->getTemperature());
}

GaseousState1::GaseousState1(const std::string &name): StateFrame::State<int, Water1>(name){}

bool GaseousState1::isMatch(int stateinfo) const { return stateinfo >= 100; }

void GaseousState1::behavior(Water1 *u) const {
    printf("I have a warm personality! current temperature: %d 'C, Flying into the sky is my lifelong dream, in which you will not see my existence, I will reach the realm of no self...\n", u->getTemperature());
}
