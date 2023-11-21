#include<bits/stdc++.h>
using namespace std;
#define reg register

namespace ProblemCode{
	static unsigned long next = 1;

	/* RAND_MAX assumed to be 32767 */
	inline int myrand(void) {
		next = next * 1103515245 + 12345;
		return((unsigned)(next>>16)&32767);
	}
}

constexpr int MAXN=1e3;
constexpr int MAXP=1e3;
constexpr int MAXS=1e3;
constexpr int MAXD=1024;

struct Netural{
	double v,u;
	float ap,b,c,d;
	bool operator<(const Netural& a)const{
		return v<a.v;
	}
};

struct Edge{
	int v;
	float w;
	int D;
};

int n,s,p,T;
double deltaT;
Netural net[MAXN];
int r[MAXP];
int eid,head[MAXN+MAXP],nxt[MAXS+1];
Edge e[MAXS+1];
int cnt[MAXN];
float Q[MAXD+1][MAXN];

inline int add(reg int a,reg int b){
	return (a+b)&(MAXD-1);
	//reg int sum=a+b;
	//return sum>=MAXD?sum-MAXD:sum;
}

inline void Add_Edge(reg int u,reg int v,reg float w,reg int D){
	nxt[++eid]=head[u];
	e[eid].v=v,e[eid].w=w,e[eid].D=D;
	head[u]=eid;
	return;
}

int main(){
	scanf("%d%d%d%d%lf",&n,&s,&p,&T,&deltaT);
	for(int s{0},Rn{};s!=n;s+=Rn){
		static double v,u,ap,b,c,d;
		scanf("%d%lf%lf%lf%lf%lf%lf",&Rn,&v,&u,&ap,&b,&c,&d);
		ap*=deltaT;
		for(int i{s};i<s+Rn;++i){
			net[i].v=v;
			net[i].u=u;
			net[i].ap=ap;
			net[i].b=b;
			net[i].c=c;
			net[i].d=d;
		}
	}
	for(int i=0;i<p;++i)
		scanf("%d",&r[i]);
	for(int i=0;i<s;++i){
		static int s,t;
		static double w;
		static int D;
		scanf("%d%d%lf%d",&s,&t,&w,&D);
		Add_Edge(s,t,w,D);
	}
	const float A=0.04*deltaT;
	const float B=5.0*deltaT;
	const float C=140.0*deltaT;
	for(reg int t{1},index{1%MAXD};t<=T;++t,index=add(index,1)){
		for(reg int nid{0};nid<n;++nid){
			static double v,u;
			v=net[nid].v,u=net[nid].u;
			net[nid].v=v+A*v*v+B*v+C-deltaT*u+Q[index][nid],net[nid].u=u+net[nid].ap*(net[nid].b*v-u);
		}
		memset(Q[index],0,n*sizeof(float));
		for(reg int nid{0};nid<n;++nid)
			if(net[nid].v>=30.0){
				net[nid].v=net[nid].c,net[nid].u+=net[nid].d;
				++cnt[nid];
				for(reg int i=head[nid];i;i=nxt[i])
					Q[add(index,e[i].D)][e[i].v]+=e[i].w;
			}
		for(reg int pid{0};pid<p;++pid)
			if(r[pid]>ProblemCode::myrand())
				for(reg int i=head[n+pid];i;i=nxt[i])
					Q[add(index,e[i].D)][e[i].v]+=e[i].w;
	}
	double ans1{min_element(net,net+n)->v},ans2{max_element(net,net+n)->v};
	int ans3{*min_element(cnt,cnt+n)},ans4{*max_element(cnt,cnt+n)};
	printf("%.3f %.3f\n%d %d\n",ans1,ans2,ans3,ans4);
	return 0;
}