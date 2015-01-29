#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define log(test_description) int log = (printf("\t     %s\n\n", test_description))
#define CHAR_SIZE sizeof(char)
#define char_size sizeof(char)
#define int_size sizeof(int)
#define INT_SIZE sizeof(int)
#define float_size sizeof(float)
#define double_size sizeof(double)
#define sizeOf_String sizeof(String)
#define sizeOf_Student sizeof(Student)
#define sizeOf_int10 sizeof(int10)
#define sizeOf_float5 sizeof(float5)
#define sizeOf_void_star sizeof(void_star)
#define sizeOf_char_star sizeof(char_star)
#define sizeOf_int_star sizeof(int_star)
#define sizeOf_float_star sizeof(float_star)
#define YES 1
#define NO 0

typedef int(*int_void_void)(void*, void*);
typedef void(*void_2void)(void*, void*);
typedef void(*void_3void)(void*, void*, void*);


typedef char* string;
typedef char String[256];
typedef void *void_star;
typedef char *char_star;
typedef int *int_star;

typedef struct Stud { 
	char name[27]; 
	int std; 
	float percentage; 
} Student;
typedef struct arrayUtil {
	void *base;
	int typeSize;
	int length;
} ArrayUtil;

int areEqual(ArrayUtil, ArrayUtil);
ArrayUtil create(int, int);
ArrayUtil resize(ArrayUtil, int);
int findIndex(ArrayUtil util, void* element);
void dispose(ArrayUtil);
void* findFirst(ArrayUtil util, int_void_void, void *hint);
void* findLast(ArrayUtil util, int_void_void, void *hint);
int count(ArrayUtil util, int_void_void, void *hint);
int filter(ArrayUtil, int_void_void , void*, void**, int);
void map(ArrayUtil, ArrayUtil, void_3void, void*);
void forEach(ArrayUtil, void_2void, void*);
void* reduce(ArrayUtil, void*(*)(void*,void*,void*), void*, void*);
