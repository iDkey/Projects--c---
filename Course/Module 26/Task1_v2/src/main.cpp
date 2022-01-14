#include "Track.h"
#include "Player.h"

int main() {
    Track track;
    Player player;
    getPlaylist(track);
    setPlaylist(track, player);
    getPlaylist(track);
    setPlaylist(track, player);
    getPlaylist(track);
    setPlaylist(track, player);

    std::string command;
    while(command != "exit")
    {
        if (command == "play")
        {
            player.play();
        }
        if (command == "pause")
        {
            player.pause();
        }
        if (command == "next")
        {
            player.next();
        }
        if (command == "stop")
        {
            player.stop();
        }
        std::cout << "Input a command (play, pause, next, stop, exit):" << std::endl;
        std::cin >> command;
        if(command != "play" and command != "pause" and command != "next" and command != "stop" and command != "exit")
            std::cout << "Wrong command." << std::endl;
    }

}
