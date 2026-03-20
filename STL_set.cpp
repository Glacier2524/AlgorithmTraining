#include<iostream>
#include<set>
#include<algorithm>
using namespace std;

void printset(set<int>& s)
{
	for (set<int>::iterator it = s.begin(); it != s.end(); it++)
	{
		cout << *it << " ";
	}
	cout << endl;
}
int main()
{
	set<int>s1;

	s1.insert(10); //input only insert
	s1.insert(20);
	s1.insert(30);
	s1.insert(50);
	s1.insert(30);//sort automatically and remove duplicate
	printset(s1);

	set<int>s2(s1); //copy constructor

	set<int>s3;
	s3 = s2; //copy assignment operator
	printset(s3);

	if (s1.empty()) //check if empty
		cout << "empty" << endl;
	else
		cout << "size=" << s1.size() << endl;

	set<int>s4;
	s4.insert(100);
	s4.insert(200);

	cout << "before swap" << endl;
	printset(s1);
	printset(s4);

	s1.swap(s4); //swap two sets
	cout << "after swap" << endl;
	printset(s1);
	printset(s4);
	s4.swap(s1);

	s1.erase(s1.begin());//erase first element (after sorting)
	s1.erase(20);//erase 20
	printset(s1);

	s1.clear(); //clear all elements
	printset(s1);

	set<int>::iterator pos = s2.find(30);//return iterator to element
	if (pos != s1.end())
		cout << *pos << endl;
	else
		cout << "not found" << endl;

	int num = s1.count(30);//return number of elements
	cout << "count=" << num << endl; //for set,it will be 0 or 1,but mutiple set can be more


	pair<set<int>::iterator, bool>ret = s1.insert(50); //if element already exist,return false
	if (ret.second) //second value,here is bool
	{
		cout << "inserted" << endl;
	}

	pair<string, int>p("tom", 20); //pair can be used to store two values
	cout << p.first << p.second << endl;

	pair<string, int>p2 = make_pair("jack", 30);//make_pair function
	cout << p2.first << p2.second << endl;

	return 0;
}