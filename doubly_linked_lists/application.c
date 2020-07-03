#include "dll.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <assert.h>

typedef struct student_{
    char name[32];
    int age;
    int weight;
    unsigned int rollno;
} student_t;

static void print_student_details(student_t *student) {
    printf("Name: %s\n", student->name);
    printf("Age: %d\n", student->age);
    printf("Weight: %d\n", student->weight);
    printf("Roll No: %d\n", student->rollno);
}

static void print_student_db(dll_t *student_db) {

#if 0
    if(!student_db || !student_db->head) return;

    dll_node_t *head = student_db->head;
    student_t *data = NULL;

    while(head) {
        data = head->data;
        print_student_details(data);
        head = head->right;
    }
#endif
    /*Iterate the list*/
    dll_node_t *node_ptr = NULL;
    student_t *data = NULL;

    ITERATE_LIST_BEGIN(student_db, node_ptr){

        data = node_ptr->data;
        print_student_details(data);
    } ITERATE_LIST_END;
}

typedef struct employee_{
    char name[32];
    char designation[32];
    unsigned int salary;
    unsigned int empid;
} employee_t;

static void print_employee_details(employee_t *employee) {
    printf("Name: %s\n", employee->name);
    printf("Designation: %s\n", employee->designation);
    printf("Salary: %d\n", employee->salary);
    printf("Employee ID: %d\n", employee->empid);
}

static void print_employee_db(dll_t *employee_db){
    if(!employee_db || !employee_db->head) return;

    dll_node_t *head = employee_db->head;
    employee_t *data = NULL;

    while(head) {
        data = head->data;
        print_employee_details(data);
        head = head->right;
    }
}

static int match_student_rec_by_key(void *data, void *key){
    student_t *student = (student_t*)data;
    int *rollno = (int*)key;
    if(student->rollno==rollno)
        return 0;
    return -1;
}

static int match_employee_rec_by_key(void *data, void *key){
    employee_t *employee = (employee_t*)data;
    int *empid = (int*)key;
    if(employee->empid==empid)
        return 0;
    return -1;
}

static int student_comparison_fn(void *student1, void *student2){
    student_t *stud1 = (student_t*) student1;
    student_t *stud2 = (student_t*) student2;

    if(strncmp(stud1->name, stud2->name, 32) < 0)
        return -1;
    else if(strncmp(stud1->name, stud2->name, 32) > 0)
        return 1;
    else if(stud1->age < stud2->age)
        return -1;
    else if(stud1->age > stud2->age)
        return 1;
    else if(stud1->weight < stud2->weight)
        return -1;
    else if(stud1->weight > stud2->weight)
        return 1;
    else if(stud1->rollno < stud2->rollno)
        return -1;
    else if(stud1->rollno > stud2->rollno)
        return 1;
    assert(0);
}

int main(int argc, char **argv){
    student_t *student1 = (student_t*)calloc(1, sizeof(student_t));
    strncpy(student1->name, "Abhishek", strlen("Abhishek"));
    student1->age = 31;
    student1->weight = 70;
    student1->rollno = 800100;

    student_t *student2 = (student_t*)calloc(1, sizeof(student_t));
    strncpy(student2->name, "Aneesh", strlen("Aneesh"));
    student2->age = 31;
    student2->weight = 70;
    student2->rollno = 800101;

    student_t *student3 = (student_t*)calloc(1, sizeof(student_t));
    strncpy(student3->name, "Abhilash", strlen("Abhilash"));
    student3->age = 31;
    student3->weight = 70;
    student3->rollno = 800103;

    dll_t *student_db = get_new_dll();
    register_key_match_callback(student_db, match_student_rec_by_key);
    register_comparison_callback(student_db, student_comparison_fn);
    dll_priority_insert_data(student_db, student1); 
    dll_priority_insert_data(student_db, student2);
    dll_priority_insert_data(student_db, student3);

    student_t *student = search_dll_by_key(student_db, (void *)800103);
    if(!student){
        printf("Student record not found");
    }
    else {
        print_student_details(student);
    }

    employee_t *employee1 = (employee_t*)calloc(1, sizeof(employee_t));
    strncpy(employee1->name, "Soman", strlen("Soman"));
    strncpy(employee1->designation, "Software Engineer 1", strlen("Software Engineer 1"));
    employee1->salary = 100000;
    employee1->empid = 800101;

    employee_t *employee2 = (employee_t*)calloc(1, sizeof(employee_t));
    strncpy(employee2->name, "Aneesh", strlen("Aneesh"));
    strncpy(employee2->designation, "Software Engineer 1", strlen("Software Engineer 1"));
    employee2->salary = 100000;
    employee2->empid = 800102;

    employee_t *employee3 = (employee_t*)calloc(1, sizeof(employee_t));
    strncpy(employee3->name, "Abhilash", strlen("Abhilash"));
    strncpy(employee3->designation, "Software Engineer 1", strlen("Software Engineer 1"));
    employee3->salary = 100000;
    employee3->empid = 800103;

    employee_t *employee4 = (employee_t*)calloc(1, sizeof(employee_t));
    strncpy(employee4->name, "Maria", strlen("Maria"));
    strncpy(employee4->designation, "Software Engineer 1", strlen("Software Engineer 1"));
    employee4->salary = 100000;
    employee4->empid = 800104;

    dll_t *employee_db = get_new_dll();
    register_key_match_callback(employee_db, match_employee_rec_by_key);
    register_comparison_callback(employee_db, student_comparison_fn);
    dll_priority_insert_data(employee_db, employee1);
    dll_priority_insert_data(employee_db, employee2);
    dll_priority_insert_data(employee_db, employee3);
    dll_priority_insert_data(employee_db, employee4);

    print_employee_db(employee_db);
    
    employee_t *employee = search_dll_by_key(employee_db, (void *)800105);
    if(!employee){
        printf("employee record not found");
    }
    else {
        print_employee_details(employee);
    }
    
    return 0;
}