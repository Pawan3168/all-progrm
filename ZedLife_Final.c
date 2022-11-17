#include <stdio.h>
#include<stdlib.h>
#include <time.h>
#include<string.h>
#include<ctype.h>
struct date
    {
        int dd;
        int mm;
        int yy;
    };
typedef struct
    {
        char name[60],birth_date[20],gender[10],address[60],email[50],*plan_type,*claim_type,health_hstry[150];
        long long int contact_no,age;
        int subs_id,subs_age;
        int charge_icu,charge_room,charge_supplies,charge_surgical,charge_other;
        int claimable_amt,remaining_amt,claimed_amt;
        char claimed_time[20];
    }subscribers_details;

int get_subs_id()
{
    int sid = 100;
    FILE * fp = fopen("sid.txt", "r") ;
    if (!fp) {
        fp = fopen("sid.txt", "w") ;
        fprintf(fp, "%d", sid) ;
        fclose(fp) ;
        return sid;
    }

    fscanf(fp, "%d", &sid) ;
    sid++;

    fclose(fp);
    fp = fopen("sid.txt", "w") ; 
    fprintf(fp, "%d", sid) ;
    fclose(fp) ;
    return sid ;
}
void store_subscribers_data(subscribers_details sd, struct date dob,int age)
    {
        // struct  date dob;
        int recread;
        char *c_type,*p_type;
        int c_choice,p_choice,sid;
        FILE *fp;
        fp = fopen("subscribers.txt", "r");
        if (!fp)
        {
            fp = fopen("subscribers.txt", "w");
        }
        else
        {
            fclose(fp);
            fp = fopen("subscribers.txt", "a");
        }

        sd.subs_id = get_subs_id();
        sprintf(sd.birth_date,"%d-%d-%d",dob.yy,dob.mm,dob.dd); // converting date integer to string
        sd.subs_age = age;

        printf("\n\n--Fill the requirements to subscribe insurance plan--\n");
        
        printf("\nEnter Name: ");
        fflush(stdin);
        gets(sd.name);
        printf("Enter Gender: ");
        fflush(stdin);
        gets(sd.gender);
        printf("Enter address: ");
        fflush(stdin);
        gets(sd.address);
        printf("Enter contact no.: ");
        fflush(stdin);
        scanf("%ld", &sd.contact_no);
        printf("Enter Email ID: ");
        fflush(stdin);
        gets(sd.email);
        
        printf("Enter the claim limit type: ");
        
        printf("\n1. Annual Claim Limit\n2. Lifetime Claim Limit\n");
        scanf("%d",&c_choice);
        if (c_choice == 1)
        {
            c_type = "Annual Claim Limit"; 
        }
        else if (c_choice == 2)
        {
            c_type =  "Lifetime Claim Limit"; 
        }
        sd.claim_type = c_type;

        printf("Enter name of Plan: ");
        if (age <= 20)
        {
            printf("\n1. Plan 120 \n2. Plan 150\n3. Plan 200\n");
            scanf("%d",&p_choice);
            if (p_choice == 1)
                p_type = "Plan 120";
            else if (p_choice == 2)
                p_type = "Plan 150";
            else if (p_choice == 3)
                p_type = "Plan 200";
        }
        else if (age <= 40)
        {
            printf("\n1. Plan 150 \n2. Plan 200\n");
            scanf("%d",&p_choice);
            if (p_choice == 1)
                p_type = "Plan 150";
            else if (p_choice == 2)
                p_type = "Plan 200";
        }
        else if(age <=54)
        {
            printf("\n1. Plan 200\n");
            scanf("%d",&p_choice);
            if (p_choice == 1)
                p_type = "Plan 150";
        }
        sd.plan_type = p_type;

        printf("Enter any chronic illness if you have in the past history: ");
        fflush(stdin);
        gets(sd.health_hstry);

        fwrite(&sd,sizeof(subscribers_details),1,fp);
        fclose(fp);
    }
    
