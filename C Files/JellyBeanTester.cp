#include <stdio.h>
#include <string.h>

struct JellyBean
{
  char flavor[15];
  char color[15];
  int EatMe;    //this is supposed to be a boolean
};

//functions
void createJellyBean();
void processJellyBean();
void printJellyBean(struct JellyBean jb);

//instances of Jelly Bean struct
JellyBean jb1;
JellyBean jb2;
JellyBean jb3;

int main(int argc, char const *argv[]) {

  createJellyBean();
  processJellyBean();

  printJellyBean(jb1);
  printJellyBean(jb2);
  printJellyBean(jb3);
  return 0;
}

//NOTE: entering a word bigger than 15 charc would cause the input to be messed up.
void createJellyBean()
{
  char col[15];
  char flav[15];

  //Jelly Bean 1
  printf("Enter the color of the first jelly bean: \n");
  fgets(col, 15, stdin);
  col[strcspn(col, "\n")] = 0;
  strcpy(jb1.color, col);

  printf("Enter the flavor of the first jelly bean\n");
  fgets(flav, 15, stdin);
  flav[strcspn(flav, "\n")] = 0;
  strcpy(jb1.flavor, flav);

  //Jelly Bean 2
  printf("\nEnter the color of the second jelly bean: \n");
  fgets(col, 15, stdin);
  col[strcspn(col, "\n")] = 0;
  strcpy(jb2.color, col);

  printf("Enter the flavor of the second jelly bean\n");
  fgets(flav, 15, stdin);
  flav[strcspn(flav, "\n")] = 0;
  strcpy(jb2.flavor, flav);

  //Jelly Bean 3
  printf("\nEnter the color of the third jelly bean: \n");
  fgets(col, 15, stdin);
  col[strcspn(col, "\n")] = 0;
  strcpy(jb3.color, col);

  printf("Enter the flavor of the third jelly bean\n");
  fgets(flav, 15, stdin);
  flav[strcspn(flav, "\n")] = 0;
  strcpy(jb3.flavor, flav);
}

void processJellyBean()
{
  int orangeBeanCounter = 0;

  //Jelly Bean 1
  if(strcmpi(jb1.color, "Orange") == 0)
  {
    orangeBeanCounter++;
    jb1.EatMe = true;
  }

  //Jelly Bean 2
  if(strcmpi(jb2.color, "Orange") == 0)
  {
    orangeBeanCounter++;
    jb2.EatMe = true;
  }

  //Jelly Bean 3
  if(strcmpi(jb3.color, "Orange") == 0)
  {
    orangeBeanCounter++;
    jb3.EatMe = true;
  }

}

void printJellyBean(struct JellyBean jb)
{
  printf("\n");
  printf("Color: %s\n", jb.color);
  printf("Flavor: %s\n",jb.flavor);
  printf("EatMe: %s\n", "false\0true" + 6*jb.EatMe);  //to printf true or false
}
