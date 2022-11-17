#include<stdio.h>
#include<conio.h>
#include<ctype.h>
#include<stdlib.h>
#include<windows.h>

void WelcomeScreen(void);
void MainMenu(void);
void YoungAge(void);
void MiddleAge(void);
void OldAge(void);
void Plan120(void);
void Plan150(void);
void Plan200(void);
void fordelay(long int);
void EndingScreen(void);

void InsurancePlanSubscription(void);
void Claim(void);
void AccountsInfo(void);
void Search(void);

void GetId();
int inputdetails(int, int);

struct details
{
	char name[50];
	char address[50];
	char phone[100];
};


int main()
{
	
	WelcomeScreen();
			
	MainMenu();	
}

void WelcomeScreen()
{
	int i;
	system("cls");
	system("color 9");
	printf("\n\n\n\n\n\n");
	printf("*******************************************************************************************************************\n");
	printf("                                       WELCOME TO ZEDLIFE INSURANCE\n");
	printf("*******************************************************************************************************************");
	Sleep(1000);
	printf("\n\n\n\n\n");
	printf("\n                                       LOADING");
	for(i=0;i<=6;i++)
	{
		fordelay(100000000);
		printf(". ");
	}
	system("cls");
}


void YoungAge(void)
{
	printf("\n\n");
	printf("\t\tAvailable Insurance Plans.\n");
	printf("\t\tPlans for age group 0 to 20.\n");
	printf("------------------------------------------------------------\n");
	printf("1. Plan120\n");
	printf("\tMonthly Premium       = 120\n");
	printf("\tAnnual Claim Limit    = 120,000\n");
	printf("\tLifetime Claim Limit  = 600,000\n\n\n");
	printf("2. Plan150\n");
	printf("\tMonthly Premium       = 150\n");
	printf("\tAnnual Claim Limit    = 150,000\n");
	printf("\tLifetime Claim Limit  = 750,000\n\n\n");
	printf("3. Plan200\n");
	printf("\tMonthly Premium       = 200\n");
	printf("\tAnnual Claim Limit    = 200,000\n");
	printf("\tLifetime Claim Limit  = 1,000,000\n\n\n");
}


void MiddleAge(void)
{
	printf("\n\n");
	printf("\t\tAvailable Insurance Plans.\n");
	printf("\t\tPlans for age group 0 to 20.\n");
	printf("------------------------------------------------------------\n");
	printf("1. Plan150\n");
	printf("\tMonthly Premium       = 150\n");
	printf("\tAnnual Claim Limit    = 150,000\n");
	printf("\tLifetime Claim Limit  = 750,000\n\n\n");
	printf("2. Plan200\n");
	printf("\tMonthly Premium       = 200\n");
	printf("\tAnnual Claim Limit    = 200,000\n");
	printf("\tLifetime Claim Limit  = 1,000,000\n\n\n");
}


void OldAge(void)
{
	int oldop;
	printf("\n\n");
	printf("\t\tAvailable Insurance Plans.\n");
	printf("\t\tPlans for age group 0 to 20.\n");
	printf("------------------------------------------------------------\n");
	printf("1. Plan200\n");
	printf("\tMonthly Premium       = 200\n");
	printf("\tAnnual Claim Limit    = 200,000\n");
	printf("\tLifetime Claim Limit  = 1,000,000\n\n\n");
}


int inputdetails(int age, int option)
{
	int sid;
	fflush(stdin);
	struct details s1;
	fflush(stdin);	
	FILE *fp;
	fp=fopen("Record.txt","a+");
	printf("\n\n");
	printf("--------------------------------------------------------------\n");
	printf("Please enter your details here.\n\n");
	if(age<20 && option==1)
	{
		fflush(stdin);
		fprintf(fp,"\nPlan120");
	}
	else if(age<20 && option==2)
	{
		fflush(stdin);
		fprintf(fp,"\nPlan150");
	}
	else if(age<20 && option==3)
	{
		fflush(stdin);
		fprintf(fp,"\nPlan200");
	}
	else if(age>=21 && age<=40 && option==1)
	{
		fflush(stdin);
		fprintf(fp,"\nPlan150");
	}
	else if(age>=21 && age<=40 && option==2)
	{
		fflush(stdin);
		fprintf(fp,"\nPlan200");
	}
	else if(age>=41 && age<=54 && option==1)
	{
		fflush(stdin);
		fprintf(fp,"\nPlan200");
	}
	fflush(stdin);
	fprintf(fp, "\nAge       : %d", age);
	printf("Name      : ");
	fflush(stdin);
	scanf("%[^\n]", s1.name);
	fprintf(fp, "\nName      : %s", s1.name);
	printf("Address   : ");
	fflush(stdin);
	scanf("%[^\n]", s1.address);
	fprintf(fp, "\nAddress   : %s", s1.address);
	printf("Phone No. : ");
	fflush(stdin);
	scanf("%s", s1.phone);
	fprintf(fp, "\nPhone No. : %s\n", s1.phone);
	fclose(fp);
	GetId();
}

