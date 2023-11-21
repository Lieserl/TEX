#include<bits/stdc++.h>
using namespace std;
#define reg register
#define getchar() (p1==p2&&(p2=(p1=buf)+fread(buf,1,1<<22,stdin),p1==p2)?EOF:*p1++)
static char buf[1<<22],*p1=buf,*p2=buf;
#define flush() (fwrite(wbuf,1,wp1,stdout),wp1=0)
#define putchar(c)(wp1==wp2&&(flush(),0),wbuf[wp1++]=c)
static char wbuf[1<<22];int wp1;const int wp2=1<<22;
inline int read(void){
	reg char ch=getchar();
	reg int res=0;
	while(!isdigit(ch)) ch=getchar();
	while(isdigit(ch)) res=10*res+(ch-'0'),ch=getchar();
	return res;
}

inline void writeln(reg int x){
	static char buf[32];
	reg int p=-1;
	if(x==0) putchar('0');
	else while(x) buf[++p]=(x%10)^'0',x/=10;
	while(~p) putchar(buf[p--]);
	putchar('\n');
	return;
}

const int MAXM=3e5+5;

int m,p,T;
int ptr[MAXM],fa[MAXM];

inline int add(reg int a,reg int b){
	reg int sum=a+b;
	return sum>=p?sum-p:sum;
}

inline int sub(reg int a,reg int b){
	reg int sum=a-b;
	return sum<0?sum+p:sum;
}

inline int mul(reg int a,reg int b){
	return 1ll*a*b%p;
}

namespace LCT{
	#define fa(u) unit[u].fa
	#define ch(u) unit[u].ch
	#define siz(u) unit[u].siz
	#define tRev(u) unit[u].tRev
	#define val(u) unit[u].val
	#define sum(u) unit[u].sum
	#define tMul(u) unit[u].tMul
	#define lson(u) ch(u)[0]
	#define rson(u) ch(u)[1]
	struct Node{
		int fa;
		int ch[2];
		int siz;
		bool tRev;
		int val;
		int sum;
		int tMul;
	};
	int tot;
	Node unit[MAXM];
	inline int getNode(reg int v){
		reg int p=++tot;
		siz(p)=1,val(p)=sum(p)=v,tMul(p)=1;
		return p;
	}
	inline bool get(reg int p){
		return rson(fa(p))==p;
	}
	inline bool isRt(reg int p){
		return lson(fa(p))!=p&&rson(fa(p))!=p;
	}
	inline void pushup(reg int p){
		siz(p)=siz(lson(p))+siz(rson(p))+1;
		sum(p)=add(add(sum(lson(p)),sum(rson(p))),val(p));
		return;
	}
	inline void Rev(reg int p){
		swap(lson(p),rson(p));
		tRev(p)=!tRev(p);
		return;
	}
	inline void Mul(reg int p,reg int val){
		val(p)=mul(val(p),val);
		sum(p)=mul(sum(p),val);
		tMul(p)=mul(tMul(p),val);
		return;
	}
	inline void pushdown(reg int p){
		if(tRev(p)){
			if(lson(p)) Rev(lson(p));
			if(rson(p)) Rev(rson(p));
			tRev(p)=false;
		}
		if(tMul(p)!=1){
			if(lson(p)) Mul(lson(p),tMul(p));
			if(rson(p)) Mul(rson(p),tMul(p));
			tMul(p)=1;
		}
		return;
	}
	inline void rotate(reg int p){
		if(isRt(p)) return;
		reg int f=fa(p),ff=fa(f),dir=get(p);
		if(!isRt(f)) ch(ff)[get(f)]=p;
		if(ch(p)[dir^1]) fa(ch(p)[dir^1])=f;
		ch(f)[dir]=ch(p)[dir^1];
		ch(p)[dir^1]=f,fa(f)=p;
		fa(p)=ff;
		pushup(f),pushup(p);
		return;
	}
	inline void update(reg int p){
		if(!isRt(p)) update(fa(p));
		pushdown(p);
		return;
	}
	inline void splay(reg int x){
		update(x);
		for(reg int y=fa(x);!isRt(x);rotate(x),y=fa(x))
			if(!isRt(y))
				rotate(get(x)==get(y)?y:x);
		pushup(x);
		return;
	}
	inline void access(reg int p){
		for(reg int las=0;p;las=p,p=fa(p))
			splay(p),rson(p)=las,pushup(p);
		return;
	}
	inline void makeRt(reg int p){
		access(p),splay(p),Rev(p);
		return;
	}
	inline void split(reg int x,reg int y){
		makeRt(x),access(y),splay(y);
		return;
	}
	inline void link(reg int x,reg int y){
		makeRt(x),makeRt(y);
		fa(x)=y;
		pushup(y);
		return;
	}
	inline int kth(reg int u,reg int k){
		while(true){
			pushdown(u);
			if(k<=siz(lson(u)))
				u=lson(u);
			else if(siz(lson(u))+1==k)
				return u;
			else
				k-=siz(lson(u))+1,u=rson(u);
		}
		return -1;
	}
	inline void update(int x,int l,int r,int v){
		split(1,x);
		reg int L=kth(x,l+1),R=kth(x,r+1);
		split(L,R);
		Mul(R,v);
		return;
	}
	inline int query(reg int x,reg int l,reg int r){
		split(1,x);
		reg int L=kth(x,l+1),R=kth(x,r+1);
		split(L,R);
		return sum(R);
	}
	#undef fa
	#undef ch
	#undef siz
	#undef tRev
	#undef val
	#undef sum
	#undef tMul
	#undef lson
	#undef rson
}

int main(void){
	LCT::getNode(0);
	m=read(),p=read(),T=read();
	reg int ans=0;
	reg int p=1;
	for(reg int i=1;i<=m;++i){
		static int opt,x,s,l,r;
		opt=read();
		switch(opt){
			case 1:{
				x=read();
				if(T) x^=ans;
				if(!x) p=fa[p];
				else{
					reg int q=LCT::getNode(x);
					LCT::link(q,p);
					fa[q]=p,p=q;
				}
				ptr[i]=p;
				break;
			}
			case 2:{
				s=read(),l=read(),r=read(),x=read();
				if(T) x^=ans;
				LCT::update(ptr[s],l,r,x);
				ptr[i]=ptr[i-1];
				break;
			}
			case 3:{
				s=read(),l=read(),r=read();
				writeln(ans=LCT::query(ptr[s],l,r));
				ptr[i]=ptr[i-1];
				break;
			}
		}
	}
	flush();
	return 0;
}