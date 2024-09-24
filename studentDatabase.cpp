// Login-Registratrion + Student DataBasa
#include <iostream>
#include <fstream>
#include <vector>
#include <string>



struct Functions {
    void toLowerCase(std::string& word){
        for (char& character: word){
            character = std::tolower(character);
        };
    }

    void toUpperCase(std::string& word){
        for (char& character: word){
            character = std::toupper(character);
        }
    }
};

struct StoredInformation {
    void createFile(std::string nameOfFile){
        std::ofstream file(nameOfFile);
        file << "File titled: " << nameOfFile << "\n";
        std::cout << "File created..." << "\n";
        file.close();
        std::cout << "\n" << "\n";
    }

    void storingInformation(std::string txtFile, std::vector<std::string> infoToStore){
        std::fstream file; 
        int sizeOfInfo = static_cast<int>(std::size(infoToStore));
        file.open(txtFile, std::ios::out);
        for (int i = 0; i < sizeOfInfo; i++){
            std::cout << "||" << infoToStore[i] << "||" << "\n";
            std::cout << "Going on file..." << "\n"; 
            file << infoToStore[i] << "\n";
        };
        file.close();
        std::cout << "\n" << "\n";
    }

    void readingFile(std::string txtFile){
        std::ifstream file;
        std::string txt; // used to output the words.
        file.open(txtFile, std::ios::in);
        while (std::getline(file, txt)){
            std::cout << txt << "\n";
        }
        file.close();
        std::cout << "\n" << "\n";
    }
};

struct Student {
    std::string name;
    std::string gradeName;
    std::vector<std::string> collegesOfInterest;
    std::vector<std::string> assignedClasses;
    std::string grade;
    float GPS;
};

struct Classes {
    struct Math {
        Functions function;
        Student student;
        std::string mathClasses[6] = {
        "algebra i", "algebra ii", 
        "pre-calculus", "ap calculus ab",
        "ap-calculus", "discrete class",
        };
        void searchClass(std::string& subject){
            int numberOfClasses = std::size(mathClasses); 
            for (int i = 0; i < numberOfClasses; i++){
                std::cout << subject << " == " << mathClasses[i] << "?" << "\n";
                if (subject == mathClasses[i]){
                    std::cout << "Subjet found: " << subject << "\n";
                    student.assignedClasses.push_back(subject);
                }
            }
        }
    };
    struct SocialScience {
        Functions function;
        Student student;
        std::string socialScienceClasses[4] = {
            "world history i", "world history ii",
            "ap world history", "ap usa history",
        };
        void searchClass(std::string& subject){
            short numberOfClasses = static_cast<short>(std::size(socialScienceClasses));
            for (int i = 0; i < numberOfClasses; i++){
                std::cout << subject << " " << socialScienceClasses[i] << "\n";
                if (subject == socialScienceClasses[i]){
                    std::cout << "Subject found: " << subject << "\n";
                    student.assignedClasses.push_back(subject);
            }
        }
    }
};
    Math math;
    SocialScience socialScience;
};












void colleges_selected_by_student(){
    
    
}

void student_gps(){
    Student student;
    float *pGPS = &student.GPS;
    std::cout << "Introduce student's GPS: ";
    std::cin >> *pGPS;

}

void assigningClasses(){
    Student student;
    Classes classes;
    Functions function;
    std::string selectedClass;
    int field;
    while (true){
        if (std::cin.fail()){  
            break;
        } else {
            std::cout << "1 --> Social Science" << "\n"
                      << "2 --> Mathematics" << "\n";
            std::cin >> field;
            switch (field) {
                case 0:
                    [[falltrhough]]
                case 1:
                    std::cout << "Name of the course: ";
                    std::cin >> selectedClass;
                    function.toLowerCase(selectedClass);
                    classes.socialScience.searchClass(selectedClass);
                    [[fallthrough]];
                case 2:
                    std::cout << "Name of the course: ";
                    std::cin >> selectedClass;
                    function.toLowerCase(selectedClass);
                    classes.math.searchClass(selectedClass);
                    [[fallthrough]]
                default:
                    break;
            };
        }
    }
};


void studentGrade(){
    Student student;
    StoredInformation store;
    std::string *pGrade = &student.grade;
    std::string *pGradeName = &student.gradeName;
    std::cout << "Student's grade: ";
    std::cin >> *pGrade;
    std::cout << "Introduce the name that refers that grade (Freshmen, etc...): ";
    std::cin >> *pGradeName;
    std::cout << "Processing information..." << "\n";
    std::vector<std::string> completeInfotmation = {*pGrade, *pGradeName}; 
    store.storingInformation("studentDatabase.txt", completeInfotmation);
    // Reset the pointers!
    pGrade = nullptr;
    pGradeName = nullptr;
}




int main(){
    assigningClasses();

    

    return 0;
}
// Complete one of the functions tomorrow!
// Or you will get fire!
// Just kidding lol
