#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include "WiimoteBtns.h"
#include <iostream> 

using namespace std;

int main() {

       WiimoteBtns wiimote;
       wiimote.Listen();
       return 0;

}
