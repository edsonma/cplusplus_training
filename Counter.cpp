#include <iostream>

using namespace std;

class Counter{
    public:
        // Constructors and Destructors
        Counter();
        Counter(int);
        Counter(const Counter&);
        ~Counter();

        // Overloading operator
        const Counter &operator++();
        const Counter operator++(int);     

        // Public members (methods)
        int getCounter() const;
        void setCounter(int);
        void increment();

    private:
        int count;  

};

/*
 * Implementing Constructors and Destructors
 */
Counter::Counter():
    count(0){
};

Counter::~Counter(){ 
};

Counter::Counter(int value): 
    count(value){
};

Counter::Counter(const Counter& rhs){
    cout << "Olha ae o count! " << rhs.getCounter() << endl;
};

/*
 * Getters and Setters
 */
int Counter::getCounter() const{
    return count;
};

void Counter::setCounter(int i){
    count = i;
};

/*
 * Overloading operators
 */
const Counter& Counter::operator++(){
    ++count;
    return *this;
};

const Counter Counter::operator++(int x){
    Counter temp(*this);
    ++count;
    return temp;
};

/*
 * Member functions
 */ 
void Counter::increment(){
    ++count;
}

/*
 * Main 
 */
int main(){
    Counter i;
    
    cout << "i com valor: " << i.getCounter() << endl;

    i++;

    cout << "i agora com valor: " << i.getCounter() << endl;

};
