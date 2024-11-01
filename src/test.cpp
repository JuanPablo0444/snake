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
    int conteo = 0;
    while (true)
    {
        auto can = Canvas(300,100);
        //Ceja izquierda
        can.DrawBlockLine(50,10,60,5);
        can.DrawBlockLine(60,5,80,5);
        can.DrawBlockLine(81,5,90,10);
        //Ceja derecha
        can.DrawBlockLine(130,10,140,5);
        can.DrawBlockLine(141,5,160,5);
        can.DrawBlockLine(161,5,170,10);
        if(frame%4==0){
            conteo++;//Cierra el ojo izquierdo
            can.DrawBlockEllipse(70,20,20,1);
            if(conteo%4==0){//Abre el ojo derecho
                can.DrawPointCircle(150,20,8);
                can.DrawBlockEllipse(150,20,20,8);
                can.DrawPointCircle(150,20,3);
                //Sonrisa
                can.DrawBlockLine(50,60,170,60);
                can.DrawBlockLine(50,60,80,75);
                can.DrawBlockLine(80,75,140,75);
                can.DrawBlockLine(140,75,170,60);
                can.DrawPointLine(80,68,140,68);
            }
            else{//Cierra el ojo derecho
                can.DrawBlockEllipse(150,20,20,1);
                //Boca
                can.DrawBlockLine(50,60,80,70);
                can.DrawBlockLine(80,70,140,70);
                can.DrawBlockLine(140,70,170,60); 
            }
        }
        else{//Ojos
            can.DrawPointCircle(70,20,8);
            can.DrawBlockEllipse(70,20,20,8);
            can.DrawPointCircle(70,20,3);
            can.DrawPointCircle(150,20,8);
            can.DrawBlockEllipse(150,20,20,8);
            can.DrawPointCircle(150,20,3);
            //Boca
            can.DrawBlockLine(50,60,80,70);
            can.DrawBlockLine(80,70,140,70);
            can.DrawBlockLine(140,70,170,60);
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
        this_thread::sleep_for(0.3s);
        frame++;
    }

    return 0;
}