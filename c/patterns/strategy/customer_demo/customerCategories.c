#include "customerCategories.h"


double bronzeCustomerStrategy(double amount,double shipping){
    return amount * 0.98 + shipping;
}
double silverCustomerStrategy(double amount,double shipping){
    return amount * 0.95 + shipping;
}
double goldCustomerStrategy(double amount,double shipping){
    return amount * 0.90;
}
