#include "order_handler.h"


void check_for_order(){
    for(int i=0;i<HARDWARE_NUMBER_OF_FLOORS;i++){
        if(hardware_read_order(i,HARDWARE_ORDER_UP)){
            Order new_order;
            new_order.floor=i;
            new_order.order_type=HARDWARE_ORDER_UP;
            add_order(&new_order);
            printf("Order recieved \n");
           
        }
        if(hardware_read_order(i,HARDWARE_ORDER_DOWN)){
            Order new_order;
            new_order.floor=i;
            new_order.order_type=HARDWARE_ORDER_DOWN;
            add_order(&new_order);
            
        }
        if(hardware_read_order(i,HARDWARE_ORDER_INSIDE)){
            Order new_order;
            new_order.floor=i;
            new_order.order_type=HARDWARE_ORDER_INSIDE;
            add_order(&new_order);
          
        }
    }
}