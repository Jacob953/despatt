/**
 * Author: arqqqq
 * Date:   2022/4/16
 */

#include "Proxy.h"

/**
 * Test Case 1
 * Output:
 *      I am the friend of Tony, i will proxy he to receive this
 *      Package Owner: Tony
 *      Phone:18512345678
 *      Receive a package: Snow Ground Shoes
 *      Proxy receiver: wendy
 */
 void test1(){
     shared_ptr<ReceiveParcel> tony = shared_ptr<ReceiveParcel>((ReceiveParcel*) new TonyReception("Tony", "18512345678"));
     WendyReception wendy("wendy", tony);
     wendy.receive("Snow Ground Shoes");
 }

int main(int argc, char *argv[]){
    test1();
}
