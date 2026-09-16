#include "pch.h"
#include "Lib_things.h"
//#define Test_math_t_with_user
#define Test_math_t_errors
#ifdef Test_math_t_with_user
TEST(test_lib, base_1) {
	MathTest m1(1);
	m1.run();
	m1.show_statistics();
}
TEST(test_lib, base_2) {
	MathTest m1(2,-5,5);
	m1.run();
	m1.show_statistics();
}
TEST(test_lib, base_3) {
	MathTest m1(2, -5, 5,'*');
	m1.run();
	m1.show_statistics();
}
#endif
#ifdef Test_math_t_errors
TEST(test_lib, err_1) {
	EXPECT_ANY_THROW(MathTest m1(0));
}
TEST(test_lib, err_2) {
	EXPECT_ANY_THROW(MathTest m1(1,10,-10));
}
TEST(test_lib, err_3) {
	EXPECT_ANY_THROW(MathTest m1(1,-10,10,'a'));
}
TEST(test_lib, err_4) {
	MathTest m1(1);
	EXPECT_ANY_THROW(m1.show_statistics());
}
#endif