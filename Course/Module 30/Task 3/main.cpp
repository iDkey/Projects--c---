#include <iostream>
#include <string>
#include <cpr/cpr.h>

int main() {
    cpr::Url url {"http://httpbin.org/"};
    std::vector<cpr::Pair> payloadData;

    std::string inputArg = "";
    std::string argVal = "";
    while(true)
    {
        std::cin >> inputArg;
        if(inputArg == "post" or inputArg == "get")
        {
            break;
        }
        std::cin >> argVal;
        payloadData.emplace_back(inputArg.c_str(), argVal.c_str());
    }
    if(inputArg == "post")
    {
        url += "post";
        cpr::Response response = cpr::Post(url, cpr::Payload(payloadData.begin(), payloadData.end()));
        std::cout << response.text;
    }
    else
    {
        url += "get?";
        for(const auto& it : payloadData)
        {
            url += it.key + '=' + it.value + '&';
        }
        std::string strUrl = url.str();
        strUrl.resize(strUrl.size() - 1);
        cpr::Response response = cpr::Get(cpr::Url(strUrl));
        std::cout << response.text;
    }
}
