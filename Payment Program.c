/*In a department store, 10% discount is given to the customer whose total expense exceeds 5000
Write a program to determine the total cost of the customer.*/
#include<stdio.h>
#include<conio.h>
void menu(sum, op, dam, dis)
{
	int cr;
	switch(op)
    	{
    		case 1:
    			{
    				printf("\n");
    				printf("Enter the amount received from customer.\n");
    				printf("> ");
    				scanf("%d", &cr);
    				if(dam<cr)
    				{
    					printf("Cash Received.\n");
    					printf("The amount received is Rs. %d.\n", cr);
    					printf("Refund to be made is Rs. %d.\n", cr-dam);    					
    					printf("\n\n");
    					printf("        Manoj Enterprises Pvt. Ltd.        \n");
    					printf("            Balkhu, Kathmandu             \n");
    					printf("            PAN No. 101010101            \n");
    					printf("Name:\n");
    					printf("Address:\n");
    					printf("Phone No.\n");
    					printf("\n\n");
    					printf("----------------Receipt----------------\n");
    					printf("Amount Received = Rs. %d.\n", cr);
    					printf("Total Expenses  = Rs. %d.\n", sum);
    					printf("Discount        = Rs. %d.\n", dis);
    					printf("______________________________________\n");
    					printf("Grand Total     = Rs. %d.\n", dam);
    					printf("Refund          = Rs. %d.\n", cr-dam);
    					break;
    				}
    				else if(dam==cr)
    				{
    					printf("Cash Received.\n");
    					printf("\n\n");
    					printf("        Manoj Enterprises Pvt. Ltd.        \n");
    					printf("            Balkhu, Kathmandu             \n");
    					printf("            PAN No. 101010101            \n");
    					printf("Name:\n");
    					printf("Address:\n");
    					printf("Phone No.\n");
    					printf("----------------Receipt----------------\n");
    					printf("Amount Received = Rs. %d.\n", cr);
    					printf("Total Expenses   = Rs. %d.\n", sum);
    					printf("Disount Received = Rs. %d.\n", dis);
    					printf("Refund          = Rs. %d.\n", cr-dam);
    					
					}
					else
					{
						printf("The amount is short by Rs. %d.\n", dam-cr);
						printf("Please make the full payment.\n");
						printf("Credit is not available.\n");
					}
    			}
    		case 2:
				{
					printf("\nPrint the bill and receipt of payment.\n");
					printf("Press enter to exit.\n");
    				break;	
				}
			case 3:
				{
					printf("\nPrint the bill and receipt of payment.\n");
					printf("Press enter to exit.\n");
    				break;
				}	
			default:
				{
					printf("\nInvalid Option.");
					break;
				}
}
void main()
{
    int itn, n1, sum=0, i, op, cr, dis, dam;
    printf("Please enter the number of items.\n");
    printf("> ");
    scanf("%d", &itn);
    for(i=itn; i!=0; i--)
    {
        printf("Please enter the prices of the items\n");
        printf("> ");
        scanf("%d", &n1);
        sum = sum + n1;
        --itn;
    }
	printf("\n");
	printf("\n");
	if(sum>=5000)
    {
    	printf("You have purchased items worth Rs. %d", sum);
    	printf("\n");
        printf("You have received a discount of 10%%.\n");
        dis = (sum*10)/100;
        dam = sum-((sum*10)/100);
        printf("Total Discount Received = Rs. %d", dis);
        printf("\nYou need to make payment of Rs. %d", dam);
    	printf("\n");
    	printf("\nHow would to like to make your payment?");
    	printf("\n");
    	printf("\n");
    	printf("-------------Payment Menu-------------");
    	printf("\n");
    	printf("1. Cash\n");
    	printf("2. Card\n");
    	printf("3. Scan Pay\n");
    	printf("Please choose your option.\n");
    	printf("> ");
    	scanf("%d", &op);
    	menu(sum, op, dam, dis);
		}
    }
getch();
}
