/**
 * Author: arqqqq
 * Date: 2022/4/25
 */

#include "Iterator.h"

/**
 * Test case of 2
 * Output:
 *      Lily, Hello! you are register successfully at Registered Air Mail! Number: 0001
 *      Pony, Hello! you are register successfully at Registered Air Mail! Number: 0002
 *      Nick, Hello! you are register successfully at Registered Air Mail! Number: 0003
 *      Tony, Hello! you are register successfully at Registered Air Mail! Number: 0004
 *
 *      Iterator form front to end
 *      Next patient: Lily Number: 0001 Please see doctor at clinic Clinic Room 1
 *      Next patient: Pony Number: 0002 Please see doctor at clinic Clinic Room 2
 *      Next patient: Nick Number: 0003 Please see doctor at clinic Clinic Room 3
 *      Next patient: Tony Number: 0004 Please see doctor at clinic Clinic Room 1
 *      Iterator form end to front
 *      Next patient: Tony Number: 0004 Please see doctor at clinic Clinic Room 1
 *      Next patient: Nick Number: 0003 Please see doctor at clinic Clinic Room 3
 *      Next patient: Pony Number: 0002 Please see doctor at clinic Clinic Room 2
 *      Next patient: Lily Number: 0001 Please see doctor at clinic Clinic Room 1
 */
 void test1(){
     NumeralSystem system("Registered Air Mail");
     Patient p1("Lily");
     p1.registerClinic(system);
     Patient p2("Pony");
     p2.registerClinic(system);
     Patient p3("Nick");
     p3.registerClinic(system);
     Patient p4("Tony");
     p4.registerClinic(system);

     printf("\n");

     Iterator it = system.getIterator();
     printf("Iterator form front to end\n");
     it.toBegin();

     while(it.next()){
         Patient p = it.current();
         printf("Next patient: %s Number: %04d Please see doctor at clinic %s\n",
               p.getName().c_str(), p.getNumber(), p.getClinic().c_str());
     }
     printf("Iterator form end to front\n");
     it.toEnd();
     while(it.previous()){
         Patient p = it.current();
         printf("Next patient: %s Number: %04d Please see doctor at clinic %s\n",
                p.getName().c_str(), p.getNumber(), p.getClinic().c_str());
     }
 }

int main(int argc, char *argv[]){
    test1();
}
