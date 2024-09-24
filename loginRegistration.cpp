// Idea#1 Login-Registration + Student DataBase 
#include <iostream>
#include <fstream>
#include <vector>
#include <ctime>
#include <string>



struct Campus{
    std::vector<std::string> zones = {
        "Omega", "Alpha", "Beta", "Gamma"
        };
    std::string info_omega = "Winter";
    std::string info_alpha = "Tropical";
    std::string info_beta = "Fall";
    std::string info_gamma = "Spring";
};

struct HomeAddress{
    std::string street;
    std::string apartment;
    std::string city;
    std::string state;
    std::string zip_code;
};
struct Student{
    std::string first_name;
    std::string middle_name;
    std::string last_name;
    std::string gender;
    std::string personal_email;
    std::string student_email;
    std::string age;
    std::string grade;
    HomeAddress address;
};

std::string info_about_campus(std::string zone){
    Campus campus;
    if (zone==campus.zones[0]){
        return campus.info_omega; 
    } else if (zone==campus.zones[1]){
        return campus.info_alpha;
    } else if (zone==campus.zones[2]){
        return campus.info_beta;
    } else if (zone==campus.zones[3]){
        return campus.info_gamma;
    }
    return "None was selected.";
}

bool in_or_out_campus(short text, std::vector<std::string>& complete_info){
    Student student;
    std::fstream student_address;
    switch(text){
        case 0:
            student_address.open("outOfCampus.txt", std::ios::in | std::ios::out);
            student_address << student.first_name << " " <<  student.last_name << std::endl;
            for (int i = 0; i < static_cast<int>(sizeof(complete_info)/sizeof(int)); i++){
            student_address << complete_info[i] << std::endl;
        }
        student_address.read("outOfCampus.txt", std::ios::in);
        student_address.close();
        return true;
        case 1:
            student_address.open("campus.txt", std::ios::in | std::ios::out);
            for (int i = 0; i < static_cast<int>(sizeof(complete_info)/sizeof(int)); i++){
            student_address << complete_info[i] << std::endl;
        }
        student_address.read("campus.txt", std::ios::in);
        student_address.close();
        return true;
        default:
            return false;
    }
    return false;
}


std::string living_on_campus(){
    Campus campus;
    std::string zone_preview;
    std::cout << std::endl << "Our campus has some perticularities. Thanks of the new technology" << std::endl
                           << "'Climate X,' we can change the season of specific parts of the campus" << std::endl;
    std::cout << "These are the zones or parts of the campus you can live in:" << std::endl;
        for (int i = 0; i < static_cast<int>(sizeof(campus.zones)/sizeof(int)); i++){
            std::cout << "--> " << campus.zones[i] << std::endl;
        }
    std::cout << "If you want to know on what season is every zone, type in the name of that zone here: ";
    std::getline(std::cin, zone_preview);
    for (char& letters: zone_preview){
        letters = std::tolower(letters);
    }
    std::cout << info_about_campus(zone_preview) << std::endl;
    while (true){
        if (zone_preview=="stop"){
            break;
        }
    std::cout << "If you want to learn about the other ones, type in the name: ";
    std::getline(std::cin, zone_preview);
    std::cout << info_about_campus(zone_preview) << std::endl;
    }
    return "Campus: complete.";
}
std::string living_out_of_campus(std::string *street, std::string *city, std::string *state, std::string *apartment, std::string *zip_code){
    short text;
    bool is_information_saved;
    std::vector<std::string> complete_info;
    std::cout << "Please, fill up the area where you live in:" << std::endl;
    std::cout << "Street: ";
    std::getline(std::cin, *street);
    std::cout << "Aprtment (if any): ";
    std::getline(std::cin, *apartment);
    std::cout << "City: ";
    std::getline(std::cin, *state);
    std::cout << "Zip Code: ";
    std::getline(std::cin, *zip_code);
    complete_info = {*street, *city, *state, *apartment, *zip_code};
    text = 0;
    is_information_saved = in_or_out_campus(text, complete_info);
    std::cout << (!is_information_saved)?"Something went wrong":"Information saved";
    return "Living out of campus: Yes.";
}

