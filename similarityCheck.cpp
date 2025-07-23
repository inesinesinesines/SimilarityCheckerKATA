#include <string>

using namespace std;

class SimLength {
public :
	double getResult(string str1, string str2)
	{
		double len1 = str1.length();
		double len2 = str2.length();

		if (len1 < len2) std::swap(len1, len2);

		double rate = (len1 - len2) / len2;
		double result = (1 - rate) * 60.0;
		return result;
	}
};

