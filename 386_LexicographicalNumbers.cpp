/**
386. Lexicographical Numbers ::
Given an integer n, return 1 to n in lexicographical order.

For example, given 13, return: [1,10,11,12,13,2,3,4,5,6,7,8,9].

Please optimize your algorithm to use less time and space. The input size may be as large as 5,000,000.
**/

class Solution
{
private:
	vector<int> nums;
	int maxNum;
	void MakeNumber(int base)
	{
		if (base <= maxNum)
		{
			nums.push_back(base);
			for (int i = 0; i < 10; ++i)
				MakeNumber(base*10 + i);
		}
	}
public:
	vector<int> lexicalOrder(int n)
	{
		maxNum = n;
		nums.reserve(n);
		for (int i = 1; i < 10; ++i)
			MakeNumber(i);
		return nums;
	}
};
