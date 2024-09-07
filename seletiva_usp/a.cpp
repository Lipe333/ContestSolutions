#include <bits/stdc++.h>
#define _io ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define vi vector<int>
#define vll vector<long long>
typedef long long ll;
using namespace std;

int n;

int main(){ _io

    cin >> n;
    
    // ti, mi, ci, index
    vector<tuple<int,int,int,int>> songs(n);
    for(int i=0; i<n; i++) {
        int ti, mi, ci; cin >> ti >> mi >> ci;
        songs[i] = {ti, mi, ci, i+1};
    }

    sort(songs.begin(), songs.end());

    vi sad;
    int guest_id = -1; 
    int song_end = 0;
   
    deque<tuple<int,int,int,int>> wait_playlist;

    for(int i=0; i<n; i++) {
        
        int ti = get<0>(songs[i]);
        int mi = get<1>(songs[i]);
        int ci = get<2>(songs[i]);
        int current_guest_id = get<3>(songs[i]);
        
        while(!wait_playlist.empty() && ti >= song_end) {
            auto next_song = wait_playlist.front();
            wait_playlist.pop_front();
            guest_id = get<3>(next_song);
            song_end += get<1>(next_song);
        }

        if (guest_id == -1 || ti >= song_end) {
            guest_id = current_guest_id;
            song_end = ti + mi;
        } else {
            if (ci == 1) { 
                sad.push_back(guest_id); 
                guest_id = current_guest_id;
                song_end = ti + mi;
            } else {
                wait_playlist.push_back(songs[i]); 
            }
        }
    }

    cout << sad.size() << endl;
    for(auto e : sad) {
        cout << e << " ";
    }
    cout << "\n";

    return 0;
}
