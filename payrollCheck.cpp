#include <iostream>
#include <chrono>
#include <vector>
#include <fstream>
#include <tuple>
#include <type_traits>

struct Employee {
    std::vector<std::string> employee_name = {"Francisco, Samir, Chaya, Emilio, himom"};
    std::vector<std::string> email = {
        "francisco@mars.us", "samir@mars.us", 
        "chaya@mars.us", "emilio@mars.us", 
        "himom@mars.us" 
        };
    std::tuple<std::string, std::string, std::string, std::string, std::string> password = {
        "franciscofrancisco", "samirsamir",
        "lollol", "lol",
        "himomhimom"};
    int time_in;
    int time_out;
};



bool is_password(std::string password){
    Employee employee;
    auto validate = [&](auto&&... args){
        return ((password==args) ||...);
    };
    return std::apply(validate, employee.password);
}
bool is_email(std::string email){
    Employee employee;
    auto validate = [&](auto&&... args){
        return ((email==args) || ...);
    };
    return std::apply(validate, employee.email);
}




bool log_in(){
    Employee employee;
    std::string email;
    std::string password;
    while (true){
        std::cout << "Email: ";
        std::getline(std::cin,email);
        std::cout << "Password: ";
        std::getline(std::cin,password);
        bool is_email_correct = is_password(password);
        bool is_password_correct = is_email(email);
        if (is_password_correct){
            std::cout << "Accessing account..." << std::endl;
            return true;
        } else {
            std::cout << "Error: Email or Password is incorrect." << std::endl;
            return false;
        }
    }
    std::cout << "Page blocked." << std::endl;
    return false;
}






int main(){
    log_in();
}
