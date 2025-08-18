#include <iostream>
#include <vector>
using namespace std;

// Abstract base class
class Employee {
protected:
    string name;
    double salary;

public:
    Employee(string n, double s) : name(n), salary(s) {}
    virtual void work()=0; // pure virtual
    virtual void showInfo() {
        cout << name << " earns " << salary << endl;
    }
    virtual ~Employee() {
        cout<<"Employee Destructor\n";
    }
};

// Derived class
class Developer : public Employee {
private:
    string language;
public:
    Developer(string n, double s, string lang)
        : Employee(n, s), language(lang) {}
    void work() override {
        cout << name << " is coding in " << language << endl;
    }
    void showInfo() override { // overriding the base version
        cout << name << " earns " << salary 
             << " and codes in " << language << endl;
    }
    ~Developer() {
        cout<<"Developer Destructor"<<endl;
    }
};

// Derived class
class Manager : public Employee {
public:
    Manager(string n, double s) : Employee(n, s) {}
    void work() override {
        cout << name << " is managing projects" << endl;
    }
    ~Manager() {
        cout<<"Manager Destructor"<<endl;
    }
};

int main() {
    vector<Employee*> team;
    team.push_back(new Developer("Alice", 70000, "C++"));
    team.push_back(new Manager("Bob", 90000));

    for (auto emp : team) {
        emp->showInfo();
        emp->work();
    }
    for (auto emp : team) delete emp; // Cleanup
}
