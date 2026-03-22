#include<iostream>
#include<algorithm>
#include<functional>
#include<numeric>
#include<ctime>
#include<vector>
using namespace std;

void print(int x)
{
	cout << x << " ";
}

bool cmp(int a, int b)
{
	return a > b;
}

bool Greater5(int x)
{
	return x > 5;
}

void pushval(vector<int>& v)
{
	for (int i = 0; i < 10; i++)
	{
		v.push_back(i);
	}
}

void printvector(vector<int>& v)
{
	for (int i = 0; i < v.size(); i++)
	{
		cout << v[i] << " ";
	}
	cout << endl;
}

class Transform {
	public:
		int operator()(int x)
		{
			return x;
		}
};
int main()
{
	// for_each =================================================================
	vector<int>v1;
	pushval(v1);
	
	for_each(v1.begin(), v1.end(), print);
	cout << endl;
	
	// transform===============================================================
			//transform(iterator beg1.iterator end1,iterator beg2,function)
	vector<int>v2;
	pushval(v2);
	vector<int>v2_target;
	v2_target.resize(v2.size());

	transform(v2.begin(), v2.end(), v2_target.begin(), Transform();

	// find=================================================================
			//find(iterator beg,iterator end,value)	
	vector<int>v3;
	pushval(v3);

	vector<int>::iterator it = find(v3.begin(), v3.end(), 5);
	if (it != v3.end())
		cout << "found" << endl;

	//find_if=================================================================
			//find_if(iterator beg,iterator end,function)
	vector<int>v4;
	pushval(v4);

	vector<int>::iterator it2 = find_if(v4.begin(), v4.end(), Greater5());
	if (it2 != v4.end())
		cout << "found" << endl;

	//adjacent_find============================================================
    		//adjacent_find(iterator beg,iterator end)
		    //return first pair of adjacent elements that match
	vector<int>v5;
	pushval(v5);
	v5.push_back(9);
	
	
	vector<int>::iterator it3 = adjacent_find(v5.begin(), v5.end());
	if ((it3 != v5.end()))
		cout << "found" << endl;

	//binary_search==============================================================
		    //bool binary_search(iterator beg,iterator end,value)
			//return true if found,not a pos
    		//only for sorted 
	bool ret = binary_search(v1.begin(), v1.end(), 5);
	if (ret)
		cout << "found" << endl;

	//count===================================================================
			//count(iterator beg,iterator end,value)
			//return the number of the element
	int num = count(v5.begin(), v5.end(), 9);
	cout << num << endl;

	//count_if================================================================
			//count_if(iterator_beg,iterator_end,function)
	int num2 = count_if(v5.begin(), v5.end(), Greater5());
	cout << num2 << endl;

	//sort======================================================================
	       //sort(iterator beg,iterator end,function)
	sort(v5.begin(), v5.end(), cmp);

	//random_shuffle==============================================================
	      //return a random permutation of the elements
	random_shuffle(v2.begin(), v2.end());
	printvector(v2);
		  //be different every time
	srand((usigned int time(NULL)));
	random_shuffle(v2.begin(), v2.end());

	//merge=======================================================================
	     //merge(iterator_beg1,iterator_end1,iterator_beg2,iterator_end2,iterator_dest)
	     //merge two sorted 
	     //target is also sorted
	vector<int>v6;
	v6.resize(v3.size() + v4.size());
	merge(v3.begin(), v3.end(), v4.begin(), v4.end(), v6.begin());
	printvector(v6);

	//reverse=====================================================================
	reverse(v6.begin(), v6.end());
	printvector(v6);

	//copy===========================================================================
	vector<int>v7;
	v7.resize(v6.size());
	copy(v6.begin(), v6.end(), v7.begin());
	printvector(v7);

	//replace========================================================================
	        //replace(iterator_beg,iterator_end,value,newvalue)
	replace(v5.begin(), v5.end(), 9, 10);
	printvector(v5);

	//replace_if===================================================================
			//replace_if(iterator_beg,iterator_end,function,newvalue)
	replace_if(v5.begin(), v5.end(), Greater5(), 0);
	printvector(v5);

	//swap=========================================================================
	        //swap(container1,container2)
	swap(v5, v6);

	//accumulate==================================================================
	       //accumulate(iterator_beg,iterator_end,value)
	       //value means the initial value
	int total = accumulatea(v5.begin(), v5.end(), 0);
	cout << total << endl;

	//fill=========================================================================
	        //fill(iterator_beg,iterator_end,value)
	fill(v7.begin(), v7.end(), 100);
	printvector(v7);

	//set=========================================================================
			//set_intersection(iterator_beg1,iterator_end1,iterator_beg2,iterator_end2,iterator_dest)
    		//set_union(iterator_beg1,iterator_end1,iterator_beg2,iterator_end2,iterator_dest)
    		//set_difference(iterator_beg1,iterator_end1,iterator_beg2,iterator_end2,iterator_dest)




}