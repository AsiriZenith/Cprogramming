#include<stdio.h>
#include<math.h>

int car=5, bike=6, van=4, driver=5;

int getVehicle(){
	int n,d;
	printf("\n\nCurrently exist vehicles\n");
	printf("Car = %d	Van = %d	Bike = %d",car,van,bike);
	printf("\n\nEnter you expect to get vehicle: \n1.Car 	2.Van	 3.Bike\n");
	printf("\nEnter the number here ");
	scanf("%d",&n);
		
	if(n == 1){
		if(car==0)
			printf("You can't get car anymore!!'");
		else
			car--;
	}
	else if(n == 2){
		if(van==0)
			printf("You can't get van anymore!!'");
		else
			van--;
	}
	else if(n == 3){
		if(bike==0)
			printf("You can't get bike anymore!!'");
		else
			bike--;
	}
	else if(n == 0)
		return;
	else
		printf("Your entered is invalid!!");
	
	printf("Do you want driver with vehicle? \t");
	printf("(press 1 if you want, press 2 if you don't want)\n");
	scanf("%d",&d);
	
	if(d == 1){
		if(driver==0)
			printf("You can't get a driver anymore!!");
		else{
			printf("\nWe can give to you the Vehicle with driver\n");
			driver--;
		}	
	}
	else if(d == 2)
		printf("Ok. You can get our vehicle now");
	else 
		printf("Your entered is invalid!!");
	return 0;
}

int backVehicle(){
	int n,d,distance;
	float charge,finalcharge;
	printf("\n\nWhat is the vehicle type\n");
	printf("\n1.Car 	2.Van	 3.Bike\n Enter the related number here ");
	scanf("%d",&n);
	printf("Enter the distance here ");
	scanf("%d",&distance);
	
	if(n == 1){
		charge = 100 * distance + 700;
		car++;
	}
	else if(n == 2){
		charge = 80 * distance + 800;
		van++;
	}
	else if(n == 3){
		charge = 60 * distance + 500;
		bike++;
	}
	else if(n == 0)
		return;
	else
		printf("Your entered is invalid!!");
	
	printf("Did you got a driver with our vehicle??\t");
	printf("(If it is Yes, press 1, if it not, press 2)  ");
	scanf("%d",&d);
	
	if(d == 1){
		finalcharge = charge * 105 / 100;
		driver++;
	}
		
	
	if(n==1 || n==2 || n==3)
		printf("\nYour charge is = %00.f",round(finalcharge));
	return 0;
}

int main(){
	int op;
	do{
		printf("\n\n1.get vehicle		2.return vehicle	  3.exit");
		printf("\nEnter your option here  ");
		scanf("%d",&op);
	
		if(op == 1)
			getVehicle();
		else if(op == 2)
			backVehicle();
		else if(op == 3)
			return 0;
		else
			printf("Your entered is invalid!!\n");
			
	}while(1);
	return 0;
}
