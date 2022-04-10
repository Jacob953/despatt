/**
 * Author: arqqqq
 * Date: 2022/4/10
 */
#include "Observer.h"
#include "ObserverFrame.h"
/**
 * Test Case 1
 * Output:
 *      CurrentTemperature 40'C
 *      CurrentTemperature 60'C
 *      Di Di Di!
 *      The water has been boiled, the temperature is normal and it is time to take a bath
 *      CurrentTemperature 100'C
 *      Di Di Di!
 *      The water is boiling, it can be used to drinking!
 */
 void testWaterHeater(){
    WaterHeater heater;
    Observer* washingObs = new WashingMode();
    Observer* drinkingObs = new DrinkingMode();
    heater.addObserver(washingObs);
    heater.addObserver(drinkingObs);

    heater.setTemperature(40);
    heater.setTemperature(60);
    heater.setTemperature(100);
 }


 /**
  * Test Case 2 base on observer frame
  * Output:
  *     output is same as previous comment's output
  */
 void testWaterHeater1(){
     WaterHeater1 heater;
     observerframe::Observer* washingObs = new WashingMode1();
     observerframe::Observer* drinkingObs = new DrinkingMode1();
     heater.addObserver(washingObs);
     heater.addObserver(drinkingObs);

     heater.setTemperature(40);
     heater.setTemperature(60);
     heater.setTemperature(100);
 }


int main(){
    testWaterHeater();
    printf("===================\n");
    testWaterHeater1();
}
