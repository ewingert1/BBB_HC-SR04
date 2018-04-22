#include <iostream>
#include <string>
#include <chrono>
#include "GPIOManager.h"

#define TRIG 60
#define ECHO 48

using namespace std;
using namespace GPIO;

int main()
{
    double distance;

    std::chrono::high_resolution_clock::time_point t1 = high_resolution_clock::now();
    GPIOManager GM;
    GM.exportPin(60); //TRIG
    GM.exportPin(48); //ECHO
    GM.setDirection(TRIG,OUTPUT);
    GM.setDirection(ECHO,INPUT);


    //Pendant 10 microsecondes TRIG = 1
    auto t1 = high_resolution_clock::now();
    GM.setValue(TRIG,HIGH);
    while(chrono::duration_cast<chrono::microseconds>(high_resolution_clock::now() - t1).count()<10);
    GM.setValue(TRIG,LOW);

    std::cout << "TRIG DONE" <<std::endl;

    GM.setEdge(ECHO,RISING);
    GM.waitForEdge(ECHO,RISING);
    auto t1 = high_resolution_clock::now();
    GM.setEdge(ECHO,FALLING);
    GM.waitForEdge(ECHO,FALLING);
    auto elapsed = chrono::duration_cast<chrono::microseconds>(high_resolution_clock::now() - t1).count()

    std::cout << "ECHO RECEIVED" <<std::endl;

    distance = elapsed*17./100.;
    std::cout << "Distance = " << distance << " cm." << std::endl;

    sleep(1);

    return 0;
}