void display_subscribers_data()
    {
        FILE *fp;
        subscribers_details sd;
        fp = fopen("subscribers.txt", "r");
        if (!fp)
        {
            printf("Cannot find file");
            return;
        }
        printf("\nID\tName\t\t    Gender\tDOB\t    Age\t\tContact no.\tEmail\t\t    Address\t    Claim Type\t\t\tPlan Type\tHealth History\n");
        while (fread(&sd,sizeof(subscribers_details),1,fp)==1)
        {
            printf("\n%-8d%-20s%-12s%-12s%-12d%-16lld%-20s%-16s%-28s%-16s%-4s",sd.subs_id,sd.name,sd.gender,sd.birth_date,sd.subs_age,sd.contact_no,sd.email,sd.address,sd.claim_type,sd.plan_type,sd.health_hstry);
        }
        fclose(fp);
    }



int show_age(struct date dob, struct tm *cdate);

struct date input_dob()
{
    struct date age;
    int y,m,d;
    printf("Enter dob (yyyy mm dd: ");
    scanf("%d %d %d",&y,&m,&d);
    struct date dob ={d,m,y};
    
    struct tm *curtime;
    time_t currenttime;
    time(&currenttime);
    curtime = localtime(&currenttime);
    show_age(dob,curtime);
}

int show_age(struct date dob, struct tm *cdate)
{
    subscribers_details sd;
    int y;
    int m;
    int d;
    cdate->tm_year+= 1900;
    cdate->tm_mon += 1;

    if (cdate->tm_mday < dob.dd)
    {
        d = (cdate->tm_mday +30) - dob.dd;
        cdate->tm_mday+=30;
        cdate->tm_mon--;
        
    }
    if (cdate->tm_mon < dob.mm)
    {
        cdate->tm_mon+=12;
        cdate->tm_year--;
    }
    d = cdate->tm_mday - dob.dd;
    m = cdate->tm_mon - dob.mm;
    y = cdate->tm_year - dob.yy;

    if (d >= 15 && y<= 20)
    {
        printf("\n\t\t\tPlan 120 (RM) \t Plan 150 (RM) \t Plan200(RM)");
        printf("\nAnnual Claim Limit \t 120,000 \t 150,000 \t 200,000");
        printf("\nLifetime Claim Limit \t 600,000 \t 750,000 \t 1,000,000 \n\n\n");

        printf("Types of Claim \t\t Eligibility Amount (RM)");
        printf("\n\t\t\t Plan 120 \t Plan 150 \t Plan 200");
        printf("\nRoom Charges \t\t 120/day \t 150/day \t 200/day");
        printf("\nICU Charges \t\t 250/day \t 400/day \t 700/day");
        printf("\nHospital Supplies\nand Services");
        printf("\nSurgical Fees\t\t\t As Charged");
        printf("\nOther Fees\n");

        store_subscribers_data(sd,dob,y);

    }

    else if (y > 21 && y <=40)
    {
        printf("\n\t\t\tPlan 150 (RM) \t Plan200(RM)");
        printf("\nAnnual Claim Limit \t 150,000 \t 200,000");
        printf("\nLifetime Claim Limit \t 750,000 \t 1,000,000 \n\n\n");

        printf("Types of Claim \t\t Eligibility Amount (RM)");
        printf("\n\t\t\t Plan 150 \t Plan 200");
        printf("\nRoom Charges \t\t 150/day \t 200/day");
        printf("\nICU Charges \t\t 400/day \t 700/day");
        printf("\nHospital Supplies\nand Services");
        printf("\nSurgical Fees\t\t\t As Charged");
        printf("\nOther Fees\n");
        store_subscribers_data(sd,dob,y);
    }
    else if (y > 41 && y <=54)
    {
        printf("\n\t\t\tPlan200(RM)");
        printf("\nAnnual Claim Limit \t 200,000");
        printf("\nLifetime Claim Limit  \t 1,000,000 \n\n\n");

        printf("Types of Claim \t\t Eligibility Amount (RM)");
        printf("\n\t\t\t Plan 200");
        printf("\nRoom Charges \t\t 200/day");
        printf("\nICU Charges \t\t 700/day");
        printf("\nHospital Supplies\nand Services");
        printf("\nSurgical Fees\t\t\t As Charged");
        printf("\nOther Fees\n");
        store_subscribers_data(sd,dob,y);

    }
    else
    {
        printf("\nHealth Insurance Plan is not available for your age !!\n");
    }
return 0;

}


