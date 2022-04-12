/**
 * Author: arqqqq
 * Date: 2022/4/12
 */

#ifndef DESPATT_STATE_H
#define DESPATT_STATE_H
#include <string>
#include <memory>

class Water;
class State{
public:
    std::string getStateName() const;

    virtual void behavior(const Water* water) = 0;
protected:
    State(const std::string& name);
private:
    std::string __name;
};

class SolidState: public State{
public:
    SolidState(const std::string& name);

    void behavior(const Water *water) override;
};

class LiquidState: public State{
public:
    LiquidState(const std::string& name);

    void behavior(const Water *water) override;
};

class GaseousState: public State{
public:
    GaseousState(const std::string& name);

    void behavior(const Water *water) override;
};

class Water{
public:
    Water(int temperature);

    int getTemperature() const;

    void setTemperature(int temperature);

    void riseTemperature(int step);

    void reduceTemperature(int step);

    void behavior();

private:
    void setState(std::shared_ptr<State> state);
    void changeState(std::shared_ptr<State> state);
    int __temperature;
    std::shared_ptr<State> __state;
};


#endif //DESPATT_STATE_H
