/**
 * Author: arqqqq
 * Date:   2022/4/14
 */
#ifndef DESPATT_RESFRAME_H
#define DESPATT_RESFRAME_H
#include <string>
#include <memory>

class Responsible;

class Request{
public:
    Request(const std::string& name, int dayoff, const std::string& reason);
    std::string getName() const;
    int getDayOff() const;
    std::string getReason() const;
private:
    std::string __name;
    std::string __reason;
    int __dayoff;
};

using Handler = std::shared_ptr<Responsible>;
class Responsible{
public:
    std::string getName() const;
    std::string getTitle() const;
    void setNextHandler(std::shared_ptr<Responsible> handler);
    std::shared_ptr<Responsible> getNextHandler() const;
    virtual void handlerRequest(Request &req) = 0;
protected:
    Responsible(const std::string& name, const std::string& title);
private:
    std::string __name;
    std::string __title;
    Handler __nextHandler;
};

/* Requester */
using Leader = std::shared_ptr<Responsible>;
class Person{
public:
    Person(const std::string& name);
    void setName(const std::string& name);
    std::string getName() const;
    void setLeader(Leader leader);
    Leader getLeader() const;
    void sendRequest(Request res);
private:
    std::string __name;
    Leader __leader;
};

class Supervisor1: public Responsible{
public:
    Supervisor1(const std::string& name, const std::string& title);
    void handlerRequest(Request &req) override;
};

class DepartmentManager1: public Responsible{
public:
    DepartmentManager1(const std::string& name, const std::string& title);
    void handlerRequest(Request &req) override;
};

class CEO1: public Responsible{
public:
    CEO1(const std::string& name, const std::string& title);
    void handlerRequest(Request &req) override;
};

class Administrator1: public Responsible{
public:
    Administrator1(const std::string& name, const std::string& title);
    void handlerRequest(Request &req) override;
};
#endif //DESPATT_RESFRAME_H
