#pragma once
#include "Place.h"

class PlaceLabel :
    public Place
{
public:
    Place place[10][10];
    int livenumber;//���ʣ�మ����
    void showplacesdata();
    PlaceLabel();
};

