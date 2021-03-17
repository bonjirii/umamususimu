#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; (i) < (int)(n); ++ (i))
#define rep3(i, m, n) for (int i = (m); (i) < (int)(n); ++ (i))
#define rep_r(i, n) for (int i = (int)(n) - 1; (i) >= 0; -- (i))
#define rep3r(i, m, n) for (int i = (int)(n) - 1; (i) >= (int)(m); -- (i))
using ll = long long;
using P = pair<int,int>;
using Graph = vector<vector<int>>;

const vector<string> SSR = {"supe", "sai", "tou", "goldship", "uo", "gura", "eru", 
                    "sei", "tama", "fa", "ai", "ui", "easya", "goldsiti-", "saku", 
                    "su-", "suma", "nisi", "bigo", "tazuna", "ogu"};
const vector<string> picSSR = {"tui"};
const vector<string> SR = {"fuji", "daiwa", "hisi", "eagru", "agu", "biwa", "maya", "man",
                    "miho", "meji", "yuki", "agu", "ei", "nari", "ma-", "mati", "mei", "meji",
                    "nai", "kin", "kiri", "sui"};
const vector<string> picSR = {"daitaku"};

const double SSRpar = 0.107, tenSSRpar = 0.107, 
        picSSRpar = 0.750, tenpicSSRpar = 0.750,
        SRpar = 0.715, tenSRpar = 3.875,
        picSRpar = 2.250, tenpicSRpar = 12.125;

const int countPerLap = 6; //一リセマラに何十連できるか


const int randcorrection = 100000;
const int correction = 1000;

int main() {
    srand((unsigned)time(NULL));

    int n;
    cin >> n;
    vector<string> want(n);
    rep(i, n) cin >> want[i];

    int lapnum = 1;
    while(1){
        vector<bool> get(n, false);
        for(int i = 0; i < countPerLap; i++){
            for(int j = 1; j <= 10; j++){
                if(j != 10){
                    int par = rand() % randcorrection;
                    if(par <= SSRpar * SSR.size() * correction){
                        string result = SSR[rand() % SSR.size()];
                        int getnum = find(want.begin(), want.end(), result) - want.begin();
                        if(getnum != n) get[getnum] = true;
                        cout << "SSR : " << result << endl;
                        continue;
                    }else if(par <= (SSRpar * SSR.size() + picSSRpar * picSSR.size()) * correction){
                        string result = picSSR[rand() % picSSR.size()];
                        int getnum = find(want.begin(), want.end(), result) - want.begin();
                        if(getnum != n) get[getnum] = true;
                        cout << "picSSR : "<< result << endl;
                        continue;
                    }else if(par <= (SSRpar * SSR.size() + picSSRpar * picSSR.size() + SRpar * SR.size()) * correction){
                        string result = SR[rand() % SR.size()];
                        int getnum = find(want.begin(), want.end(), result) - want.begin();
                        if(getnum != n) get[getnum] = true;
                        cout << "SR : " << result << endl;
                        continue;
                    }else if(par <= (SSRpar * SSR.size() + picSSRpar * picSSR.size() + SRpar * SR.size() + picSRpar * picSR.size()) * correction){
                        string result = picSR[rand() % picSR.size()];
                        int getnum = find(want.begin(), want.end(), result) - want.begin();
                        if(getnum != n) get[getnum] = true;
                        cout << "picSR : " << result << endl;
                        continue;
                    }else{
                        cout << "Rの子！" << endl;
                    }
                }else{
                    int par = rand() % randcorrection;
                    if(par <= tenSSRpar * SSR.size() * correction){
                        string result = SSR[rand() % SSR.size()];
                        int getnum = find(want.begin(), want.end(), result) - want.begin();
                        if(getnum != n) get[getnum] = true;
                        cout << "SSR : " << result << endl;
                        continue;
                    }else if(par <= (tenSSRpar * SSR.size() + tenpicSSRpar * picSSR.size()) * correction){
                        string result = picSSR[rand() % picSSR.size()];
                        int getnum = find(want.begin(), want.end(), result) - want.begin();
                        if(getnum != n) get[getnum] = true;
                        cout << "picSSR : " <<result << endl;
                        continue;
                    }else if(par <= (tenSSRpar * SSR.size() + tenpicSSRpar * picSSR.size() + tenSRpar * SR.size()) * correction){
                        string result = SR[rand() % SR.size()];
                        int getnum = find(want.begin(), want.end(), result) - want.begin();
                        if(getnum != n) get[getnum] = true;
                        cout << "SR : " << result << endl;
                        continue;
                    }else if(par <= (tenSSRpar * SSR.size() + tenpicSSRpar * picSSR.size() + tenSRpar * SR.size() + tenpicSRpar * picSR.size()) * correction){
                        string result = picSR[rand() % picSR.size()];
                        int getnum = find(want.begin(), want.end(), result) - want.begin();
                        if(getnum != n) get[getnum] = true;
                        cout << "picSR : " << result << endl;
                        continue;
                    }else{
                        cout << "Rの子！" << endl;
                    }
                }
            }
        }
        if(find(get.begin(), get.end(), false) == get.end()){
            cout << lapnum << "回目 : あたり！！！！！！きたあああ" << endl;
            break;
        }
        cout << lapnum << "回目：ダメです！" << endl;
        lapnum++;
    }

    return 0;
}