#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//1- enum
typedef enum{

	Low = 10,
	Medium = 50,
	High = 100,


}Level;

void printLevel(Level input){

	printf("please insert Custom Level \n");
	printf("%d",input);
}
//2- union
typedef union{

	int id;
	float age;
	char name[30];

}person;

void printUnion(){

	person uid;
	int id = uid.id =1;
	int age  = uid.age = 28;
	strcpy(uid.name,"sajjad");

	printf("%d\n%d\n%s",id,age,uid.name);

}
//3- strtof
void printStrtof(){

	char mount[] = "365.0 30.0";
	char* ptr;
	float f1,f2;
	f1 = strtof(mount,&ptr);
	f2 = strtof(ptr,NULL);
	printf("the mount is years is : %.2f",f1/f2);

}
//4- strtol
void printStrtol(){

	char burn[30] = "1375 sajjad";
	char* ptr;
	long rel;

	rel = strtol(burn, &ptr, 10);
	printf("you born %ld \n",rel);
	printf("name is %s",ptr);


}

//5- strcmp
void printStrcmp(){

	char a[10] = "sajjad";
	char b[10] = "sajjad";
	int result;
	result = strcmp(a , b);
	
	if(result == 0){
	
		printf("SUCCESS");
	}else{
		printf("WRONG");
	}


}

void printAtoi(){

   int val;
   char str[20];

   strcpy(str, "98993489");
   val = atoi(str);
   printf("String value = %s, Int value = %d\n", str, val);

   strcpy(str, "tutorialspoint.com");
   val = atoi(str);
   printf("String value = %s, Int value = %d\n", str, val);

}

void printAtof(){

float val;
   char str[20];
   
   strcpy(str, "98993489");
   val = atof(str);
   printf("String value = %s, Float value = %f\n", str, val);

   strcpy(str, "tutorialspoint.com");
   val = atof(str);
   printf("String value = %s, Float value = %f\n", str, val);

}

int main(){

	printAtof();

	return 0;

}
