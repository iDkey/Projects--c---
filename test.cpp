#include <iostream>
#include <map>
#include <string>

using namespace std;

bool requestIsSurname(const string&);

int main() {

  string request;
  getline(cin, request);

  map<string, string> oMap;
  for(int i = 0; i < 10; ++i)
    oMap.insert(pair<string, string> ("67-68-9" + to_string(i), "Ivanov"));

  if(request.find(' ') != string::npos)  {
    string number = request.substr(0,request.find(' '));
    string surname = request.substr(request.find(' ') + 1, request.length());

    oMap.insert(pair<string, string> (number, surname));
    
    system("clear");
    for(auto& item : oMap)
      cout << item.first << " " << item.second << endl;

  } else if(requestIsSurname(request))  {
    system("clear");
    cout << "Surname: " << request << endl;
    cout << "Phone number: ";

    for(auto& item : oMap) {
      if(item.second == request)
      {
        cout << " " << item.first ;
      }
    }
    cout << endl;
  } else  {
    system("clear");
    cout << "Surname: " << request;

    cout << oMap[request] << endl;
  }
}

bool requestIsSurname(const string& request){
  for(int i = 0; i < request.length(); ++i)  {
    if(!(request[i] >= 'a' && request[i] <= 'z') && !(request[i] >= 'A' && request[i] <= 'Z'))
    {
      return false;
    }
  }
  return true;
}