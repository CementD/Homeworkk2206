#include <iostream>
using namespace std;

class Person {
public:
    string name;
    int age;

    Person(string n, int a) : name(n), age(a) {}

    virtual void print() const {
        cout << "I am " << name << ", " << age << " years old." << endl;
    }
};

class Worker : public Person {
public:
    string jobTitle;

    Worker(string n, int a, string jt) : Person(n, a), jobTitle(jt) {}

    void print() const override {
        cout << "I am " << name << ", " << age << " years old and I work as a " << jobTitle << "." << endl;
    }
};

int main() {
    Person person("Alice", 30);
    Worker worker("Bob", 25, "Engineer");

    Person* pPerson;
    Worker* pWorker;

    pPerson = &worker;
    Worker* castedPWorker = dynamic_cast<Worker*>(pPerson);

    if (castedPWorker) {
        cout << "Casting Person* to Worker* succeeded." << endl;
        castedPWorker->print();
    }
    else {
        cout << "Casting Person* to Worker* failed." << endl;
    }

    pWorker = &worker;
    Person* castedPPerson = dynamic_cast<Person*>(pWorker);

    if (castedPPerson) {
        cout << "Casting Worker* to Person* succeeded." << endl;
        castedPPerson->print();
    }
    else {
        cout << "Casting Worker* to Person* failed." << endl;
    }

    return 0;
}
