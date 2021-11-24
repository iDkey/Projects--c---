#include <iostream>

enum music_notes
{
    DO = 1,
    RE,
    MI,
    FA,
    SOL,
    LA,
    SI
};

void print_music_notes(int num_note)
{
    std::string notes[7] = {"DO", "RE", "MI", "FA", "SOL", "LA", "SI"};
    std::cout << notes[num_note - 1] << " ";
}

int main()
{
    int melody[3];
    for (int i = 0; i < 3; i++)
    {
        std::cout << "Input the combination of notes:" << std::endl;
        std::cin >> melody[i];
    }


    for (int i = 0; i < 3; i++)
    {
        do
        {
            int num_note = melody[i] % 10;
            print_music_notes(num_note);
            melody[i] /= 10; 
        } while (melody[i] > 0);
        std::cout << std::endl;
    }
}