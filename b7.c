#include <stdio.h>
#include <string.h>

struct data {
// had to change from char to unsigned char 
    unsigned char field1[6]; // 6 
    unsigned char field2; // 1
    unsigned short field3; // 2
    char field4; // 1
};

unsigned char test_data1[] = {
    0xf6, 0x51, 0xd0, 0x58, 0xc9, 0x6d, 0x75, 0x00, 
    0x0d, 0xb6, 0x03, 
};



unsigned char test_data2[] = {
    0xee, 0x79, 0x31, 0x8a, 0xfa, 0xbc, 0x13, 0x00, 
    0x59, 0xeb, 0x1e, 
};


void process(struct data *s, unsigned char d[])
{
        memcpy(&s->field1, &d[0], 6); // from 0 to 5 not including 6
        memcpy(&s->field2, &d[6], 1);
        memcpy(&s->field3, &d[8], 2);
        memcpy(&s->field4, &d[10], 1);
}

void print_output(struct data *s)
{
        printf("%d %d %d %d %d %d \n", s->field1[0], s->field1[1], s->field1[2], s->field1[3], s->field1[4], s->field1[5]);
        printf("%d \n", s->field2);
        printf("%d \n", s->field3);
        printf("%d \n", s->field4);
}

int main(void)
{
        struct data foo;

        process(&foo, test_data1);
        print_output(&foo);

        printf("\n");

        process(&foo, test_data2);
        print_output(&foo);



        return 0;
}