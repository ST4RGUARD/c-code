#define _USE_MATH_DEFINES	//needs to be defined b4 include math.h
#define PI 3.14				//const defined - but CAN be redfined
#define STRLEN 4
#define NUMBER_OF_CDS 4
#define _CRT_SECURE_NO_WARNINGS
#define FILENAME "test.txt"
#define MAXSTRLEN 200

#include <stdio.h>
#include <math.h>
#include <ctype.h>
#include <string.h>
#include "mystring.h"  // - include header file in project

// enumeration constant can't be changed - assigned from 0, 1 etc 
enum days {
  Monday, Tuesday, Wednesday, Thursday, Friday, Saturday, Sunday
};
enum suits {
  Hearts, Diamonds, Clubs,Spades
};
// but can have own values assigned
enum numbers {
  Couple = 2, Dozen = 12, Score = 20
};

// will use with our struct example
enum score {
  Terrible, Bad, Average, Good, Excellent
};


void flush_input();
int readln(char, int);
void find_char_type(int);
void show_ascii();
void show_string(char);
char * string_function(char);
char * string_function_dynamic(char);
void chartypes();
void create_cdcollection();
void display_cdcollection();
void show_card();
void show_day_type();
void buy_in_bulk();
void add_numbers();
void read_file();
void write_file();
void clear_file();
void delete_file();

// only put here for simple use with all examples
const char str1[] = "Hello";
const char *str2 = "Goodbyeworld";
const char greeting[STRLEN];
char mystring[] = "This will be 1 good example of a long string with a bunch of different Things in it! let's see:";

int main(int argc, char *argv[]) {
  enum days today;
  enum suits playingcard;
  enum numbers num;
  today = Saturday;                   // could set these enums here or somewhere else in our code
  playingcard = Diamonds;
  num = Dozen;
	int subtotal;
	double tax;
	double grandtotal;
	double taxrate;
	const double TAXRATE_CONST = .175;	// cannot redifine this const
	int age=0,num1,num2,row,column;
	char agestring[10], ch;             // handles user input
  int grid[2][3] = {                  // multi dimen array rxc
    {1, 2, 3},
    {4, 5, 6}
  };

  // use for loops to iterate through rows and columns of multi array
  for (row = 0; row < 2; row++) {
    printf("--- row %d --- \n", row);
    for (column = 0; column < 3; column++) {
      printf("column [%d], value=%d\n", column,grid[row][column]);

    }
  }

	taxrate    = 0.175;
	subtotal   = 200;
	tax        = subtotal * taxrate;
	grandtotal = subtotal + tax;

	printf("The tax on %d is %.f, so the grand total is %.f", subtotal, tax, grandtotal);
	printf("\n\n%.10f\n", M_PI);
	printf("\n%f\n", PI);

	//operators
	printf("Enter your age: ");
	//gets(agestring);                    //unsafe takes any amt of txt or chars 
                                        //char agestring[10] will spill over into other mem (buffer) if >= 9 bc of null
	fgets(agestring, 10, stdin);          //same here will read 9 but more will be allocated into buffer to be processed in next read
	//flush_input();                        //too confusing & not good enough error checking
	                                      // calling our flush_input() that process extra chars in buffer til newline or EOF
	                                      //fflush, tcflush, or rewind may only work in some instances
                                        //fgets reads first newline so flush_input will read 2nd..have to press enter twice

	age = atoi(agestring);
	if (age == 0) {
		printf("invalid age");
	}
	else {
		if (age > 45) {
			printf("over hump");
		}
		else {
			printf("no hump");
		}
	}
	//increment/decrement
	printf("age = %s", agestring);
	num1 = 10;
	num2 = num1++;					 //10   11
	printf("\nnum2 = %d & num = %d ", num2, num1);
	num1 = 10;
	num2 = ++num1;					 //11	11
	printf("\nnum2 = %d & num = %d ", num2, num1);
  
  char ascii[BUFSIZE];
  int len_ascii;
  printf("\nEnter chartype: ");
  len_ascii = readln(ascii, BUFSIZE);
  printf("your char: %s \n", ascii);
  printf("len char: %d \n", len_ascii);
  int numberz = atoi(ascii);
  printf("your num: %d \n", numberz);

  //show_ascii();

  find_char_type(numberz);

  // do while same c++ syntax
  // char arrays and pointers
  //show_string(str1);
  //show_string(str2);

  printf("%x %x %s\n", &str1, str1, str1); // name of str1 & address of str1 or start of Hello is the same address
  printf("%x %x %s\n", &str2, str2, str2); // not true for pointer str2 - string Goodbeye occupies 1 address, pointer is different address
                                           // pointer str2 (it's data) is the address of the string Goodbye - so it points to the string goodbye
	
  str2 = &str1;   // str2 gets address of str1 (or string Hello)
  str2 = str1;    // same thing str1 array is address of string Hello, so str2 now points to address of str1
  // see below
  char blah1[] = "Hello"; // array initialized with characters hello
  char *blah2  = "Hello"; // pointer to an array of characters hello
  char blah3[6];          // fixed length array of 6 chars not initialized

  blah3[0] = 'H';
  blah3[1] = 'e';
  blah3[2] = 'l';
  blah3[3] = 'l';
  blah3[4] = 'o';
  blah3[5] = '\0';

  // cannot re-initialize the array -VisualStudio tells us this
  // blah1 = "goodbye";
  // can change our pointer blah2
  blah2 = "goodbye";

  //printf(string_function("Fred"));
  //printf(string_function_dynamic("Mary"));

  // strncpy_s over strncpy
  // thing of chars 'x' strings "x" compiler may allow it but function may not work properly
  chartypes();

  //structs
  create_cdcollection();
  display_cdcollection();
  printf("\n");
  printf("\n");

  //enums
  show_card(playingcard);
  printf("\n");
  show_day_type(today);
  printf("\n");
  buy_in_bulk(num);

  add_numbers();
  add_numbers();
  add_numbers();

  // read & write file r,w,a,r+ - read&write file must exist w+ -empty file read&write overwrites a+ -creates if not exist b -binary
 /* write_file();
  read_file();
  clear_file();
  delete_file();*/

  //// malloc - if we have some var like pointer bar
  //char *bar;
  //// type cast malloc to match our pointer
  //bar = (char*)malloc(10);
  //// free up our memory allocated
  //free(bar);


  getchar();
	return 0;
}

