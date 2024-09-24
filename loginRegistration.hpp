// Orginizing function in this specific file
#ifdef LOGIN_REGISTRATION
#define LOGIN_REGISTRATION

std::string registering();
std::string creating_student_email(std::string *first_name, std::string *last_name);
std::string living_out_of_campus(std::string *street, std::string *city, std::string *state, std::string *apartment, std::string *zip_code);
std::string living_on_campus();
bool in_or_out_campus(short text, std::vector<std::string>& complete_info);
std::string into_abput_campus(std::string zone);

#endif