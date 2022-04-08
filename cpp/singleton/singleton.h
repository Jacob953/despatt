/**
 * Author: arqqqq
 * Date:   2022/4/7
 */

#ifndef DESPATT_SINGLETON_H
#define DESPATT_SINGLETON_H
#include<iostream>
//#include<mutex>


/**
 * Case 1 Singleton1
 */
class Singleton1{
public:
    Singleton1(std::string name);
    std::string getName();
    std::string id();

private:
    std::string  myName() const;
    Singleton1();
    static std::string __name;
    static Singleton1* __instance;
};

/**
 * Case 2 use GetInstance to get the singleton
 */
class Singleton2{
public:
    static Singleton2* getInstance(std::string name);
    std::string getName() const;
    std::string id();

private:
    Singleton2(std::string name);
    static Singleton2* __instance;
//    static std::mutex lock;
    std::string __name;
};

/**
 * Case 3 Singleton Decorator Definition
 */

#define DECLARE_CLASS() \
    protected:          \
        static ClassInfo ms_classinfo; \
    public:             \
        static Object*  CreateObject();

#define IMPLEMENT_CLASS(interface_name, class_name) \
    ClassInfo class_name::ms_classinfo(interface_name, (ObjectConstructorFn)class_name::CreateObject); \
    Object* class_name::CreateObject()              \
        { return new class_name(); }

class Object;
class ClassInfo;
typedef Object* (*ObjectConstructorFn)();

class Object{
protected:
    Object(){};
public:
    virtual ~Object(){}
    static void Register(ClassInfo* ci);
    static Object* CreateObject(const std::string name);
};

class ClassInfo{
public:
    ClassInfo(const std::string name, ObjectConstructorFn ctor);
    Object* CreateObject() const;

public:
    std::string m_classname;
    ObjectConstructorFn m_ctor;
};

class SingletonDecorator{
public:
    static Object* wrapperSingleton(const std::string class_name);
};



#endif //DESPATT_SINGLETON_H
