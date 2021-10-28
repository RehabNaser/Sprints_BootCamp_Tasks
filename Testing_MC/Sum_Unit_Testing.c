#include "Unit_Testing_Tool/UNIT_TESTING_TOOL.h"
#include "Sum.h"

//Tester Name: Rehab Naser

/****************************************Sum_Statement_Coverage_Group*********************************/
TEST_GROUP(Sum_Statement_Coverage);

TEST_SETUP(Sum_Statement_Coverage)
{

}

TEST_TEAR_DOWN(Sum_Statement_Coverage)
{

}

TEST(Sum_Statement_Coverage, TEST_CASE_1)
{
	uint16_t u16_SumActualResult=0,u16_SumExpectedResult=0;
	u16_SumActualResult = Sum((uint8_t)5,(uint8_t)6);
	u16_SumExpectedResult =	11;
	TEST_ASSERT_EQUAL_INT(u16_SumActualResult,u16_SumExpectedResult);
}

TEST_GROUP_RUNNER(Sum_Statement_Coverage)
{
	RUN_TEST_CASE(Sum_Statement_Coverage, TEST_CASE_1);
}
/*****************************************************************************************************/

/*************************************Sum_Equivalence_Partitioning_Group******************************/
TEST_GROUP(Sum_Equivalence_Partitioning);

TEST_SETUP(Sum_Equivalence_Partitioning)
{

}

TEST_TEAR_DOWN(Sum_Equivalence_Partitioning)
{

}

TEST(Sum_Equivalence_Partitioning, TEST_CASE_1)
{
	uint16_t u16_SumActualResult=0,u16_SumExpectedResult=0;
	u16_SumActualResult = Sum((uint8_t)25,(uint8_t)12);
	u16_SumExpectedResult =	37;
	TEST_ASSERT_EQUAL_INT(u16_SumActualResult,u16_SumExpectedResult);
}

TEST(Sum_Equivalence_Partitioning, TEST_CASE_2)
{
	uint16_t u16_SumActualResult=0,u16_SumExpectedResult=0;
	u16_SumActualResult = Sum((uint8_t)25.7,(uint8_t)60.9);
	u16_SumExpectedResult =	85;
	TEST_ASSERT_EQUAL_INT(u16_SumActualResult,u16_SumExpectedResult);
}

TEST_GROUP_RUNNER(Sum_Equivalence_Partitioning)
{
	RUN_TEST_CASE(Sum_Equivalence_Partitioning, TEST_CASE_1);
	RUN_TEST_CASE(Sum_Equivalence_Partitioning, TEST_CASE_2);
}
/*****************************************************************************************************/

/*************************************Sum_Boundary_Value_Analysis_Group*******************************/
TEST_GROUP(Sum_Boundary_Value_Analysis);

TEST_SETUP(Sum_Boundary_Value_Analysis)
{

}

TEST_TEAR_DOWN(Sum_Boundary_Value_Analysis)
{

}

TEST(Sum_Boundary_Value_Analysis, TEST_CASE_1)
{
	uint16_t u16_SumActualResult=0,u16_SumExpectedResult=0;
	u16_SumActualResult = Sum((uint8_t)0,(uint8_t)0);
	u16_SumExpectedResult =	0;
	TEST_ASSERT_EQUAL_INT(u16_SumActualResult,u16_SumExpectedResult);
}

TEST(Sum_Boundary_Value_Analysis, TEST_CASE_2)
{
	uint16_t u16_SumActualResult=0,u16_SumExpectedResult=0;
	u16_SumActualResult = Sum((uint8_t)255,(uint8_t)255);
	u16_SumExpectedResult =	510;
	TEST_ASSERT_EQUAL_INT(u16_SumActualResult,u16_SumExpectedResult);
}

TEST(Sum_Boundary_Value_Analysis, TEST_CASE_3)
{
	uint16_t u16_SumActualResult=0,u16_SumExpectedResult=0;
	u16_SumActualResult = Sum((uint8_t)257,(uint8_t)258);
	u16_SumExpectedResult =	3;
	TEST_ASSERT_EQUAL_INT(u16_SumActualResult,u16_SumExpectedResult);
}

TEST(Sum_Boundary_Value_Analysis, TEST_CASE_4)
{
	uint16_t u16_SumActualResult=0,u16_SumExpectedResult=0;
	u16_SumActualResult = Sum((uint8_t)-1,(uint8_t)-2);
	u16_SumExpectedResult =	509;
	TEST_ASSERT_EQUAL_INT(u16_SumActualResult,u16_SumExpectedResult);
}

TEST_GROUP_RUNNER(Sum_Boundary_Value_Analysis)
{
	RUN_TEST_CASE(Sum_Boundary_Value_Analysis, TEST_CASE_1);
	RUN_TEST_CASE(Sum_Boundary_Value_Analysis, TEST_CASE_2);
	RUN_TEST_CASE(Sum_Boundary_Value_Analysis, TEST_CASE_3);
	RUN_TEST_CASE(Sum_Boundary_Value_Analysis, TEST_CASE_4);
}
/*****************************************************************************************************/