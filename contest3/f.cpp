#include<bits/stdc++.h>
#define _io ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define vi  vector<int>
#define vll vector<ll>
using namespace std;
typedef long long ll;

int dir[]={0,1,0,-1,1,0,-1,0};
const ll INF=1e9;
const int sz=2e5;
vi a;
int dp[sz+10][3][3];
int n;

int func(int pos,int p,int peg){
	if(pos>=n)
		return 0;

	if(dp[pos][p][peg]!=-1) return dp[pos][p][peg];

	int ans1=INF,ans2=INF;

	if(p){
		if(peg<2)
			ans1=a[pos]+func(pos+1,1,peg+1);
		if(pos != 0)
			ans2 = func(pos+1,0,1);
	}else{

		if(peg<2) ans1 = func(pos+1,0,peg+1);
		ans2 = a[pos] + func(pos+1,1,1);
        
	}

	return dp[pos][p][peg] = min(ans1,ans2);
}

void solve(){
	
	cin>>n;
	a = vi(n+1);
	for(int i=0;i<n;i++)
		cin>>a[i];
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<3;j++)
		{
			for(int k=0;k<3;k++)
				dp[i][j][k]=-1;
		}
	}
	int ans = func(0,1,0);
	cout<<ans<<endl;
}

int main(){ _io
	int t;	cin>>t;
	while(t--){
		solve();
	}
    return 0;
}