std::string creating_student_email(std::string *first_name, std::string *last_name){
    const std::string university_email = "mariaCorinaUniversity@publicInstitution.ve";
    std::string initial_first_name;
    std::string initial_last_name;
    std::string complete_email;
    for (char& letters: *first_name){
        letters = std::tolower(letters);       
    }
    for (char& letters: *last_name){
        letters = std::tolower(letters);       
    }
    initial_first_name = first_name->substr(0,1);
    initial_last_name = last_name->substr(0,1);
    ///////////////////////////////////////////////
    srand(time(0));
    const short min_value = 100;
    const short max_value = 998;
    short id_number = (rand() % (max_value - min_value + 1)) + min_value;
    complete_email.append(initial_first_name);
    complete_email.append(initial_last_name);
    complete_email.append(std::to_string(id_number));
    complete_email.append(".");
    complete_email.append(university_email);

    return complete_email;
}

std::string registering(){
    std::fstream student_info;
    Student student;
    std::string *pFirstName = &student.first_name;
    std::string *pMiddleName = &student.middle_name;
    std::string *pLastName = &student.last_name;
    std::string *pGender = &student.gender;
    std::string *pPersonalEmail = &student.personal_email;
    std::string *pStudentEmail = &student.student_email;
    std::string *pStudentStreet = &student.address.street;
    std::string *pStudentCity = &student.address.city;
    std::string *pStudentState = &student.address.state;
    std::string *pStudentApartment = &student.address.apartment;
    std::string *pStudentZipCode = &student.address.zip_code;
    std::string *pAge = &student.age;
    std::string *pGrade = &student.grade;
    short live_on_campus;
    std::vector<std::string> complete_info;
    std::cout << "Processing  student..." << std::endl;
    //Processing...
    std::cout << "First name: ";
    std::getline(std::cin, *pFirstName);
    std::cout << "Middle Name (if none, leave blank): ";
    std::getline(std::cin, *pMiddleName);
    std::cout << "Last name: ";
    std::getline(std::cin, *pLastName);
    std::cout << "Gender: ";
    std::getline(std::cin, *pGender);
    std::cout << "Personal email: ";
    std::getline(std::cin, *pPersonalEmail);
    std::cout << "Age: ";
    std::getline(std::cin, *pAge);
    std::cout << "Grade: ";
    std::getline(std::cin, *pGrade);
    std::cout << "You're done!" << std::endl;
    *pStudentEmail = creating_student_email(pFirstName, pLastName);
    complete_info = {*pFirstName, *pMiddleName, *pLastName, *pGender, *pPersonalEmail, *pStudentEmail, *pAge, *pGrade};
    std::cout << "Storing information..." << std::endl;
    student_info.open("studentInformation", std::ios::in | std::ios::out);
    for (int i = 0; i < static_cast<int>(sizeof(complete_info)/sizeof(int)); i++){
        student_info << complete_info[i] << std::endl;
    } 
    student_info.close();
    std::cout << "Do you want to live on campus?" << std::endl
              << "0 --> No" << std::endl
              << "1 --> Yes" << std::endl;
    std::cin >> live_on_campus;
    switch (live_on_campus){
    case 0:
        living_out_of_campus(pStudentStreet, pStudentCity, pStudentState, pStudentApartment, pStudentZipCode);
    case 1:
        living_on_campus();
    default:
        break;
    }


// Resetting pointers!
pFirstName = nullptr;
pMiddleName = nullptr;
pLastName = nullptr;
pGender = nullptr;
pPersonalEmail = nullptr;
pStudentEmail = nullptr;
pStudentStreet = nullptr;
pStudentApartment = nullptr;
pStudentCity = nullptr;
pStudentState = nullptr;
pStudentZipCode = nullptr;
}





int main(){

    registering();


    return 0;
}
