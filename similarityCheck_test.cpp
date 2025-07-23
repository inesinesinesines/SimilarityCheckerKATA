#include "gmock/gmock.h"
#include "similarityCheck.cpp"
#include <string>
using namespace testing;

TEST(CheckSimularity, SameLength)
{
	std::string str1 = "ABCD";
	std::string str2 = "ABCD";
	SimLength simlength;
	int result = simlength.getResult(str1, str2);

	EXPECT_EQ(60, result);
}

TEST(CheckSimularity, SameLengthDiffChar)
{
	std::string str1 = "DSA";
	std::string str2 = "ASD";
	SimLength simlength;
	int result = simlength.getResult(str1, str2);

	EXPECT_EQ(60, result);
}

TEST(CheckSimularity, 2xLengthDiffChar)
{
	std::string str1 = "A";
	std::string str2 = "BB";
	SimLength simlength;
	int result = simlength.getResult(str1, str2);

	EXPECT_EQ(0, result);
}

TEST(CheckSimularity, LenDiff5to3)
{
	std::string str1 = "AAABB";
	std::string str2 = "BAA";
	SimLength simlength;
	int result = simlength.getResult(str1, str2);

	EXPECT_LT(result, 60);
}


int main() {
	::testing::InitGoogleMock();
	return RUN_ALL_TESTS();
}