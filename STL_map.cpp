#include<iostream>
#include<map>
#include<algorithm>
using namespace std;


void printmap(map<int, int>& m)
{
	for (map<int, int>::iterator it = m.begin(); it != m.end(); i++)
	{
		cout << "key=" << (*it).first << " value=" << it->second << endl;
	}
	cout << endl;
}
int main()
{
	//-----------------------------construct--------------------------------------

	map<int, int>m;
	m.insert(pair<int, int>(1, 10)); //insert by pair 
	m.insert(pair<int, int>(2, 20)); //key is not allowed to duplicate
	m.insert(pair<int, int>(3, 30));
	m.insert(pair<int, int>(4, 40));
	printmap(m); //sort automatically

	map<int, int>m2(m);//copy constructor

	map<int, int>m3;
	m3 = m2;//copy assignment operator

	if (m.empty())
		cout << "empty" << endl;
	else
		cout << "size=" << m.size() << endl;

	//-------------------------------swap----------------------------------------

	map<int, int>m4;
	m4.insert(pair<int, int>(1, 100)); 
	m4.insert(pair<int, int>(2, 200));
	m4.insert(pair<int, int>(3, 300));
	m4.insert(pair<int, int>(4, 400));

	cout << "before swap" << endl;
	printmap(m);
	printmap(m4);

	m.swap(m4);//swap two maps
	cout << "after swap" << endl;
	printmap(m);
	printmap(m4);
	m.swap(m4);

	//-------------------------------insert and erase----------------------------------------

	m.insert(make_pair(5, 50));//insert by make_pair
	m.insert(map<int, int>::value_type(6, 60)); //insert by value_type
	
	m[7] = 70;  //  insert by subscript operator,but if key is not exist,its value will be 0
	// so this method is not advised to insert,but good for access the value

	m.erase(m.begin());
	printmap(m);
	m.erase(3); // erase by key,but cannot erase by value
	m.erase(m.begin(), m.end());//erase all elements
	m.clear();

	//------------------------------find and count----------------------------------------

	map<int, int>::iterator pos = m2.find(3);
	if (pos != m.end())
		cout << "key=" << (*pos).first << " value=" << pos->second << endl;
	else
		cout << "not found" << endl;

	int num = m2.count(3);
	//return number of elements,for map,it will be 0 or 1,but mutiple map can be more

	return 0;
}