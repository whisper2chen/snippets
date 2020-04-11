#ifndef __CUSTOMER_H
#define __CUSTOMER_H


typedef struct customer* customerPtr;

customerPtr createBronzeCustomer(char *name);
//customerPtr createSilverCustomer(void);
customerPtr createGoldCustomer(char *name);
void freeCustomer(customerPtr instance);
double caculatePrice(customerPtr instance);
void placeOrder(customerPtr instance,double amount,double shipping);
#endif
