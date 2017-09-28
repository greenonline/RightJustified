# RightJustified
A collection of routines to convert unsigned ints, unsigned longs, floats and doubles to right justified strings:

 - `ui2s()`
 - `ul2s()`
 - `f2s()`
 - `d2s()`

The routines are adapted from [this post](https://forum.arduino.cc/index.php?topic=95175.msg714960#msg714960) on the Arduino forum, [Right Justify](https://forum.arduino.cc/index.php?topic=95175.0):

>     /*============================================================================*/
>     /* Convert unsigned long value to d-digit decimal string in local buffer      */
>     /*============================================================================*/
>     char *u2s(unsigned long x,unsigned d)
>     {  static char b[16];
>        char *p;
>        unsigned digits = 0;
>        unsigned long t = x;

>        do ++digits; while (t /= 10);
>        // if (digits > d) d = digits; // uncomment to allow more digits than spec'd
>        *(p = b + d) = '\0';
>        do *--p = x % 10 + '0'; while (x /= 10);
>        while (p != b) *--p = ' ';
>        return b;
>     }
