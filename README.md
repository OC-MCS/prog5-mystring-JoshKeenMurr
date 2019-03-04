# prog5-mystring-JoshKeenMurr
prog5-mystring-JoshKeenMurr created by GitHub Classroom  

Two bugs:
1) else if (*str == *other.str) checks to see if only the first char of each string is the same. These are ptr to char, so *ptr is the single char pointed at  
   Why not use the strcmp function that I gave you in the assignment that handles this correctly?  
   
2) Your functions will crash is passed a default-constructed MyString (need to check for nullptr everywhere)  

Grade: 35/40  
