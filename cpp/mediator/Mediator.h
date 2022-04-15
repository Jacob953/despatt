/**
 * Author: arqqqq
 * Date: 2022/4/15
 */

#ifndef DESPATT_MEDIATOR_H
#define DESPATT_MEDIATOR_H
#include <string>
#include <vector>
#include <memory>

#define HAS true
#define NO false
class HouseOwner;

using Owner = std::shared_ptr<HouseOwner>;

class HouseInfo{
public:
    HouseInfo(int area,
              int price,
              bool hasWindow,
              bool bathroom,
              bool kitchen,
              const std::string& address,
              Owner owner);
    std::string getAddress() const;
    Owner getHouseOwner() const;
    void showInfo(bool isShowOwner = true) const;
private:
    int __area;
    int __price;
    bool __hasWindow;
    bool __bathroom;
    bool __kitchen;
    std::string __address;
    Owner __owner;
};

using HInfo = std::shared_ptr<HouseInfo>;

class HousingAgency{
public:
    HousingAgency(const std::string& name);
    std::string getName() const;
    void addHouseInfo(HInfo &info);
    void removeHouseInfo(HInfo info);
    std::string getSearchCondition(const std::string& description);
    std::vector<HInfo> getMatchInfos(const std::string& searchCondition) const;
    void signContract(HInfo info, const std::string& time) const;
    void signContracts(const std::string& time) const;
private:
    std::vector<HInfo> __houseInfos;
    std::string __name;
};


class HouseOwner{
public:
    HouseOwner(const std::string& name,
               const std::string& address);
    std::string getName() const;
    std::string getAddress() const;
    void setHouseInfo(int area, int price, bool hasWindow, bool bathroom, bool kitchen);
    void publishHouseInfo(HousingAgency &agency);
private:
    std::string __name;
    std::string __address;
    HInfo __houseInfo;
};

class Custom{
public:
    Custom(const std::string& name);
    std::string getName() const;
    std::vector<HInfo> findHouse(const std::string& desc, HousingAgency& agency);
    HInfo seeHouse(std::vector<HInfo> houseInfos);
    void signContract(HInfo &houseInfo, HousingAgency& agency, const std::string& time);
private:
    std::string __name;
};
#endif //DESPATT_MEDIATOR_H
