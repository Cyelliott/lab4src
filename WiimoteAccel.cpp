#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <iostream> 

using namespace std;

class WiimoteAccel {

private:

  int fd;

public:

  WiimoteAccel(){
  
    fd= open("/dev/input/event0", O_RDONLY);
    if (fd == -1) { 
      cerr << "Error: Could not open event file - forgot sudo?\n";
      exit(1);
    }
  
  }

  ~WiimoteAccel(){
  
    close(fd);
  
  }
  
  void Listen() {
  
    while (true) {
    
      char buffer[16];
      read(fd, buffer, 16);

      int code = buffer[10];
      short acceleration = * (short *) (buffer + 12);
      
      AccelerationEvent(code, acceleration);
      
    }
  
  }
  
  void AccelerationEvent(int code, int acceleration) {
  
    cout << "Code = " << code << ", acceleration = " << acceleration << '\n'; 
  
  }

};
