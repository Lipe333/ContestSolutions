#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> ii;

#define _io ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define pb push_back
#define mp make_pair
#define f first
#define s second
#define vi vector<int>
#define vll vector<ll>
#define MAX 1e9
#define all(x) x.begin(),x.end()

const int maxn = 1000010;

string str,pattern;
int p[maxn];
int n,m;

void pi(){
    p[0] = 0;
    int len = 0;

    for(int i=1;i<m;i++){

        if(pattern[i]==pattern[len]){
            len++;
            p[i]=len;
        }

        else{
            
            if(len==0) p[i]=0;
            else{
                len = p[len-1];
                i = i-1;
            } 

        }

    }

}

void kmp(){
    int j=0,ans=0;;
    for(int i=0;i<n;i++){

        if(str[i]==pattern[j]){
            j++;
            if(j==m){
                ans++;
                j=p[j-1];
            }
        }
        else{

            if(j!=0){
                j = p[j-1];
                i--;
            } 

        }
    }
    cout << ans << "\n";
}

int main(){ _io
    cin >> str >> pattern;
    n = str.size();
    m = pattern.size();
    pi();
    kmp();
}