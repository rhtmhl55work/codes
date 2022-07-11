// c program to pass structure to function for use in multithreading

//#include <stdio.h>
//#include <pthread.h>
//#include <stdlib.h>
//#include <unistd.h>
//#include <string.h>
//
//struct st_bio
//{
//    char name[30];
//    int sn;
//    int age;
//};
//
//void *func1(void *arg)
//{
//    struct st_bio *st = (struct st_bio*) arg;
//    int i, sleep_time, sn, age;
//    char name[30];
//    strcpy(name, st->name);
//    sn = st->sn;
//    age = st->age;
//    for(i=0; i<5; i++){
//        sleep_time = 1 + rand() % 5;
//        printf("name=%s\t sn=%d\t age=%d\n", name, sn, age);
//        sleep(sleep_time);
//    }
//}
//
//void *func2(void *arg)
//{
//    struct st_bio *st = (struct st_bio*) arg;
//    int i, sleep_time, sn, age;
//    char name[30];
//    strcpy(name, st->name);
//    sn = st->sn;
//    age = st->age;
//    for(i=0; i<5; i++){
//        sleep_time = 1 + rand() % 5;
//        printf("name=%s\t sn=%d\t age=%d\n", name, sn, age);
//        sleep(sleep_time);
//    }
//}
//
//void main()
//{
//    pthread_t t1, t2;
//    struct st_bio st1, st2;
//    
//    strcpy(st1.name, "Rohit Mahali");
//    st1.sn = 5734;
//    st1.age = 26;
//    strcpy(st2.name,"Rohan Rath");
//    st2.sn = 5735;
//    st2.age = 25;    
//
//    pthread_create(&t1, NULL, func1, &st1);
//    pthread_create(&t2, NULL, func2, &st2);
//    pthread_join(t1, NULL);
//    pthread_join(t2, NULL);
//    
//}


#include <stdio.h>
#include <pthread.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

struct st_bio {
    int sn;
    char name[30];
};

void *func1(void *arg) {
    struct st_bio st = *((struct st_bio *)arg);
    int sn, i, sleep_time;
    char name[30];
    sn = st.sn;
    strcpy(name, st.name);
    for(i=0; i<5; i++) {
        sleep_time = 1 + rand() % 5;
        printf("sn=%d\t name=%s\n", sn, name);
        sleep(sleep_time);
    }
}

void *func2(void *arg) {
    struct st_bio st = *((struct st_bio *)arg);
    int sn, i, sleep_time;
    char name[30];
    sn = st.sn;
    strcpy(name, st.name);
    for(i=0; i<5; i++) {
        sleep_time = 1 + rand() % 5;
        printf("sn=%d\t name=%s\n", sn, name);
        sleep(sleep_time);
    }
}

void main() {
    pthread_t t1, t2;
    struct st_bio st1, st2;
    
    st1.sn = 5734;
    strcpy(st1.name, "Rohit Mahali");
    st2.sn = 5735;
    strcpy(st2.name, "Rohan Rath");

    pthread_create(&t1, NULL, func1, &st1);
    pthread_create(&t2, NULL, func2, &st2);
    pthread_join(t1, NULL);
    pthread_join(t2, NULL);
}
