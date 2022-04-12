/**
 * Author: arqqqq
 * Date: 2022/4/12
 */
#ifndef DESPATT_STATEFRAME_H
#define DESPATT_STATEFRAME_H
#include <string>
#include <vector>
#include <memory>

namespace StateFrame{

    template<class T, class U> class State;
    template<class T, class U> class Context;

    template<class T, class U>
    class Context{
    public:
        Context();

        void addState(std::shared_ptr<State<T, U>> state);

        bool changeState(std::shared_ptr<State<T, U>> state);

        const State<T, U>* getState() const;

        void _setStateInfo(T info);

        T _getStateInfo() const;

    protected:
        std::vector<std::shared_ptr<State<T, U>>> __states;
        std::shared_ptr<State<T, U>> __currState;
        T __stateInfo;
    };

    template<class T, class U>
    class State{
    public:
        std::string getStateName() const;

        virtual bool isMatch(T stateinfo) const = 0;

        virtual void behavior(U *u) const = 0;
    protected:
        State(const std::string& name);
    private:
        std::string __name;
    };

}

class Water1:public StateFrame::Context<int, Water1>{
public:
    Water1();

    int getTemperature() const;

    void setTemperature(int t);

    void riseTemperature(int step);

    void reduceTemperature(int step);

    void behavior() const;
};


class SolidState1: public StateFrame::State<int, Water1>{
public:
    SolidState1(const std::string& name);
    void behavior(Water1 *u) const override;
    bool isMatch(int stateinfo) const override;
};

class LiquidState1:public StateFrame::State<int, Water1>{
public:
    LiquidState1(const std::string& name);
    void behavior(Water1 *u) const override;
    bool isMatch(int stateinfo) const override;
};

class GaseousState1: public StateFrame::State<int, Water1>{
public:
    GaseousState1(const std::string& name);
    void behavior(Water1 *u) const override;
    bool isMatch(int stateinfo) const override;
};


#endif //DESPATT_STATEFRAME_H
