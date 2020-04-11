#include <assert.h>
#include <stdlib.h>
#include "customer.h"
#include "customerCategories.h"
#include "customerStrategy.h"


struct customer {
    char *name;
    double amount;
    double shipping;
    customerPriceStrategy strategy;
};

static customerPtr createCustomer(char *name,customerPriceStrategy priceStrategy){
    customerPtr c = malloc(sizeof(struct customer)); 
    assert(c != NULL);

    c->name = name; 
    c->amount = 0;
    c->shipping = 0;
    c->strategy = priceStrategy;
    return c;
}

void freeCustomer(customerPtr instance) {
    if (instance) free(instance);
}

customerPtr createBronzeCustomer(char *name){
    return createCustomer(name, bronzeCustomerStrategy);
}

customerPtr createGoldCustomer(char *name){
    return createCustomer(name, goldCustomerStrategy);
}

void placeOrder(customerPtr instance,double amount,double shipping){
    assert(instance != NULL);

    instance->amount = amount;
    instance->shipping = shipping;
}
double caculatePrice(customerPtr instance){
    assert(instance != NULL);

    return instance->strategy(instance->amount,instance->shipping);
}
