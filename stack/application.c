#include "stack.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stddef.h>

typedef struct employee_{
    char name[50];
    int age;
    char designation[50];
    int salary;
    stack_element_t stack_element;
} employee_t;

void print_stack_top(stack_element_t *top){
    if(!top) return;
    employee_t *employee = NULL;
    size_t offset_stack_element = offsetof(employee_t, stack_element);
    employee = (char *)top - offset_stack_element;
    printf("Name: %s\n", employee->name);
    printf("Age: %d\n", employee->age);
    printf("Designation: %s\n", employee->designation);
    printf("Salary: %d\n", employee->salary);
}

int main(void){
    employee_t *e1 = calloc(1, sizeof(employee_t)); 
    strncpy(e1->name, "John", strlen("John"));
    e1->age = 36; 
    strncpy(e1->designation, "SRE", strlen("SRE"));
    e1->salary = 90000;
    // init_stack_element((&e1->stack_element));

    employee_t *e2 = calloc(1, sizeof(employee_t)); 
    strncpy(e2->name, "Brad", strlen("Brad"));
    e2->age = 36;
    strncpy(e2->designation, "SRE", strlen("SRE"));
    e2->salary = 90000;
    // init_stack_element((&e2->stack_element));

    stack_t *employee_stack = init();
    push(employee_stack, &e1->stack_element);
    push(employee_stack, &e2->stack_element);
    print_stack_top(pop(employee_stack));
    print_stack_top(pop(employee_stack));
    print_stack_top(pop(employee_stack));

    return 0;
}
