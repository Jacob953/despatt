/**
 * Author: arqqqq
 * Date:   2022/4/13
 */

#include "Responsibility.h"

LeaveTips::LeaveTips(const std::string &name, const std::string &reason, int leave_day):__name(name),
                                                                                        __reason(reason),
                                                                                        __leave_days(leave_day){
    __leader = nullptr;
}

void LeaveTips::setLeader(std::shared_ptr<Manager> leader) {
    __leader = std::move(leader);
}

std::string LeaveTips::getName() const { return __name; }

std::string LeaveTips::getReason() const { return __reason; }

int LeaveTips::getDays() const { return __leave_days; }

void LeaveTips::request() {
    printf("%s apply for leave %d day. leave reason: %s\n", __name.c_str(), __leave_days, __reason.c_str());
    if( __leader != nullptr ){
        __leader->handleRequest(*this);
    }else{
        printf("No one handle this application!\n");
    }
}

Manager::Manager(const std::string &name, const std::string &company):__name(name),
                                                                     __company(company){
    nextManager = nullptr;
}

std::string Manager::getName() const { return __name; }

std::string Manager::getCompany() const { return __company; }

void Manager::setNextHandler(std::shared_ptr<Manager> handle) {
    nextManager = std::move(handle);
}

std::shared_ptr<Manager> Manager::getNextHandler() const { return std::move(nextManager); }

Supervisor::Supervisor(const std::string &name, const std::string &company): Manager(name, company){}

void Supervisor::handleRequest(const LeaveTips &tips) const {
    if(tips.getDays() <= 2)
        printf("Agree %s's apply, Signatories: %s Title: (%s)\n", tips.getName().c_str(), __name.c_str(), __company.c_str());
    if(nextManager != nullptr)
        nextManager->handleRequest(tips);

}

DepartmentManager::DepartmentManager(const std::string &name, const std::string &company): Manager(name, company){}

void DepartmentManager::handleRequest(const LeaveTips &tips) const {
    if(tips.getDays() > 2 && tips.getDays() <= 5)
        printf("Agree %s's apply, Signatories: %s Title: (%s)\n", tips.getName().c_str(), __name.c_str(), __company.c_str());
    if(nextManager != nullptr)
            nextManager->handleRequest(tips);
}

CEO::CEO(const std::string &name, const std::string &company): Manager(name, company){}

void CEO::handleRequest(const LeaveTips &tips) const {
    if(tips.getDays() > 5 && tips.getDays() <= 22)
        printf("Agree %s's apply, Signatories: %s Title: (%s)\n", tips.getName().c_str(), __name.c_str(), __company.c_str());
    if(nextManager != nullptr)
        nextManager->handleRequest(tips);
}

Administrator::Administrator(const std::string &name, const std::string &company): Manager(name, company){}

void Administrator::handleRequest(const LeaveTips &tips) const {
    printf("%s's leave request has been reviewed and is true! Filed for processing, Signatories: %s Title: (%s)\n\n", tips.getName().c_str(), __name.c_str(), __company.c_str());
}
