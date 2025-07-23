#include <string>

using namespace std;

class LengthCheck {
public :
	double getLengthScore(string str1, string str2)
	{
		double len1 = static_cast<double>(str1.length());
		double len2 = static_cast<double>(str2.length());

		sortLength(len1, len2);

		return calculateScore(len1, len2);
	}

private: 
	const double LENGTH_MAX_SCORE = 60.0;
	const double LENGTH_MIN_SCORE = 0.0;

	void sortLength(double& len1, double& len2)
	{
		if (len1 < len2) std::swap(len1, len2);
	}

	int calculateScore(int max, int min)
	{
		int gap = max - min;
		int rate = (max - min) / min;

		if (rate >= 1) return LENGTH_MIN_SCORE; 

		return (LENGTH_MAX_SCORE - (LENGTH_MAX_SCORE * gap) / min);
	}
};

