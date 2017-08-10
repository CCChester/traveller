/************************************************
 * Name: Chen Chen
 * Student ID: 20518383
 * File: reservation.c 
 * CS 136 Fall 2014 - Assignment 6, Problem 1
 * Description: 
***********************************************/
#include <stdio.h>
#include <assert.h>
#include <stdbool.h>

static struct manifest *new_one = NULL;
    
struct manifest {
    bool seats[100];
    int num_fc;
    int num_ec;
};

struct manifest M(int num_fc, int num_ec) {
    assert(num_fc >= 0);
    assert(num_ec >= 0);
    assert(num_fc + num_ec <= 100);
    struct manifest result;
    result.num_fc = num_fc;
    result.num_ec = num_ec;
    for (int i=0; i < 100; ++i)
        result.seats[i] = false;
    return result;
}

int get_available_seats_fc(struct manifest *man) {
    assert(man);
    new_one=man;
    return new_one->num_fc;
}

int get_available_seats_ec(struct manifest *man){
    assert(man);
    new_one=man;
    return new_one->num_ec;
}

int book_seat_fc(struct manifest *man){
    assert (man);
    new_one=man;
    int negative=-1;
    bool *name=new_one->seats;
    while (name < new_one->num_fc + new_one->seats){
        if (*name==0) {
            negative=negative+1;
            return negative;
        }
        else{
            negative=negative+1;
        }
        ++name;
        }
    return negative;
}

int book_seat_ec(struct manifest *man){
    assert(man);
    new_one=man;
    int negative=-1;
    bool *name = new_one->num_fc + new_one->seats;
    while (name < new_one->num_ec + new_one->num_fc + new_one->seats){
        if (*name==0) {
            negative=negative+1;
            negative+=new_one->num_fc;
            return negative;
        }
        else{
            negative=negative+1;
        }
        ++name;
    }
    negative+=new_one->num_fc;
    return negative;
}

void reset_manifest(struct manifest *man){
    assert(man);
    new_one=man;
    bool *name=new_one->seats;
    while (name < 100 + new_one->seats) {
        *name = 0;
        ++name;
    }

}



