#include "Unit_Testing_Tool/UNIT_TESTING_TOOL.h"

void RunAllTests(void);

int main (void)
{
	UnitTestingRun(RunAllTests);
}

void RunAllTests(void)
{
	RUN_TEST_GROUP(Sum_Statement_Coverage);
	RUN_TEST_GROUP(Sum_Equivalence_Partitioning);
	RUN_TEST_GROUP(Sum_Boundary_Value_Analysis);
}