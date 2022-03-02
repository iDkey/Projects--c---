#include <iostream>
#include <string>
#include <vector>
#include <cpr/cpr.h>

int main()
{
    cpr::Url url{"http://httpbin.org/post"};
    std::vector<cpr::Pair> payloadData;
    std::string a = "x";
    std::string b = "1";
    std::string c = "y";
    std::string d = "2";
    payloadData.emplace_back(a.c_str(), b.c_str());
    payloadData.emplace_back(c.c_str(), d.c_str());
    cpr::Response response = cpr::Post(url, cpr::Payload(payloadData.begin(), payloadData.end()));
    std::cout << response.text;
}
