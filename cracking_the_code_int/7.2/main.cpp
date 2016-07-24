#include <iostream>
using namespace std;

/*
 * Call center software architectire
 * ---------------------------------
 * CallHandler is implemented as single process that
 * handles client connections.
 * Call handler has work queues: assigned_calls and unassigned_calls
 * Client connects over TCP socket to CallHandlerDaemon
 * Employees have rank.
 * Each employee is registered the CallHandlerDaemon.
 * When connected, CallHandlerDaemon can assign calls to that employee.
 * Only rank manager and above can assign calls to other employees.
 * FirstLevelSupport can assign calls to themselves.
 *
*/
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
   class Call;
public:
   enum status_e { FAILED, SUCCESS }; 
   virtual status_e escalate() = 0;
   virtual status_e assign(Call c) = 0;
};

int main() {
   
   return 0;
}
