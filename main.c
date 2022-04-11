#include <stdio.h>
#include "tils.h"
#include "list_dynamicArray.h"

void test_dynamicArray()
{
    struct dynamicArray *darr = init_dynamicArray(10);
    print_dynamicArray(darr);
}

int main(int argc, char const *argv[])
{
    // struct dynamicArray *init_dynamicArray(int capacity);
    test_dynamicArray();
}
