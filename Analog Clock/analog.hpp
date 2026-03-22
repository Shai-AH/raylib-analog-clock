#ifndef ANALOG_HPP_INCLUDED
#define ANALOG_HPP_INCLUDED
#include "raylib.h"
#include <ctime>

using namespace std;

class AnalogClock{
private:
    Color DARK_GREY = {45, 45, 45, 255};
    Color LIGHT_GREY = {229, 229, 229, 255};
    int Size;
    int hour;
    int minute;
    int second;
    Vector2 pos;
    void DrawFace()const{
        DrawCircleV(pos, Size, DARK_GREY);
        DrawCircleV(pos, Size - 30, LIGHT_GREY);
        DrawCircleV(pos, Size - 40, RAYWHITE);
    }


    void DrawHoursMark()const{
        float recWidth = 10;
        float recHeight = Size;
        Rectangle rectangle = {pos.x, pos.y, recWidth, recHeight};
        Vector2 newRectOrigin = {recWidth/2 , recHeight};

        for(int i = 0; i < 12; i++){
            DrawRectanglePro(rectangle, newRectOrigin, i*30, DARK_GREY);
        }
        DrawCircleV(pos, Size - 50, RAYWHITE);
    }


    void DrawMinuteHand(int minute) const{
        float handWidth = 10;
        float handLenght = Size * 0.7;
        Vector2 newRectOrigin = {handWidth/2 , handLenght};

        int angle = minute * 6;

        Rectangle handrect = Rectangle{pos.x, pos.y, handWidth, handLenght};
        DrawRectanglePro(handrect, newRectOrigin, angle, DARK_GREY);
    }


    void DrawHourHand(int hour, int minute) const{
        float handWidth = 15;
        float handLenght = Size * 0.45;
        Vector2 newRectOrigin = {handWidth/2 , handLenght};

        float angle = (hour * 30) + (minute / 60.0) * 30;

        Rectangle handrect = Rectangle{pos.x, pos.y, handWidth, handLenght};
        DrawRectanglePro(handrect, newRectOrigin, angle, DARK_GREY);
    }


    void DrawSecondHand(int second) const{
        float handWidth = 5;
        float handLenght = Size;
        Vector2 newRectOrigin = {handWidth/2 , handLenght - 55};

        float angle = second * 6;

        Rectangle handrect = Rectangle{pos.x, pos.y, handWidth, handLenght};
        DrawRectanglePro(handrect, newRectOrigin, angle, RED);
    }


public:
    AnalogClock(int Size, Vector2 pos) : Size(Size), pos(pos){}
    void Draw()const{
        DrawFace();
        DrawHoursMark();
        DrawMinuteHand(minute);
        DrawHourHand(hour, minute);
        DrawSecondHand(second);
        DrawCircleV(pos, 15, DARK_GREY);
    }
    void Update(){
        time_t t = time(0);
        tm* now = localtime(&t);
        hour = now -> tm_hour % 12;
        minute = now -> tm_min;
        second = now -> tm_sec;
    }
};

#endif // ANALOG_HPP_INCLUDED
