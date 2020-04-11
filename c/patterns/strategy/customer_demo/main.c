#include <stdio.h>
#include "customer.h"


int main(int argc, char *argv[])
{
    customerPtr c = createBronzeCustomer("chen");
    placeOrder(c,1000.0,50.0);
    printf("total:%f\n",caculatePrice(c));
    freeCustomer(c);


    c = createGoldCustomer("tao");
    placeOrder(c,10000.0,70.0);
    printf("total:%f\n",caculatePrice(c));
    freeCustomer(c);
    return 0;
}
