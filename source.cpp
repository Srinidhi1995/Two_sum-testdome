#include <stdexcept>
#include <iostream>
#include <vector>
#include <utility>
#include<unordered_map> //to map elements without sorting


using namespace std;
std::pair<int, int> findTwoSum(const std::vector<int>& list, int sum)
{
	unordered_map<int, int>mp;
	for (int i = 0; i < list.size(); i++)
	{
		auto num_found = mp.find(sum - list[i]);

		if (num_found != mp.end())
		{
			return make_pair(i, num_found->second);
		}
		mp[list[i]] = i;
		//cout<<"\t"<<num_found->first <<"\t"<<num_found->second<<endl;
		//cout << "\t" << num_found->second << endl;
	}
	return make_pair(-1, -1);
}

#ifndef RunTests
int main()
{
	std::vector<int> list = { 3, 1, 5, 7, 5, 9 };
	std::pair<int, int> indices = findTwoSum(list, 10);
	std::cout << indices.first << '\n' << indices.second;
}
#endif
