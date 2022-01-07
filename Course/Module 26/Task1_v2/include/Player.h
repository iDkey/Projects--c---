#include <vector>
#include <string>
#include <iostream>
#include <random>
#include "Track.h"

class Player {
public:
    bool playerIsOn = false;
    bool track_in = false;
    std::vector<Track> tracks;

    void play();
    void pause();
    void next();
    void stop();
    static void dateOut(std::tm&);
};

void setPlaylist(Track&, Player&);