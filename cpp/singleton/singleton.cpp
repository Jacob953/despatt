/**
 * Author: arqqqq
 * Date: 2022/4/7
 */

#include "singleton.h"
#include <sstream>

/**
 * Case 1 Singleton1
 */
std::string Singleton1::__name;
Singleton1* Singleton1::__instance = nullptr;

Singleton1::Singleton1(std::string name) {
    if(__instance == nullptr){
        __name = name;
        __instance = new Singleton1();
    }
}

Singleton1::Singleton1() {}

std::string Singleton1::getName() {
    return __instance->myName();
}

std::string Singleton1::id() {
    std::stringstream ss;
    ss<<__instance;
    return ss.str();
}

std::string Singleton1::myName() const {return __name;}


/**
 * Case 2 use GetInstance to get the singleton, Thread-Safe
 */

Singleton2* Singleton2::__instance= nullptr;
//std::mutex Singleton2::lock;

Singleton2::Singleton2(std::string name):__name(name) {}

std::string Singleton2::getName() const { return __name; }

std::string Singleton2::id() {
    std::stringstream ss;
    ss<<this;
    return ss.str();
}

Singleton2 *Singleton2::getInstance(std::string name) {
    if(__instance == nullptr){
//        std::lock_guard<std::mutex> lk(lock);
//        if(__instance == nullptr){
        __instance = new Singleton2(name);
//        }
    }
    return __instance;
}

/**
 * Case 3 Singleton Decorator
 * Code Reference: https://blog.csdn.net/zhangqi_gsts/article/details/53395297
 */
#include <map>

std::map<std::string, ClassInfo*> objmaps{};
std::map<std::string, Object*> __instances{};

void Object::Register(ClassInfo *ci) {
    if(ci != NULL && objmaps.find(ci->m_classname) == objmaps.end()){
        objmaps.insert(std::map<std::string, ClassInfo*>::value_type(ci->m_classname, ci));
    }
}

Object* Object::CreateObject(std::string name) {
    std::map<std::string, ClassInfo*>::const_iterator iter = objmaps.find(name);
    if(iter != objmaps.end()){
        return iter->second->CreateObject();
    }
    return NULL;
}

ClassInfo::ClassInfo(const std::string className, ObjectConstructorFn ctor)
        :m_classname(className), m_ctor(ctor){
    Object::Register(this);
}

Object *ClassInfo::CreateObject() const {
    return m_ctor? (*m_ctor)() : NULL;
}

Object *SingletonDecorator::wrapperSingleton(const std::string class_name) {
    if(__instances.find(class_name) == __instances.end()){
        Object *obj = Object::CreateObject(class_name);
        __instances.insert(std::map<std::string, Object*>::value_type(class_name, obj));
    }
    return __instances[class_name];
}