void fordelay(long int j)
{
	int i, k;
	for(i=0;i<j;i++)
	{
		k=i;
	}
}

void Plan120(void)
{
	system("cls");
	printf("\n\n");
	printf("\tBenefits of Plan120\n");
	printf("---------------------------------------------------------------------------------------------\n");
	printf("\tHospitalisation and Surgical Benefits\n");
	printf("---------------------------------------------------------------------------------------------\n");
	printf("\tTypes of Claim                        Eligibility Amount\n\n");
	printf("\tRoom Charges                       =  120/day\n");
	printf("\tIntensive Care Unit (ICU Charges)  =  250/day\n");
	printf("\tHospital Supplies and Services     =  As Charged. Subject to approval by ZeeMediLife\n");
	printf("\tSurgical Fees                      =  As Charged. Subject to approval by ZeeMediLife\n");
	printf("\tOther Fees                         =  As Charged. Subject to approval by ZeeMediLife\n");
}

void Plan150(void)
{
	system("cls");
	printf("\n\n");
	printf("\tBenefits of Plan150\n");
	printf("---------------------------------------------------------------------------------------------\n");
	printf("\tHospitalisation and Surgical Benefits\n\n");
	printf("---------------------------------------------------------------------------------------------\n");
	printf("\tTypes of Claim                        Eligibility Amount\n");
	printf("\tRoom Charges                       =  150/day\n");
	printf("\tIntensive Care Unit (ICU Charges)  =  400/day\n");
	printf("\tHospital Supplies and Services     =  As Charged. Subject to approval by ZeeMediLife\n");
	printf("\tSurgical Fees                      =  As Charged. Subject to approval by ZeeMediLife\n");
	printf("\tOther Fees                         =  As Charged. Subject to approval by ZeeMediLife\n");
}

void Plan200(void)
{
	system("cls");
	printf("\n\n");
	printf("\tBenefits of Plan200\n");
	printf("---------------------------------------------------------------------------------------------\n");
	printf("\tHospitalisation and Surgical Benefits\n");
	printf("---------------------------------------------------------------------------------------------\n");
	printf("\tTypes of Claim                        Eligibility Amount\n\n");
	printf("\tRoom Charges                       =  200/day\n");
	printf("\tIntensive Care Unit (ICU Charges)  =  700/day\n");
	printf("\tHospital Supplies and Services     =  As Charged. Subject to approval by ZeeMediLife\n");
	printf("\tSurgical Fees                      =  As Charged. Subject to approval by ZeeMediLife\n");
	printf("\tOther Fees                         =  As Charged. Subject to approval by ZeeMediLife\n");
}

