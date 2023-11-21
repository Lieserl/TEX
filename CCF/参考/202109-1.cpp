#include<bits/stdc++.h>
using namespace std;

int main(){
	istream_iterator<int> in{cin};
	[[maybe_unused]] int n=*in++;
	vector<int> v(in,istream_iterator<int>{});
	int ans1{accumulate(v.begin(),v.end(),0)};
	int ans2{accumulate(v.begin(),unique(v.begin(),v.end()),0)};
	cout<<ans1<<endl<<ans2<<endl;
	return 0;
}