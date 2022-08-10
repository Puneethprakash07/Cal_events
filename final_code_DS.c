#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>

int main() {
   int choice, year;;
   void add();
   void show();
   void date();
   void printCalendar(int year);
   while(1){
   printf("\n");
   printf("Menu:-\n\n");
   printf("1.Add Note\n2.Show Note\n3.Print Calender\n4.Find out the day\n5.Exit\n");
   printf("Enter ur choice:- ");
   scanf("%d",&choice);
   if(choice==1){
      add();
   }
   else if(choice==2){
      show();
   }
   else if(choice==3){
      printf("Enter the year: "); 
      scanf("%d",&year);
    	printCalendar(year);
   }
   else if(choice==4){
      date();
   }
   else if(choice==5){
      break;
   }
   }
    return 0;
}
int dayNumber(int day, int month, int year)
{

	static int t[] = { 0, 3, 2, 5, 0, 3,
					5, 1, 4, 6, 2, 4 };
	year -= month < 3;
	return (year + year / 4
			- year / 100
			+ year / 400
			+ t[month - 1] + day)
		% 7;
}


char* getMonthName(int monthNumber)
{
	char* month;

	switch (monthNumber) {
	case 0:
		month = "January";
		break;
	case 1:
		month = "February";
		break;
	case 2:
		month = "March";
		break;
	case 3:
		month = "April";
		break;
	case 4:
		month = "May";
		break;
	case 5:
		month = "June";
		break;
	case 6:
		month = "July";
		break;
	case 7:
		month = "August";
		break;
	case 8:
		month = "September";
		break;
	case 9:
		month = "October";
		break;
	case 10:
		month = "November";
		break;
	case 11:
		month = "December";
		break;
	}
	return month;
}


int numberOfDays(int monthNumber, int year)
{

	if (monthNumber == 0)
		return (31);
	
	if (monthNumber == 1) {
	
		if (year % 400 == 0
			|| (year % 4 == 0
				&& year % 100 != 0))
			return (29);
		else
			return (28);
	}


	if (monthNumber == 2)
		return (31);


	if (monthNumber == 3)
		return (30);


	if (monthNumber == 4)
		return (31);

	if (monthNumber == 5)
		return (30);


	if (monthNumber == 6)
		return (31);


	if (monthNumber == 7)
		return (31);


	if (monthNumber == 8)
		return (30);


	if (monthNumber == 9)
		return (31);


	if (monthNumber == 10)
		return (30);

	
	if (monthNumber == 11)
		return (31);
}


void printCalendar(int year)
{
   int days,k;
	printf("	 Calendar - %d\n\n", year);
	int current = dayNumber(1, 1, year);

	for (int i = 0; i < 12; i++) {
		days = numberOfDays(i, year);

	
		printf("\n ------------%s-------------\n",
			getMonthName(i));

	
		printf(" Sun Mon Tue Wed Thu Fri Sat\n");

		for (k = 0; k < current; k++)
			printf("     ");

		for (int j = 1; j <= days; j++) {
			printf("%5d", j);

			if (++k > 6) {
				k = 0;
				printf("\n");
			}
		}

		if (k)
			printf("\n");

		current = k;
	}

	return;
}
void add(){
    FILE *fp;
   char first_string[20];
    char second_string[20]=".txt";
    char date[20];
    char month[20];
    char note[100];
    char buf[100]="";
   char delim[100]="#";
   char delim2[100]="\n";
   //char demo[20]="00#00#abcd&&&&&&";

    printf("Enter the year: ");  
    scanf("%s",first_string);  
    strcat(first_string,second_string);
    fp=fopen(first_string,"aw"); 
   printf("Enter the date (dd): ");
   scanf("%s",date);

    printf("Enter the month (mm): ");
    scanf("%s",month);

    printf("Enter the note");
    //scanf("%s",note);
    scanf(" %[^\n]%*c",note);
     
   //strcat(buf,demo);
   strcat(buf,delim2);
   strcat(buf,date);
   strcat(buf,delim);
   strcat(buf,month);
   strcat(buf,delim);
   /*while(strlen(note)!=10){
      strcat(note,"&");
   }*/
   strcat(buf,note);
   strcat(buf,delim2);
   fwrite(buf,1,strlen(buf),fp);
   fclose(fp);
   return;
}
void show(){
     FILE *fp;
    char first_string[20];
    char second_string[20]=".txt";
    char actualdate[10];
    char actualmonth[10];
    char date[10]; 
    char month[10];
    char data[10];
    char line[100];
    char ans[20];
    char date2[10];
    char month2[10];
    char ans2[20];
    int kk=0;

    printf("Enter the year: ");  
    scanf("%s",first_string);  
    strcat(first_string,second_string);
    printf("Enter the date (dd):  ");
    scanf("%s",&actualdate);

    printf("Enter the month (mm) :");
     scanf("%s",&actualmonth);
  

    fp=fopen(first_string,"r");
   while (!feof(fp))
   {
       int  i,j=0;
       int  l=0;
       int  k=0,p;
       int a=atoi(date);
       int b=atoi(month);
       int t=0;
       int z=0;
       fgets(line,45,fp);
       p=strlen(line);
       for(i=0;i<2;i++){
	      date[j]=line[i];
	      j++;
        }
        for(i=3;i<5;i++){
	      month[k]=line[i];
	      k++;
        }
        for(i=6;i<=p;i++){
	     data[l]=line[i];
	      l++;
        }
      for(i=0;i<strlen(date);i++){
	   if(isdigit(date[i])){
	    date2[t]=date[i];
	    t++;
	   }
      }
       for(i=0;i<strlen(month);i++){
	   if(isdigit(month[i])){
	    month2[z]=month[i];
	    z++;
	   }
      }
      //puts(date2);
      //puts(month2);


      if(strcmp(date2,actualdate)==0){
	 if(strcmp(month2,actualmonth)==0){
	    for(i=0;i<strlen(data);i++){
	       ans[i]=data[i];
	    }
	    }
      ans[20]="No notes";
      }
   }
   
   for(int i=0;i<strlen(ans);i++){
      if(ans[i]!='\n'){
         if(!isdigit(ans[i])){
         ans2[kk]=ans[i];
         kk++;
      }
      }
   }
   puts(ans2);
   fclose(fp);
   return;
}
void date(){
     int month[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}; 
 char week[7][10] ;
 int date, mon, year, i, r, s = 0 ; 

 strcpy(week[0], "Sunday") ; 
 strcpy(week[1], "Monday") ; 
 strcpy(week[2], "Tuesday") ; 
 strcpy(week[3], "Wednesday") ; 
 strcpy(week[4], "Thursday") ; 
 strcpy(week[5], "Friday") ; 
 strcpy(week[6], "Saturday") ; 
 printf("Enter a valid date (dd/mm/yyyy) : ") ; 
 scanf("%d / %d / %d", &date, &mon, &year) ; 
 if( (year % 400 == 0) || ((year % 4 == 0) && (year % 100 != 0)) ) 
  month[1] = 29 ; 
 for(i = 0 ; i < mon - 1 ; i++) 
  s = s + month[i] ; 
 s = s + (date + year + (year / 4) - 2) ; 
 s = s % 7 ; 
 printf("\nThe day is : %s", week[s]) ; 
}