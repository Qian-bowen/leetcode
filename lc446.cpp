#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

int numberOfArithmeticSlices(vector<int>& nums) {
	int n = nums.size();
	int result = 0;
	if (n < 3)
		return 0;
	//unordered_map<a,b> 第i个元素前不连续差值为a的有b个
	vector<unordered_map<long long, int>> f(n);
	for (int i = 0;i < n;++i)
	{
		for (int j = 0;j < i;++j)
		{
			long long gap = nums[i] - nums[j];
			++f[i][gap];
			//该差值，是否在j元素中记录的不连续差值元素
			if (f[j].count(gap))
			{
				result += f[j][gap];
				f[i][gap] += f[j][gap];
			}
		}

	}
	return result;
}

int main()
{
	return 0;
}