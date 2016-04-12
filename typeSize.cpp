#include <iostream>

using namespace std;

void printType(const char *typeName){
    cout << typeName << " has size of " << sizeof(bool) << " bytes \n";
}

int main(){
    printType("bool");
    cout << "int has size of "  << sizeof(int) << " bytes \n";
    cout << "short has size of " << sizeof(short) << " bytes \n";
    cout << "long has size of "  << sizeof(long) << " bytes \n";
    cout << "float has size of "  << sizeof(float) << " bytes \n";
    cout << "double has size of "  << sizeof(double) << " bytes \n";
    cout << "char has size of "  << sizeof(char) << " bytes \n";
    
    return 0;
}
