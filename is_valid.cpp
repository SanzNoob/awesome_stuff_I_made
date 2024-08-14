#include "is_valid.hpp"
#include <iostream>

using namespace std;


bool is_valid(string* sentence, int min_char, int min_digit){

string string_to_analyze = *sentence;
int min_value_of_characters = min_char;
int min_value_of_digits = min_digit;    
int counter_for_characters = 0;
int counter_fot_digits = 0;
int how_many_char_left;
int how_many_digit_left;
    for (int i = 0; i < static_cast<int>(string_to_analyze.length()); i++){
        if (isalpha(string_to_analyze[i]) == 0){
            counter_for_characters++;
        } else if (isdigit(string_to_analyze[i]) == 0) {
            counter_fot_digits++;
        } 
    }
    how_many_char_left = static_cast<int>(min_value_of_characters - counter_for_characters);
    how_many_digit_left = static_cast<int>(min_value_of_digits - counter_fot_digits);
    if ((counter_for_characters >= min_value_of_characters) && (counter_fot_digits  >= min_value_of_digits)) {
        cout << "The password " << string_to_analyze << " is valid" << endl;
        return true;
    } else {
        cout << "You are missing " << how_many_char_left << " character(s) " 
             << "and " << how_many_digit_left << " digit(s)."
             << "Try again!" << endl;
        return false;
    }



}