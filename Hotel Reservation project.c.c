#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

struct details
{
	char name[50];
	char address[50];
	char phone[10];
	char national[50];
	char date[50];
	char email[50];	
	char period[50];
}s1;
void hlist();
void filldetails();
void WelcomeScreen(void);
void fordelay(long int);
void login(void);
void hmenu(void);
void choice(void);
void menu(void);
void Admin(void);
void ViewInfo(void);
void EditInfo(void);
void SearchInfo(void);
void DeleteInfo(void);


void main()
{	
	WelcomeScreen();
	choice();
	
}
void choice()
{
	int opt,p;
	printf("\n\n-----------------------------------------------------------------------");
	printf("\n\n\t\t\tPlease choice any one\n");
	printf("-----------------------------------------------------------------------\n");
	printf("\n\t\t1. Admin \t 2. customer \t 3. Exit\n");
	printf("\n\t\t> ");
	scanf("%d",&p);
	if(p==1)
	{
	login();
	Admin();
	}
	else if(p==2)
	{
	menu();
	}
	else
	{
		printf("\n\n\t\tThank You for using our program !!!!");
		exit(0);
	}

}

void menu()
{	int opt,range;
	char ch[100];


	system("cls");
	printf("\n\n---------------------------- |MAIN MENU| --------------------------------");
	printf("\n\n Please enter the choice from menu. \n\n");
	printf("\t1. Book a room.\n");
	printf("\t2. Verification.\n");
	printf("\t3. Edit Record.\n");
	printf("\t4. Exit.\n");
	printf("     > ");
	scanf("%d",&opt);
	
	
	switch(opt)
	{
		case 1:
			{
				printf("\nPlease select the price range : ");
				printf("\n\n  1.Rs.800-1000\t\t2.Rs.1000-1500\t\t3.Rs.2000(above)\n");
				scanf("%d",&range);
				switch(range)
				{
					case 1:
						system("cls");
						printf("\n\n---------------------------------------------------------------------------------------------\n\n");
						printf("Hotel Name \t\tPrice \t\tRoom Type \tAvailable Room ");
						printf("\n----------------------------------------------------------------------------------------------\n\n");
						printf("1.Hotel lai lai \tRs.800 \t\tGeneral \t\tYes");
					
				}
				hlist();
				break;
			}
/*		case 2:
			{	
				system("cls");
				printf("\n**************************** |VERIFICATION |******************************\n\n");
				printf("\nPlease enter the following details\n ");
				printf("Name : ");
				gets(s2.name);
				printf("");
			}*/
	}
	
}

void WelcomeScreen()
{
	int i;
	system("cls");
	printf("\n\n\n\n\n\n");
	printf("*******************************************************************************************************************\n");
	printf("                                       WELCOME TO HOTEL RESERVATION SYSTEM\n");
	printf("*******************************************************************************************************************");
	Sleep(1000);
	printf("\n\n\n\n\n");
	printf("\n                                       LOADING");
	for(i=0;i<=6;i++)
	{
		fordelay(100000000);
		printf(" . ");
	}
	system("cls");
}


void fordelay(long int j)
{
	int i, k;
	for(i=0;i<j;i++)
	{
		k=i;
	}
}

void login()
{
	char pass[10],password[10]="codewithc";
    int i=0,main_exit;
    system("cls");
    login_try:
    printf("\n\n\t\tEnter the password to login:");
    scanf("%s",pass);
    
    if (strcmp(pass,password)==0)
        {printf("\n\n\t\t\tPassword Match!!!\n\n\t\t\tLOADING");
        for(i=0;i<=6;i++)
        {
            fordelay(100000000);
            printf(".");
        }
            system("cls");
        }
    else
        {   printf("\n\t\t\tWrong password !!!\n");
           
            printf("\n\t\tEnter 1 to try again and 0 to exit:");
            scanf("%d",&main_exit);
            if (main_exit==1)
                    {

                        system("cls");
                        goto login_try;
                    }

            else if (main_exit==0)
                    {
                    system("cls");
                    choice();}
            else
                    {printf("\nInvalid!");
                    fordelay(1000000000);
                    system("cls");
                    goto login_try;}
			 }
}
void Admin()
{
	int input, i;
	InsideLabel:
	printf("\n      YOU ARE CURRENTLY LOGED IN AS ADMIN.");
	printf("\n\n");
	printf("      1. View Customer\'s Information\n");
	printf("      2. Search Customer\'s Information\n");
	printf("      3. Edit Customer\'s Information\n");
	printf("      4. Delete Customer\'s Information\n");
	printf("      5. Exit\n");
	printf("\n   Please enter your choice.\n");
	printf("   > ");
	scanf("%d", &input);
	switch(input)
	{
		case 1:
			{
				ViewInfo();
				break;
			}
		case 2:
			{
				SearchInfo();
				break;
			}
		case 3:
			{
				EditInfo();
				break;
			}
		case 4:
			{
				DeleteInfo();
				break;
			}
		case 5:
			{
				choice();
				break;
			}
		default:
			{
				printf("\n\nPlease Enter a Valid Option.");
				for(i=0;i<=3;i++)
       			{
            		fordelay(100000000);
        		}
				system("cls");
				goto InsideLabel;
			}
	}
}
void hmenu()
{
	printf("\n\n---------------------------- |MENU| --------------------------------");
	printf("\n\nPlease select your Hotel \n\n");
	printf("\t1. Classic Nepal Hotel.\n ");
	printf("\t2. Hotel snow peak. \n");
	printf("\t3. Hotel Mystic Mountain.\n");
	printf("\t4. Hotel Himalaya. \n");
	printf("\t5. The Garden Hotel. \n");
	printf("\t6. Hotel Lai Lai. \n");
	printf("     > ");
}
	
