#include <iostream>
#include <string>
#include <memory>
#include <fstream>
#include "is_valid.cpp";

struct Account {
    std::string user_first_name;
    std::string user_middle_name;
    std::string user_last_name;
    std::string card_number;
    std::string card_password;
    double user_balance;
};
struct Account2 {
    std::string user_first_name;
    std::string user_middle_name;
    std::string user_last_name;
    std::string card_number;
    std::string card_password;
    double user_balance;
};

bool balance(){
}
bool deposit(){
    Account2 user;
    double* balance = &user.user_balance;
    short is_correct;
    std::fstream users_info; 
    users_info.open("users_info.txt", std::ios::in | std::ios::out);
    std::cout << "How much money do you want to deposit?";
    std::cout << "--> ";
    std::cin >> *balance;
    std::cout << "Depositing...";
}
void leave_review(){

}
void change_personal_info(){
    Account user;
    std::fstream user_info;
    user_info.open("users_info.txt", std::ios::in);
    
}
bool deposit_to(){


}
bool help(){
    Account user;
    short request;
    std::cout << "How can we help you?";
    std::cout << "0 --> How to deposit" << std::endl
              << "1 --> How to deposit to another account" << std::endl
              << "2 --> Change personal information" << std::endl
              << "3 --> Privacy & Terms" << std::endl
              << "4 --> Review" << std::endl;
    std::cin >> request;
    switch (request){
        case 0:
            std::cout << " " << std::endl;
        case 1:
            std::cout << " " << std::endl;
        case 2:
            change_personal_info();
        case 3:
            std::cout << "bla bla bla bla bla steal steal steal legal legal legal" << std::endl;
        case 4:
            leave_review();
        default:
            break;

    }




}
void store_info(std::string* first_name, std::string* middle_name, std::string* last_name, std::string* card_number, std::string* password){
    std::fstream users_info;      //  reading      or    writing    (including both) 
    users_info.open("users_info.txt", std::ios::in | std::ios::out);
    std::string info[5] = {*first_name, *middle_name, *last_name, *card_number, *password};
    for (int i = 0; i < static_cast<int>((sizeof(info)) / sizeof(int)); i++){
        users_info << info[i] << std::endl; 
    }
    users_info.close();
    std::cout << std::endl << std::endl;
}
bool confirming_user(std::string card_number, std::string password){
    Account user;
    if ((card_number == user.card_number) && (password == user.card_password)){
        return true;
    } else {
        return false;
    }
}
void bring_to_its_account(){
    Account user;
    short going_to;
    std::cout << "Welcome back, " << user.user_first_name << "!" << std::endl << std::endl;
    std::cout << "  0 --> See balance" << "         "
              << "  1 --> Deposit" << "         " << std::endl
              << "  2 --> Deposit to..." << "        "
              << "  3 --> Contact professional" << std::endl;
    std::cin >> going_to;
    switch(going_to){

        case 0:
            balance();
        case 1:
            deposit();
        case 2: 
            deposit_to();
        case 3:
            help();
        default:
            break;
    } 
}
void log_in_to_account(){
    Account user;
    std::fstream user_info;
    user_info.open("users_info.txt", std::ios::in);
    std::string card_number;
    std::string password;
    std::cout << "Welcome to livEEvil" << std::endl;
    std::cout << "Card Number: ";
    std::cin >> card_number;
    std::cout << "Password: ";
    std::cin >> password;
    if (confirming_user(card_number, password) == false){
        while (true){
        std::cout << "Card number or password is incorrect. Try again" << std::endl;
        std::cout << "Card Number: ";
        std::cin >> card_number;
        std::cout << "Password: ";
        std::cin >> password; 
        } if (confirming_user(card_number, password) == true) {
            bring_to_its_account();
        } 
    } else {
            bring_to_its_account();
        }
}
std::string pick_card_number(int n){
    std::string card_numbers[10] = {

        "000-000-000-000",
        "111-111-111-111",
        "222-222-222-222",
        "333-333-333-333",
        "444-444-444-444",
        "555-555-555-555",
        "666-666-666-666",
        "777-777-777-777",
        "888-888-888-888",
        "999-999-999-999",

    };
    return card_numbers[n];
}
void create_account(){
    Account new_user;
    std::string* pFirstName = &new_user.user_first_name;
    std::string* pMiddleName = &new_user.user_middle_name;
    std::string* pLastName = &new_user.user_last_name;
    std::string* pCardNumber = &new_user.card_number;
    std::string* pCardPassword = &new_user.card_password;
    //Extra stuff:
    int favorite_number;
    short is_there_middle_name;
    std::cout << "The following questions are used to create an bank account. Please, fill it up."
              << std::endl 
              << std::endl;
    std::cout << "First name: ";
    std::cin >> *pFirstName;
    std::cout << "Middle name (if not, only press ENTER): ";
    std::cin >> *pMiddleName;
    if (new_user.user_middle_name.empty()){
        is_there_middle_name = 0;
    } else {
        is_there_middle_name = 1;
    }
    std::cout << "Last name: ";
    std::cin >> *pLastName;
    std::cout << "To create your card number, "
              << "please introduce your favorite number: " << std::endl;
    std::cin >> favorite_number;
    *pCardNumber = pick_card_number(favorite_number);
    while (true) {
        std::cout << "Password (must have 8 character and 4 numbers): ";
        std::cin >> *pCardPassword;
        if (is_valid(pCardPassword, 8, 4) == true) {
            break;
        }
    }
    switch (is_there_middle_name)
    {
    case 0:
    std::cout << "We're done! Here's all the information:" << std::endl;
    std::cout << "Name: " << *pFirstName << " " << *pLastName << std::endl
              << "Card: " << *pCardNumber << std::endl
              << "Password: " << *pCardPassword
              << std::endl
              << std::endl;
        break;
    case 1:
    std::cout << "We're done! Here's all the information:" << std::endl;
    std::cout << "Name: " << *pFirstName << " " << *pMiddleName << " " << *pLastName << std::endl
              << "Card: " << *pCardNumber << std::endl
              << "Password: " << *pCardPassword 
              << std::endl
              << std::endl;
        break;
    default:
        break;
    }
    std::cout << "Account created";
    store_info(pFirstName, pMiddleName, pLastName, pCardNumber, pCardPassword);
    //finished!!
    //Reseting pointers
    pFirstName = nullptr; 
    pMiddleName = nullptr; 
    pLastName = nullptr;
    pCardNumber = nullptr;
    pCardPassword = nullptr;
    //Sending to user to the home page
    log_in_to_account();
}
int main() {
    short initiate;
    while (true){
        std::cout << "Type in 0 if sign in:" << std::endl
                  << "Type in 1 if log in:" << std::endl
                  << "--> ";
        std::cin >> initiate;
        if (std::cin.fail()){
            break;
        } else {
            break;
        }
    }
    switch (initiate) {
    case 0:
        create_account();
    case 1:
        log_in_to_account();
    default:
        std::cout << "No input";
        break;
    }
    return 0;
}