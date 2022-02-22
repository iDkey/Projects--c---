#include <iostream>
#include <string>
#include <cpr/cpr.h>

int main() {
    cpr::Response answer = cpr::Get(cpr::Url("http://httpbin.org/html"), cpr::Header({{"accept", "text/html"}}));
    std::string header = "";
    std::string flagLeft = "h1";
    std::string flagRight = "/h1";

    for(int i = 0; ; i++)
    {
        if(answer.text[i] == '<')
        {
            std::string plug = "";
            for(int j = i + 1; answer.text[j] != '>'; j++)
                plug += answer.text[j];
            if(plug == flagLeft)
            {
                for(int j = i + plug.size() + 2; ; ++j)
                {
                    if(answer.text[j] == '<')
                    {
                        plug = "";
                        for(int k = j + 1; answer.text[k] != '>'; ++k)
                            plug += answer.text[k];
                    }
                    if(plug == flagRight)
                    {
                        break;
                    }
                    header += answer.text[j];
                }
                break;
            }

        }
    }
    std::cout << "Header: "<< header << std::endl;
}
