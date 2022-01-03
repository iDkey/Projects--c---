#include "cpu.h"

void compute(std::stringstream& data)
{
    int summ = 0;
    int plug_int;
    data.seekg(0,std::ios_base::beg);
    for(int i = 0; i < 8; ++i)
    {
        data >> plug_int ;
        summ += plug_int;
    }
    std::cout << "Summ is " << summ << std::endl;
}