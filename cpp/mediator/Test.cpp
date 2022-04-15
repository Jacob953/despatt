/**
 * Author: arqqqq
 * Date: 2022/4/15
 */

#include "Mediator.h"

/**
 * Test Case 1
 * Output:
 *      ZhangSan published the rent house info in Love my home
 *      Area: 20 m^2, Price: 2500, Window: Yes, Bathroom: Yes, Kitchen: Yes, Address: Shang di West, HouseOwner: ZhangSan
 *
 *      LiSi published the rent house info in Love my home
 *      Area: 16 m^2, Price: 1800, Window: Yes, Bathroom: Yes, Kitchen: Yes, Address: Contemporary city home, HouseOwner: LiSi
 *
 *      WangWu published the rent house info in Love my home
 *      Area: 18 m^2, Price: 2600, Window: Yes, Bathroom: Yes, Kitchen: Yes, Address: Jin yu mei and the garden, HouseOwner: WangWu
 *
 *      I am Tony. i am looking for the house it maybe Area: 18 m^2, Has bathroom, Has window, Has kitchen, Head South, Price in 2000
 *
 *      Love my home search property House for you...
 *      Area: 20 m^2, Price: 2500, Window: Yes, Bathroom: Yes, Kitchen: Yes, Address: Shang di West, HouseOwner:
 *      Area: 16 m^2, Price: 1800, Window: Yes, Bathroom: Yes, Kitchen: Yes, Address: Contemporary city home, HouseOwner:
 *      Area: 18 m^2, Price: 2600, Window: Yes, Bathroom: Yes, Kitchen: Yes, Address: Jin yu mei and the garden, HouseOwner:
 *
 *      Find property house to rent!
 *
 *      Tony sign contract with Love my home in Jin yu mei and the garden's house
 *      The lease: 2
 *      During the time Tony have the right to use it!
 */
 void test1(){
    HousingAgency myHome = HousingAgency("Love my home");
    HouseOwner zhangsan = HouseOwner("ZhangSan", "Shang di West");
    zhangsan.setHouseInfo(20, 2500, HAS, HAS, HAS);
    zhangsan.publishHouseInfo(myHome);

    HouseOwner lisi = HouseOwner("LiSi", "Contemporary city home");
    lisi.setHouseInfo(16, 1800, HAS, HAS, HAS);
    lisi.publishHouseInfo(myHome);

    HouseOwner wangwu = HouseOwner("WangWu", "Jin yu mei and the garden");
    wangwu.setHouseInfo(18, 2600, HAS, HAS, HAS);
    wangwu.publishHouseInfo(myHome);

    Custom tony("Tony");
    std::vector<HInfo> hinfos = tony.findHouse("Area: 18 m^2, Has bathroom, Has window, Has kitchen, Head South, Price in 2000\n", myHome);
    printf("Find property house to rent!\n");
    HInfo info = tony.seeHouse(hinfos);
    tony.signContract(info,myHome, "2");
 }


int main(int argc, char* argv[]){
    test1();
}
