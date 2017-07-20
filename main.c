#include <stdlib.h>
#include <stdio.h>
#include <err.h>

#include "1-10.h"

typedef unsigned long (*functype)();

const functype ops[] = {
  mult3And5,
  fibo,
  primeFact
};

const char *op_names[] = {
  "Multiples of 3 and 5",
  "Even Fibonacci numbers",
  "Largest prime factor"
};

const char usage[] = 
"<op>\n"
"\tOperators:\n"
"\t\t0: Multiples of 3 and 5\n"
"\t\t1: Even Fibonacci numbers\n"
"\t\t2: Largest prime factor\n";


int main(int argc, char *argv[]){
  if(argc < 2)
    errx(1,"%s",usage);
  unsigned long op = strtoul(argv[1],NULL,10);
  printf("%s() = %lu\n" , op_names[op], ops[op]());
  return 0;
}
