/**
 * Author: arqqq
 * Date: 2022/4/6
 */
#include<string>
#include<sstream>
#include<iostream>
#include<thread>
#include<mutex>

/**
 * Case 1 Singleton1
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

/**
 * Case 2, use GetInstance to get the SINGLETON, Thread-Safe
 */
class Singleton2{
public:
    static Singleton2* getInstance(std::string name){
        if(__instance == nullptr){
            std::lock_guard<std::mutex> lk(lock);
            if(__instance == nullptr){
                __instance = new Singleton2(name);
            }
        }
        return __instance;
    }

    std::string getName() const{
        return __name;
    }

    std::string id(){
        std::stringstream ss;
        ss<<__instance;
        return ss.str();
    }

private:
    Singleton2(std::string name):__name(name){}
    static Singleton2* __instance;
    static std::mutex lock;
    std::string __name;
};

Singleton2* Singleton2::__instance= nullptr;
std::mutex Singleton2::lock;

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

/**
 * Case 3 Singleton Decorator 装饰器模式,实现参考了博客https://blog.csdn.net/zhangqi_gsts/article/details/53395297
 */
#include<map>

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

std::map<std::string, ClassInfo*> objmaps{};
class Object{
protected:
    Object(){}
public:
    virtual ~Object(){}
    static void Register(ClassInfo* ci);
    static Object* CreateObject(std::string name);
};

class ClassInfo{
public:
    ClassInfo(const std::string className, ObjectConstructorFn ctor);
    Object* CreateObject() const;
public:
    std::string m_className;
    ObjectConstructorFn m_ctor;
};

void Object::Register(ClassInfo *ci) {
    if(ci != NULL && objmaps.find(ci->m_className) == objmaps.end()){
        objmaps.insert(std::map<std::string, ClassInfo*>::value_type(ci->m_className, ci));
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
            :m_className(className), m_ctor(ctor){
    Object::Register(this);
}

Object *ClassInfo::CreateObject() const {
    return m_ctor? (*m_ctor)() : NULL;
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


std::map<std::string, Object*> __instance{};
class SingletonDecorator{
public:
    static Object* wrapperSingleton(std::string class_name){
        if(__instance.find(class_name) == __instance.end()){
            Object *obj = Object::CreateObject(class_name);
            __instance.insert(std::map<std::string, Object*>::value_type(class_name, obj));
        }
        return __instance[class_name];
    }
};


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


int main(int argc, char *argv[]){
    test1();
    test2();
    test3();
}


