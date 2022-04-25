/**
* Author: arqqqq
* Date: 2022/4/25
*/

#ifndef DESPATT_ITERATOR_H
#define DESPATT_ITERATOR_H
#include<string>
#include<vector>

using namespace std;

class NumeralSystem;
class Iterator;

/// Case 1
class Patient{
public:
    Patient(const string& name);

    string getName() const;

    void setNumber(int num);
    int getNumber() const;

    void registerClinic(NumeralSystem &system);

    void setClinic(const string& clinic);
    string getClinic() const;
private:
    string name;
    int number;
    string clinic;
};

class Iterator{
public:
    Iterator(vector<Patient> *patients);
    ~Iterator();
    Patient current();

    void toBegin();
    void toEnd();

    bool next();
    bool previous();
private:
    int len;
    vector<Patient> *data;
    int cur_Index;
};

const vector<string> clinic{"Clinic Room 1", "Clinic Room 2", "Clinic Room 3"};

class NumeralSystem{
public:
    NumeralSystem(const string& name);
    ~NumeralSystem();

    void pushPatient(Patient patient);

    Iterator getIterator() const;
private:
    vector<Patient> *patients;
    string name;
    int curNum;
};

#endif //DESPATT_ITERATOR_H
