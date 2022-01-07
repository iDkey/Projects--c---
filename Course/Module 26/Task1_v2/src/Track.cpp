#include "Track.h"


void getPlaylist(Track& track)
{
    std::cout << "Input a track name:" << std::endl;
    std::cin >> track.trackName;
    std::cout << "Input a date of creation in format DD/MM/YYYY:" << std::endl;
    std::time_t t = std::time(nullptr);
    std::tm t_now = *std::localtime(&t);
    std::cin >> std::get_time(&t_now, "%d/%m/%Y");
    track.dateCreate = t_now;
    std::cout << "Input a duration in seconds:" << std::endl;
    std::cin >> track.duration;
}

