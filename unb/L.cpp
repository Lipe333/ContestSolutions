#include <bits/stdc++.h>
#define _io ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
typedef long long ll;

int freq1[256];
int freq2[256];

int main(){ _io
    int n; cin >> n;
    while(n--){
        string s1,s2;
        cin >> s1 >> s2;

        //cout << s1 << " " << s2 << endl;

        for(int i=0;i<256;i++){
            freq1[i]=0;
            freq2[i]=0;
        }

        for(auto ch: s1){
            freq1[ch]++;
        }

        for(auto ch: s2){
            freq2[ch]++;
        }

        char extra='\0';
        for(auto ch:s2){
            if(freq2[ch] != freq1[ch]){
                extra = ch;
                break;
            }
        }

        cout << extra << endl;


    }

}