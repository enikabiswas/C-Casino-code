//
//  main.cpp
//  Enika B Lab 6: Casino
//
//  Created by enika biswas on 7/24/17.
//  Copyright © 2017 enika biswas. All rights reserved.
//

#include <string>
#include <iostream>
#include <sstream>
#include <stdlib.h>
#include <ctime>
using namespace std;

//TripleString class prototype
class TripleString {

private:
   string string1, string2, string3;
   bool validString(string str);

public:
   static const int MAX_LEN;

   TripleString();

   //mutators and accessors prototype
   bool setString1(string str1);
   bool setString2(string str2);
   bool setString3(string str3);
   //using in-line to define accessor
   string getStrings(int strNum) {
      if(strNum == 1)
         return string1;
      else if(strNum == 2)
         return string2;
      else
         return string3;
   }

};

//Global scope method prototypes
int getBet();
TripleString pull();
string randString();
int getPayMultiplier(TripleString thePull);
void display (TripleString thePull, int winnings);

//Global scope constants
const int BAR = RAND_MAX*0.4;
const int CHERRIES = RAND_MAX*0.3;
const int SPACE = RAND_MAX*0.05;
const int MAX_BET = 50;
const int PAY_MULTIPLIER_5 = 5;
const int PAY_MULTIPLER_15 = 15;
const int PAY_MULTIPLER_30 = 30;
const int PAY_MULTIPLIER_50 = 50;
const int PAY_MULTIPLER_100 = 100;


//static member initialization
const int TripleString::MAX_LEN = 20;

// main method
int main() {
    int x = 1;
    srand((int)time(0));
    while(true) {
      x = getBet();
      if(x == 0)
         return 0;
      TripleString pulled = pull();
      int winnings = getPayMultiplier(pulled) * x;
      display(pulled, winnings);
      cout << endl << endl;
   }

   return 0;
}

//Global scope method definitions
int getBet()
{
   int betValue = -1;
   while(betValue < 0 || betValue > MAX_BET)
   {
      string bet = "";
      cout << "How much would you like to bet (1 - 50) "
      << "or 0 to quit? ";
      getline(cin, bet);
      istringstream(bet) >> betValue;
   }
   return betValue;

}

TripleString pull(){
   TripleString str;
   str.setString1(randString());
   str.setString2(randString());
   str.setString3(randString());
   return str;
}

string randString(){
   string slotMachinePulls = "";
   long randNum = rand()%RAND_MAX;
   if(randNum < BAR)
      slotMachinePulls = "BAR";
   else if((randNum >= BAR) && (randNum < BAR + CHERRIES))
      slotMachinePulls = "cherries";
   else if((randNum >= BAR + CHERRIES) && (randNum < BAR + CHERRIES + SPACE))
      slotMachinePulls = "space";
   else
      slotMachinePulls = "7";
   return slotMachinePulls;
}
int getPayMultiplier (TripleString thePull) {
   string string1 = thePull.getStrings(1);
   string string2 = thePull.getStrings(2);
   string string3 = thePull.getStrings(3);

   if(string1 == "cherries" && string2 != "cherries") {
      return PAY_MULTIPLIER_5; }
   else if((string1 == "cherries") && (string2 == "cherries"))
   {
      if((string3 != "cherries")) {
         return PAY_MULTIPLER_15; }
      else  {
         return PAY_MULTIPLER_30; }
   }
   else if(string1=="BAR" && string2=="BAR" && string3=="BAR") {
      return PAY_MULTIPLIER_50; }
   else if((string1=="7") && (string2=="7") && (string3=="7")) {
      return PAY_MULTIPLER_100; }
   else {
      return 0; }
}

