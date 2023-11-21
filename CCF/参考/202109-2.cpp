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
	using vit=vector<int>::iterator;
	vector<vector<vit>> bucket(V+1);
	for(auto it=v.begin();it!=v.end();++it)
		bucket[*it].emplace_back(it);
	bucket[0].clear();
	int val{getCnt(v)};
	int ans{val};
	for(const auto& buc:bucket){
		for(const auto& it:buc){
			int vLef{it==v.begin()?0:*(it-1)},vRig{(it+1)==v.end()?0:*(it+1)};
			if(vLef<*it&&*it>vRig) --val;
			if(vLef>*it&&*it<=vRig) ++val;
			*it=0;
		}
		ans=max(ans,val);
	}
	cout<<ans<<endl;
	return 0;
}