char *chartype;

void find_char_type(int i) {
  
  switch (i) {
    case 0:
      chartype = "NULL";
      break;
    case 7:
      chartype = "Bell";
      break;
    case 78:
      chartype = "BackSpace";
    case 9:
      chartype = "Tab";
      break;
    case 10:
      chartype = "LineFeed";
      break;
    case 13:
      chartype = "Carriage Return";
      break;
    case 32:
      chartype = "Space";
      break;
    case 48:
    case 49:
    case 50:
    case 51:
    case 52:
    case 53:
    case 54:
    case 55:
    case 56:
    case 57:
      chartype = "Number";
      break;
    default:
      chartype = "Character";
      break;
    
  }

  printf("Chartype is: %s \n", chartype);
}

void show_ascii() {
  int i;
  char c;
  for (i = 0; i <= 127; i++) {
    find_char_type(i);
    printf("%d = %c\t\t[%s]\n", i, i, chartype);
  }
  getchar();
}

// only reads to first null in string
void show_string(char *str) {
  int i;
  int len = strlen(str);
  printf("Length of %s is %d.\n", str, len);
  for (i = 0; i <= len; i++) {
    if (str[i] == '\0') {
      printf("char[%d] = NULL\n", i);
    }
    else {
      printf("char[%d] = %c\n", i, str[i]);
    }
  }
}

// our responsibility to validate input
//char * string_function(char astring[]) {
//  strcat(greeting, "hello");
//  strcat(greeting, astring);
//  strcat(greeting, "\n");
//  return greeting;
//}

// not safe to return strings inside a func that were allocated on stack - use malloc to allocate global available mem
//char * string_function_dynamic(char *astring) {
//  char *s;
//  s = malloc(STRLEN);
//  s[0] = 0;             //need this to initialize the buffer created by malloc
//  strcat(s, "hello ");
//  strcat(s, astring);
//  strcat(s, "\n");
//  return s;
//}


void flush_input() {
  int ch;
  while ((ch = getchar()) != '\n' && ch != EOF);
}

//int readln(char s[], int maxlen) {
//	int len_s;
//	fgets(s, maxlen, stdin);
//	len_s = strlen(s);
//	if (s[len_s - 1] == '\n') {
//		s[len_s - 1] == '\0';
//		len_s -= 1;
//	}
//	rewind(stdin); //flushes keyboard buffer on windows..need to check functionality for other systems
//	return len_s
//}

//read chars 1 by 1 in order to flush remainder from keyboard buffer much better - will include in custom hdr
//int readln(char s[], int maxlen) {
//  char ch;
//  int i;
//  int chars_remain;
//  i = 0;
//  chars_remain = 1;
//  while (chars_remain) {
//    ch = getchar();
//    if ((ch == '\n') || (ch == EOF)) {
//      chars_remain = 0;
//    }
//    else if (i < maxlen - 1) {
//      s[i] = ch;
//      i++;
//    }
//  }
//  s[i] = '\0';
//  return i;
//}

