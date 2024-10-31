#include <ftxui/dom/elements.hpp>
#include <ftxui/screen/screen.hpp>
#include <ftxui/screen/color.hpp>
#include <ftxui/screen/terminal.hpp>
#include <iostream>
#include <thread>

using namespace std;
using namespace ftxui;

int main(int argc, char const *argv[])
{
    std::string reset_position;
    int frame = 0;


   /* auto ColorSupport = vbox({

                            Terminal::ColorSupport() >= Terminal::Color::Palette16
                                ? text(" 16 color palette support : Yes")
                                : text(" 16 color palette support : No"),
                            Terminal::ColorSupport() >= Terminal::Color::Palette256
                                ? text("256 color palette support : Yes")
                                : text("256 color palette support : No"),
                            Terminal::ColorSupport() >= Terminal::Color::TrueColor
                                ? text("       True color support : Yes")
                                : text("       True color support : No"),
                        });*/
    while (true)
    {
        auto can = Canvas(300,100);
        can.DrawBlockLine(0,10,10,5);
        can.DrawBlockLine(11,5,30,5);
        can.DrawBlockLine(31,5,40,10);
        
        can.DrawBlockLine(80,10,90,5);
        can.DrawBlockLine(91,5,110,5);
        can.DrawBlockLine(111,5,120,10);

        can.DrawBlockLine(0,60,30,70);
        can.DrawBlockLine(30,70,90,70);
        can.DrawBlockLine(90,70,120,60);
        if(frame%4==0){
            can.DrawBlockEllipse(20,20,20,1);
            can.DrawBlockEllipse(100,20,20,1);
        }
        else{
            can.DrawPointCircle(20,20,8);
            can.DrawBlockEllipse(20,20,20,8);
            can.DrawPointCircle(20,20,3);
            can.DrawPointCircle(100,20,8);
            can.DrawBlockEllipse(100,20,20,8);
            can.DrawPointCircle(100,20,3);
        }
        //Crear pantalla y agregar canvas
        Screen pantalla = Screen::Create(Dimension::Full(), Dimension::Full());
        Element lienzo = bgcolor(Color::Blue,canvas(&can));
        Render(pantalla, lienzo);
        //Limpiar pantalla y agregar el canvas
        std::cout << reset_position;
        pantalla.Print();
        reset_position = pantalla.ResetPosition(true);
        //Detener el programa 
        this_thread::sleep_for(0.2s);
        frame++;
    }

    return 0;
}