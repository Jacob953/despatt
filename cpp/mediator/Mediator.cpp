/**
 * Author: arqqqq
 * Date: 2022/4/15
 */

#include "Mediator.h"
#include <algorithm>

/* HouseInfo */
HouseInfo::HouseInfo(int area, int price, bool hasWindow, bool bathroom, bool kitchen, const std::string &address,
                     Owner owner):__area(area),
                                              __price(price),
                                              __hasWindow(hasWindow),
                                              __bathroom(bathroom),
                                              __kitchen(kitchen),
                                              __owner(std::move(owner)),
                                              __address(address){}

std::string HouseInfo::getAddress() const { return __address; }

Owner HouseInfo::getHouseOwner() const { return std::move(__owner); }

void HouseInfo::showInfo(bool isShowOwner) const {
    printf("Area: %d m^2, Price: %d, Window: %s, Bathroom: %s, Kitchen: %s, Address: %s, ",
           __area, __price, __hasWindow?"Yes":"No", __bathroom?"Yes":"No", __kitchen?"Yes":"No", __address.c_str());
    printf("HouseOwner: %s\n", isShowOwner?__owner->getName().c_str():"");
}


/* HousingAgency */
HousingAgency::HousingAgency(const std::string &name):__name(name){}

std::string HousingAgency::getName() const { return __name; }

void HousingAgency::addHouseInfo(HInfo &info) {
    auto it = std::find(__houseInfos.cbegin(), __houseInfos.cend(), info);
    if(it == __houseInfos.end())
        __houseInfos.push_back(info);
}

void HousingAgency::removeHouseInfo(HInfo info) {
    auto it = __houseInfos.begin();
    while(it != __houseInfos.end()){
        if(*it == info){
            __houseInfos.erase(it);
            break;
        }
        it++;
    }
}

std::string HousingAgency::getSearchCondition(const std::string &description) {
    return description;
}

std::vector<HInfo> HousingAgency::getMatchInfos(const std::string &searchCondition) const {
    printf("%s search property House for you...\n", __name.c_str());
    for(auto& it: __houseInfos){
        it->showInfo(false);
    }
    return __houseInfos;
}

void HousingAgency::signContract(HInfo info, const std::string &time) const {
    printf("%s sign a lease contract with the landlord %s in %s's house\nThe lease: %s year\nDuring the contract %s have the right to use and rent it!\n"
            ,__name.c_str(), info->getHouseOwner()->getName().c_str(), info->getAddress().c_str(), time.c_str(), __name.c_str());
}

void HousingAgency::signContracts(const std::string &time) const {
    for(auto &it: __houseInfos){
        signContract(it, time);
    }
}


/* House Owner */
HouseOwner::HouseOwner(const std::string &name, const std::string &address): __name(name),
                                                                            __address(address){}

std::string HouseOwner::getName() const { return __name; }

std::string HouseOwner::getAddress() const { return __address; }

void HouseOwner::setHouseInfo(int area, int price, bool hasWindow, bool bathroom, bool kitchen) {
    __houseInfo = std::make_shared<HouseInfo>(HouseInfo(area, price, hasWindow, bathroom, kitchen, __address, Owner(this)));
}

void HouseOwner::publishHouseInfo(HousingAgency &agency) {
    agency.addHouseInfo(__houseInfo);
    printf("%s published the rent house info in %s\n", __name.c_str(), agency.getName().c_str());
    __houseInfo->showInfo();
}

Custom::Custom(const std::string &name): __name(name){}

std::string Custom::getName() const { return __name; }

std::vector<HInfo> Custom::findHouse(const std::string &desc, HousingAgency &agency) {
    printf("I am %s. i am looking for the house it maybe %s", __name.c_str(), desc.c_str());
    return agency.getMatchInfos(desc);
}

HInfo Custom::seeHouse(std::vector<HInfo> houseInfos){
    return *(houseInfos.end()-1);
}

void Custom::signContract(HInfo &houseInfo, HousingAgency &agency, const std::string &time) {
    printf("%s sign contract with %s in %s's house\nThe lease: %s\nDuring the time %s have the right to use it!\n",
           __name.c_str(), agency.getName().c_str(), houseInfo->getAddress().c_str(), time.c_str(), __name.c_str());
}
