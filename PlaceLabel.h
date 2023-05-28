#pragma once
#include "Place.h"

class PlaceLabel :
    public Place
{
public:
    Place place[10][10];
    int livenumber;//Íæ¼ÒÊ£Óà°®ÐÄÊý
    void showplacesdata();
    PlaceLabel();
};

