#include "client.h"

using namespace std;

Client::Client() {
  this->name = (char *) malloc(MAX_NAME_LENGHT+1);
}

void Client::SetName(char *name) {
  //Copies at most MAX_NAME_LENGHT + 1 (including '\0')
  this->name =  name;
}

void Client::SetId(int id) {
  this->id = id;
}
