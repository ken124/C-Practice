#include <stdio.h>
#include <string.h>

struct SuperHeroDomain
{
  char firstName[50];
  char lastName[50];
  char superPower[50];
  char favColor[50];
};

struct SuperHeroDomain myHero;    //create a variable of type SuperHeroDomain

//when using string arrays in Structures you have to use strcpy to move variables into the structure

void getDataFromUser()
{
  char fName[50];
  char lName[50];
  char sPower[50];
  char fColor[50];

  //fgets adds an extra '\n' at the end, so it messes with strcmp, so we have to remove it
  printf("What is your first name?\n");
  fgets(fName, 50, stdin);
  fName[strcspn(fName, "\n")] = 0;
  strcpy(myHero.firstName, fName);

  printf("What is your last name?\n");
  fgets(lName, 50, stdin);
  lName[strcspn(lName, "\n")] = 0;
  strcpy(myHero.lastName, lName);

  printf("What is your super power?\n");
  fgets(sPower, 50, stdin);
  sPower[strcspn(sPower, "\n")] = 0;
  strcpy(myHero.superPower, sPower);

  printf("What is your favorite color?\n");
  fgets(fColor, 50, stdin);
  fColor[strcspn(fColor, "\n")] = 0;
  strcpy(myHero.favColor, fColor);

  printf("\n*************************************\n");
};



void determineSuperHeroIdentity()
{
  printf("First Name: %s\n", myHero.firstName);
  printf("Last Name: %s\n", myHero.lastName);
  printf("Super Power: %s\n", myHero.superPower);
  printf("Favorite Color: %s\n",  myHero.favColor);

  if(strcmpi(myHero.favColor, "Red") == 0)
    printf("You must be Spiderman!\n");
  if(strcmpi(myHero.favColor, "Green") == 0)
    printf("You must be the Green Goblin!\n");
  if(strcmpi(myHero.favColor, "Black") == 0)
    printf("You must be Batman!\n");
  if(strcmpi(myHero.favColor, "Blue") == 0)
    printf("You must be Captain America!\n");
  if(strcmpi(myHero.favColor, "Purple") == 0)
    printf("You must be the Magneto!\n");
  else
    printf("You are a mysterious super hero...\n");


};

int main(int argc, char const *argv[]) {

  getDataFromUser();
  determineSuperHeroIdentity();

  return 0;
}
