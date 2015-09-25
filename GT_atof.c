/* 
   function : GT_atof

   description:   attempt at a simple, fast atof routine
                  (for known magnitude numbers)
                  Conversion from text to floating point.
 
   assume: 1. all numbers will be smaller/larger than 1.0E +/-19
           2. there are no scientific notation type strings
           3. leading blanks (spaces) have been removed
           4. negative sign must appear in the first character (if it does at all)

   comments:  this routine may be up to 3 times faster than stdlib's atof or sscanf
 
 

   by Nathan E Frick, Texas

	


*/

double GT_atof(char *s)

{ double tf;
  int nc,d,i,j,neg;

  tf = 0.0;
  if (s[0] == '-')
  { neg = 1;
  }
  else
  { neg = 0;
  }
  /* search for decimal point */
  for (nc=neg;( isdigit(s[nc]) &&
              (s[nc] != '.') &&
              (s[nc] != '\0')); nc++) ;
  for (i=neg; ( (isdigit(s[i]) || (s[i] == '.')) &&
                (s[i] != '\0') ) ;i++)
  {     /* printf("%c %d %lf\n",s[i],nc-i,tf); */
    switch((nc-i))
    { case 0:break; /* we're at the decimal point */
      case 1:tf += (s[i] - '0');  break; /* one's place */
      case 2:tf += (s[i] - '0') * 10; break;
      case 3:tf += (s[i] - '0') * 100; break;
      case 4:tf += (s[i] - '0') * 1000; break;
      case 5:tf += (s[i] - '0') * 10000; break;
      case 6:tf += (s[i] - '0') * 100000; break;
      case 7:tf += (s[i] - '0') * 1000000; break;
      case 8:tf += (s[i] - '0') * 10000000; break;
      case 9:tf += (s[i] - '0') * 100000000.0; break;
      case 10:tf += (s[i] - '0') * 1000000000.0; break;
      case 11:tf += (s[i] - '0') * 10000000000.0;  break; 
      case 12:tf += (s[i] - '0') * 100000000000.0; break;
      case 13:tf += (s[i] - '0') * 1000000000000.0; break;
      case 14:tf += (s[i] - '0') * 10000000000000.0; break;
      case 15:tf += (s[i] - '0') * 100000000000000.0; break;
      case 16:tf += (s[i] - '0') * 1000000000000000.0; break;
      case 17:tf += (s[i] - '0') * 10000000000000000.0; break;
      case 18:tf += (s[i] - '0') * 100000000000000000.0; break;
      case 19:tf += (s[i] - '0') * 1000000000000000000.0; break;
      case -1:tf += (s[i] - '0') * 0.1; break;
      case -2:tf += (s[i] - '0') * 0.01; break;
      case -3:tf += (s[i] - '0') * 0.001; break;
      case -4:tf += (s[i] - '0') * 0.0001; break;
      case -5:tf += (s[i] - '0') * 0.00001; break;
      case -6:tf += (s[i] - '0') * 0.000001; break;
      case -7:tf += (s[i] - '0') * 0.0000001; break;
      case -8:tf += (s[i] - '0') * 0.00000001; break;
      case -9:tf += (s[i] - '0') * 0.000000001; break;
      case -10:tf += (s[i] - '0') * 0.0000000001; break;
      case -11:tf += (s[i] - '0') * 0.00000000001; break;
      case -12:tf += (s[i] - '0') * 0.000000000001; break;
      case -13:tf += (s[i] - '0') * 0.0000000000001; break;
      case -14:tf += (s[i] - '0') * 0.00000000000001; break;
      case -15:tf += (s[i] - '0') * 0.000000000000001; break;
      case -16:tf += (s[i] - '0') * 0.0000000000000001; break;
      case -17:tf += (s[i] - '0') * 0.00000000000000001; break;
      case -18:tf += (s[i] - '0') * 0.000000000000000001; break;
      case -19:tf += (s[i] - '0') * 0.0000000000000000001; break;
      default : break;
    }
  }
  if (neg) tf *= -1.0;
  return(tf);
}

