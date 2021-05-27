#include <iostream>
#include <string>

#pragma warning(disable : 4996)

using namespace std;

int main()
{
	string s = "1";

	for (int i = 0; i < 10; i++)
	{
		string end ="";
		char num = s[0];
		int count = 0;

		for (int j = 0; j < s.length(); j++)
		{
			if(num  == s[j])
			{
				count++;
			}
			else
			{
				string temp = "";
				temp += num;
				end += (temp + to_string(count));
				count = 1;
				num = s[j];
			}
		}
		string temp = "";
		temp += num;
		end += (temp + to_string(count));
		s = end;
		cout << s << endl;
	}
}

