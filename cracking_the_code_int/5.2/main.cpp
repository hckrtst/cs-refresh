#include <iostream>
#include <string>

using namespace std;

string dec2bin(int n) {
    if (n > 1) {
        int rem = n % 2;
        return (dec2bin(n/2) + to_string(rem));
    } else if (n == 1){
        return "1";
    } else {
      return "0";
    }
}

void extract(const string src, string& left, string& right) {
   int pos = src.find(".");
   if (pos == string::npos) {
      // no decimal point
      left = src;
      right = "0";
   } else {
      left = src.substr(0, pos);
      right = src.substr(pos+1, src.size());
   }
}

string compose(const string left, const string right) {
   string s;;
   s.append(left);
   s.append(".");
   s.append(right);
   return s;
}

bool is_valid(const string src) {
   for (int i=0; i < src.size(); i++) {
      if (!((isdigit(src[i])) || src[i] == '.'))
         return false;
   }
   return true;
}

void solve(string src) {
   if (!is_valid(src)) {
      cout << src << " = ERROR" << endl;
   } else {
      string left, right;
      extract(src, left, right);

      cout << src << " = " << compose(dec2bin(atoi(left.c_str())),
         dec2bin(atoi(right.c_str()))) << endl;
   }
}

int main() {
    solve("32");
    solve("0000012.345");
    solve("hello");
    return 0;
}
