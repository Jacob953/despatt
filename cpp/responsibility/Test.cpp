/**
* Author: arqqqq
* Date: 2022/4/13
*/

#include "Responsibility.h"
#include "ResFrame.h"

/**
* Test Case 1
* Output:
*
*      Sunny apply for leave 1 day. leave reason: Participation in the MDCC Conference.
*      Agree Sunny's apply, Signatories: Eren Title: (Manager of client R&D department)
*      Sunny's leave request has been reviewed and is true! Filed for processing, Signatories: Nina Title: (Director of the Administrative Center)
*
*      Tony apply for leave 5 day. leave reason: There is an emergency at home!
*      Agree Tony's apply, Signatories: Bob Title: (Director of Technology R&D Center)
*      Tony's leave request has been reviewed and is true! Filed for processing, Signatories: Nina Title: (Director of the Administrative Center)
*
*      Pony apply for leave 15 day. leave reason: Study abroad.
*      Agree Pony's apply, Signatories: Helen Title: (CEO of Innovative Culture)
*      Pony's leave request has been reviewed and is true! Filed for processing, Signatories: Nina Title: (Director of the Administrative Center)
*/
void test1(){
    std::shared_ptr<Manager> supervisor = std::shared_ptr<Manager>((Manager*)new Supervisor("Eren", "Manager of client R&D department"));
    std::shared_ptr<Manager> departmentManager = std::shared_ptr<Manager>((Manager*)new DepartmentManager("Bob", "Director of Technology R&D Center"));
    std::shared_ptr<Manager> ceo = std::shared_ptr<Manager>((Manager*)new CEO("Helen", "CEO of Innovative Culture"));
    std::shared_ptr<Manager> administrator = std::shared_ptr<Manager>((Manager*)new Administrator("Nina", "Director of the Administrative Center"));

    supervisor->setNextHandler(departmentManager);
    departmentManager->setNextHandler(ceo);
    ceo->setNextHandler(administrator);

    LeaveTips l1("Sunny", "Participation in the MDCC Conference.", 1);
    l1.setLeader(supervisor);
    l1.request();

    LeaveTips l2("Tony", "There is an emergency at home!", 5);
    l2.setLeader(supervisor);
    l2.request();

    LeaveTips l3("Pony", "Study abroad.", 15);
    l3.setLeader(supervisor);
    l3.request();
}

/**
 * Test Case 2, ResFrame
 * Output:
 *      output is same as above
 */
 void test2(){
     Leader supervisor = Leader((Responsible*) new Supervisor1("Eren", "Manager of client R&D department"));
     Leader departmentLeader = Leader((Responsible*) new DepartmentManager1("Bob", "Director of Technology R&D Center"));
     Leader ceo = Leader((Responsible*)new CEO1("Helen", "CEO of Innovative Culture"));
     Leader administrator = Leader((Responsible*)new Administrator("Nina", "Director of the Administrative Center"));

     supervisor->setNextHandler(departmentLeader);
     departmentLeader->setNextHandler(ceo);
     ceo->setNextHandler(administrator);

     Person p1 = Person("Sunny");
     p1.setLeader(supervisor);
     p1.sendRequest(Request(p1.getName(), 1, "Participation in the MDCC Conference."));

     Person p2 = Person("Tony");
     p2.setLeader(supervisor);
     p2.sendRequest(Request(p2.getName(), 5, "There is an emergency at home!"));

     Person p3 = Person("Pony");
     p3.setLeader(supervisor);
     p3.sendRequest(Request(p3.getName(), 15, "Study aboard."));
 }


int main(){
    test1();
    printf("=================\n");
    test2();
}
