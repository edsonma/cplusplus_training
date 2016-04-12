#include <iostream>

using namespace std;

class CAT{
    public:
        CAT();
        CAT(const CAT &theCat);

        ~CAT();

        int getAge() const { return *itsAge; };
        int getWeight() const { return *itsWeight; };
        void setAge(int age) { *itsAge = age; };
        void setWeight(int weight) { *itsWeight = weight; };

    private:
        int *itsAge;
        int *itsWeight;
};

CAT::CAT(){
    itsAge = new int;
    itsWeight = new int;
    *itsAge = 5;
    *itsWeight = 10;
}

CAT::CAT(const CAT &rhs){
    itsAge = new int;
    itsWeight = new int;
    *itsAge = rhs.getAge(); 
    *itsWeight = rhs.getWeight();
}

CAT::~CAT(){
    delete itsAge;
    delete itsWeight;
    itsAge = NULL;
    itsWeight = NULL;
}

int main(){
    CAT garfield;
    cout << "Garfield's age:    " << garfield.getAge() << endl;
    cout << "Garfield's weight: " << garfield.getWeight() << endl;

    garfield.setAge(10);

    cout << "Micky here!" << endl;    
    CAT micky(garfield);

    cout << "Garfield's age:   " << garfield.getAge() << endl;
    cout << "Micky's age   :   " << garfield.getAge() << endl;
    
    micky.setAge(11);
    cout << "Old old Micky" << endl;

    cout << "Garfield's age:   " << garfield.getAge() << endl;
    cout << "Micky's    age:   " << micky.getAge() << endl;

    



}
