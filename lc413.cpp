#include<iostream>
#include<vector>
using namespace std;

int numberOfArithmeticSlices(vector<int>& nums) {
	int ptr = 2,cnt=0;
	int len = nums.size();
	if (len < 3)
		return 0;
	while (ptr < len)
	{
		int gap = nums[ptr-1] - nums[ptr-2];
		int tmp_cnt = 0;

		do {
			int gap_next = nums[ptr] - nums[ptr - 1];
			if (gap_next == gap)
			{
				tmp_cnt++;
				ptr++;
			}
			else
				break;
		} while (ptr < len);
		
		ptr++;
		cnt += (1 + tmp_cnt) * tmp_cnt / 2;
	}
	return cnt;
}

int main()
{
	vector<int> test = { 1,2,3,4 };
	cout << numberOfArithmeticSlices(test) << endl;
	return 0;
}
