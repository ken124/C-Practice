#include <stdio.h>
#include <string.h>

struct Pizza
{
  char custName[50];
  char handThinDeep;
  int pizSize;
  int cheese;
  int pepperoni;
  int sausage;
  int onion;
  int mushroom;
};


void getUserInput();
void calculatePizzaCost();
void checkForDiscount();
void calculateTax();
void displayFinalPrice();

Pizza myPizza;

int main(int argc, char const *argv[]) {
  printf("This is the main method...\n");
  getUserInput();

  return 0;
}

void getUserInput()
{
  char fName[50];
  char userInput;
  char pizzaType;
  myPizza.cheese = false;
  myPizza.pepperoni = false;
  myPizza.sausage = false;
  myPizza.onion = false;
  myPizza.mushroom = false;

  printf("Welcome to Mike and Diane's Pizza!\n");

  //get the user's name
  printf("Please enter your first name: \n");
  fgets(fName, 50, stdin);
  fName[strcspn(fName, "\n")] = 0;
  strcpy(myPizza.custName, fName);

  printf("\n***************************************\n");

  //prompt user and get pizza size choice
  printf("Pizza Size Cost: \n");
  printf("10' $10.99\n");
  printf("12' $12.99\n");
  printf("14' $12.99\n");
  printf("16' $12.99\n");

  printf("\nWhat size pizza would you like? \n");
  printf("10, 12, 14, or 16 (Enter the number only...)\n");
  scanf("%d", &myPizza.pizSize);

  printf("\n***************************************\n");

  printf("What type of crust would you like?\n");
  printf("(H)Hand-tossed, (T)Thin-crust, or (D)Deep-dish\n");
  printf("(Enter H, T, or D): \n");
  scanf("%c\n", &myPizza.handThinDeep);

}