void hlist() //Details of room and customer
		{	
			int hopt,sel;
			char p;
			scanf("%d",&hopt);
			if(hopt<=6)
			{
				printf("-----------------------------------------------------------------------\n");
				printf("Choose the Room type\n");
				printf("\t1.Delux. \t\t2.General\n");
				printf("     > ");
				scanf("%d",&sel);
				switch (sel)
				{
					case 1:
					{
					system("cls");	
					printf("\n ------------------------ |FEATURES OF ROOM| --------------------------\n");
					printf("Room Type  >>   Delux. \n");
					printf("Room charge >>   Rs.1000 per day.\n");
					printf("Bed         >>   2 \n");
					printf("Capacity    >>   4 \n");
					printf("\n-------------------------- |ADDITIONAL FEATURES| -----------------------\n");
					printf("\n1.TV available   \t\t\t 2.Free WIFI with AC \n");
					printf("\n------------------------------------------------------------------------");
					printf("\nNote: We Accept Online Payments from Esewa as well as khalti too.\n ");
					printf("\nPress any key to continue....");
					getch();
					break;
					}
					case 2:
					{
					system("cls");
					printf("\n ------------------------ |FEATURES OF ROOM| --------------------------\n");
					printf("Room Type  >>   General. \n");
					printf("Room charge >>   Rs.500 per day.\n");
					printf("Bed         >>   2 \n");
					printf("Capacity    >>   4 \n");
					printf("-------------------------- |ADDITIONAL FEATURES| ----------------------\n");
					printf("\n1.TV available   \t\t\t 2.Free WIFI  \n");
					printf("------------------------------------------------------------------------");
					printf("\nNote: We Accept Online Payments from Esewa as well as khalti too.\n ");
					printf("\nPress any key to continue....");
					getch();
					break;
					}
					default:
						{
							printf("\nPlease Retry! You have enter ah Invalid option. \n");
							exit(0);
						}
				}	
			}
			filldetails();
	}
void ViewInfo()
{
	FILE *view;
	view=fopen("detail.txt","r+");
	int Test=0;
    int main_exit;
    system("cls");
    while(fscanf(view,"%s%s%s%s%s%s%s", s1.name, s1.address, s1.phone, s1.national, s1.date, s1.email, s1.period)!=EOF)
       {
            printf("Name      = %s\nAddress   = %s\nPhone     = %s\nNational  = %s\nDate      = %s\nEmail     = %s\nPeriod    = %s\n\n", s1.name, s1.address, s1.phone, s1.national, s1.date, s1.email, s1.period);
            Test++;
       }
    fclose(view);
    if (Test==0)
        {   
		    system("cls");
            printf("\nNO RECORDS FOUND!!\n");}
            view_list_invalid:
            printf("\n\nEnter 1 to go to the main menu and 0 to exit: ");
            scanf("%d",&main_exit);
            system("cls");
        if (main_exit==1)
        {
        	Admin();
		}
        else if(main_exit==0)
        {
        	exit(0);
		}
        else
        {
            printf("\nInvalid!\a");
            goto view_list_invalid;
        }

    fclose(view);
    if (Test==0)
        {   system("cls");
            printf("\nNO RECORDS FOUND!!\n");
		}
	}

