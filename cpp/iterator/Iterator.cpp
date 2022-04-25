/**
* Author: arqqqq
* Date: 2022/4/25
*/

#include "Iterator.h"
#include <assert.h>

/// Class Patient

Patient::Patient(const string &name):name(name), clinic(""), number(-1){}

string Patient::getName() const { return name; }

int Patient::getNumber() const { return number; }

void Patient::setNumber(int num) { number = num; }

string Patient::getClinic() const { return clinic; }

void Patient::setClinic(const string &clinic) { this->clinic = clinic; }

void Patient::registerClinic(NumeralSystem &system) {
    system.pushPatient(*this);
}

/// Class Iterator

Iterator::Iterator(vector<Patient> *patients):data(patients),cur_Index(-1){}

Iterator::~Iterator() { data = nullptr; }

Patient Iterator::current() {
    return data->at(cur_Index);
}

bool Iterator::next() {
    if(cur_Index >= static_cast<int>(data->size()-1))
        return false;
    cur_Index++;
    return true;
}

bool Iterator::previous() {
    if(cur_Index <= 0)
        return false;
    cur_Index--;
    return true;
}

void Iterator::toBegin() {
    cur_Index = -1;
}

void Iterator::toEnd() {
    cur_Index = static_cast<int>(data->size());
}

/// Class NumeralSystem
NumeralSystem::NumeralSystem(const string& name):name(name){
    patients = new vector<Patient>();
    curNum = 0;
}

NumeralSystem::~NumeralSystem() {
    delete patients;
    patients = nullptr;
}

Iterator NumeralSystem::getIterator() const {
    return Iterator(patients);
}

void NumeralSystem::pushPatient(Patient patient) {
    patient.setNumber(curNum+1);
    string cli = clinic[curNum%clinic.size()];
    patient.setClinic(cli);

    curNum++;
    patients->push_back(patient);

    printf("%s, Hello! you are register successfully at %s! Number: %04d\n", patient.getName().c_str(),
           name.c_str(), curNum);
}
