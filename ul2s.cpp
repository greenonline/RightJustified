// This code was published on https://forum.arduino.cc/index.php?topic=95175.msg714960#msg714960


/*============================================================================*/
/* Convert unsigned long value to d-digit decimal string in local buffer      */
/* 32 bit unsigned long: 0 < x < 4,294,967,295 => 10 characters + '\0'        */
/*============================================================================*/

char *ul2s(unsigned long x,unsigned d)
{
  const int buffMaxSize = 11;

  static char b[buffMaxSize];
  char *p;
  unsigned digits = 0;
  unsigned long t = x;

  do ++digits; while (t /= 10);
  // if (digits > d) d = digits; // uncomment to allow more digits than spec'd
  *(p = b + d) = '\0';
  do *--p = x % 10 + '0'; while (x /= 10);
  while (p != b) *--p = ' ';
  return b;
}
