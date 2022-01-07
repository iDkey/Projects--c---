#include "Player.h"

void setPlaylist(Track& track, Player& player)
{
    player.tracks.push_back(track);
}

void Player::play()
{
    if(!playerIsOn)
    {
        std::string track_name;
        std::cout << "Input a track name: " << std::endl;
        std::cin >> track_name;
        for(int i = 0; i < tracks.size() and !track_in; ++i)
        {
            if(track_name == tracks[i].trackName)
            {
                playerIsOn = true;
                std::cout << "Track: " << tracks[i].trackName << std::endl;
                std::cout << "Date of create: ";
                dateOut(tracks[i].dateCreate);
                std::cout << "Duration: " << tracks[i].duration << std::endl;
                track_in = true;
            }
        }
        if(!track_in)
        {
            std::cout << "This track is not found." << std::endl;
        }
        track_in = false;
    }
}

void Player::pause()
{
    if(playerIsOn)
    {
        std::cout << "Pause" << std::endl;
        playerIsOn = false;
    }
    else
    {
        std::cout << "Nothing is playing right now." << std::endl;
    }
}

void Player::next()
{
    std::mt19937 gen(static_cast<unsigned int>(time(nullptr)));
    std::uniform_int_distribution<> rand_x(0,tracks.size() - 1);
    int random_track = rand_x(gen);
    std::cout << "Now playing:" << std::endl;
    std::cout << "Track name: " << tracks[random_track].trackName << std::endl;
    std::cout << "Date created: ";
    dateOut(tracks[random_track].dateCreate);
    std::cout << "Duration: " << tracks[random_track].duration << std::endl;
}

void Player::stop()
{
    if(playerIsOn)
    {
        std::cout << "Stop playing" << std::endl;
        playerIsOn = false;
    }
    else
    {
        std::cout << "Nothing is playing right now." << std::endl;
    }
}

 void Player::dateOut(std::tm &date) {
    std::cout << date.tm_mday << "/";
    std::cout << date.tm_mon + 1 << "/";
    std::cout << date.tm_year + 1900 << std::endl;
}