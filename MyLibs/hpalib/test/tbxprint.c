/*
   Copyright (C)  2000    Daniel A. Atkinson  <DanAtk@aol.com>
   Copyright (C)  2004    Ivano Primi  <ivprimi@libero.it>    

   This file is part of the HPA Library.

   The HPA Library is free software; you can redistribute it and/or
   modify it under the terms of the GNU Lesser General Public
   License as published by the Free Software Foundation; either
   version 2.1 of the License, or (at your option) any later version.

   The HPA Library is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
   Lesser General Public License for more details.

   You should have received a copy of the GNU Lesser General Public
   License along with the HPA Library; if not, write to the Free
   Software Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA
   02110-1301 USA.
*/

/*
    Test:  xbprint  xprint

    Uses:  xbprint  xprint  atox  

    Input file:  data/bxprint.dat
*/
#include <stdio.h>
#include <stdlib.h>
#include "xpre.h"

#define BUFF_SIZE 5120		/* 5 Kb */

int
main (int na, char **av)
{
  int i;
  char buffer[BUFF_SIZE];
  struct xpr f;
  FILE *fp;

  if (na != 2)
    {
      printf ("para: input_file\n");
      exit (-1);
    }
  fp = fopen (*++av, "r");
  printf ("     Test of Binary Printing Functions");
  while (fgets (buffer, BUFF_SIZE, fp) != NULL)
    {
      for (i = 0; buffer[i] != '\0'; i++);
      if (i > 0 && buffer[i - 1] == '\n')
	buffer[i - 1] = '\0';
      printf ("\n string in : %s\n", buffer);

      /* convert ascii string to extended precision */
      f = atox (buffer);
      /* Binary and Hexadecimal representations     */
      printf (" binary =  ");
      xbprint (stdout, f);
      printf (" hex    =  ");
      xprint (stdout, f);
    }
  fclose (fp);
  return 0;
}

