#pragma once
#include <string>
#include <ctime>
#include <iostream>
#include <iomanip>

class Track {
public:
    std::string trackName;
    std::tm dateCreate;
    int duration;
};

void getPlaylist(Track& track);