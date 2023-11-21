#include<bits/stdc++.h>
using namespace std;

int getCnt(const vector<int>& v){
	int cnt=0;
	for(size_t i=0;i<v.size();++i)
		if((!i||v[i-1]==0)&&v[i])
			++cnt;
	return cnt;
}

int main(){
	ios::sync_with_stdio(false);
	istream_iterator<int> in{cin};
	[[maybe_unused]] int n{*in++};
	vector<int> v(in,istream_iterator<int>{});
	int V{*max_element(v.begin(),v.end())};
	int val{getCnt(v)};
	int ans{val};
	for(int p=2;p<=V;++p){
		for(auto &i:v)
			if(i<p)
				i=0;
		ans=max(ans,getCnt(v));
	}
	cout<<ans<<endl;
	return 0;
}