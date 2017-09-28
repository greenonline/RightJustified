/*============================================================================*/
/* Convert double value to d-digit long string in local buffer                 */
/* d includes decimal place and preceding '0'                                 */
/*============================================================================*/

char *d2s(double x, unsigned d, unsigned dp)
{  
  const int buffMaxSize = 7;

  static char b[buffMaxSize];
  char *p;
//   unsigned digits = 0;

  // Error checks
#defined __Use_Error_Checking__  // Comment out to save memory
#if defined (__Use_Error_Checking__)
  if (d > buffMaxSize-2) return ("STL");  // Sanity check - "String Too Long" - d is more than maximum string length, plus terminating '\0' (plus preceding '0'?)
  if (d < dp + 2) return ("STS");         // Sanity check - "String Too Short" - d is less than number of decimal places plus preceding '0'
  if (dp < 1) return("NDP");              // Sanity check - "No Decimal Places" - must have at least one decimal place
#endif
  
  unsigned dp_count=dp;
  unsigned magnitude = pow(10, dp); 
  unsigned long ul = x*magnitude;

  strcpy (b, ul2s(ul, d));
   
//   *(p = b + d + 1 + (x<magnitude)) = '\0';
//#define __Original__
#ifdef __Original__
  *(p = b + d + 1) = '\0';    // shift end of string along by one, to give space for decimal place (this line is redundant, can subsume into next line)
  do *--p = *(p-1); while (dp_count--);  // shift all characters after decimal place along by one, to give space for decimal place
  *p = '.';  // insert decimal point
// need to add preceding 0s, both before AND after the decimal point
//  if (ul<magnitude) *--p = '0'; 
  if (ul<magnitude){
    *--p = '0';                   // put 0 preceding decimal point 0
    while (p++ < b + d)  // Is it possible to change to stop incrementing p after non '0' characters, by calculating the number of decimal places, in order to remove else
      if (*p == ' ') *p = '0';    // replace any spaces after decimal point
      else if (*p != '.') break;  // stop incrementing p (and checking) after non '0' characters after the decimal point
  }
#else
  p = b + d + 1;    // shift end of string along by one, to give space for decimal place (this line is redundant, can subsume into next line)
//  do *p-- = *p; while (dp_count--);  // shift all characters after decimal place along by one, to give space for decimal place
  do *p-- = *p; while (dp_count--);  // shift all characters after decimal place along by one, to give space for decimal place
//  do {*p = *(p-1); p--;} while (dp_count--);  // shift all characters after decimal place along by one, to give space for decimal place
  *p-- = '.';  // insert decimal point
// need to add preceding 0s, both before AND after the decimal point
  if (ul<magnitude){
    *p++ = '0';                    // put 0 preceding decimal point 0
    while (p++ < b + d - (dp -1))  // Stop incrementing p after non '0' characters, by calculating the number of decimal places
      if (*p == ' ') *p = '0';     // replace any spaces after decimal point
  }
#endif
  return b;
}

