#include <cmath>
#include "box_capacity.h"

int box_capacity(int CurLength,int CurWidgh,int CurHeight){
    return CurLength * CurWidgh * CurHeight*pow(12,3) / pow(16,3);
}