/*============================================================================*/
/* Convert unsigned value to d-digit integer string in local buffer           */
/* 16 bit unsigned int: 0 < x < 65535 => 5 characters + '\0'                  */
/*============================================================================*/

char *ui2s(unsigned x, unsigned d)
{
  const int buffMaxSize = 6;

  static char b[buffMaxSize];
  char *p;
  unsigned digits = 0;
  unsigned  t = x;

  do ++digits; while (t /= 10);
  // if (digits > d) d = digits; // uncomment to allow more digits than spec'd
  *(p = b + d) = '\0';
  do *--p = x % 10 + '0'; while (x /= 10);
  while (p != b) *--p = ' ';
  return b;
}