void submit_claim(){
    subscribers_details sd;
    FILE *fr,*fw;
    int d_icu,d_room,icu_cost,room_cost;
    float c_supplies,c_surgical,c_other;
    char insured_name[40];
    int not_found = 0;
    int deductible_amt,available_balance,claimed_amt;
    char buffer[20]; // taken for time

    fw = fopen("claim details.txt", "r");
    if (!fw)
    {
        fw = fopen("claim details.txt", "w");
    }
    else
    {
        fclose(fw);
        fw = fopen("claim details.txt", "a");
    }

    printf("\n------ Fill out the following details to apply for claim ------\n");
    printf("Enter no. of days spend in a hospital's room: \n");
    scanf("%d",&d_room);
    printf("Enter no. of days hospitalized in ICU: \n");
    scanf("%d",&d_icu);
    printf("Enter cost of Hospital Supplies and Services: \n");
    scanf("%f",&c_supplies);
    printf("Enter Surgical Fees: \n");
    scanf("%f",&c_surgical);
    printf("Enter Other Fees: \n");
    scanf("%f",&c_other);

    // # checking eligibility
    printf("Enter name of the Insured: ");
    fflush(stdin);
    gets(insured_name);

    fr = fopen("subscribers.txt", "r");
    if (!fr)
    {
        printf("Cannot find file");
        return;
    }
    
    while(fread(&sd,sizeof(subscribers_details),1,fr)==1)
    {
        if(strcmp(sd.name, insured_name)==0) // checking if name is available
        {
            if(strcmp(sd.claim_type,"Annual Claim Limit")==0) //Checking if annual annual Claim Limit
            {
                if(strcmp(sd.plan_type,"Plan 120")==0)
                {
                    deductible_amt = 1200000;
                    room_cost = d_room * 120;
                    icu_cost = d_icu * 250;
                }
                else if(strcmp(sd.plan_type,"Plan 150")==0)
                {
                    deductible_amt = 1500000;
                    room_cost = d_room * 150;
                    icu_cost = d_icu * 400;
                }
                else if(strcmp(sd.plan_type,"Plan 200")==0)
                {
                    deductible_amt = 2000000;
                    room_cost = d_room * 200;
                    icu_cost = d_icu * 700;
                }
            }

            else if(strcmp(sd.claim_type,"Lifetime Claim Limit")==0)
            {
                if(strcmp(sd.plan_type,"Plan 120")==0)
                {
                    deductible_amt = 600000;
                    room_cost = d_room * 120;
                    icu_cost = d_icu * 250;
                }
                else if(strcmp(sd.plan_type,"Plan 150")==0)
                {
                    deductible_amt = 7500000;
                    room_cost = d_room * 150;
                    icu_cost = d_icu * 400;
                }
                else if(strcmp(sd.plan_type,"Plan 200")==0)
                {
                    deductible_amt = 10000000;
                    room_cost = d_room * 200;
                    icu_cost = d_icu * 700;
                }
            }

            available_balance = deductible_amt - room_cost - icu_cost - c_supplies - c_surgical - c_other; // calculating amount remained to claim
            claimed_amt = room_cost + icu_cost + c_other + c_supplies + c_surgical; //Calculating amount claimed by insurer
            
            if (available_balance < 0)
                {
                    printf("Dear subscriber, your available balance amount has exceeded your Plan Subscription...\nNow, you need to pay %d from your account", abs(available_balance)); 
                }
            else{
                    sd.claimable_amt = deductible_amt;
                    sd.remaining_amt = available_balance;
                    sd.claimed_amt = claimed_amt;
                    
                    struct tm *curtime;
                    time_t currenttime;
                    time(&currenttime);
                    curtime = localtime(&currenttime);
                    strftime(buffer,80,"%Y-%m-%d",curtime);
                    strcpy(sd.claimed_time,buffer);

                    fwrite(&sd,sizeof(subscribers_details),1,fw);
                    printf("\nYour claim request has been sent successfully...\n");
                    fclose(fr);
                    fclose(fw);
            }
        }
    }

}

void display_claim()
{
    FILE *fp;
    subscribers_details sd;
    fp = fopen("claim details.txt", "r");
    if (!fp)
    {
        printf("Cannot find file");
        return;
    }
    printf("\nSubscriber ID\tName\t\tClaim Limit Type\tClaim Type\tClaimable Amount\tClaimed Amount\tAvailable Balance\n");
    while(fread(&sd,sizeof(subscribers_details),1,fp)==1)
    {
        printf("\n%-16d%-16s%-16s\t%-2s\t%-20d\t%-9d\t%d",sd.subs_id,sd.name,sd.claim_type,sd.plan_type,sd.claimable_amt,sd.claimed_amt,sd.remaining_amt);
    }
    fclose(fp);

}




