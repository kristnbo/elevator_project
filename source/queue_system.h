#include "hardware.h"

#include <stdio.h> //for clearing terminal
/**
 * @file
 * @brief A system for keeping track of all current orders. 
 * The system also calculates the elevators movements based on this.
 */
#ifndef QUEUE_SYSTEM_H
#define QUEUE_SYSTEM_H
#define MAX_NUMBER_OF_ORDERS 10
#define MAX_NUMBER_OF_ACTIONS 15

/**
 * @brief Common type for orders.
 */

typedef struct Order {
    int floor;
    HardwareOrder order_type;
    int active;
}Order; 


/**
 * @brief The state type found in main
 */
typedef enum {
    UP,
    DOWN,
    IDLE,
    WAITING,
    EMERGENCY_STOP,
    IGNORE
} State;


/**
 * @brief Adds an order to the order array by setting active to 1.
 */
void add_order(Order *order);

/**
 * @brief Removes all order for a floor, by setting active to zero. 
 * @param current_floor The floor orders should be deactivated for.
 */
void remove_order(int current_floor,Order *order_array);

void clear_order(int current_floor);

/**
 * @brief Prints all orders with floor and type, and shows wether they are active or not.
 */
void print_queue();

/**
 * @brief Calculates the elevators actions and refreshes the action_list.
 */

void calculate_action_array(State state, State last_state, int current_floor);

/**
 * @brief Fetches next action, and updates the order array by deleting all completed orders.
 * @param state FSM current state.
 */

State request_action();

/**
 * @brief Prints all actions planned.
 */
void print_actions();

void clear_all_orders();

void clear_all_actions();


#endif

