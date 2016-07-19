#include <stdlib.h>
#include <check.h>
#include "romancal.h"
#include <string.h> 
 
START_TEST(one_plus_one)
 {
	char str1[] = "I";
	char str2[] = "I";
	char strres[] = "II";  
        ck_assert_str_eq(strres,add(str1,str2));
     
 }
 END_TEST
 
START_TEST(one_plus_two)
 {
	char str1[] = "I";
	char str2[] = "II";
	char strres[] = "III";  
        ck_assert_str_eq(strres,add(str1,str2));
     
 }
 END_TEST

Suite * roman_numeral_cal_suite(void)
{
    Suite *s;
    TCase *tc_core;

    s = suite_create("RomanNumeralCalculator");

    /* Core test case */
    tc_core = tcase_create("Core");

    tcase_add_test(tc_core, one_plus_one);
    tcase_add_test(tc_core, one_plus_two);
    suite_add_tcase(s, tc_core);

    return s;
}

 int main(void)
 {
    
    int number_failed;
    Suite *s;
    SRunner *sr;

    s = roman_numeral_cal_suite();
    sr = srunner_create(s);

    srunner_run_all(sr, CK_NORMAL);
    number_failed = srunner_ntests_failed(sr);
    srunner_free(sr);
    return (number_failed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
 }
