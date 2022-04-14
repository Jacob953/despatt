/**
 * Author: arqqqq
 * Date: 2022/4/13
 */
#ifndef DESPATT_RESPONNSIBILITY_H
#define DESPATT_RESPONNSIBILITY_H
#include <string>
#include <memory>

/**
 * Case 1 Simulate the leave process
 */
class Manager;

 /* Leave slip */
 struct LeaveTips{
    std::string __name;                         // The name of applicants
    std::string __reason;                       // The reason why leave
    int __leave_days;                           // The leave days
    std::shared_ptr<Manager> __leader;          // The handle leader
    LeaveTips(const std::string& name, const std::string& reason, int leave_day);
    void setLeader(std::shared_ptr<Manager> leader);
    std::string getName() const;
    std::string getReason() const;
    int getDays() const;
    void request();
 };

 class Manager{
 public:
     std::string getName() const;
     std::string getCompany() const;
     void setNextHandler(std::shared_ptr<Manager> handle);
     std::shared_ptr<Manager> getNextHandler() const;
     virtual void handleRequest(const LeaveTips &tips) const = 0;
 protected:
     Manager(const std::string& name, const std::string& company);
     std::string __name;
     std::string __company;
     std::shared_ptr<Manager> nextManager;
 };

class Supervisor: public Manager{
public:
    Supervisor(const std::string& name, const std::string& company);
    void handleRequest(const LeaveTips &tips) const override;
};

class DepartmentManager: public Manager{
public:
    DepartmentManager(const std::string& name, const std::string& company);
    void handleRequest(const LeaveTips &tips) const override;
};

class CEO: public Manager{
public:
    CEO(const std::string& name, const std::string& company);
    void handleRequest(const LeaveTips &tips) const override;
};

class Administrator: public Manager{
public:
    Administrator(const std::string& name, const std::string& company);
    void handleRequest(const LeaveTips &tips) const override;
};

#endif //DESPATT_RESPONNSIBILITY_H
