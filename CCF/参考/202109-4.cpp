#include<bits/stdc++.h>
using namespace std;
#define cnt __builtin_popcount

int main(){
	int n,k;
	cin>>n>>k;
	vector<double> p(n);
	for(int i=0;i<n;++i)
		cin>>p[i];
	vector<vector<double>> f(n*k+1);
	for(int i=0;i<=n*k;++i) f[i].resize(1<<n);
	f[0][0]=1.0;
	for(int i=0;i<n*k;++i)
		for(int S=0;S<(1<<n);++S)
			if(i-cnt(S)<(n-cnt(S))*k)
				for(int j=0;j<n;++j)
					f[i+1][S|(1<<j)]+=f[i][S]*p[j];
	vector<double> ans;
	for(int i=0;i<=n*k;++i)
		for(int S=0;S<(1<<n);++S)
			if(i-cnt(S)>=(n-cnt(S))*k)
				ans.emplace_back(f[i][S]*i);
	sort(ans.begin(),ans.end());
	printf("%.10lf\n",accumulate(ans.begin(),ans.end(),0.0));
	return 0;
}