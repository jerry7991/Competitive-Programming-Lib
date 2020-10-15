#include <iostream>
using namespace std;

class Player
{
private:
    int id;
    static int next_id;
public:
    int getID() { return id; }
    Player()  {  id = next_id++; }
};
int Player::next_id = 1;

int main()
{

	int n;
	cin>>n;
	    int sp=2, st=1;
    for(int i=1; i<=n; i++) {
        for(int j=1; j<=sp; j++) {
            cout<<""<<' ';;
        }
        int val=i;
        if(i> n/2) {
            val=n+1-i;
        }
        for(int j=1; j<=st; j++) {
          cout<<(val);
            if(j<=st/2)
                val++;
            else
                val--;

        }
       cout<<""<<'\n';
        if(i<(n/2 +1)) {
            st+=2;
            sp--;
        }else {
            st-=2;
            sp++;
        }
    }

}