/*  Test output

     Test of Binary Printing Functions
 string in : 0
 binary =  0000000000000000.0000000000000000 0000000000000000 0000000000000000 0000000000000000 0000000000000000 0000000000000000 0000000000000000 
 hex    =  0000.0000000000000000000000000000

 string in : +1
 binary =  0011111111111111.1000000000000000 0000000000000000 0000000000000000 0000000000000000 0000000000000000 0000000000000000 0000000000000000 
 hex    =  3fff.8000000000000000000000000000

 string in : -1
 binary =  1011111111111111.1000000000000000 0000000000000000 0000000000000000 0000000000000000 0000000000000000 0000000000000000 0000000000000000 
 hex    =  bfff.8000000000000000000000000000

 string in : +2
 binary =  0100000000000000.1000000000000000 0000000000000000 0000000000000000 0000000000000000 0000000000000000 0000000000000000 0000000000000000 
 hex    =  4000.8000000000000000000000000000

 string in : -2
 binary =  1100000000000000.1000000000000000 0000000000000000 0000000000000000 0000000000000000 0000000000000000 0000000000000000 0000000000000000 
 hex    =  c000.8000000000000000000000000000

 string in : +3
 binary =  0100000000000000.1100000000000000 0000000000000000 0000000000000000 0000000000000000 0000000000000000 0000000000000000 0000000000000000 
 hex    =  4000.c000000000000000000000000000

 string in : -3
 binary =  1100000000000000.1100000000000000 0000000000000000 0000000000000000 0000000000000000 0000000000000000 0000000000000000 0000000000000000 
 hex    =  c000.c000000000000000000000000000

 string in : +4
 binary =  0100000000000001.1000000000000000 0000000000000000 0000000000000000 0000000000000000 0000000000000000 0000000000000000 0000000000000000 
 hex    =  4001.8000000000000000000000000000

 string in : -4
 binary =  1100000000000001.1000000000000000 0000000000000000 0000000000000000 0000000000000000 0000000000000000 0000000000000000 0000000000000000 
 hex    =  c001.8000000000000000000000000000

 string in : +7
 binary =  0100000000000001.1110000000000000 0000000000000000 0000000000000000 0000000000000000 0000000000000000 0000000000000000 0000000000000000 
 hex    =  4001.e000000000000000000000000000

 string in : -7
 binary =  1100000000000001.1110000000000000 0000000000000000 0000000000000000 0000000000000000 0000000000000000 0000000000000000 0000000000000000 
 hex    =  c001.e000000000000000000000000000

 string in : +8
 binary =  0100000000000010.1000000000000000 0000000000000000 0000000000000000 0000000000000000 0000000000000000 0000000000000000 0000000000000000 
 hex    =  4002.8000000000000000000000000000

 string in : -8
 binary =  1100000000000010.1000000000000000 0000000000000000 0000000000000000 0000000000000000 0000000000000000 0000000000000000 0000000000000000 
 hex    =  c002.8000000000000000000000000000

 string in : +16
 binary =  0100000000000011.1000000000000000 0000000000000000 0000000000000000 0000000000000000 0000000000000000 0000000000000000 0000000000000000 
 hex    =  4003.8000000000000000000000000000

 string in : -16
 binary =  1100000000000011.1000000000000000 0000000000000000 0000000000000000 0000000000000000 0000000000000000 0000000000000000 0000000000000000 
 hex    =  c003.8000000000000000000000000000

 string in : +30
 binary =  0100000000000011.1111000000000000 0000000000000000 0000000000000000 0000000000000000 0000000000000000 0000000000000000 0000000000000000 
 hex    =  4003.f000000000000000000000000000

 string in : -30
 binary =  1100000000000011.1111000000000000 0000000000000000 0000000000000000 0000000000000000 0000000000000000 0000000000000000 0000000000000000 
 hex    =  c003.f000000000000000000000000000

 string in : +32
 binary =  0100000000000100.1000000000000000 0000000000000000 0000000000000000 0000000000000000 0000000000000000 0000000000000000 0000000000000000 
 hex    =  4004.8000000000000000000000000000

 string in : -32
 binary =  1100000000000100.1000000000000000 0000000000000000 0000000000000000 0000000000000000 0000000000000000 0000000000000000 0000000000000000 
 hex    =  c004.8000000000000000000000000000

 string in : +1023
 binary =  0100000000001000.1111111111000000 0000000000000000 0000000000000000 0000000000000000 0000000000000000 0000000000000000 0000000000000000 
 hex    =  4008.ffc0000000000000000000000000

 string in : -1023
 binary =  1100000000001000.1111111111000000 0000000000000000 0000000000000000 0000000000000000 0000000000000000 0000000000000000 0000000000000000 
 hex    =  c008.ffc0000000000000000000000000

 string in : +1024
 binary =  0100000000001001.1000000000000000 0000000000000000 0000000000000000 0000000000000000 0000000000000000 0000000000000000 0000000000000000 
 hex    =  4009.8000000000000000000000000000

 string in : -1024
 binary =  1100000000001001.1000000000000000 0000000000000000 0000000000000000 0000000000000000 0000000000000000 0000000000000000 0000000000000000 
 hex    =  c009.8000000000000000000000000000

 string in : +65530
 binary =  0100000000001110.1111111111111010 0000000000000000 0000000000000000 0000000000000000 0000000000000000 0000000000000000 0000000000000000 
 hex    =  400e.fffa000000000000000000000000

 string in : -65530
 binary =  1100000000001110.1111111111111010 0000000000000000 0000000000000000 0000000000000000 0000000000000000 0000000000000000 0000000000000000 
 hex    =  c00e.fffa000000000000000000000000

 string in : +65536
 binary =  0100000000001111.1000000000000000 0000000000000000 0000000000000000 0000000000000000 0000000000000000 0000000000000000 0000000000000000 
 hex    =  400f.8000000000000000000000000000

 string in : -65536
 binary =  1100000000001111.1000000000000000 0000000000000000 0000000000000000 0000000000000000 0000000000000000 0000000000000000 0000000000000000 
 hex    =  c00f.8000000000000000000000000000

 string in : +0.5
 binary =  0011111111111101.1111111111111111 1111111111111111 1111111111111111 1111111111111111 1111111111111111 1111111111111111 1111111111111111 
 hex    =  3ffd.ffffffffffffffffffffffffffff

 string in : -0.5
 binary =  1011111111111101.1111111111111111 1111111111111111 1111111111111111 1111111111111111 1111111111111111 1111111111111111 1111111111111111 
 hex    =  bffd.ffffffffffffffffffffffffffff

 string in : +0.25
 binary =  0011111111111100.1111111111111111 1111111111111111 1111111111111111 1111111111111111 1111111111111111 1111111111111111 1111111111110111 
 hex    =  3ffc.fffffffffffffffffffffffffff7

 string in : -0.25
 binary =  1011111111111100.1111111111111111 1111111111111111 1111111111111111 1111111111111111 1111111111111111 1111111111111111 1111111111110111 
 hex    =  bffc.fffffffffffffffffffffffffff7

 string in : +0.75
 binary =  0011111111111110.1011111111111111 1111111111111111 1111111111111111 1111111111111111 1111111111111111 1111111111111111 1111111111111001 
 hex    =  3ffe.bffffffffffffffffffffffffff9

 string in : -0.75
 binary =  1011111111111110.1011111111111111 1111111111111111 1111111111111111 1111111111111111 1111111111111111 1111111111111111 1111111111111001 
 hex    =  bffe.bffffffffffffffffffffffffff9

 string in : +0.625
 binary =  0011111111111110.1001111111111111 1111111111111111 1111111111111111 1111111111111111 1111111111111111 1111111111111111 1111111111110111 
 hex    =  3ffe.9ffffffffffffffffffffffffff7

 string in : -0.625
 binary =  1011111111111110.1001111111111111 1111111111111111 1111111111111111 1111111111111111 1111111111111111 1111111111111111 1111111111110111 
 hex    =  bffe.9ffffffffffffffffffffffffff7

 string in : +0.125
 binary =  0011111111111011.1111111111111111 1111111111111111 1111111111111111 1111111111111111 1111111111111111 1111111111111111 1111111111110010 
 hex    =  3ffb.fffffffffffffffffffffffffff2

 string in : -0.125
 binary =  1011111111111011.1111111111111111 1111111111111111 1111111111111111 1111111111111111 1111111111111111 1111111111111111 1111111111110010 
 hex    =  bffb.fffffffffffffffffffffffffff2

 string in : +0.0009765625
 binary =  0011111111110100.1111111111111111 1111111111111111 1111111111111111 1111111111111111 1111111111111111 1111111111111111 1111111111000111 
 hex    =  3ff4.ffffffffffffffffffffffffffc7

 string in : -0.0009765625
 binary =  1011111111110100.1111111111111111 1111111111111111 1111111111111111 1111111111111111 1111111111111111 1111111111111111 1111111111000111 
 hex    =  bff4.ffffffffffffffffffffffffffc7

 string in : +74.3759765625
 binary =  0100000000000101.1001010011000000 0111111111111111 1111111111111111 1111111111111111 1111111111111111 1111111111111111 1111111111111111 
 hex    =  4005.94c07fffffffffffffffffffffff

 string in : -74.3759765625
 binary =  1100000000000101.1001010011000000 0111111111111111 1111111111111111 1111111111111111 1111111111111111 1111111111111111 1111111111111111 
 hex    =  c005.94c07fffffffffffffffffffffff

 string in : +126.625
 binary =  0100000000000101.1111110100111111 1111111111111111 1111111111111111 1111111111111111 1111111111111111 1111111111111111 1111111111111111 
 hex    =  4005.fd3fffffffffffffffffffffffff

 string in : -126.625
 binary =  1100000000000101.1111110100111111 1111111111111111 1111111111111111 1111111111111111 1111111111111111 1111111111111111 1111111111111111 
 hex    =  c005.fd3fffffffffffffffffffffffff

 string in : +131186.6259765625
 binary =  0100000000010000.1000000000011100 1010100000001111 1111111111111111 1111111111111111 1111111111111111 1111111111111111 1111111111111111 
 hex    =  4010.801ca80fffffffffffffffffffff

 string in : -131186.6259765625
 binary =  1100000000010000.1000000000011100 1010100000001111 1111111111111111 1111111111111111 1111111111111111 1111111111111111 1111111111111111 
 hex    =  c010.801ca80fffffffffffffffffffff
*/
