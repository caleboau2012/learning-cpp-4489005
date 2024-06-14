// Learning C++ 
// Challenge 01_03
// Console Interaction, by Eduardo Corpeño 

#include <iostream>
#include <string>

int main(){
    std::cout << "Please enter your first name 🤗" << std::endl;

    std::string str;
    std::cin >> str;
    std::cout << "Your name is: " << str << std::endl;

    std::cout << std::endl << std::endl;
    return (0);
}
