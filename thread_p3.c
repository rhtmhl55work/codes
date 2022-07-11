//#include <stdio.h>
//#include <pthread.h>
//#include <string.h>
//#include <stdlib.h>
//#include <unistd.h>
//
//void *func1(void *arg) {
//    int i, sleep_time;
//    char name[30];
//    strcpy(name, (char *)arg);
//    for(i=0; i<5; i++) {
//        sleep_time = 1 + rand() % 5;
//        printf("hi %s\n", name);
//        sleep(sleep_time);
//    }
//}
//
//void *func2(void *arg) {
//    int i, sleep_time;
//    char name[30];
//    strcpy(name, (char *)arg);
//    for(i=0; i<5; i++) {
//        sleep_time = 1 + rand() % 5;
//        printf("hello %s\n", name);
//        sleep(sleep_time);
//    }
//}
//
//void main() {
//    pthread_t t1, t2;
//    char name[30] = "rohit";
//    pthread_create(&t1, NULL, func1, (void *)name);
//    pthread_create(&t2, NULL, func2, (void *)name);
//    pthread_join(t1, NULL);
//    pthread_join(t2, NULL);
//}


//#include <stdio.h>
//#include <pthread.h>
//#include <string.h>
//#include <stdlib.h>
//#include <unistd.h>
//
//void *func1(void *arg) {
//    int i, sleep_time, id;
//    //char name[30];
//    //strcpy(name, (char *)arg);
//    id = *((int*)arg);
//    for(i=0; i<5; i++) {
//        sleep_time = 1 + rand() % 5;
//        printf("hi %d\n", id);
//        sleep(sleep_time);
//    }
//}
//
//void *func2(void *arg) {
//    int i, sleep_time, id;
//    //char name[30];
//    //strcpy(name, (char *)arg);
//    id = *((int*)arg);
//    for(i=0; i<5; i++) {
//        sleep_time = 1 + rand() % 5;
//        printf("hello %d\n", id);
//        sleep(sleep_time);
//    }
//}
//
//void main() {
//    pthread_t t1, t2;
//    //char name[30] = "rohit";
//    int id = 5734;
//    pthread_create(&t1, NULL, func1, &id);
//    pthread_create(&t2, NULL, func2, &id);
//    pthread_join(t1, NULL);
//    pthread_join(t2, NULL);
//}


//#include <stdio.h>
//#include <pthread.h>
//#include <string.h>
//#include <stdlib.h>
//#include <unistd.h>
//
//void *func1(void *arg) {
//    int i, sleep_time, id;
//    //char name[30];
//    //strcpy(name, (char *)arg);
//    char ch;
//    ch = *((char*)arg);
//    for(i=0; i<5; i++) {
//        sleep_time = 1 + rand() % 5;
//        printf("hi %c\n", ch);
//        sleep(sleep_time);
//    }
//}
//
//void *func2(void *arg) {
//    int i, sleep_time, id;
//    //char name[30];
//    //strcpy(name, (char *)arg);
//    char ch;
//    ch = *((char*)arg);
//    for(i=0; i<5; i++) {
//        sleep_time = 1 + rand() % 5;
//        printf("hello %c\n", ch);
//        sleep(sleep_time);
//    }
//}
//
//void main() {
//    pthread_t t1, t2;
//    //char name[30] = "rohit";
//    //int id = 5734;
//    char ch = 'R';
//    pthread_create(&t1, NULL, func1, &ch);
//    pthread_create(&t2, NULL, func2, &ch);
//    pthread_join(t1, NULL);
//    pthread_join(t2, NULL);
//}


//#include <stdio.h>
//#include <pthread.h>
//#include <string.h>
//#include <stdlib.h>
//#include <unistd.h>
//
//void *func1(void *arg) {
//    int i, sleep_time;
//    char name[30];
//    strcpy(name, (char *)arg);
//    for(i=0; i<5; i++) {
//        sleep_time = 1 + rand() % 5;
//        printf("hi %s\n", name);
//        sleep(sleep_time);
//    }
//}
//
//void *func2(void *arg) {
//    int i, sleep_time;
//    char name[30];
//    strcpy(name, (char *)arg);
//    for(i=0; i<5; i++) {
//        sleep_time = 1 + rand() % 5;
//        printf("hello %s\n", name);
//        sleep(sleep_time);
//    }
//}
//
//void main() {
//    pthread_t t1, t2;
//    char name[30] = "rohit";
//    pthread_create(&t1, NULL, func1, name);
//    pthread_create(&t2, NULL, func2, name);
//    pthread_join(t1, NULL);
//    pthread_join(t2, NULL);
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
