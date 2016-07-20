#include <stdlib.h>
#include <check.h>
#include "romancal.h"
#include <string.h> 
#define MAXIMUM_LENGTH	4096

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

START_TEST(two_plus_two)
 {
	char str1[] = "II";
	char str2[] = "II";
	char strres[] = "IV";  
        ck_assert_str_eq(strres,add(str1,str2));
     
 }
 END_TEST

START_TEST(three_plus_two)
 {
	char str1[] = "III";
	char str2[] = "II";
	char strres[] = "V";  
        ck_assert_str_eq(strres,add(str1,str2));
     
 }
 END_TEST

START_TEST(nine_plus_two)
 {
	char str1[] = "IX";
	char str2[] = "II";
	char strres[] = "XI";  
        ck_assert_str_eq(strres,add(str1,str2));
     
 }
 END_TEST

START_TEST(ten_plus_thirty)
 {
	char str1[MAXIMUM_LENGTH] = "X";
	char str2[MAXIMUM_LENGTH] = "XXX";
	char strres[MAXIMUM_LENGTH] = "XL";
        ck_assert_str_eq(strres,add(str1,str2));
     
 }
 END_TEST

START_TEST(hundred_plus_ninety)
 {
	char str1[MAXIMUM_LENGTH] = "C";
	char str2[MAXIMUM_LENGTH] = "XC";
	char strres[MAXIMUM_LENGTH] = "CXC";
        ck_assert_str_eq(strres,add(str1,str2));
     
 }
 END_TEST

START_TEST(FivehundredThirtySix_plus_ninetyEight)
 {
	char str1[MAXIMUM_LENGTH] = "DXXXVI";
	char str2[MAXIMUM_LENGTH] = "XCVIII";
	char strres[MAXIMUM_LENGTH] = "DCXXXIV";
        ck_assert_str_eq(strres,add(str1,str2));
     
 }
 END_TEST

START_TEST(OneThousandFivehundred_plus_OneThousandOneHundred)
 {
	char str1[MAXIMUM_LENGTH] = "MD";
	char str2[MAXIMUM_LENGTH] = "MC";
	char strres[MAXIMUM_LENGTH] = "MMDC";
        ck_assert_str_eq(strres,add(str1,str2));
     
 }
 END_TEST

START_TEST(two_minus_one)
 {
	char str1[] = "II";
	char str2[] = "I";
	char strres[] = "I";  
        ck_assert_str_eq(strres,subtract(str1,str2));
     
 }
 END_TEST

START_TEST(three_minus_one)
 {
	char str1[] = "III";
	char str2[] = "I";
	char strres[] = "II";  
        ck_assert_str_eq(strres,subtract(str1,str2));
     
 }
 END_TEST

START_TEST(six_minus_two)
 {
	char str1[] = "VI";
	char str2[] = "II";
	char strres[] = "IV";  
        ck_assert_str_eq(strres,subtract(str1,str2));
     
 }
 END_TEST

START_TEST(twentyOne_minus_eigth)
 {
	char str1[MAXIMUM_LENGTH] = "XXI";
	char str2[MAXIMUM_LENGTH] = "VIII";
	char strres[MAXIMUM_LENGTH] = "XIII";  
        ck_assert_str_eq(strres,subtract(str1,str2));
     
 }
 END_TEST

START_TEST(Hundred_minus_thirtyFive)
 {
	char str1[MAXIMUM_LENGTH] = "C";
	char str2[MAXIMUM_LENGTH] = "XXXV";
	char strres[MAXIMUM_LENGTH] = "LXV";
        ck_assert_str_eq(strres,subtract(str1,str2));
     
 }
 END_TEST

START_TEST(FiveHundredThirtyFIve_minus_TwoHundredSeventy)
 {
	char str1[MAXIMUM_LENGTH] = "DXXXV";
	char str2[MAXIMUM_LENGTH] = "CCLXX";
	char strres[MAXIMUM_LENGTH] = "CCLXV";
        ck_assert_str_eq(strres,subtract(str1,str2));
     
 }
 END_TEST

START_TEST(Thousamd_minus_TwoHundredTwenty)
 {
	char str1[MAXIMUM_LENGTH] = "M";
	char str2[MAXIMUM_LENGTH] = "CCXX";
	char strres[MAXIMUM_LENGTH] = "DCCLXXX";
        ck_assert_str_eq(strres,subtract(str1,str2));
     
 }
 END_TEST

START_TEST(TwoThousandEightHundred_minus_TwoThousandTwenty)
 {
	char str1[MAXIMUM_LENGTH] = "MMDCCC";
	char str2[MAXIMUM_LENGTH] = "MMXX";
	char strres[MAXIMUM_LENGTH] = "DCCLXXX";
        ck_assert_str_eq(strres,subtract(str1,str2));
     
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
    tcase_add_test(tc_core, two_plus_two);
    tcase_add_test(tc_core, three_plus_two);
    tcase_add_test(tc_core, nine_plus_two);
    tcase_add_test(tc_core, ten_plus_thirty);
    tcase_add_test(tc_core, hundred_plus_ninety);
    tcase_add_test(tc_core, FivehundredThirtySix_plus_ninetyEight);
    tcase_add_test(tc_core, OneThousandFivehundred_plus_OneThousandOneHundred);
    tcase_add_test(tc_core, two_minus_one);
    tcase_add_test(tc_core, three_minus_one);
    tcase_add_test(tc_core, six_minus_two);
    tcase_add_test(tc_core, twentyOne_minus_eigth);
    tcase_add_test(tc_core, Hundred_minus_thirtyFive);
    tcase_add_test(tc_core, FiveHundredThirtyFIve_minus_TwoHundredSeventy);
    tcase_add_test(tc_core, Thousamd_minus_TwoHundredTwenty);
    tcase_add_test(tc_core, TwoThousandEightHundred_minus_TwoThousandTwenty);
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
