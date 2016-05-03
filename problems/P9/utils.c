#include "utils.h"
#include <stdlib.h>
#include <stdio.h>

static inline int _isspace(const char c) {
    return (c == ' ' || c == '\n' || c == '\t');
}

static inline int _isdigit(const char c) {
   return (c >= '0' && c <= '9');
}

static inline int _isvalidchar(const char c) {
   return ((c >= 'a' || c >= 'A') && (c <= 'f' || c <= 'F'));
}

static inline int _islower(const char c) {
   return (c >= 'a' && c <= 'f');
}

static int convert(const char c) {
   if (_isdigit(c)) return (c - '0');

   if (_isvalidchar(c)) {
      if (_islower(c)) {
         // 'a' is 97 => 97 - 87 => 10
         return (c - 87);
      } else {
         // 'A' is 65
         return (c - 55);
      }
   }

   return 0;
}

int my_htoi(const char * const s) {
    //int neg = 0;
    if (s == NULL) return 0;

    char* cur = (char*)s;
    while(*cur != '\0' && _isspace(*cur)) {
      cur++;
    }

    if (*cur++ == '0' && (*cur == 'x' || *cur == 'X')) {
      cur++;
    } else {
      // backtrack
      cur--;
    }

    int acc = 0;
    while(*cur != '\0' && (_isdigit(*cur) || _isvalidchar(*cur))) {
      acc = acc * 16 + convert(*cur);
      //printf("acc = %x \n", acc);
      ++cur;
    }

    if (*cur != '\0') acc = 0;

    return acc;
}