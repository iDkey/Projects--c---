#include <iostream>
#include <sstream>
#include <string>

enum switches
{
    POWER = 1,
    ROSSETTE = 2,
    LIGHT_IN = 4,
    LIGHT_OUT = 8,
    INDOOR_HEATING = 16,
    HEATING_WATER_SUPLY = 32,
    CONDITIONER = 64
};

int color_temp_change(int time)
{
    int temp_light = 5000;
    if (time > 16 and time <= 20)
    {
        // for 16h - 5000K
        // for 17h - 4425K
        // for 18h - 3850K
        // for 19h - 3275K
        // for 20h - 2700K
        temp_light -= 575 * (time - 16);
    }
    return temp_light;
}

int check_temp_outside(int state, std::string temp_outside, int time)
{
    if (std::stof(temp_outside) - 0.01 < 0 and std::stof(temp_outside) + 0.01 < 0)
    {
        if (!(state & HEATING_WATER_SUPLY))
        {
            state |= HEATING_WATER_SUPLY;
            std::cout << "Heating water suply is on." << std::endl;
        }
    }
    if (std::stof(temp_outside) - 0.01 > 5 and std::stof(temp_outside) + 0.01 > 5)
    {
        if (state & HEATING_WATER_SUPLY)
        {
            state &= ~HEATING_WATER_SUPLY;
            std::cout << "Heating water suply is off." << std::endl;
        }
    }
    return state;
}

int check_temp_inside(int state, std::string temp_inside, int time)
{
    if (std::stof(temp_inside) - 0.01 < 22 and std::stof(temp_inside) + 0.01 < 22)
    {
        if (!(state & INDOOR_HEATING))
        {
            state |= INDOOR_HEATING;
            std::cout << "Indoor heating is on." << std::endl;
        }  
    }
    if (std::stof(temp_inside) - 0.01 > 25 and std::stof(temp_inside) + 0.01 > 25)
    {
        if (state & INDOOR_HEATING)
        {
            state &= ~INDOOR_HEATING;
            std::cout << "Indoor heating is off." << std::endl;
        }
    }

    if (std::stof(temp_inside) - 0.01 > 30 and std::stof(temp_inside) + 0.01 > 30)
    {
        if (!(state & CONDITIONER))
        {
            state |= CONDITIONER;
            std::cout << "The conditioner is on." << std::endl;
        }    
    }
    if (std::stof(temp_inside) - 0.01 < 25 and std::stof(temp_inside) + 0.01 < 25)
    {
        if (state & CONDITIONER)
        {
            state &= ~CONDITIONER;
            std::cout << "The conditioner is off." << std::endl;
        }
    }
    return state;
}

int check_light_oustide(int state, std::string movement, int time)
{
    if (time >= 16 or time <= 5)
    {
        if (movement == "yes")
        {
            if (!(state & LIGHT_OUT))
            {
                std::cout << "The light outside is on." << std::endl;
                state |= LIGHT_OUT;  
            }
        }
        if (movement == "no")
        {
            if (state & LIGHT_OUT)
            {
                std::cout << "The light outside is off." << std::endl;
                state &= ~LIGHT_OUT;
            }
        }
    }
    if (time < 16 and time > 5)
    {
        if (movement == "yes")
        {
            if (state & LIGHT_OUT)
            {
                std::cout << "The light outside is off." << std::endl;
                state &= ~LIGHT_OUT;
            }
        }
        if (movement == "no")
        {
            if (state & LIGHT_OUT)
            {
                std::cout << "The light outside is off." << std::endl;
                state &= ~LIGHT_OUT;
            }
        }
    }
    return state;
}

int check_light_inside(int state, std::string light_in_house, int time)
{
    if (state & LIGHT_IN)
    {
        if (light_in_house == "yes")
        {
            std::cout << "The light inside is on." << std::endl;
            std::cout << "Its colour temperature is " << color_temp_change(time) << std::endl;
        }
        if (light_in_house == "no")
        {
            state &= ~LIGHT_IN;
        }
    }
    if (!(state & LIGHT_IN))
    {
        if (light_in_house == "yes")
        {
            std::cout << "The light inside is on." << std::endl;
            std::cout << "Colour temperature is " << color_temp_change(time) << std::endl;
            state |= LIGHT_IN;
        }
    }
    return state;
}

int main()
{
    int state = 0;
    int temp_light;
    std::stringstream  state_of_sensors;

    int time;
    int day = 1;
    for (time = 0; time != 24 and day != 3; time++)
    {
        temp_light = 5000;
        std::string states;
        if (time < 10)
        {
            std::cout << "Input state of sensors on " << day << " day 0" << time << ":00h in the following order:" << std::endl;
        }
        else
        {
            std::cout << "Input state of sensors on " << day << " day " << time << ":00h in the following order:" << std::endl;
        }
        std::cout << "Temperature outside, temperature inside, is there movement outside, is the light on in the house." << std::endl;
        std::cout << "Input format: yes/no or float number" << std::endl;
        getline(std::cin, states);
        
        int count_of_spase = 0;
        std::string temp_inside, temp_outside;
        std::string movement, light_in_house;
        for (int i = 0; i < states.length(); i++)
        {
            if (states[i] == ' ')
            {
                count_of_spase++;
            }
            if (count_of_spase == 0 and states[i] != ' ')
            {
                temp_outside += states[i];
            }
            if (count_of_spase == 1 and states[i] != ' ')
            {
                temp_inside += states[i];
            }
            if (count_of_spase == 2 and states[i] != ' ')
            {
                movement += states[i];
            }
            if (count_of_spase == 3 and states[i] != ' ')
            {
                light_in_house += states[i];
            }
        }

        state_of_sensors << "Temperature outside: " << std::stof(temp_outside) << " Temperature inside: " << std::stof(temp_inside)
                            << " Is there movement outside: " << movement << " Is the light on in the house: " << light_in_house;

        state = check_temp_outside(state, temp_outside, time);
        state = check_temp_inside(state, temp_inside, time);
        state = check_light_oustide(state, movement, time);
        state = check_light_inside(state, light_in_house, time);

        if (time == 23)
        {
            time = -1;
            day++;
        }
    }
}