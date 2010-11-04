#include <iostream>
#include "../sockets/SocketW.h"
#include <string>
#include <vector>
#include <cstdlib>
#include <cstdio>
#include <unistd.h>
#include <fcntl.h>

int main() {
  SWUnixSocket mySocket;
  std::string input;
  std::cin >> input;
  input = "/tmp/shared_socket_"+input;
  mySocket.connect(input);
  char buffer[500000];
  int msg;
  while(std::cout.good()) {
    msg = mySocket.recv(&buffer[0],10000);
    std::cout.write(buffer,msg);
  }
  // disconnect
  mySocket.disconnect();
  return 0;
}
