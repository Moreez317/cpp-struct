#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

struct data
{
        unsigned long field1; // 8
        char field2;          // 1
        char field3[8];       // 8
        unsigned long field4; // 8
};

void test_code1(struct data *d)
{
        d->field1 = 4097912552115920292U;
        d->field2 = 11;
        d->field3[0] = 176;
        d->field3[1] = 95;
        d->field3[2] = 179;
        d->field3[3] = 255;
        d->field3[4] = 156;
        d->field3[5] = 55;
        d->field3[6] = 140;
        d->field3[7] = 167;
        d->field4 = 3551640973236821270U;
}

void test_code2(struct data *d)
{
        d->field1 = 1822677561619647631U;
        d->field2 = 227;
        d->field3[0] = 144;
        d->field3[1] = 226;
        d->field3[2] = 211;
        d->field3[3] = 245;
        d->field3[4] = 28;
        d->field3[5] = 186;
        d->field3[6] = 53;
        d->field3[7] = 155;
        d->field4 = 14758400869715079791U;
}

void process(struct data *d)
{
        unsigned char buf[28] = {0};

        for (int i = 0; i < 8; i++)
        {
                buf[i] = ((unsigned char *)&d->field1)[7 - i];
        }

        buf[8] = d->field2;

        for (int i = 0; i < 8; i++)
        {
                buf[9 + i] = d->field3[i];
        }

        for (int i = 0; i < 8; i++)
        {
                buf[20 + i] = ((unsigned char *)&d->field4)[7 - i];
        }

        for (int i = 0; i < 28; i++)
        {
                if (i % 8 == 0)
                {
                        printf("\n");
                }

                printf("%02X ", buf[i]);
        }

        printf("\n");
}

int main(void)
{
        struct data d;
        test_code1(&d);
        process(&d);
        test_code2(&d);
        process(&d);
        printf("Done! \n");

        return 0;
}