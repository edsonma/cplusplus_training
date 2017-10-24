#include <iostream>

using namespace std;

class Mammal{
public:
    Mammal():itsAge(1) {};
    virtual ~Mammal() {};
    virtual void speak() const =0;
    virtual void move() const=0;

protected:
    int itsAge;
};

class Dog: public Mammal{
public:
    void speak() const { cout << "Bark bark" << endl; };
    void move() const { cout << "run doggy!" << endl; };
};

class Cat: public Mammal{
public:
    void speak() const { cout << "Miau!" << endl; };
    void move() const { cout << "silent move!" << endl; };
};

class Horse: public Mammal {
public:
    void speak() const { cout << "winny!" << endl; };
    void move() const { cout << "Galloping" << endl; };
};

int main(){
    void (Mammal::*pFunc) () const=0;
    Mammal *ptr = NULL;

    int animal;
    int method;
    bool fquit = false;

    while(fquit == false){
        cout << "(0) quit / (1)dog / (2)cat / (3)horse" << endl;
        cin >> animal;

        switch(animal){
            case 1: ptr = new Dog; break;
            case 2: ptr = new Cat; break;
            case 3: ptr = new Horse; break;
            default: fquit = true; break;
        }

        if(fquit) break;

        cout << " (1) speak / (2) move" << endl;
        cin >> method;

        switch(method){
            case 1: pFunc = &Mammal::speak; break;
            case 2: pFunc = &Mammal::move; break;
        }

        (ptr->*pFunc)();
        delete ptr;
    }

    return 0;
}