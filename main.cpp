#include<iostream> 
#include<vector> 
#include<algorithm> 

using namespace std; 

int x = 0; 

vector<pair<char,int>> teamCount; 


/*

    C vs M
    B vs P
    K vs S
    C vs G
    L vs R
    P vs D 
    M vs S
    K vs L
    B vs G
    R vs C
    M vs D
    S vs P
*/ 



bool comparingPairs(pair<int,int> a, pair<int,int> b){
    return a.second > b.second; 
}

void recurse(int matchIndex, vector<pair<char, int>> pointTable, vector<pair<char,char>> curMatches){
    if(matchIndex == 12){
        sort(pointTable.begin(), pointTable.end(), comparingPairs);

        for(int i = 0; i<4; i++){
            cout << pointTable[i].first << " "; 

            for(int j = 0; j<teamCount.size(); j++){
                if(teamCount[j].first == pointTable[i].first){
                    teamCount[j].second++; 
                } 
            }
        }
        x++; 

        cout << "\n";
         
    

        //return pointTable; 
    }
    else{
        vector<pair<char,int>> copy1; 
        vector<pair<char,int>> copy2; 
        for(int i = 0; i<pointTable.size(); i++){
            copy1.push_back(make_pair(pointTable[i].first, pointTable[i].second)); 
            copy2.push_back(make_pair(pointTable[i].first, pointTable[i].second)); 
        }

        char firstTeam = curMatches[matchIndex].first; 
        char secondTeam = curMatches[matchIndex].second; 

        for(int i = 0; i<copy1.size(); i++){
            if(copy1[i].first == firstTeam){
                copy1[i].second+=2; 
            }
        }

        for(int i = 0; i<copy2.size(); i++){
            if(copy2[i].first == secondTeam){
                copy2[i].second+=2; 
            }
        }

        recurse(matchIndex+1, copy1, curMatches); 
        recurse(matchIndex+1, copy2, curMatches); 
        
    }
}


int main(){

    vector<pair<char,int>> curPts; // [['G', 18], ['L', 16], ...] 
    vector<pair<char,char>> curMatches; // [['C', 'M'], ['B', 'P'],...]


    curMatches.push_back(make_pair('C', 'M')); 
    curMatches.push_back(make_pair('B', 'P')); 
    curMatches.push_back(make_pair('K', 'S')); 
    curMatches.push_back(make_pair('C', 'G')); 
    curMatches.push_back(make_pair('L', 'R')); 
    curMatches.push_back(make_pair('P', 'D')); 
    curMatches.push_back(make_pair('M', 'S')); 
    curMatches.push_back(make_pair('K', 'L')); 
    curMatches.push_back(make_pair('B', 'G')); 
    curMatches.push_back(make_pair('R', 'C')); 
    curMatches.push_back(make_pair('M', 'D')); 
    curMatches.push_back(make_pair('S', 'P')); 



    curPts.push_back(make_pair('G', 18)); 
    curPts.push_back(make_pair('L', 16)); 
    curPts.push_back(make_pair('R', 14)); 
    curPts.push_back(make_pair('B', 14)); 
    curPts.push_back(make_pair('D', 12)); 
    curPts.push_back(make_pair('S', 10)); 
    curPts.push_back(make_pair('K', 10)); 
    curPts.push_back(make_pair('P', 10)); 
    curPts.push_back(make_pair('C', 8)); 
    curPts.push_back(make_pair('M', 4)); 


    teamCount.push_back(make_pair('G', 0));
    teamCount.push_back(make_pair('L', 0));
    teamCount.push_back(make_pair('R', 0));
    teamCount.push_back(make_pair('B', 0));
    teamCount.push_back(make_pair('D', 0));
    teamCount.push_back(make_pair('S', 0));
    teamCount.push_back(make_pair('K', 0));
    teamCount.push_back(make_pair('P', 0));
    teamCount.push_back(make_pair('C', 0));
    teamCount.push_back(make_pair('M', 0));




    recurse(0, curPts, curMatches); 

    cout << x << "\n"; 

    cout << "PROBABILITIES" << "\n"; 

    for(int i = 0; i<teamCount.size(); i++){
        cout << teamCount[i].first << " " << (double) teamCount[i].second/4096.0 << "\n"; 
    }

    




}