// # search record
void search_subscriber_record(subscribers_details sd, int choice)
{
    FILE *fp;
    subscribers_details sd1;
    int recread;
    fp = fopen("subscribers.txt", "r");
    if (!fp)
    {
        printf("Cannot find file");
        return;
    }
    
    while(1)
    {
        recread= fread(&sd1,sizeof(subscribers_details),1, fp);
        if (recread!=1) break;
        switch(choice)
        {
            case 1:
                if (sd.subs_id == sd1.subs_id)
                {
                    printf("ID : %d\n", sd1.subs_id);
                    printf("Name : %s\n", sd1.name);
                    printf("Age: %d years\n",sd1.subs_age);
                    printf("Contact no. : %d\n",sd1.contact_no);
                    printf("Plan Type : %s\n", sd1.plan_type);
                    printf("Claim Limit Type : %s\n",sd1.claim_type);
                }
                break;
            case 2:
                if(strcmp(sd.name, sd1.name)==0)
                {
                    printf("ID : %d\n", sd1.subs_id);
                    printf("Name : %s\n", sd1.name);
                    printf("Age: %d years\n",sd1.subs_age);
                    printf("Contact no. : %d\n",sd1.contact_no);
                    printf("Plan Type : %s\n", sd1.plan_type);
                    printf("Claim Limit Type : %s\n",sd1.claim_type);                
                }
                break;

        }
    }
    

}

int fordelay(long int j)
{
	int i, k;
	for(i=0;i<j;i++)
	{
		k=i;
	}
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

void main()
{
	WelcomeScreen();
    struct date age;
    char claimtype[2][100]={"Annual Claim Limit","Lifetime Claim Limit"};
    subscribers_details sd;
    char choice;
    char ch;
    printf("ZeeMediLife Insurance Company\n");

    do
    {
        printf("\n\nChoose our services:\n\n");
        printf("1. Insurance Plan Subsription\n2. Claim Processing\n3. Accounts Information\n4. Searching Subsribers \n\t Type 'q' to exit");
        fflush(stdin);
        printf("\n\nSelect what you want to do (1-4): ");
        ch = tolower(getchar());
        switch (ch)
        {
            case '1':
                printf("\n1. Apply for Claim\n2. Display Claim Details\n");
                fflush(stdin);
                scanf("%d",&choice);
                switch (choice)
                {
                    case 1:
                        age = input_dob();

                        break;
                    case 2:
                        display_subscribers_data();
                        break;
                }
                break;
                
            case '2':
                printf("\n1. Submit Claim\n2. Display Claim Details\n");
                fflush(stdin);
                scanf("%d",&choice);
                switch (choice)
                {
                case 1:
                    submit_claim();
                    break;
                
                case 2:
                    display_claim();
                    break;
                default:
                    printf("\nInvalid Input\n");
                }
                break;

            case '4':
                printf("\n1. Search by Subscriber ID\n");
                printf("2. Search by Name\n");
                printf("3. Search by Plan Name\n");
                printf("4. Search By Claim Limit Type\n");
                printf("5. Search by Age\n ");

                fflush(stdin);
                choice = getchar();
                
                switch(choice)
                {
                    case '1':
                        printf("\nEnter subscriber ID: ");
                        fflush(stdin);
                        scanf("%d", &sd.subs_id);
                        search_subscriber_record(sd,1);
                        break;
                    case '2':
                        printf("\nEnter subscriber name: ");
                        fflush(stdin);
                        gets(sd.name);
                        search_subscriber_record(sd,2);
                        break;
                    case '3':
                        printf("\nEnter plan's name: ");
                        fflush(stdin);
                        gets(sd.plan_type);
                        search_subscriber_record(sd,3);
                        break;
                    case '4':
                        printf("Enter Limit Type: ");
                        fflush(stdin);
                        gets(sd.claim_type);
                        search_subscriber_record(sd,4);
                        break;
                    case '5':
                        printf("Enter suscriber age: ");
                        fflush(stdin);
                        scanf("%d",&sd.subs_age);
                        search_subscriber_record(sd,5);
                        break;
                }
                break;
        }

    }while (ch!='q');
                    
}
