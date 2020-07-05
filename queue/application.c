#include "queue.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stddef.h>

typedef struct employee_{
    char name[50];
    int age;
    char designation[50];
    int salary;
    queue_element_t queue_element;
} employee_t;

void print_employee_details(queue_element_t *element){
    if(!element) return;
    employee_t *employee = NULL;
    size_t offset_queue_element = offsetof(employee_t, queue_element);
    employee = (char *)element - offset_queue_element;
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

    employee_t *e2 = calloc(1, sizeof(employee_t)); 
    strncpy(e2->name, "Brad", strlen("Brad"));
    e2->age = 29;
    strncpy(e2->designation, "SRE", strlen("SRE"));
    e2->salary = 90000;

    employee_t *e3 = calloc(1, sizeof(employee_t)); 
    strncpy(e3->name, "Salim", strlen("Salim"));
    e3->age = 22;
    strncpy(e3->designation, "SRE", strlen("SRE"));
    e3->salary = 100000;


    employee_t *e4 = calloc(1, sizeof(employee_t)); 
    strncpy(e4->name, "William", strlen("William"));
    e4->age = 39;
    strncpy(e4->designation, "SRE", strlen("SRE"));
    e4->salary = 90000;

    employee_t *e5 = calloc(1, sizeof(employee_t)); 
    strncpy(e5->name, "Boris", strlen("Boris"));
    e5->age = 33;
    strncpy(e5->designation, "SRE", strlen("SRE"));
    e5->salary = 85000;

    employee_t *e6 = calloc(1, sizeof(employee_t)); 
    strncpy(e6->name, "Trump", strlen("Trump"));
    e6->age = 36;
    strncpy(e6->designation, "Asshole", strlen("Asshole"));
    e2->salary = 90000;

    queue_t *employee_queue = init_queue();
    enqueue(employee_queue, &e1->queue_element);
    enqueue(employee_queue, &e2->queue_element);
    enqueue(employee_queue, &e3->queue_element);
    enqueue(employee_queue, &e4->queue_element);
    enqueue(employee_queue, &e5->queue_element);
    enqueue(employee_queue, &e6->queue_element);
    print_employee_details(peek(employee_queue));

    print_employee_details(dequeue(employee_queue));
    print_employee_details(dequeue(employee_queue));
    print_employee_details(dequeue(employee_queue));
    print_employee_details(dequeue(employee_queue));
    print_employee_details(dequeue(employee_queue));
    print_employee_details(dequeue(employee_queue));
    print_employee_details(peek(employee_queue));
    return 0;
}
