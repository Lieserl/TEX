#include<bits/stdc++.h>
using namespace std;

int main(){
	istream_iterator<int> in{cin};
	[[maybe_unused]] int n=*in++;
	int ans{accumulate(in,istream_iterator<int>{},0)};
	cout<<ans<<endl<<ans<<endl;
	return 0;
}