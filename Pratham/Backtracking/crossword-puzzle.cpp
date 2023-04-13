#include <bits/stdc++.h>
#define CROSSWORD_SIZE 10
using namespace std;

string ltrim(const string &);
string rtrim(const string &);

/*
https://www.hackerrank.com/challenges/crossword-puzzle/problem?isFullScreen=true
 * Complete the 'crosswordPuzzle' function below.
 *
 * The function is expected to return a STRING_ARRAY.
 * The function accepts following parameters:
 *  1. STRING_ARRAY crossword
 *  2. STRING words
 */
 
 
vector<string> split(string &words, char delimiter){
    vector<string> list;
    list.push_back("");
    
    for(auto &ch : words){
        if(ch == delimiter){
            list.push_back("");
        }else{
            list.back() += ch;
        }
    }
    
    if(list.back() == ""){
        list.pop_back();
    }
    
    return list;
}

bool getEmptySlot(vector<string> &crossword, int &row, int &col){

    for(int i=0; i < crossword.size(); i++){
        for(int j=0; j < crossword[i].size(); j++){
            
            if(crossword[i][j] == '-'){
                
                row = i;
                col = j;
                
                // check for word starting
                
                if(i > 0 && crossword[i-1][j] != '+'){
                    row = row - 1;
                        cout<< "seg  "<<endl;
                }
                
                if(j > 0 && crossword[i][j-1] != '+'){
                    col = col - 1;
                
                }
                
                cout<< " R= "<<row << " , " << col <<endl;
                return true;
            }
        }
    }
    return false;
}

bool willFillVertically(vector<string> &crossword, int i, int j, string &word){
    
    if(word.size() + i > CROSSWORD_SIZE){
        return false;
    }
    
    
    for(char &s: word){
        if(crossword[i][j] != '-' && crossword[i][j] != s)
        {
            return false;
        }
    
        i++;
    }
    
    if(i < CROSSWORD_SIZE && crossword[i][j] != '+'){
        return false; // because word is too small to fit
    }
    
    return true;
}


bool willFillHorizontally(vector<string> &crossword, int i, int j, string &word){
    
    if(word.size() + j > CROSSWORD_SIZE){
        return false;
    }
    
    for(char &s: word){
        if(crossword[i][j] != '-' && crossword[i][j] != s)
        {
            return false;
        }
    
        j++;
    }
    
    if(j < CROSSWORD_SIZE && crossword[i][j] != '+'){
        return false; // because word is too small to fit
    }
    
    return true;
}


void fillVertically(vector<string> &crossword, int i, int j, string &word, vector<bool> &track){
    int x = 0;
    while(i < CROSSWORD_SIZE && (crossword[i][j] == '-' || crossword[i][j] == word[x])){
        if(crossword[i][j] != word[x]){
            track[x] = true;
        }
        
        crossword[i][j] = word[x];
        x++;
        i++;
    }
    
}

void fillHorizontally(vector<string> &crossword, int i, int j, string &word, vector<bool> &track){
    int x = 0;
    while(j < CROSSWORD_SIZE && (crossword[i][j] == '-' || crossword[i][j] == word[x])){
        if(crossword[i][j] != word[x]){
                track[x] = true;
            }
            
        crossword[i][j] = word[x];
        x++;
        j++;
    }
    
}

void removeFillVertically(vector<string> &crossword, int i, int j, string &word, vector<bool> &track){
    int x = 0;
    
    for(bool t:track){
        if(t){
            crossword[i][j] = '-';
        }
        i++;
    }
    
}

void removeFillHorizontally(vector<string> &crossword, int i, int j, string &word, vector<bool> &track){
    int x = 0;
    
    for(bool t:track){
        
        if(t){
            crossword[i][j] = '-';
        }
        
        j++;
    }
}

bool crosswordPuzzleBacktrack(vector<string> &crossword, vector<string> &words) {
        int i, j;
        
        if(!getEmptySlot(crossword, i, j)){
            // all slots filled
            return true;
        }
        
            for(auto &word: words){
                    if(willFillHorizontally(crossword, i, j,word)){
                        
                        vector<bool> track(word.size(), false);
                        fillHorizontally(crossword, i, j, word, track);
                        
                        if(crosswordPuzzleBacktrack(crossword, words)){
                            return true;
                        }
                        
                        removeFillHorizontally(crossword, i, j, word, track);
                    }
                    
                    if(willFillVertically(crossword, i, j,word)){
                         
                        vector<bool> track(word.size(), false);
                        fillVertically(crossword, i, j, word, track);
                        
                        if(crosswordPuzzleBacktrack(crossword, words)){
                            return true;
                        }
                        
                        removeFillVertically(crossword, i, j, word, track);
                    }
                }
                
                return false;
}

vector<string> crosswordPuzzle(vector<string> crossword, string words) {
    vector<string> list  = split(words, ';');
    
    crosswordPuzzleBacktrack(crossword, list);
    return crossword;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    vector<string> crossword(10);

    for (int i = 0; i < 10; i++) {
        string crossword_item;
        getline(cin, crossword_item);

        crossword[i] = crossword_item;
    }

    string words;
    getline(cin, words);

    vector<string> result = crosswordPuzzle(crossword, words);

    for (size_t i = 0; i < result.size(); i++) {
        fout << result[i];

        if (i != result.size() - 1) {
            fout << "\n";
        }
    }

    fout << "\n";

    fout.close();

    return 0;
}

string ltrim(const string &str) {
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
    );

    return s;
}

string rtrim(const string &str) {
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end()
    );

    return s;
}
