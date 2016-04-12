#include <iostream>

/**
  * Testing classses concept with pointers and heap allocation
  *
  * Create time: 27-03-2016 
  * Crafted by : Edson Ma
  *
  **/

using namespace std;

// Declaring Cat Class
class Cat {
    public:
        // Constructors
        Cat();
        Cat(char *name);
    
        // Destructor
        ~Cat();
    
        void meow();

        char* getName();        
        void setName(char* name);

    private:
        char *name;
};

// Implementing Cat Class

// Constructors Implementation
Cat::Cat(){
    cout << "Constructor called!" << endl;
};

Cat::Cat(char *name){
    cout << "Construtor called with " << name << endl;
};

// Destructor
Cat::~Cat(){
    cout << "Seek and Destroy!" << endl;
    meow();
};

// Public Methods
void Cat::meow(){
    cout << "Meeeeeeeeeeeeeowwww!" << endl;
};

char* Cat::getName(){
    return this->name;
}

void Cat::setName(char* name){
    this->name = name;
}

// Main
int main(){
    Cat *pGarfield = new Cat;

    pGarfield->setName("Garfield");
    cout << "Hello " << pGarfield->getName() << " !!!!!!!" << endl;
    pGarfield->meow();
    
    delete(pGarfield);
    pGarfield = NULL;

    cout << "Rest in peace...." << endl;

    return 0;
}   
