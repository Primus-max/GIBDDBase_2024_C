#pragma once
#include <ctime>
#include "enums.h"
using namespace std;


struct Penalty
{
    int id = 0;
    int carId = 0;
    time_t datTime = 0;
    double penaltyAmount = 0.0;
    char location[200]{};
    char additionalInfo[300]{};

    PenaltyType penaltyType;
};

