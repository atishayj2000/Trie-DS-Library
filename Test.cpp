#include<iostream>
#include<unordered_map>
#include<algorithm>
#include <set>
#include<vector>
#include "TrieDS.h"

using namespace std;

int main()
{
    /*
     *THIS PROGRAM USES THE TEST DATA
     *TO BUILD A TRIE FOR THE GIVEN DATA
     *THEN IT CONVERTS THE TRIE INTO ITS
     *SERIALIZED FORM AND WRITES IT TO A FILE
     */
    
    
    freopen ("TEST_DATA.txt", "r", stdin);
    freopen ("SERIAL_FORM.txt", "w", stdout);

    vector<string> input;
     string word;
    

     cin>>word;
     while(word != "#END#")
    {
       input.push_back(word);
       cin>>word;
    }
    

    TrieDS *myTestTrie = new TrieDS(input);
    string serial  = myTestTrie->trieToString();
    
    TrieDS * myTestTrie2 = new TrieDS(serial);
    
    vector<string> ans = myTestTrie2->trieToList();
    freopen ("TEST_RESULT.txt", "w", stdout);
    
    sort(ans.begin(),ans.end());
    sort(input.begin(),input.end());
    
    if(ans==input){
        cout<<"TEST PASSED"<<endl;
        cout<<"List of words converted to serial form and back to list of words without any loss";
    }else{
        cout<<"TEST FAILED"<<endl;
    }
    
    return 0;
}
