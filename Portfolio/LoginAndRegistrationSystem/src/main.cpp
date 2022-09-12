#include <iostream>
#include <fstream>
#include <string>
#include "ValidateData.h"

class Login
{
private:
    std::string logStr;

public:

};

int main() {
    std::string str = "x";
    std::string login = "";
    std::string password = "";

    while(str != "exit")
    {
        std::cin >> str;

        if(str == "registration")
        {
            do
            {
                std::cout << "Create your login:";
                std::cin >> login;

                //cancel of login's creating
                if(login == "exit")
                {
                    break;
                }

                //check login's data to valid
                else if(checkData(login))
                {
                    std::cout << "Login create." << std::endl;
                    break;
                }

                //error message
                else if(!checkData(login))
                    std::cout << "Wrong data. Try again" << std::endl;
            }while(!checkData(login));

            if(login != "exit")
            do
            {
                std::cout << "Create your password:";
                std::cin >> password;

                //cancel of password's creating
                if(password == "exit")
                    break;

                //check password's data to valid
                else if(checkData(password))
                {
                    std::cout << "Password create." << std::endl;
                    break;
                }

                //error message
                else if(!checkData(password))
                    std::cout << "Wrong data. Try again" << std::endl;
            }while(!checkData(password));

            //saving login and password to .txt file
            if(!login.empty() and !password.empty())
            {
                std::ofstream logins(R"(D:\Projects\Portfolio\LoginAndRegistrationSystem\Database\Logins.txt)", std::ios_base::app);

                logins << login << " " << password << std::endl;

                std::cout << "Registration complete!" << std::endl;
            }
        }

        if(str == "log in")
        {
            std::cout << "Enter your login: ";
            std::cin >> login;

            //check valid login's data

            //check valid password's data

            //if login and password is correct
            //display "login in"
            //else display "invalid data"
        }
    };
}
