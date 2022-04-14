/**
 * Author: arqqqq
 * Date: 2022/4/14
 */

#include "ResFrame.h"
#include <iostream>


Request::Request(const std::string &name, int dayoff, const std::string &reason):
                                                        __name(name), __dayoff(dayoff), __reason(reason){}

std::string Request::getName() const { return __name; }

std::string Request::getReason() const { return __reason; }

int Request::getDayOff() const { return __dayoff; }

Responsible::Responsible(const std::string &name, const std::string &title): __name(name),
                                                                            __title(title),
                                                                            __nextHandler(nullptr){}

std::string Responsible::getName() const { return __name; }

std::string Responsible::getTitle() const { return __title; }

std::shared_ptr<Responsible> Responsible::getNextHandler() const { return std::move(__nextHandler); }

void Responsible::setNextHandler(std::shared_ptr<Responsible> handler) { __nextHandler = std::move(handler); }


Person::Person(const std::string &name): __name(name){}

void Person::setName(const std::string &name) { __name = std::move(name); }

std::string Person::getName() const { return std::move(__name); }

void Person::setLeader(Leader leader) { __leader = std::move(leader); }

Leader Person::getLeader() const { return std::move(__leader); }

void Person::sendRequest(Request res) {
    printf("%s apply for leave %d days, The reason: %s\n", __name.c_str(), res.getDayOff(), res.getReason().c_str());
    if(__leader != nullptr){
        __leader->handlerRequest(res);
    }
}

Supervisor1::Supervisor1(const std::string &name, const std::string &title): Responsible(name, title){}

void Supervisor1::handlerRequest(Request &req) {
    if(req.getDayOff() <= 2)
        printf("Agree %s's apply, Signatories: %s Title: (%s)\n", req.getName().c_str(), getName().c_str(), getTitle().c_str());
    if(getNextHandler() != nullptr)
        getNextHandler()->handlerRequest(req);
}


DepartmentManager1::DepartmentManager1(const std::string &name, const std::string &title): Responsible(name, title){}

void DepartmentManager1::handlerRequest(Request &req) {
    if(req.getDayOff() > 2 && req.getDayOff() <= 5)
        printf("Agree %s's apply, Signatories: %s Title: (%s)\n", req.getName().c_str(), getName().c_str(), getTitle().c_str());
    if(getNextHandler() != nullptr)
        getNextHandler()->handlerRequest(req);
}

CEO1::CEO1(const std::string &name, const std::string &title): Responsible(name, title){}

void CEO1::handlerRequest(Request &req) {
    if(req.getDayOff() > 5 && req.getDayOff() <= 22)
        printf("Agree %s's apply, Signatories: %s Title: (%s)\n", req.getName().c_str(), getName().c_str(), getTitle().c_str());
    if(getNextHandler() != nullptr)
        getNextHandler()->handlerRequest(req);
}

Administrator1::Administrator1(const std::string &name, const std::string &title): Responsible(name, title){}

void Administrator1::handlerRequest(Request &req) {
    printf("%s's leave request has been reviewed and is true! Filed for processing, Signatories: %s Title: (%s)\n\n", req.getName().c_str(), getName().c_str(), getTitle().c_str());
}
