#include <bits/stdc++.h>
#define _io ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define vi vector<int>
#define vll vector<long long>
#define mp make_pair
typedef long long ll;
using namespace std;

const ll INF = 100000000000LL;

vll towers(2000000,INF);
int ans;

int findTower(ll value){

    int res=0;
    int init=0, end=towers.size();

    while(init<=end){
        int mid = (init+mid/2);

        if(value < towers[mid]){
            res = mid;
            end = mid-1;
        }
        else init = mid+1;
    }

    return res;

}

int main(){
    int n; cin >> n;
    vll blocks(n);
    for(int i=0;i<n;i++) cin >> blocks[i];

    for(int i=0; i<n; i++){
        int pos_bloco = findTower(blocks[i]);

        if(towers[pos_bloco]==INF)
            ans++;
        towers[pos_bloco] = blocks[i];

    }

    cout << ans << endl;

}