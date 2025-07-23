#include <string>

using namespace std;

class LengthCheck {
public :
	double getLengthScore(string str1, string str2)
	{
		double len1 = str1.length();
		double len2 = str2.length();

		sortLength(len1, len2);

		return calculateScore(len1, len2);
	}

	void sortLength(double& len1, double& len2)
	{
		if (len1 < len2) std::swap(len1, len2);
	}

	double calculateScore(double LongLen, double shortLen)
	{
		double rate = (LongLen - shortLen) / shortLen;

		if (rate >= 1) return 0; // long len >= shortlen * 2

		return (1 - rate) * LENGTH_SCORE;	
	}
private: 
	const double LENGTH_SCORE = 60.0;

};

