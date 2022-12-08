// Compares string with the keywords
bool isEqual(char *str1, char *str2){
   for (; *str1 && *str2 && *str1 == *str2; str1++,str2++);
   return (!(*str1) && !(*str2))? true : false;
}
// Checks if string is equal with keyword array
bool isValidKeyword(char* str) {
   char *const keywords[] = {
      "go to", "return", "while", "break", "do", "switch", "include", "default",
      "boolean", "case", "void", "else", "for", "if", "int", "float", "string",
      "char", "printf", "scanf" };


   int size = sizeof(keywords) / sizeof(*keywords);

   for (int i = 0; i < size; i++){
      if(isEqual(str, *(keywords + i))){
         return true;
      }
   }
   return false;  
 }

bool isValidDelimiter(char ch) {
   if (ch == ' ' || ch == '+' || ch == '-' || ch == '*' ||
   ch == '/' || ch == ',' || ch == ';' || ch == '>' ||
   ch == '<' || ch == '=' || ch == '(' || ch == ')' ||
   ch == '[' || ch == ']' || ch == '{' || ch == '}')
   return (true);
   return (false);
}
bool isValidOperator(char ch){
   if (ch == '+' || ch == '-' || ch == '*' ||
   ch == '/' || ch == '>' || ch == '<' ||
   ch == '=' || ch == '%' || ch == '~' || 
   ch == '^')
   return (true);
   return (false);
}

bool isValidCommentContent(char* str){
   if (str[0] == 'A' || str[0] == 'B' || str[0] == 'C' ||
   str[0] == 'D' || str[0] == 'E' || str[0] == 'F' ||
   str[0] == 'G' || str[0] == 'H' || str[0] == 'I' || 
   str[0] == 'J' || str[0] == 'K' || str[0] == 'L' || 
   str[0] == 'M' || str[0] == 'N' || str[0] == 'O' ||
   str[0] == 'P' || str[0] == 'Q' || str[0] == 'R' || 
   str[0] == 'S' || str[0] == 'T' || str[0] == 'U' || 
   str[0] == 'V' || str[0] == 'W' || str[0] == 'X' || 
   str[0] == 'Y' || str[0] == 'Z'){
      return (true);
   }else
      return (false);
}


bool isValidComment(char* str){
   int i, len = strlen(str);
   for (i = 0; i <=len; i++) {
      if (str[0] == 'e' && str[1] == 'n' && str[2] == 'y' && str[3] == 'e')
      return (true);
   }
   return (false);
}
// Returns 'true' if the string is a VALID IDENTIFIER.
bool isvalidIdentifier(char* str){
   if (str[0] == '0' || str[0] == '1' || str[0] == '2' ||
   str[0] == '3' || str[0] == '4' || str[0] == '5' ||
   str[0] == '6' || str[0] == '7' || str[0] == '8' ||
   str[0] == '9' || isValidDelimiter(str[0]) == true)
   return (false);
   return (true);
}
bool isValidInteger(char* str) {
   int i, len = strlen(str);
   if (len == 0)
   return (false);
   for (i = 0; i < len; i++) {
      if (str[i] != '0' && str[i] != '1' && str[i] != '2'&& str[i] != '3' && str[i] != '4' && str[i] != '5'
      && str[i] != '6' && str[i] != '7' && str[i] != '8' && str[i] != '9' || (str[i] == '-' && i > 0))
      return (false);
   }
   return (true);
}
bool isRealNumber(char* str) {
   int i, len = strlen(str);
   bool hasDecimal = false;
   if (len == 0)
   return (false);
   for (i = 0; i < len; i++) {
      if (str[i] != '0' && str[i] != '1' && str[i] != '2' && str[i] != '3' && str[i] != '4' && str[i]       != '5' && str[i] != '6' && str[i] != '7' && str[i] != '8'
      && str[i] != '9' && str[i] != '.' || (str[i] == '-' && i > 0))
      return (false);
         if (str[i] == '.')
      hasDecimal = true;
   }
   return (hasDecimal);
}
char* subString(char* str, int left, int right) {
   int i;
   char* subStr = (char*)malloc( sizeof(char) * (right - left + 2));
   for (i = left; i <= right; i++)
      subStr[i - left] = str[i];
   subStr[right - left + 1] = '\0';
   return (subStr);
}

void detectTokens(char* str) {
   int left = 0, right = 0;
   int length = strlen(str);
   while (right <= length && left <= right) {
      if (isValidDelimiter(str[right]) == false)
      right++;
      if (isValidDelimiter(str[right]) == true && left == right) {
         if (isValidOperator(str[right]) == true)
         printf("Valid operator : '%c'\n", str[right]);
         right++;
         left = right;
         // if (isUnaryOperator(str[right]) == true)
         // printf("Valid unary operator : '%c'\n", str[right]);
         // right++;
         // left = right;
      } else if (isValidDelimiter(str[right]) == true && left != right || (right == length && left != right)) {
         char* subStr = subString(str, left, right - 1);
         if (isValidKeyword(subStr) == true)
            printf("Keyword : '%s'\n", subStr);
         else if (isValidComment(subStr) == true)
            printf("Comment : '%s'\n", subStr);
          else if (isValidCommentContent(subStr) == true){
            printf("Comment Content : '%s'\n", subStr);
         }
         else if (isValidInteger(subStr) == true)
            printf("Integer : '%s'\n", subStr);
         else if (isRealNumber(subStr) == true)
            printf("Number : '%s'\n", subStr);
         else if (isvalidIdentifier(subStr) == true
            && isValidDelimiter(str[right - 1]) == false)
         printf("Identifier : '%s'\n", subStr);
         else if (isvalidIdentifier(subStr) == false
            && isValidDelimiter(str[right - 1]) == false)
         printf("Invalid Identifier : '%s'\n", subStr);
         left = right;
      }
   }
   return;
}
