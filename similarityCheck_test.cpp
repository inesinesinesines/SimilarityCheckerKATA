#include "gmock/gmock.h"
#include "similarityCheck.cpp"
#include <string>
using namespace testing;

class LengthTestFixture : public testing::Test {
public:
	const int PERFECT_SCORE = 60;
	const int ZERO_SCORE = 0;
	double getTestResult(std::string str1, std::string str2)
	{
		LengthCheck lengthChecker;
		return lengthChecker.getLengthScore(str1, str2);
	}
};

TEST_F(LengthTestFixture, SameLength)
{
	EXPECT_EQ(PERFECT_SCORE, getTestResult("ABCD", "ABCD"));
}

TEST_F(LengthTestFixture, SameLengthDiffChar)
{
	EXPECT_EQ(PERFECT_SCORE, getTestResult("DSA", "ASD"));
}

TEST_F(LengthTestFixture, 2xLengthDiffChar)
{
	EXPECT_EQ(ZERO_SCORE, getTestResult("A", "BB"));
}

TEST_F(LengthTestFixture, 2xLengthDiffCharReverse)
{
	EXPECT_EQ(ZERO_SCORE, getTestResult("DDDDDD", "A"));
}

TEST_F(LengthTestFixture, LenDiff5to3)
{
	EXPECT_LT(getTestResult("AAABB", "BAA"), PERFECT_SCORE);
}

int main() {
	::testing::InitGoogleMock();
	return RUN_ALL_TESTS();
}