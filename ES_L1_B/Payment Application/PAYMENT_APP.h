/*
 * File Name: PAYMENT_APP.h
 * Creation Date: 04/07/2021
 * Author: Rehab
 * Description: Header File for Payment Application ....
 */ 
 
#ifndef PAYMENT_APP_H_
#define PAYMENT_APP_H_

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

#include "STD_TYPES.h"
#include "STRING.h"

#define MAX_TRANS_AMOUNT	5000.0
#define ACCOUNTS_NUMBERS	10
#define NOT_FOUND			-1

typedef enum EN_AmountStat
{
	REJECTED = 0,
	ACCEPTED = 1	
}EN_AmountStat_t;
 
typedef enum EN_transStat
{
	DECLINED = 0,
	APPROVED = 1
}EN_transStat_t;
 
typedef struct ST_cardData
{
	uint8_t cardHolderName[25];
	uint8_t primaryAccountNumber[20];
	uint8_t cardExpirationDate[6];
}ST_cardData_t;

typedef struct ST_terminalData
{
	float transAmount;
	float maxTransAmount;
	uint8_t transactionDate[11];
}ST_terminalData_t;

#if 0
typedef struct ST_transaction
{
	ST_cardData_t cardHolderData;
	ST_terminalData_t transData;
	EN_transStat_t transStat;
}ST_transaction_t;
typedef ST_transaction_t* ptr_ST_transaction_t; 
#endif

typedef struct ST_accountBalance
{
	float balance;
	uint8_t primaryAccountNumber[20];
}ST_accountBalance_t;

typedef ST_cardData_t* ptr_ST_cardData_t;
typedef ST_terminalData_t* ptr_ST_terminalData_t; 



int8_t LinearSearch(uint8_t ArraySize,ptr_uint8_t String);

void CardDataRead(void);
EN_AmountStat_t TerminalDataRead(void);

void CardDataReset(void);
void TerminalDataReset(void);

EN_transStat_t ServerCheck(void);

void PaymentApplication(void);

#endif