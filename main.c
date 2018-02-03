#include <stdlib.h>
#include <stdio.h>
#include <err.h>

#include "1-10.h"

typedef unsigned long (*functype)();

const functype ops[] = {
  mult3And5,
  fibo,
  primeFact,
  lowerMult,
  squareSum,
  prime10001,
  palin,
  pythagor,
  firstSum,
  triforce,
  powerSum
};

const char *op_names[] = {
  "Multiples of 3 and 5",
  "Even Fibonacci numbers",
  "Largest prime factor",
  "Lower Multiple",
  "Sum of different square",
  "10 001th primary number",
  "the larger factors of palin",
  "special triplet pythagor",
  "addition of prime number",
  "triangle number",
  "Sum of power number"
};

const char usage[] = 
"<op>\n"
"\tOperators:\n"
"\t\t0: Multiples of 3 and 5\n"
"\t\t1: Even Fibonacci numbers\n"
"\t\t2: Largest prime factor\n"
"\t\t3: Lower Multiple\n"
"\t\t4: Sum of different square\n"
"\t\t5: 10 001th primary number\n"
"\t\t6: the larger factors of palin\n"
"\t\t7: special triplet pythagor\n"
"\t\t8: addition of prime number\n"
"\t\t9: triangle number\n"
"\t\t10: Sum of power number";


int main(int argc, char *argv[]){
  if(argc < 2)
    errx(1,"%s",usage);
  unsigned long op = strtoul(argv[1],NULL,10);
  printf("%s() = %lu\n" , op_names[op], ops[op]());
  return 0;
}
