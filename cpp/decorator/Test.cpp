/**
 * Author: arqqqq
 * Date: 2022/4/18
 */

#include "Decorator.h"

/**
 * Test Case 1
 * Output:
 *  I am C++ Software Developer engineer Tony
 *  My wear is
 *  A pair of khaki slacks
 *  A black belt with silver pin buckles
 *  A pair of dark casual leather shoes
 *  A white shirt
 *  A fuchsia knit sweater
 *  A pair of square black-rimmed glasses
 *
 *  I am Wells professor
 *  My wear is
 *  A pair of dark casual leather shoes
 *  A white shirt
 *  A pair of square black-rimmed glasses
 */
 void test1(){
     shared_ptr<Person> tony = shared_ptr<Person>((Person*) new Engineer("Tony", "C++ Software Developer"));
     shared_ptr<Person> pant = shared_ptr<Person>((Person*) new CasualPantDecorator(tony));
     shared_ptr<Person> belt = shared_ptr<Person>((Person*)new BeltDecorator(pant));
     shared_ptr<Person> shoes = shared_ptr<Person>((Person*)new LeatherShoesDecorator(belt));
     shared_ptr<Person> shirt = shared_ptr<Person>((Person*)new WhiteShirtDecorator(shoes));
     shared_ptr<Person> sweater = shared_ptr<Person>((Person*)new KnittedSweaterDecorator(shirt));
     shared_ptr<Person> glasses = shared_ptr<Person>((Person*)new GlassesDecorator(sweater));
     glasses->wear();

     printf("\n");
     shared_ptr<Person> decorateTeacher = shared_ptr<Person>((Person*)new Teacher("Wells", "professor"));
     shared_ptr<Person> shoes1 = shared_ptr<Person>((Person*)new LeatherShoesDecorator(decorateTeacher));
     shared_ptr<Person> shirt1 = shared_ptr<Person>((Person*)new WhiteShirtDecorator(shoes1));
     shared_ptr<Person> glasses1 = shared_ptr<Person>((Person*)new GlassesDecorator(shirt1));
     glasses1->wear();
 }

int main(int argc, char *argv[]){
    test1();
}