void display (TripleString thePull, int winnings) {
   string string1 = thePull.getStrings(1);
   string string2 = thePull.getStrings(2);
   string string3 = thePull.getStrings(3);
   cout << "whirrr...and your pull is....." << endl;
   cout << "\t" << string1 + " " + string2 + " " + string3 << endl;
   if(winnings != 0)
      cout << "Congrats, you won $" << winnings << ".";
   else
      cout << "Sorry - you lost";

}
//class method definitions
//constructor
TripleString::TripleString()
{
   string1 = "";
   string2 = "";
   string3 = "";
}

bool TripleString::validString(string str){
   if(str.length() <= MAX_LEN)
      return true;
   return false;
}

//mutators definition
bool TripleString::setString1(string str1)
{
   if (validString(str1)) {
      string1 = str1;
      return true;
   }
   return false;
}
bool TripleString::setString2(string str2)
{
   if (validString(str2))
   {
      string2 = str2;
      return true;
   }
   return false;
}
bool TripleString::setString3(string str3)
{
   if (validString(str3)){
      string3 = str3;
      return true;
   }
   return false;
}
/* ----------------------------
 Got BAR BAR BAR at pulls #31, #35
 Got cherries cherries cherries at pull #34
 -------------- */
 /* -------Run-----------------
 How much would you like to bet (1 - 50) or 0 to quit? -55
 How much would you like to bet (1 - 50) or 0 to quit? 200
 How much would you like to bet (1 - 50) or 0 to quit? 40
 whirrr...and your pull is.....
	BAR BAR 7
 Sorry - you lost

 How much would you like to bet (1 - 50) or 0 to quit? 4
 whirrr...and your pull is.....
	cherries cherries BAR
 Congrats, you won $60.

 How much would you like to bet (1 - 50) or 0 to quit? 38
 whirrr...and your pull is.....
	BAR cherries cherries
 Sorry - you lost

 How much would you like to bet (1 - 50) or 0 to quit? 54
 How much would you like to bet (1 - 50) or 0 to quit? 32
 whirrr...and your pull is.....
	7 BAR cherries
 Sorry - you lost

 How much would you like to bet (1 - 50) or 0 to quit? 3
 whirrr...and your pull is.....
	7 BAR BAR
 Sorry - you lost

 How much would you like to bet (1 - 50) or 0 to quit? 5
 whirrr...and your pull is.....
	cherries cherries BAR
 Congrats, you won $75.

 How much would you like to bet (1 - 50) or 0 to quit? 20
 whirrr...and your pull is.....
	BAR BAR cherries
 Sorry - you lost

 How much would you like to bet (1 - 50) or 0 to quit? 34
 whirrr...and your pull is.....
	cherries cherries 7
 Congrats, you won $510.

 How much would you like to bet (1 - 50) or 0 to quit? 45
 whirrr...and your pull is.....
	7 cherries BAR
 Sorry - you lost

 How much would you like to bet (1 - 50) or 0 to quit? 31
 whirrr...and your pull is.....
	cherries cherries space
 Congrats, you won $465.

 How much would you like to bet (1 - 50) or 0 to quit? 35
 whirrr...and your pull is.....
	7 7 BAR
 Sorry - you lost

 How much would you like to bet (1 - 50) or 0 to quit? 42
 whirrr...and your pull is.....
	BAR space BAR
 Sorry - you lost

 How much would you like to bet (1 - 50) or 0 to quit? 50
 whirrr...and your pull is.....
	cherries 7 7
 Congrats, you won $250.

 How much would you like to bet (1 - 50) or 0 to quit? 17
 whirrr...and your pull is.....
	BAR BAR 7
 Sorry - you lost

 How much would you like to bet (1 - 50) or 0 to quit? 27
 whirrr...and your pull is.....
	space 7 cherries
 Sorry - you lost

 How much would you like to bet (1 - 50) or 0 to quit? 37
 whirrr...and your pull is.....
	BAR cherries 7
 Sorry - you lost

 How much would you like to bet (1 - 50) or 0 to quit? 47
 whirrr...and your pull is.....
	BAR cherries 7
 Sorry - you lost

 How much would you like to bet (1 - 50) or 0 to quit? 53
 How much would you like to bet (1 - 50) or 0 to quit? 49
 whirrr...and your pull is.....
	cherries BAR BAR
 Congrats, you won $245.

 How much would you like to bet (1 - 50) or 0 to quit? 33
 whirrr...and your pull is.....
	BAR BAR cherries
 Sorry - you lost

 How much would you like to bet (1 - 50) or 0 to quit? 28
 whirrr...and your pull is.....
	7 7 BAR
 Sorry - you lost

 How much would you like to bet (1 - 50) or 0 to quit? 48
 whirrr...and your pull is.....
	7 cherries cherries
 Sorry - you lost

 How much would you like to bet (1 - 50) or 0 to quit? 49
 whirrr...and your pull is.....
	BAR 7 cherries
 Sorry - you lost

 How much would you like to bet (1 - 50) or 0 to quit? 36
 whirrr...and your pull is.....
	BAR BAR 7
 Sorry - you lost

 How much would you like to bet (1 - 50) or 0 to quit? 54
 How much would you like to bet (1 - 50) or 0 to quit? 50
 whirrr...and your pull is.....
	BAR cherries BAR
 Sorry - you lost

 How much would you like to bet (1 - 50) or 0 to quit? 43
 whirrr...and your pull is.....
	BAR 7 cherries
 Sorry - you lost

 How much would you like to bet (1 - 50) or 0 to quit? 44
 whirrr...and your pull is.....
	cherries 7 BAR
 Congrats, you won $220.

 How much would you like to bet (1 - 50) or 0 to quit? 31
 whirrr...and your pull is.....
	7 7 7
 Congrats, you won $3100.

 How much would you like to bet (1 - 50) or 0 to quit? 35
 whirrr...and your pull is.....
	BAR BAR cherries
 Sorry - you lost

 How much would you like to bet (1 - 50) or 0 to quit? 38
 whirrr...and your pull is.....
	7 cherries space
 Sorry - you lost

 How much would you like to bet (1 - 50) or 0 to quit? 46
 whirrr...and your pull is.....
	space 7 7
 Sorry - you lost

 How much would you like to bet (1 - 50) or 0 to quit? 36
 whirrr...and your pull is.....
	BAR BAR BAR
 Congrats, you won $1800.

 How much would you like to bet (1 - 50) or 0 to quit? 48
 whirrr...and your pull is.....
	cherries cherries 7
 Congrats, you won $720.

 How much would you like to bet (1 - 50) or 0 to quit? 45
 whirrr...and your pull is.....
	cherries 7 BAR
 Congrats, you won $225.

 How much would you like to bet (1 - 50) or 0 to quit? 50
 whirrr...and your pull is.....
	cherries cherries cherries
 Congrats, you won $1500.

 How much would you like to bet (1 - 50) or 0 to quit? 32
 whirrr...and your pull is.....
	BAR BAR BAR
 Congrats, you won $1600.

 How much would you like to bet (1 - 50) or 0 to quit? 45
 whirrr...and your pull is.....
	cherries 7 BAR
 Congrats, you won $225.

 How much would you like to bet (1 - 50) or 0 to quit? 37
 whirrr...and your pull is.....
	cherries cherries 7
 Congrats, you won $555.

 How much would you like to bet (1 - 50) or 0 to quit? 8
 whirrr...and your pull is.....
	BAR BAR 7
 Sorry - you lost

 How much would you like to bet (1 - 50) or 0 to quit? 43
 whirrr...and your pull is.....
	cherries cherries BAR
 Congrats, you won $645.

 How much would you like to bet (1 - 50) or 0 to quit? 19
 whirrr...and your pull is.....
	BAR cherries cherries
 Sorry - you lost

 How much would you like to bet (1 - 50) or 0 to quit? 42
 whirrr...and your pull is.....
	7 BAR cherries
 Sorry - you lost

 How much would you like to bet (1 - 50) or 0 to quit? 0
 Program ended with exit code: 0
 ------------------------------------------- */


