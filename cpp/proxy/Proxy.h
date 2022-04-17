/**
 * Author: arqqqq
 * Date:  2022/4/17
 */

#ifndef DESPATT_PROXY_H
#define DESPATT_PROXY_H
#include <string>
#include <memory>

using namespace std;

class ReceiveParcel{
public:
    ReceiveParcel(const string& name);
    string getName() const;
    virtual void receive(const string& parcelContent) = 0;
private:
    string __name;
};


class TonyReception: public ReceiveParcel{
public:
    TonyReception(const string& name, const string& phone_number);\
    string getPhoneNumber() const;
    void receive(const string &parcelContent) override;
private:
    string __phone_number;
};


class WendyReception: public ReceiveParcel{
public:
    WendyReception(const string& name, shared_ptr<ReceiveParcel> receiver);
    void receive(const string &parcelContent) override;
private:
    shared_ptr<ReceiveParcel> __receiver;
};


#endif //DESPATT_PROXY_H
