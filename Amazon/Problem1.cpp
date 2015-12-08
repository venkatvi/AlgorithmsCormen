//racecar
//i am mai
//race!car
//!!!
//"", very large string
//ABC, 122

bool isAPalindrome(const string &str) {
    //Idea:
    //copiedStr = str - remove all special characters, spaces
    //i - start of string, j - end of strin
    // i++, --j : you see the same character
    // Time and Space: O(n)
   int i=0; j = str.length()-1;
   while(i < j){
       if (str[i] < 97 || str[i] >122) { 
           ++i; 
       }else if (str[j] < 97 || str[j] > 122){
           --j;
       }
       else{
           if(str[i] != str[j]){
               return false;
           }
           ++i;
           --j;
       }
   }
   return true;   
}
// race!car
// i =r, j = r
// i = a, j = a
// i = c, j = c
// i= e, j = e

//i= ! j =!
//i = ! j =!


