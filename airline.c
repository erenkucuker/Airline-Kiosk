#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <time.h>


//Sizes
#define SIZEPASS 10
#define USERLIMIT 20
#define SIZEPROCESS 5
#define CITYSIZE 5
#define FLIGHTSIZE 4
//Initializers
size_t kullanicino;
int isLoaded;
int processtart;
int statuscheck;
char *boolquestion;
char checkiname[20];
char checkinsurname[20];
char checkinsure;
size_t biletsira;
char usernameform[20];
char passform[20];
int WantsBoardingPass;
//Boarding Pass Definition
typedef struct bpass {
    char name[20];
    char surname[20];
    int age;
    int dtime;
    int youhere;
    int going;
    int ischeckedin;
}Boardingpass;

typedef struct user {
    char username[20];
    char pass[20];
    int points;
    int isloggedin;
}User;

typedef struct session{
    int sess;
    int id;
}Session;

typedef struct process{
    char name[30];
    int id;
    int showguest;
}Processs;

typedef struct flights {
    int id;
    int hour;
    int minute;
}Flightss;

typedef struct il{
    int id;
    char name[30];
}Il;

//Storages
Boardingpass boardingPassList[SIZEPASS]={"ali","can",20,16,2,7,0};
User UserList[20]={"can","12qwaszx",0};
Il serviceIller[] = {1,"Ankara",2,"Istanbul",3,"Izmir",4,"Adana"};
Flightss Flights[] = {1,10,30,2,11,30,3,12,30,4,14,30};
Processs process[SIZEPROCESS] = {"Buy a ticket",1,1,"Check-in",2,0};

//Prototypes
int buyAticket(void);
void checkIn(void);
void listingIlAll(Il b[]);
int isUser(char a[],char b[]);
void processListAll(Processs a[]);
void listingFlights(Flightss a[]);

int main(void) {
    if(isLoaded == 0){
        puts("Welcome to the Eren Airlines.");
    }
    processListAll(process);
    printf("Please Select Your Process:");
    scanf("%1d",&processtart);
    if (processtart==process[0].id) {
        statuscheck = buyAticket();
        printf("Do you wanna have boarding Pass ? ");
        scanf("%d" , &WantsBoardingPass);
    }else if(processtart==process[1].id) {
        puts("Please enter Name Surname for Check-in: ");
        scanf("%s %s",checkiname,checkinsurname);
        printf("%s %s \n",checkiname,checkinsurname);
        checkIn();
    }else if(processtart==process[2].id) {
        printf("Please enter your username: ");
        scanf("%s",usernameform);
        printf("Please enter your password: ");
        scanf("%s",passform);
        isUser(usernameform,passform);
    }
    isLoaded=1;
    main();
}












//Functions
int buyAticket(void){
    listingIlAll(serviceIller);
    printf("From: ");
    scanf("%1d",&boardingPassList[biletsira].youhere);
    listingIlAll(serviceIller);
    printf("To: ");
    scanf("%1d",&boardingPassList[biletsira].going);
    printf("Enter Your Name: ");
    scanf("%s",&boardingPassList[biletsira].name);
    printf("Enter Your Surname: ");
    scanf("%s",&boardingPassList[biletsira].surname);
    printf("Enter Your Age: ");
    scanf("%d",&boardingPassList[biletsira].age);
    listingFlights(Flights);
    printf("Select a Flight Time: ");
    scanf("%d",&boardingPassList[biletsira].dtime);
    puts("Your Buying Ticket is Completed Succesfully.");
    biletsira++;
    return 0;
}


void checkIn(void){
    for(size_t i=0;i<SIZEPASS;i++){
    if(strcmp(checkiname,boardingPassList[i].name) == 0 && strcmp(checkinsurname,boardingPassList[i].surname) == 0) {
        if(boardingPassList[i].ischeckedin==0) {
                    printf("You are about to complete check-in for %s %s Are you sure? :  \n",checkiname,checkinsurname);
        checkinsure=getch();
        if(checkinsure == 'y'||'Y') {
            boardingPassList[i].ischeckedin=1;
            printf("Dear %s Your Check-in Completed.\n",boardingPassList[i].name);
            break;
        }else{
            break;
        }
        }else if(boardingPassList[i].ischeckedin==1) {
            printf("You are already checked-in.\n");
            break;
        }
    }else{
        printf("We didn't found your ticket.Please try other methods for check-in.\n");
        break;
    }
    }  
}




int isUser(char a[],char b[]) {
    for(kullanicino=0;kullanicino<USERLIMIT;kullanicino++) {
        if(strcmp(a,UserList[kullanicino].username) == 0  && strcmp(b,UserList[kullanicino].pass) == 0){
            printf("You are logged in now.\n");
            return 1;
            break;
            UserList[kullanicino].isloggedin=1;
        }else{
            printf("Your username or password was incorrect please try again.\n");
            return 0;
            break;
        }
    }
}


void listingIlAll(Il b[]){
    for(size_t i=0;i<CITYSIZE;i++) {
        printf("%d - %s ",i+1,b[i].name);
    }
    printf("\n");
}

void processListAll(Processs a[]){

    for(size_t i = 0;i<SIZEPROCESS;i++){
        printf("%d - %s ",i+1,a[i].name);
    }
    printf("\n");
}

void listingFlights(Flightss a[]){
    for(size_t i = 0;i<FLIGHTSIZE;i++){
        printf("%d - %d:%d \n",i+1,a[i].hour,a[i].minute);
    }
}