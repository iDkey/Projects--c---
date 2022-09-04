#include <iostream>
#include <string>
#include <fstream>
#include "nlohmann/json.hpp";

struct Actor{
    std::string name;
    std::string surname;
    int age;
};

struct Film{
    std::string title;
    std::string country;
    std::string date;
    std::string filmStudio;
    std::string writtenBy;
    std::string director;
    std::string producer;
    Actor *mainActors[2];
};

int main() {

    Film film;
    Actor actor1;

    film.title = "1+1";
    film.country = "France";
    film.date = "2012/11/26";
    film.filmStudio = "Gaumont";
    film.writtenBy = "Olivie Nakash";
    film.director = "Olivie Nakash";
    film.producer = "Loran Zeitun";

    actor1.name = "Fransua";
    actor1.surname = "Kluze";
    actor1.age = 66;

    film.mainActors[0] = &actor1;

    Actor actor2;
    actor2.name = "Omar";
    actor2.surname = "Si";
    actor2.age = 44;

    film.mainActors[1] = &actor2;

    std::ofstream file("record.json");
    nlohmann::json dict;
    nlohmann::json dict1;
    nlohmann::json dict2;

    dict = {
            {"title", film.title},
            {"country", film.country},
            {"date", film.date},
            {"filmStudio", film.filmStudio},
            {"writtenBy", film.writtenBy},
            {"director", film.director},
            {"producer", film.producer},
            {"mainActors", {
                dict = {
                    {"name", film.mainActors[0]->name},
                    {"surname", film.mainActors[0]->surname},
                    {"age", film.mainActors[0]->age}
                    },
                dict = {
                        {"name", film.mainActors[1]->name},
                        {"surname", film.mainActors[1]->surname},
                        {"age", film.mainActors[1]->age}
                    }

            }}
    };
    file << dict;
}
