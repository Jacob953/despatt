/**
 * Author: arqqqq
 * Date:  2022/4/17
 */

#include "Proxy.h"

/* Class ReceiverParcel */
ReceiveParcel::ReceiveParcel(const string &name): __name(name){}

string ReceiveParcel::getName() const { return __name; }

/* Class TonyReception */
TonyReception::TonyReception(const string &name, const string &phone_number): ReceiveParcel(name),__phone_number(phone_number){}

string TonyReception::getPhoneNumber() const { return __phone_number; }

void TonyReception::receive(const string &parcelContent) {
    printf("Package Owner: %s\nPhone:%s\n", getName().c_str(), __phone_number.c_str());
    printf("Receive a package: %s\n", parcelContent.c_str());
}

/* Wendy Reception */
WendyReception::WendyReception(const string &name, shared_ptr<ReceiveParcel> receiver): ReceiveParcel(name){
    __receiver = std::move(receiver);
}

void WendyReception::receive(const string &parcelContent) {
    if(__receiver != nullptr){
        printf("I am the friend of %s, i will proxy he to receive this\n", __receiver->getName().c_str());
        __receiver->receive(parcelContent);
        printf("Proxy receiver: %s\n", getName().c_str());
    }

}
