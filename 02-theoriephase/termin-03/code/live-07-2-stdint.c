#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

int main(void)
{
    printf("int8_t:  %zu Byte, Wertebereich %d bis %d\n", sizeof(int8_t), INT8_MIN, INT8_MAX);
    printf("uint8_t: %zu Byte, Wertebereich 0 bis %d\n", sizeof(uint8_t), UINT8_MAX);
    printf("int16_t: %zu Byte, Wertebereich %d bis %d\n", sizeof(int16_t), INT16_MIN, INT16_MAX);
    printf("int32_t: %zu Byte, Wertebereich %d bis %d\n", sizeof(int32_t), INT32_MIN, INT32_MAX);

    system("pause");

    return 0;
}
