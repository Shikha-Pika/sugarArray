#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stddef.h>
#include "sugar_arr.h"

DECLARE_WRAPPER(char*, strBuf);
DEFINE_ARRAY(char*, strBuf);

int main()
{

    strBuf buf;
    array_init(&buf);

    array_push(&buf, "THIS IS A STRING");
    array_push(&buf, "     TESTING    ");
    array_push(&buf, "      TESTS     ");
    array_push(&buf, "       BOO      ");

    printf("\n\nvector length: %d\n\n", buf.count);

    while (buf.count > 0) {
        printf("popped: %s\n", array_pop(&buf));
    }

    array_free(&buf);
    return 0;
}