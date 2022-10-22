#include "calculate.h"
using namespace std;
float calculate(std::string formula)
{
	int len = formula.size();
	if ((formula == "0") || (len == 0))
		return 0;
	std::vector<float> stack;
	float num = 0;
	int res = 0;
	char sign = '+';
	for (int i = 0; i < len; i++)
	{
		if (isdigit(formula[i]))
		{
			num = formula[i] - '0';
			while (i + 1 < len && isdigit(formula[i + 1]))
			{
				num = num * 10 + (formula[i + 1] - '0');
				i++;
			}
		}
		if (!isdigit(formula[i]) || i == len - 1)
		{
			if (sign == '+')
				stack.push_back(num);
			if (sign == '-')
				stack.push_back(0 - num);
			if (sign == '*')
			{
				float tmp = stack.back();
				stack.pop_back();
				cout << tmp << "*" << num << endl;
				stack.push_back(tmp * num);
			}
			if (sign == '/')
			{
				float tmp = stack.back();
				stack.pop_back();
				cout << tmp << "/" << num << endl;
				stack.push_back(tmp / num);
			}
			sign = formula[i];
			num = 0;
		}
		float ans = 0;
		for (int i = 0; i < int(stack.size()); i++)
		{
			// cout << "stack[" << i << "]: " << stack[i] << endl;
			// cout << "tmp res: " << ans << endl;
			ans += stack[i];
		}
		res = ans;
	}
	return res;
}