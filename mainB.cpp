#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include "WiimoteAccel.h"
#include <iostream> 

using namespace std;

int main() {

       WiimoteAccel wiimote;
       wiimote.Listen();
       return 0;

}
