#include "PAYMENT_APP.h"

ST_cardData_t CardData;
ST_terminalData_t TerminalData;

ST_accountBalance_t AccountsBalance[ACCOUNTS_NUMBERS]={	{ 100.00 ,	"123456789" },
														{ 6000.00,	"234567891" }, 
														{ 3250.25, 	"567891234" },
														{ 1500.12, 	"456789123" },
														{ 500.00 , 	"258649173" },
														{ 2100.00, 	"654823719" },
														{ 0.00   ,	"971362485" },
														{ 1.00   ,	"793148625" },
														{ 10.12  ,	"123123456" },
														{ 0.55	 ,	"456789321" }							
};

int8_t LinearSearch(uint8_t ArraySize,ptr_uint8_t String)
{
	for(uint8_t i=0;i<ArraySize;i++)
	{
		if(StringCompare((ptr_int8_t)&(AccountsBalance[i].primaryAccountNumber),String)==0)
		{
			return i;
		}
	}
	return NOT_FOUND;
}
void CardDataReset(void)
{
	for(uint8_t i=0;i<25;i++)
	{
		CardData.cardHolderName[i]='\0';
		if(i<20)
		{
			CardData.primaryAccountNumber[i]='\0';
		}
		if(i<6)
		{
			CardData.cardExpirationDate[i]='\0';
		}
	}
}

void TerminalDataReset(void)
{
	TerminalData.transAmount=0;
	TerminalData.maxTransAmount=0;
	
	for(uint8_t i=0;i<11;i++)
	{
		TerminalData.transactionDate[i]='\0';
	}	
}

void CardDataRead(void)
{
	printf("\n\t\t\t  Please Enter Card Data:\n\n");
	printf("Please Enter Card Holder Name:\n");
	scanf("%[^\t\n]",CardData.cardHolderName);
	getchar();
	printf("Please Enter the Primary Account Number\n");
	scanf("%[^\t\n]",CardData.primaryAccountNumber);
	getchar();
	printf("Please Enter Card Expiry Date MM/YY:\n");
	scanf("%[^\t\n]",CardData.cardExpirationDate);
	getchar();
}

EN_AmountStat_t TerminalDataRead(void)
{
	TerminalData.maxTransAmount = MAX_TRANS_AMOUNT;
	printf("\n\t\t  Please Enter Transaction Data:\n\n");
	printf("Please Enter the Transaction Amount:\n");
	scanf("%f",&(TerminalData.transAmount));
	getchar();
	if(TerminalData.transAmount > MAX_TRANS_AMOUNT)
	{
		return REJECTED;
	}
	printf("Please Enter Transaction Date DD/MM/YYYY:\n");
	scanf("%[^\t\n]",TerminalData.transactionDate);
	getchar();
	return ACCEPTED;
}

void PaymentApplication(void)
{
	uint8_t ContinueFlag;
	uint8_t MM_Card,YY_Card,MM_Transaction,YY_Transaction; 
	do
	{
		system("cls");
		
		CardDataReset();
		TerminalDataReset();
		
		CardDataRead();
		if(TerminalDataRead() == ACCEPTED)
		{
			MM_Card= ((CardData.cardExpirationDate[0]-48)*10) + (CardData.cardExpirationDate[1]-48);
			YY_Card= ((CardData.cardExpirationDate[3]-48)*10) + (CardData.cardExpirationDate[4]-48);
			MM_Transaction= ((TerminalData.transactionDate[3]-48)*10) + (TerminalData.transactionDate[4]-48);
			YY_Transaction= ((TerminalData.transactionDate[8]-48)*10) + (TerminalData.transactionDate[9]-48);
		

			if((YY_Card < YY_Transaction) || ((YY_Card == YY_Transaction)&&(MM_Card < MM_Transaction)))
			{
				printf("The Transaction is DECLINED.");
			}
			else
			{
					
					printf("Verifying Data from the server...\n");
					if(ServerCheck() == APPROVED)
					{
						
					}
					else
					{
						printf("The Transaction is DECLINED.");
					}
			}			

		}
		else
		{
			printf("The Transaction is DECLINED.");
		}
		
		printf("\t\t\t\nDo you want to continue (y/n)?:\n");
		scanf("%c",&ContinueFlag);
		getchar();
		
	}while((ContinueFlag=='y') || (ContinueFlag=='Y'));
}

EN_transStat_t ServerCheck(void)
{
	int8_t PAN_FindingFlag;
	
	PAN_FindingFlag = LinearSearch( ACCOUNTS_NUMBERS,CardData.primaryAccountNumber);
	
	if(PAN_FindingFlag == -1)
	{
		return DECLINED;
	}
	else
	{
		if(AccountsBalance[PAN_FindingFlag].balance < TerminalData.transAmount)
		{
			return DECLINED;
		}
		else
		{
			AccountsBalance[PAN_FindingFlag].balance -= TerminalData.transAmount;
			printf("%f\n",AccountsBalance[PAN_FindingFlag].balance);
			return ACCEPTED;
		}
	}
}