void chartypes() {
  int i;
  char c;
  int numDigits = 0;
  int numLetters = 0;
  int numUpCase = 0;
  int numLowCase = 0;
  int numSpaces= 0;
  int numPunct = 0;
  int numUnknown = 0;
  int lengthOfStr = 0;
  lengthOfStr = strlen(mystring);

  for (i = 0; i < lengthOfStr; i++) {
    c = mystring[i];
    if (isalpha(c)) {
      numLetters++;
      if (isupper(c)) {
        printf("'%c' [uppercase]\n", c);
        numUpCase++;
      }
      else {
        printf("'%c' [lowercase]\n", c);
        numLowCase++;
      }
    }
    else if (isdigit(c)) {
      printf("'%c' [digit]\n", c);
      numDigits++;
    }
    else if (ispunct(c)) {
      printf("'%c' [punctuation]\n", c);
      numPunct++;
    }
    else if (isblank(c)) {
      printf("'%c' [blank]\n", c);
      numSpaces++;
    }
    else {
      printf("'%c' [unknown]\n", c);
      numUnknown++;
    }
  }

  printf("This string contains %i characters: %i letters (%i uppercase, %i lowercase) %i digits, %i punctuation characters, %i spaces and %i unclassified characters", lengthOfStr, numLetters,numUpCase,numLowCase,numDigits,numPunct,numSpaces,numUnknown);
}

//struct cd {
//  char name[50];
//  char artist[50];
//  int trackcount;
//  int rating;
//};

// typedef struct alternative
typedef char Str50[50];

typedef struct cd {
  Str50 name;
  Str50 artist;
  int trackcount;
  enum score rating;
} CD;

//struct cd cd_collection[NUMBER_OF_CDS];
// typedef array declaration alternative
CD cd_collection[NUMBER_OF_CDS];

// of course strcpy is not safe
void create_cdcollection() {
  strcpy(cd_collection[0].name, "Great Hits");
  strcpy(cd_collection[0].artist, "Van Halen");
  cd_collection[0].trackcount = 20;
  cd_collection[0].rating = Excellent;

  strcpy(cd_collection[1].name, "Mega Songs");
  strcpy(cd_collection[1].artist, "Pharell Williams");
  cd_collection[1].trackcount = 18;
  cd_collection[1].rating = Good;

  strcpy(cd_collection[2].name, "Test");
  strcpy(cd_collection[2].artist, "blah");
  cd_collection[2].trackcount = 20;
  cd_collection[2].rating = Average;

  strcpy(cd_collection[3].name, "Mega");
  strcpy(cd_collection[3].artist, "juice");
  cd_collection[3].trackcount = 18;
  cd_collection[3].rating = Terrible;
}

void display_cdcollection() {
  int i;
  //struct cd thiscd;
  // with typedef
  CD thiscd;
  for (i = 0; i < NUMBER_OF_CDS; i++) {
    thiscd = cd_collection[i];
    printf("\n\nCD #%d '%s' by %s has %d tracks.  My rating = %d\n", i, thiscd.name, thiscd.artist, thiscd.trackcount, thiscd.rating);
  }
}

void show_card(enum suits card) {
  if ((card == Hearts) || (card == Diamonds)) {             // an alt to line below - is more descriptive representation
    //if ((card == 0) || (card == 1)){
    printf("This card is red (in suit #%d).\n", card);
  }
  else {
    printf("This is a black card.\n");
  }
}

void show_day_type(enum days day) {
  if ((day == Saturday) || (day == Sunday)) {
    printf("It's the weekend!\n");
  }
  else {
    printf("It's a working day :(\n");
  }
}

void buy_in_bulk(enum numbers num) {
  printf("The customer wants to buy %d items\n", num);
}

// static function is private (can only be called) within the file in which it occurs
// static var retains its value between function calls

void add_numbers() {
  static int x = 0;
  int y = 0;
  x++;
  y++;
  printf("\nadd_numbers() x=%d y=%d\n", x, y);
}

void read_file() {
  FILE *fp = fopen(FILENAME, "r");
  char line[MAXSTRLEN];
  if (fp != 0) {
    while (fgets(line, sizeof(line), fp) != 0) {
      fputs(line, stdout);
    }
    fclose(fp);
  }
  else {
    printf("File %s cannot be opened!", FILENAME);
  }
}

void write_file() {
  FILE *fp;
  fp = fopen(FILENAME, "w");
  fputs("Hi peeps\n", fp);
  fputs("bye peeps\n", fp);
  fputs("cry peeps\n", fp);
  fclose(fp);
}

// opens file in write just to clear contents
void clear_file() {
  FILE *fp;
  fp = fopen(FILENAME, "w");
  fclose(fp);
}

void delete_file() {
  if (remove(FILENAME) == 0) {
    printf("%s file deleted.\n", FILENAME);
  }
  else {
    printf("Unable to delete the file: %s\n", FILENAME);
  }
}