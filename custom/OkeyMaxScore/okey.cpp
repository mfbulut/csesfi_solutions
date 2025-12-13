#include <bits/stdc++.h>
using namespace std;

string colors[5] = {
    "",
    "Red",
    "Blue",
    "Yellow",
    "Black",
};

vector<unordered_set<int>> same_color(13);

int main() {
    int n;
    cin >> n;

    vector<int> tiles(n);

    for(int i = 0; i < tiles.size(); ++i) {
        int color, value;
        cin >> color >> value;
        tiles[i] = (color - 1) * 12 + (value - 1); // 0..12 13..24 25..36 37..48, categorized by colors
    }

    sort(tiles.begin(), tiles.end());

    for (int& tile : tiles)
    {
        same_color[tile % 13].insert(tile);
    }

    // for (auto s : same_color) {
    //     cout << s.size() << " ";
    // }
    vector<int> vec;
    int sum = 0; // to be filled in next loop
    //  0 1 2 3 i=9

    for (int i = 0; i < tiles.size() - 3; ++i) {
        bool group = true;

        for (int j = i; j < min(i + 2, (int) tiles.size() - 1); ++j) {
            if (tiles[j] / 12 != tiles[j + 1] / 12) {
                group = false;
                break;
            }

            if (tiles[j + 1] != (tiles[j] + 1)) {
                group = false;
                break;
            }
        }

        if (!group) continue;
        vec.insert(vec.end(), tiles.begin() + i, tiles.begin() + i + 3);

        int j = (i + 3);
        while (j < tiles.size()) {
            if (vec.back() + 1 == tiles[j]) {
                vec.push_back(tiles[j]);
                // puan hesabi  eklenecek
            } else break;

            j +=1;
        }

        i = j + 1;
    }

    for (auto v : vec) cout << v  << " " ;
    //sum+= (v+1) % 13;


    for(int i = 0; i < 13; ++i){
    control:
        auto s= same_color[i];
        if(s.size() > 2) {
            for(auto x: s) {
                if(find(vec.begin(), vec.end(), x)!= vec.end() ) {
                    i++;
                    goto control;
                }
                sum += ((*s.begin()) %13 +1)* s.size();
            }

        }
    }

    cout << sum;
}
