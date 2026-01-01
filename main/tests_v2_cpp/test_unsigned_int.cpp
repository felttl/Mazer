
/* test_unsigned_int.cpp */
#include <gtest/gtest.h>

extern "C" {
    #include <limits.h>
}

TEST(UnsignedIntTest, MaxValueIsCorrect) {
    unsigned int max = UINT_MAX;

    // Vérifie que UINT_MAX est bien > 0
    EXPECT_GT(max, 0u);

    // Vérifie le wrap-around (comportement défini)
    unsigned int overflow = max + 1;
    EXPECT_EQ(overflow, 0u);
}
