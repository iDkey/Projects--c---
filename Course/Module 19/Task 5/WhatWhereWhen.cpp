#include <iostream>
#include <fstream>
#include <string>

int check_spin(int spin, bool* pass)
{
    if (*(pass + spin - 1))
        while (*(pass + spin - 1))
        {
            if (spin == 13)
                spin = 1;
            else
                spin++;
        }
    return spin;
}

int main()
{
    int balls_viewers = 0;
    int balls_experts = 0;
    int spin;
    bool pass[13] = {};
    while(balls_experts != 6 or balls_viewers != 6)
    {
        std::cout << "Points now is (viewers:experts) " << balls_viewers << ":" 
                    << balls_experts << std::endl; 
        std::cout << "Spin the top" << std::endl;
        std::cin >> spin;
        spin = check_spin(spin, pass);

        std::ifstream question;
        question.open("A:\\Programs\\Projects (c++)\\Course\\Module 19\\Task 5\\Questions.txt");
        std::string plug;
        std::string que;

        for (int i = 0; i < spin; ++i)
        {
            getline(question, plug);
            que = plug;
        }
        std::cout << que << std::endl;
        question.close();

        std::cin.ignore();
        std::string user_ans;
        std::cout << "Input your answer (all answers start with a capital letter!):" << std::endl;
        getline(std::cin, user_ans);

        std::ifstream answer;
        answer.open("A:\\Programs\\Projects (c++)\\Course\\Module 19\\Task 5\\Answers.txt");
        std::string ans;
        for (int i = 0; i < spin; ++i)
        {
            getline(answer, plug);
            ans = plug;
        }
        answer.close();

        if (ans == user_ans)
            balls_experts++;
        else
            balls_viewers++;
        
        pass[spin - 1] = true;
    }
}