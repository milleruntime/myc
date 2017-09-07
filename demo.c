#include<stdio.h>
#define SFILE_FORMAT 1
#define SFILE_NAME "info"
// strength-endurance-speed-agility

int getInput(char* prompt);
void createFile(FILE * fp);
void readFile(FILE * fp);

int main(void) {
   int str, endur, speed, agil;
   FILE *fp = fopen(SFILE_NAME, "a");

   //check if file is empty or not
   //long fileSize = ftell(fp);
   printf("File loc: %ld\n", ftell(fp));
   if (ftell(fp) == 0) 
      createFile(fp);
   else {
      //rewind(fp);
      fp = fopen(SFILE_NAME, "r");
      printf("File loc after reopen: %ld\n", ftell(fp));
      readFile(fp);
   }

   fclose(fp);
   return 0;
}

void createFile(FILE * fp) {
   int str, endur, speed, agil;
   str = getInput("Enter your strength: ");
   if (str > 10) puts("Wow dude you are strong!");
   else puts("you wuss");

   endur = getInput("Enter your endurance: ");
   speed = getInput("Enter your speed: ");
   agil = getInput("Enter your agility: ");

   fprintf(fp, "Format X%d\n", SFILE_FORMAT);
   fprintf(fp, "%d-%d-%d-%d\n", str, endur, speed, agil);
}

void readFile(FILE * fp) {
   puts("Read file");
   int c;
   int format = -1;
   while (c != EOF) {
      c = fgetc(fp);
      if ((char)c == 'X')
         format = fgetc(fp);
   }
   printf("Format read %c", format);
   return;
}

int getInput(char* prompt) {
   int input;
   puts(prompt);
   scanf("%d", &input);
   return input;
}
