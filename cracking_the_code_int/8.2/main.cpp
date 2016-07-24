#include <iostream>
#include <cstdio>
#include <string>
#include <vector>

using namespace std;

class Game {
public:
   enum dir_e {RIGHT, DOWN};
   struct pos_e{int x,y;};
   void run() {
      vector<pos_e> path;
      step(path, RIGHT, {0,0});
   }

   Game() {
      resetMap();
   }

private:
   char map[4][6] = {{0}};
   bool inline outOfBound(pos_e p) {
      if ((p.x >= 4) || (p.y >= 6)) return true;
      return false;
   }

   void printMap(std::vector<pos_e> vec) {
      for (auto e: vec) {
         map[e.x][e.y] = '*';
      }

      for (int y = 0; y < 6; y++) {
         for (int x = 0; x < 4; x++) {
            cout << map[x][y] << "\t";
         }
         cout << endl;
      }
   }

   void resetMap() {
      for (int i = 0; i < 4; i++) {
         for (int j = 0; j < 6; j++) {
            map[i][j] = '-';
         }
      }
   }

   void step(vector<pos_e> path, dir_e dir, pos_e pos) {
      path.push_back(pos);
      if ((pos.x == 3) && (pos.y == 5)) {

         printMap(path);
         printf("=======================================\n");
         resetMap();
         return;
      }

      if (!outOfBound({pos.x+1, pos.y})) {
         step(path, DOWN, {pos.x+1, pos.y});
      }
      if (!outOfBound({pos.x, pos.y+1})) {
         step(path, RIGHT, {pos.x, pos.y+1});
      }

   }
};

int main() {
   Game g;
   g.run();
   return 0;
}