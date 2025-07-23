#include <string>

using namespace std;

class SimLength {
public :
	int getResult(string str1, string str2)
	{
		int len1 = str1.length();
		int len2 = str2.length();

		if (len1 < len2) std::swap(len1, len2);

		return (1 - ((len1 - len2) / len2)) * 60;
	}
};

