#include <iostream>
#include <vector>
using namespace std;

class Command {
public:
   virtual void execute() = 0;
   virtual ~Command() {
      cout << "deleting command" << endl;
   }
};

class Hello : public Command {
public:
   virtual void execute() {
      cout << "Hello " << endl;
   }
   virtual ~Hello() {
      cout << "deleting Hello" << endl;
   }
};

class World : public Command {
public:
   virtual void execute() {
      cout << "World " << endl;
   }
   virtual ~World() {
      cout << "deleting World" << endl;
   }
};

class CmdRunner {
public:
   // nicer c++11 way of typedefing
   using CmdPtr = unique_ptr<Command>;
   void add(CmdPtr c) {
      cmd.push_back(std::move(c));
   }
   void run() {
      // Cannot use this since it tries to copy the ptr
      // and rightfully fails! Nice catch!
      /*for(unique_ptr<Command> c: cmd) {
         c->execute();
      }*/
      for(vector<CmdPtr>::const_iterator iter = cmd.begin();
            iter != cmd.end();
            iter++) {
         (*iter)->execute();
      }
   }
private:
   // Cannot create a vector of abstrace class objects
   vector<CmdPtr> cmd;
};

int main() {

   // Make unique ptrs that will be automatically cleaned up when out of scope
   CmdRunner::CmdPtr cmd1(new Hello);
   CmdRunner::CmdPtr cmd2(new World);

   CmdRunner runner;
   // Must use move() to move
   runner.add(std::move(cmd1));
   runner.add(std::move(cmd2));

   runner.run();

   return 0;
}