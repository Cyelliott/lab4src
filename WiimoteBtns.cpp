#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <iostream> 

using namespace std;

class WiimoteBtns {

private:

  int fd;

public:

  WiimoteBtns(){
  
    fd= open("/dev/input/event2", O_RDONLY);
    if (fd == -1) { 
      cerr << "Error: Could not open event file - forgot sudo?\n";
      exit(1);
    }
  
  }

  ~WiimoteBtns(){
  
    close(fd);
  
  }
  
  void Listen() {
  
    while (true) {
    
      char buffer[32];
      read(fd, buffer, 32);
      
      int code = buffer[10];
      int value = buffer[12];
      
      ButtonEvent(code, value);
      
    }
  
  }
  
  void ButtonEvent(int code, int value) {
  
    cout << "Code = " << code << ", value = " << value << '\n'; 
  
  }
  
};