void EditInfo()
{
    char name[50];
    int a=1, choice, cl, rolno;
    char c='y';
    FILE *fs;
    while(c=='y'||c=='Y')
        {
            system("cls");
            printf("\n-----------------------------------------------------------------------------------\n");
            printf("\n                                    MODIFY RECORD\n");
			printf("\n-----------------------------------------------------------------------------------\n");
            printf("\nEdit information by: ");
            printf("\n1. Edit name");
            printf("\n2. Edit name & Address.");
            printf("\n3. Edit Date & Period");
            printf("\n4. Exit");
            printf("\nEnter your choice\n> ");
            fflush(stdin);
            scanf("%d",&choice);
            if (choice==1)
            {
                int a=0;
                printf("\n\nEnter Name to Edit: ");
                fflush(stdin);
                scanf("%[^\n]", name);
                fs=fopen("detail.txt","rb+");
                while(fread(&s1,sizeof(s1),1,fs)==1)
                {
                    a=1;
                    if (strcmpi(name,s1.name)==0)
                    {
                        a=0;
                        printf("\nEnter New Name: ");
                        fflush(stdin);
                        scanf("%[^\n]",s1.name);
                        fseek(fs,sizeof(s1),SEEK_CUR);
                        fwrite(&s1,sizeof(s1),1,fs);
                        fclose(fs);
                    }
                }
                if (a==1)
                {
                    printf("\n\nRECORDS NOT FOUND");
            	}
                else
                
                printf("\n\nRECORDS SUCCESSFULLY  MODIFIED");
                printf("\n\n");
                system("pause");
            }
            /*else if (choice==2)
            {
                int a=0;
                printf("\n\nenter name of student to modify: ");
                fflush(stdin);
                scanf("%[^\n]",name);
                printf("\n\nenter class of student to modify: ");
                fflush(stdin);
                cl=clscanf();
                fs=fopen("student","rb+");
                while(fread(&s1,sizeof(s1),1,fs)==1)
                {
                    a=1;
                    if (strcmpi(name,stud.n)==0 && cl==stud.c)
                    {
                        a=0;
                        printf("\nenter new name of student: ");
                        fflush(stdin);
                        scanf("%[^\n]",stud.n);
                        printf("\nenter new class of student: ");
                        fflush(stdin);
                        stud.c=clscanf();
                        printf("\nenter new roll of student: ");
                        fflush(stdin);
                        scanf("%d",&stud.r);
                        fseek(fs,-sizeof(stud),SEEK_CUR);
                        fwrite(&stud,sizeof(stud),1,fs);
                        fclose(fs);
                    }
                }
                if (a==1)
                    printf("\n\nRECORDS NOT FOUND");
                else
                    printf("\n\nRECORDS SUCCESSFULLY  MODIFIED");
                printf("\n\n");
                system("pause");
            }
            else if (choice==3)
            {
                int a=0;
                printf("\n\nenter name of student to modify: ");
                fflush(stdin);
                scanf("%[^\n]",name);
                printf("\n\nenter class of student to modify: ");
                fflush(stdin);
                cl=clscanf();
                printf("\n\nenter roll of student to modify: ");
                fflush(stdin);
                scanf("%d",&rolno);
                fs=fopen("student","rb+");
                while(fread(&stud,sizeof(stud),1,fs)==1)
                {
                    a=1;
                    if (strcmpi(name,stud.n)==0 && cl==stud.c &&rolno==stud.r)
                    {
                        a=0;
                        printf("\nenter new name of student: ");
                        fflush(stdin);
                        scanf("%[^\n]",stud.n);
                        printf("\nenter new class of student: ");
                        fflush(stdin);
                        stud.c=clscanf();
                        printf("\nenter new roll of student: ");
                        fflush(stdin);
                        scanf("%d",&stud.r);
                        fseek(fs,-sizeof(stud),SEEK_CUR);
                        fwrite(&stud,sizeof(stud),1,fs);
                        fclose(fs);
                    }
                }
                if (a==1)
                    printf("\n\nRECORDS NOT FOUND");
                else
                    printf("\n\nRECORDS SUCCESSFULLY  MODIFIED");
                printf("\n\n");
                system("pause");
            }
            else if (choice==4) ext();
            else
            {
                printf("\n\n\n\t\tINVALID ENTRY!!!!\n\n\t\t");
                system("pause");
                modrec(1);
            }

            printf("\n\nDo you want to continue with the process(press y or Y");
            fflush(stdin);
            c=getch();
        }
        getch();
    }*/
}
void DeleteInfo()
{
	exit(0);
}
void SearchInfo()
{
	char name[50],namet[50];
    int a=1, choice;
    char c='y';
    FILE *pf;
	InfoLabel1:
        while(c=='y'||c=='Y')
        {
            int a=1;
            system("cls");
            printf("\n----------------------------------------------------------------------------------------");
            printf("\n                                      SEARCH RECORD");
            printf("\n----------------------------------------------------------------------------------------");
            printf("\n     PLEASE CHOOSE SEARCH TYPE::");
            printf("\n     1: Search by Customer\'s Name");
            printf("\n     2: Search by Customer\'s Contact Number");
            printf("\n     3: Exit");
            printf("\n\n     Please enter your choice.\n");
            fflush(stdin);
            scanf("%d",&choice);
            if (choice==1)
            {
                a=1;
                printf("\n\nEnter Name of Customer\'s to search: ");
                fflush(stdin);
                scanf("%[^\n]", name);
                pf=fopen("detail.txt","a+");
                while(fscanf(pf, "%s, %d, %d, %s, %s, %s, %s", &s1.name, &s1.address, &s1.phone, &s1.national, &s1.date, &s1.email, &s1.period)!=EOF)
                {
                    if (strcmpi(name,s1.name)==0)
                    {
                        a=0;
                        printf("\nName        = %s", s1.name);
                        printf("\nAddress     = %d", s1.address);
                        printf("\nPhone       = %d", s1.phone);
                        printf("\nNationality = %s", s1.national);
                        printf("\nDate        = %s", s1.date);
                        printf("\nEmail       = %s", s1.email);
                        printf("\nPeriod      = %s", s1.period);                        
                    }
                }
                if (a==1)
                {
					printf("\n\nRECORD NOT FOUND");
                	printf("\n\n");
                	system("pause");
                	fflush(stdin);
                	fclose(pf);
            	}
            else if (choice==2)
            {
                int a;
                char contact;
                a=1;
                printf("\n\nEnter Contact.");
                fflush(stdin);
                scanf("%s", contact);
                pf=fopen("detail.txt","a+");
                while(fread(&s1,sizeof(s1),1,pf)==1)
                {
                    if (s1.phone==contact)
                    {
                        a=0;
                        printf("\nName        = %s", s1.name);
                        printf("\nAddress     = %d", s1.address);
                        printf("\nPhone       = %d", s1.phone);
                        printf("\nNationality = %s", s1.national);
                        printf("\nDate        = %s", s1.date);
                        printf("\nEmail       = %s", s1.email);
                        printf("\nPeriod      = %s", s1.period); 
                    }
                }
                if (a==1)
                {
                    printf("\n\nRECORD NOT FOUND");
                	printf("\n\n");
                	system("pause");
                	fflush(stdin);
                	fclose(pf);
            	}
            }
            else if(choice==3)
            {
                Admin();
            }
            else
            {
                printf("\n\n\n        INVALID ENTRY!!!!\n\n         ");
                system("pause");
                Admin();
            }
            printf("\n\nDo you want to continue with the process (press y or Y): ");
            fflush(stdin);
            c=getch();
        }
        getch();
    }
}

void filldetails()
{
	int test,main_exit;
	FILE *pf;
	system("cls");
	printf("\n------------------------------------------------------------------------");
	printf("\n\nPlease fill up the details for booking process.\n\n");
	fflush(stdin);
	pf=fopen("detail.txt","a+");
	printf("Enter Name    : ");
	fflush(stdin);
	scanf("%[^\n]", s1.name);
	printf("Enter Address   : ");
	fflush(stdin);
	scanf("%[^\n]", s1.address);
	printf("Enter Phone Number : ");
	fflush(stdin);
	scanf("%s", s1.phone);
	printf("Enter Nationality  : ");
	fflush(stdin);
	scanf("%[^\n]", s1.national);
	printf("Arrivel date (mm/dd/yyyy) : ");
	fflush(stdin);
	scanf("%s",s1.date);
	printf("Enter Email ID : ");
	fflush(stdin);
	scanf("%s",s1.email);
	printf("Enter Period(\'x\'days): ");
	fflush(stdin);
	scanf("%s",s1.period);
	fprintf(pf,"%s\n%s\n%s\n%s\n%s\n%s\n%s\n",s1.name,s1.address,s1.phone,s1.national,s1.date,s1.email,s1.period);

	fclose(pf);
	printf("\n\nRoom is successfully booked!!!\n\n");
	  {printf("\nEnter 1 to go to the main menu and 0 to exit:");
        scanf("%d",&main_exit);}
        if (main_exit==1)
        {
            system("cls");
            menu();
        }

        else
           {
			system("cls");
            printf("\n\n\t\tThank You for using our program !!!!");
            }
}
}
