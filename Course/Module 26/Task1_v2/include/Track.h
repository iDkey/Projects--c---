#include <string>
#include <ctime>
#include <iostream>
#include <iomanip>
#pragma once

class Track {
public:
    std::string trackName;
    std::tm dateCreate;
    int duration;
};

void getPlaylist(Track& track);