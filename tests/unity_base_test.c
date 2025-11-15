#include <unity.h>

void setUp(void) {
    // empty
}

void tearDown(void) {
    // also empty
}

void test_base(void) {
    int expected = 1;
    int actual = 1;
    TEST_ASSERT_EQUAL_INT(actual, expected);
}


int main(void) {
    UNITY_BEGIN();
    RUN_TEST(test_base);

    return UNITY_END();
}
