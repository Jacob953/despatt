/**
 * Author: arqqq
 * Date: 2022/4/6
 */
#include<string>
#include<sstream>
#include<iostream>

/**
 * Singleton1 Case 1
 */
class Singleton1{
public:
    Singleton1(std::string name){
        if(__instance == nullptr) {
            __name = name;
            __instance = new Singleton1();
        }
    }

    std::string getName() const{
        return __instance->myName();
    }

    std::string id(){
        std::stringstream ss;
        ss<<__instance;
        return ss.str();
    }
private:
    std::string  myName(){
        return __name;
    }
    Singleton1(){}
    static std::string __name;
    static Singleton1* __instance;
};

std::string Singleton1::__name = "";
Singleton1* Singleton1::__instance = nullptr;

/**
 * Test of Case 1
 * Output:
 *      Tony Tony
 *      id(tony) == id(karry)
 *      tony == karry: True
 */
void test1(){
    Singleton1 tony = Singleton1("Tony");
    Singleton1 karry = Singleton1("Karry");
    std::string com_res = tony.id() == karry.id()?"True":"False";

    printf("%s %s\n", tony.getName().c_str(), karry.getName().c_str());
    printf("id(tony): %s id(karry) %s\n", tony.id().c_str(), karry.id().c_str());
    printf("tony == karry: %s\n", com_res.c_str());
}


int main(int argc, char *argv[]){
    test1();
}


