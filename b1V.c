#include <stdio.h>
#include <string.h>

struct data {
    long int field1;
    char field2;
    unsigned char field3[8];
    unsigned long int field4;
};

void test_code1(struct data *d) {
    d->field1 = 4097912552115920292;
    d->field2 = 11;
    d->field3[0] = 176;
    d->field3[1] = 95;
    d->field3[2] = 179;
    d->field3[3] = 255;
    d->field3[4] = 156;
    d->field3[5] = 55;
    d->field3[6] = 140;
    d->field3[7] = 167;
    d->field4 = 3551640973236821270;
}

void proc(struct data *d) {
    unsigned char buf[28] = {0};
    int pos = 0;
    for (int i=0; i<8;i++){
        buf[pos] = ((unsigned char*) &d->field1)[7-i];
        pos++;
        // printf(" %02X", ((unsigned char*) &d->field1)[7-i] );
    }
    // printf("\n");
    // printf(" %02X", d->field2);
    buf[pos] = d->field2;
    pos++;
    // printf("\n");
    for (int i=0; i<8;i++){
        // printf(" %02X", d->field3[i]);
        buf[pos] = (d->field3)[i];
        pos++;
    }
    // printf("\n");
    pos +=3;
    for (int i=0; i<8;i++){
        buf[pos] = ((unsigned char*) &d->field4)[7-i];
        pos++;
        // printf(" %02X", ((unsigned char*) &d->field4)[7-i] );
    }
    for (int i=0; i<28;i++){
        printf(" %02X", buf[i]);
    }
}

int main()
{
    struct data foo;
    test_code1(&foo);
    proc(&foo);
    
    printf("\n");

    return 0;
}
