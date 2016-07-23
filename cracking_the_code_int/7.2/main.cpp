#include <iostream>
using namespace std;

class ICallHandler {
private:
   class Call;
public:
   enum status_e { FAILED, SUCCESS };
   virtual status_e addCall(Call c) = 0;
};

class ICall {
public:
   enum status_e {CONNECTED, DISCONNECTED};
   virtual status_e connect() = 0;
   virtual status_e disconnect() = 0;
};

class IEmployee {

};

int main() {
   return 0;
}