void InsurancePlanSubscription(void)
{
	int age;
	int option;
	char oldop;
	printf("Please Enter your age.\n");
	printf("> ");
	scanf("%d", &age);
	if(age<=20)
	{
		MainScreen1:
		YoungAge();
		printf("Please enter your choice.\n");
		printf("> ");
		scanf("%d", &option);
		system("cls");
		switch(option)
		{
			case 1:
				{
					Plan120();
					inputdetails(age, option);
					break;
				}
			case 2:
				{
					Plan150();
					inputdetails(age, option);
					break;
				}
			case 3:
				{
					Plan200();
					inputdetails(age, option);
					break;
				}
			default:
				{
				printf("Please Retry! You have enter an invalid option\n");
				system("cls");
				printf("***You had input a wrong choice earlier***\n\n");
				goto MainScreen1;
				}
		}
	}
	else if(age>20 && age<=40)
	{
		MainScreen2:
		MiddleAge();
		printf("Please enter your choice.\n");
		printf("> ");
		scanf("%d", &option);
		switch(option)
		{
			case 1:
				{
					Plan150();
					inputdetails(age, option);
					break;
				}
			case 2:
				{
					Plan200();
					inputdetails(age, option);
					break;
				}
			default:
				{
				printf("Please Retry! You have enter an invalid option\n");
				system("cls");
				printf("***You had input a wrong choice earlier***\n\n");
				goto MainScreen2;
				}
		}
	}
	else if(age>41 && age<=54)
	{
		MainScreen3:
		OldAge();
		printf("Do you want to continue with the available plan \?\n");
		printf("-------------------\n");
		printf("Enter 1 For Yes.\n");
		printf("Enter 2 For No.\n");		
		printf("-------------------\n\n");
		printf("> ");
		scanf("%d", &option);
		switch(option)
		{
			case 1:
				{
					Plan200();
					inputdetails(age, option);
					break;
				}
			case 2:
				{
					printf("Thank You for visiting.");
					break;
				}
			
			default:
				{
				printf("Please Retry! You have enter an invalid option\n");
				system("cls");
				printf("***You had input a wrong choice earlier***\n\n");
				goto MainScreen3;
				}
		}
	}
	else if(age>54)
	{
		printf("\nSorry! Currently not any Insurance Plan is avaiable for your age\n");
		printf("Press any key to continue...");
		getch();
		exit(0);
	}
}

void Claim(void)
{
	exit(0);
}

void AccountsInfo(void)
{
	exit(0);
}

void MainMenu(void)
{
	int loopchoice;
	int MainOption;
	printf("LOADING");
	fordelay(1000);
	printf(".");
	MainScreen:
	system("cls");
	printf("\n");
	printf("   ENTER YOUR choice.\n\n");
	printf("   1 : Insurance Plan Subscription\n");
	printf("   2 : Claim\n");
	printf("   3 : Accounts Information\n");
	printf("   4 : Search\n");
	printf("   5 : Exit\n");
	printf("\n\n       Please Enter Your Choice.\n");
	printf("    > ");
	scanf("%d", &MainOption);
	switch(MainOption)
	{
		case 1:
			{
				system("cls");
				InsurancePlanSubscription();
				system("cls");
				printf("Do you want to subscribe another plan ?\n");
				printf("Enter 1 For Yes.\n");
				printf("Enter 2 For No.\n");
				scanf("%d", &loopchoice);
				if(loopchoice==1)
					{
					MainMenu();
					break;
					}
				else
					{
						printf("Thank you !\n");
						system("cls");
						MainMenu();
					}
			}
		case 2:
			{
				system("cls");
				Claim();
			}
		case 3:
			{
				system("cls");
				AccountsInfo();
			}
		case 4:
			{
				system("cls");
				Search();
			}
		case 5:
			{
				EndingScreen();
			}
		default:
			{
				printf("Please Enter a valid option.");
				goto MainScreen;
			}
	}
	
}

void Search(void)
{
	exit(0);
}

void EndingScreen(void)
{
	int i;
	system("cls");
	printf("\n\n\n\n\n\n");
	printf("*******************************************************************************************************************\n");
	printf("                                  THANK YOU FOR TRUSTING ZEDLIFE INSURANCE\n");
	printf("*******************************************************************************************************************");
	Sleep(1000);
	printf("\n\n\n\n\n");
	printf("\n                                              EXITING");
	for(i=0;i<=6;i++)
	{
		fordelay(100000000);
		printf(". ");
	}
	exit(0);
}

void GetId()
{
    int sid = 100;
    FILE * fp = fopen("Record.txt", "a+");
    if (!fp)
	{
        fp = fopen("Record.txt", "a+") ;
        fprintf(fp, "%d", sid) ;
        fclose(fp) ;
    }   
	fseek(fp, EOF-3, SEEK_SET);
    fscanf(fp, "%d", &sid);
    sid++;
    fclose(fp);
    fp = fopen("Record.txt", "a+") ; 
    fprintf(fp, "%d", sid);
    
    fclose(fp) ;
}
