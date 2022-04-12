/**
 * Author: arqqqq
 * Date: 2022/4/12
 */
#include "State.h"
#include "StateFrame.h"

/**
 * Test Case 1 Three state of water
 * Output:
 *      Initialize of the state Liquid
 *      I have a gentle personality! current temperature: 25 'C, I can nourish all things, and drinking me will make you more energetic...
 *      From Liquid to Solid
 *      I have a high and cold personality! current temperature: -4 'C, I am as strong as steel, like a cold-blooded animal, please use me to smash people, hehe...
 *      From Solid to Liquid
 *      I have a gentle personality! current temperature: 14 'C, I can nourish all things, and drinking me will make you more energetic...
 *      From Liquid to Gaseous
 *      I have a warm personality! current temperature: 124 'C, Flying into the sky is my lifelong dream, in which you will not see my existence, I will reach the realm of no self...
 *      From Gaseous to Liquid
 *      I have a gentle personality! current temperature: 60 'C, I can nourish all things, and drinking me will make you more energetic...
 *      From Liquid to Solid
 *      I have a high and cold personality! current temperature: -20 'C, I am as strong as steel, like a cold-blooded animal, please use me to smash people, hehe...
 */
 void test1(){
     Water water(25);
     water.behavior();
     water.setTemperature(-4);
     water.behavior();
     water.riseTemperature(18);
     water.behavior();
     water.riseTemperature(110);
     water.behavior();
     water.setTemperature(60);
     water.behavior();
     water.reduceTemperature(80);
     water.behavior();
 }

 /**
  * Test Case 2 of State frame
  * Output:
  *     output is same as above
  */
 void test2(){
     Water1 water = Water1();
     water.behavior();
     water.setTemperature(-4);
     water.behavior();
     water.riseTemperature(18);
     water.behavior();
     water.riseTemperature(110);
     water.behavior();
     water.setTemperature(60);
     water.behavior();
     water.reduceTemperature(80);
     water.behavior();
 }

int main(){
    test1();
    printf("================\n");
    test2();
}
