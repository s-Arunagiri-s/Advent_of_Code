
#include<iostream>
#include<string>
#include<fstream>
#include<sstream>
using namespace std;
int main(){
    fstream file;
    int blue;
    int red;
    int green;
    cout<<"enter number of blue cubes:";
    cin>>blue;
    cout<<"enter number of red cubes:";
    cin>>red;
    cout<<"enter number of green cubes:";
    cin>>green;
    file.open("day1.txt",ios::in);
    if(file.is_open())
    {
        string tp;
        int power=0;
        string s;
        int bp;
        int rp;
        int gp;
        int b=0;
        int r=0;
        int g=0;
        int b_max=1;
        int r_max=1;
        int g_max=1;
        string ss;
        int sum=0;
        while(getline(file,tp)){
            size_t pos=tp.find(':');
            s=tp.substr(pos+1,tp.size()-pos);
            //cout<<s<<"\n";
            stringstream sss(s);
            while(getline(sss,ss,';'))
            {
               b=0;
               r=0;
               g=0;
              // cout<<ss<<"\n";
               bp=ss.find("blue")-3;
               rp=ss.find("red")-3;
               gp=ss.find("green")-3;

               if(ss[bp]!=' ')
               b=int(ss[bp]-'0')*10;
               b+=int(ss[bp+1]-'0');
               //cout<<"b"<<b<<" ";

               if(ss[rp]!=' ')
               r=int(ss[rp]-'0')*10;
               r+=int(ss[rp+1]-'0');
               //cout<<"r"<<r<<" ";

               if(ss[gp]!=' ')
               g=int(ss[gp]-'0')*10;
               g+=int(ss[gp+1]-'0');
               //cout<<"g"<<g<<" ";

               if(b>b_max)
               b_max=b;
               
               if(r>r_max)
               r_max=r;
               
               if(g>g_max)
               g_max=g;
            }
          power=r_max*b_max*g_max;
          cout<<"game:"<<power<<"\n";
          sum+=power;
          power=0;
          r_max=1;
          b_max=1;
          g_max=1;
        }
        cout<<sum;
    }
}
