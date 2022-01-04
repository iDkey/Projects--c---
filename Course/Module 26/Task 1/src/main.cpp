#include <iostream>
#include <string>
#include <ctime>
#include <random>
#include <vector>

class Track
{
public:
    std::string trackName;
    std::tm dateCreate;
    int duration;
};

class Player
{
public:
    bool playerIsOn = false;
    bool track_in = false;
    std::vector<Track> tracks;

    void play()
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

    void pause()
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

    void next()
    {
        std::mt19937 gen(static_cast<unsigned int>(time(0)));
        std::uniform_int_distribution<> rand_x(0,tracks.size() - 1);
        int random_track = rand_x(gen);
        std::cout << "Now playing:" << std::endl;
        std::cout << "Track name: " << tracks[random_track].trackName << std::endl;
        std::cout << "Date created: ";
        dateOut(tracks[random_track].dateCreate);
        std::cout << "Duration: " << tracks[random_track].duration << std::endl;
    }

    void stop()
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

    static void dateOut(std::tm& date)
    {
        std::cout << date.tm_mday << "/";
        std::cout << date.tm_mon + 1 << "/";
        std::cout << date.tm_year + 1900 << std::endl;
    }
};

int main() {
    std::time_t t = time(nullptr);
    std::tm t_now = *localtime(&t);
    Track track = {"qwe", t_now, 30};

    Player *player = new Player;

    player->tracks.push_back(track);
    t_now = *localtime(&t);
    t_now.tm_year -= 10;
    t_now.tm_mday += 20;
    track = {"asd", t_now, 50};
    player->tracks.push_back(track);
    t_now = *localtime(&t);
    t_now.tm_year -= 2;
    t_now.tm_mon += 2;
    track = {"zxc", t_now, 50};
    player->tracks.push_back(track);


    std::string command = "";
    while(command != "exit")
    {
    if (command == "play")
    {
        player->play();
    }
    if (command == "pause")
    {
        player->pause();
    }
    if (command == "next")
    {
        player->next();
    }
    if (command == "stop")
    {
        player->stop();
    }
    std::cout << "Input a command (play, pause, next, stop, exit):" << std::endl;
    std::cin >> command;
    if(command != "play" and command != "pause" and command != "next" and command != "stop" and command != "exit")
        std::cout << "Wrong command." << std::endl;
    }

    delete player;
}
