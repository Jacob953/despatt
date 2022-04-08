//
// Created by 20580 on 2022/4/7.
//
#include "singleton.h"
#include <iostream>

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

/**
 * Test of 2 get singleton by API getInstance
 *
 * Output:
 *      Tony Tony
 *      id(tony) == id(karry)
 *      tony == karry: True
 */
void test2(){
    Singleton2 *tony = Singleton2::getInstance("Tony");
    Singleton2 *karry = Singleton2::getInstance("Karry");
    std::string com_res = tony->id() == karry->id()?"True":"False";
    printf("%s %s\n", tony->getName().c_str(), karry->getName().c_str());
    printf("id(tony): %s id(karry) %s\n", tony->id().c_str(), karry->id().c_str());
    printf("tony == karry: %s\n", com_res.c_str());
}


// Class deca
class TestClass: public Object{
    DECLARE_CLASS()

public:
    TestClass(){}
    void setName(std::string name){ __name = name; }
    std::string getName() const { return __name; }
private:
    std::string __name;
};

IMPLEMENT_CLASS("TestCase", TestClass)

/**
 * Test of 3 Singleton Decorator
 *
 * Output:
 *      Karry Karry
 *      id(tony) == id(karry)
 *      tony == karry: True
 */
void test3(){
    TestClass *tony = (TestClass*)SingletonDecorator::wrapperSingleton("TestCase");
    TestClass *karry = (TestClass*)SingletonDecorator::wrapperSingleton("TestCase");
    tony->setName("Tony");
    karry->setName("Karry");
    std::string com_res = tony == karry?"True":"False";
    printf("%s %s\n", tony->getName().c_str(), karry->getName().c_str());
    std::cout<<"id(tony): "<<tony<<" id(karry): "<<karry<<std::endl;
    printf("tony == karry: %s\n", com_res.c_str());
}

/**
 * Tips: MSVC and GCC can both compile it, but when i run the exe file that use MSVC compiled, it will exit at error
 *       and the error will locate at singleton.cpp:74, but i don't know why, if you have any suggestion, please give
 *       Pull request
 */
int main(int argc, char *argv[]){
    printf("Execute test1 [__instance] the standard out put is:\n");
    printf("Tony Tony\n");
    printf("id(tony) == id(karry)\n");
    printf("tony == karry: True\n");
    printf("======================================\n");
    test1();
    printf("======================================\n");

    printf("Execute test2 [getInstance] the standard out put is:\n");
    printf("Tony Tony\n");
    printf("id(tony) == id(karry)\n");
    printf("tony == karry: True\n");
    printf("The execute result is: \n");
    printf("======================================\n");
    test2();
    printf("======================================\n");

    printf("Execute test3 [wrapper] the standard out put is:\n");
    printf("Karry Karry\n");
    printf("id(tony) == id(karry)\n");
    printf("tony == karry: True\n");
    printf("The execute result is: \n");
    printf("======================================\n");
    test3();
    printf("======================================\n");
}
