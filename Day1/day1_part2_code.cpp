#include<iostream>
#include<bits/stdc++.h>
#include<fstream>
#include<string>
using namespace std;
int main(){
    fstream file;
    file.open("day1.txt",ios::in);
    if(file.is_open())
    {
        string tp;
        int sum=0;
        int num=0;
        int num1;
        int num2;
        int word1;
        int word2;
        int first_num_pos=INT_MAX;
        int last_num_pos=INT_MAX;
        int first_word_pos=INT_MAX;
        int last_word_pos=INT_MAX;
        
        while(getline(file,tp)){
            for(int i=0;i<tp.length();i++)
            {
                if(tp[i]<='9' && tp[i]>='0')
                {
                    num1=int(tp[i]-'0');
                    first_num_pos=i;
                    break;
                }
            }
            for(int i=tp.length()-1;i>=0;i--)
            {
                if(tp[i]<='9' && tp[i]>='0')
                {
                    num2=int(tp[i]-'0');
                    last_num_pos=tp.length()-i-1;
                    break;
                }
            }
            cout<<"\nfirst num pos"<<first_num_pos<<"\n";
            cout<<"last num pos"<<last_num_pos<<"\n";
            vector<string> number_words={"one","two","three","four","five","six","seven","eight","nine"};
            map<string, int> mp;
            mp["one"] = 1;
            mp["two"] = 2;
            mp["three"] = 3;
            mp["four"] = 4;
            mp["five"] = 5;
            mp["six"] = 6;
            mp["seven"] = 7;
            mp["eight"] = 8;
            mp["nine"] = 9;
            for(int i=0;i<number_words.size();i++)
            {
                size_t pos=tp.find(number_words[i]);
                if(pos != string::npos && pos<first_word_pos)
                {
                    first_word_pos=pos;
                    word1=mp[number_words[i]];
                }
                
            }
            
            reverse(tp.begin(), tp.end());
            cout<<tp<<" ";
            vector<string> number_words_back={"eno","owt","eerht","ruof","evif","xis","neves","thgie","enin"};
            map<string, int> mp_back;
            mp_back["eno"] = 1;
            mp_back["owt"] = 2;
            mp_back["eerht"] = 3;
            mp_back["ruof"] = 4;
            mp_back["evif"] = 5;
            mp_back["xis"] = 6;
            mp_back["neves"] = 7;
            mp_back["thgie"] = 8;
            mp_back["enin"] = 9;
            for(int i=0;i<number_words_back.size();i++)
            {
                size_t pos=tp.find(number_words_back[i]);
                if(pos != string::npos && pos<last_word_pos)
                {
                    last_word_pos=pos;
                    word2=mp_back[number_words_back[i]];
                }
                
            }
            if(first_word_pos>first_num_pos)
            {
                num=num1*10;
            }
            else
            {
                num=word1*10;
            }
            if(last_word_pos>last_num_pos)
            {
                num+=num2;
            }
            else
            {
                num+=word2;
            }
            cout<<"\nfirst word pos"<<first_word_pos<<"\n";
            cout<<"last word pos"<<last_word_pos<<"\n";
            cout<<num<<"\n";
            sum+=num;
            num=0;
            num1=0;
            word1=0;
            num2=0;
            word2=0;
            first_num_pos=INT_MAX;
            last_num_pos=INT_MAX;
            first_word_pos=INT_MAX;
            last_word_pos=INT_MAX;
        }
        cout<<sum;
    }
}
