#include <iostream>
#include <string>
#include <chrono>
#include "GPIOManager.h"

using namespace std;
using namespace GPIO;

int main()
{
    std::chrono::high_resolution_clock::time_point t1 = high_resolution_clock::now();
    GPIOManager GM;
    GM.exportPin(60);
    GM.exportPin(48);


    cout << "Hello world!" << endl;
    return 0;
}
