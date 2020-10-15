#include<bits/stdc++.h>
using namespace std;
#define N 10
void display(char grid[][N] )
{
    for(int i=0 ; i<N ; i++)
    {
        for(int j=0 ; j<N ; j++)
        {
            cout<<grid[i][j];
        }
        cout<<endl;
    }
}
void resetHorizontal(char grid[N][N] , int row , int col , bool * MemoArray , int Msize)
{
    cout<<"\nreset horizontal\n"<<endl;
    for(int i=0 ; i<Msize ; i++)
    {
       // if(MemoArray[i])
        {
             //means we have to reset all thing which i have done earlier ok!!!
             grid[row][col+i]='-';
        }//else no need to reset because current word is also common for other word which all ready have filled successfully
    }
    display(grid);
}
void setHorizontal(char grid[N][N] , string wordHasToFill , int row , int col , bool * MemoArray)
{
    for(int i=0 ; i<wordHasToFill.size() ; i++)
    {
        if(grid[row][col+i]=='-')
        {
            MemoArray[i]=true;
            grid[row][col+i]=wordHasToFill[i];
        }
        if(grid[row][col+i]==wordHasToFill[i])//means collision of same word that's means while backtracking we wouldn't delete it because it's common word
        {
            MemoArray[i]=false;
            //else no need to fill because all ready have common word
        }
    }

    cout<<"\nHorizontal\n"<<endl;
   display(grid);
}
bool isValidHorizontal (char grid[N][N] , string wordHasToFill  ,int row, int col)
{
    //cout<<wordHasToFill<<"forhr"<<endl;
    for(int i=0 ; i<wordHasToFill.size() ; i++)
    {
        //col will be different and row same
        if(grid[row][col+i]=='+')   //we have reached on block position can't fill all word
            return false;
        if(grid[row][col+i]!='-' && grid[row][col+i]!=wordHasToFill[i] && i<wordHasToFill.size())//neither a common word nor -, so can't fill all word
        return false;
    }
    //if no return activated it means word will be valid because vertical grid have either - or common letter
    return true;
}
void resetVertical(char grid[N][N] , int row , int col , bool *MemoArray , int Msize)
{
    cout<<"\n hi reset vertical \n"<<endl;
    for(int i=0 ; i<Msize ; i++)
    {
       // if(MemoArray[i])
        {
            //means we have to reset all thing which i have done earlier ok!!!
            grid[row+i][col]='-';
        }//else no need to reset because current word is also common for other word which all ready have filled successfully
    }
    display(grid);
}
void setVertical(char grid[N][N] , string wordHasToFill ,int row , int col , bool * Memoarray)
{
    for(int i= 0 ; i<wordHasToFill.size() ; i++)
    {
        if(grid[i+row][col]=='-')//that's means if we will wrong then at the time of backtracking we will have to reset this index to -
        {
            Memoarray[i]=true;
            grid[i+row][col]=wordHasToFill[i];
        }
        if(grid[i+row][col]==wordHasToFill[i])//means collision of same word that's means while backtracking we wouldn't delete it because it's common word
        {
            Memoarray[i]=false;
            //no need of insertion because all ready have common word
        }
    }
    cout<<"\nvertical\n"<<endl;
    display(grid);
}
bool isValidVertical (char grid[N][N] , string wordHasToFill  ,int row, int col)
{
    //cout<<wordHasToFill<<"for Vr"<<endl;
    for(int i=0 ; i<wordHasToFill.size() ; i++)
    {
        if(grid[row+i][col]=='+')
            return false;
        if( grid[row+i][col] !='-' && grid[row+i][col] !=wordHasToFill[i])//either should be same character or -
            return false;
    }
    //if no return activated it means word will be valid because vertical grid have either - or common letter
    return true;
}
bool crossWordHelper(char grid[N][N] , vector<string>word , int indexOfWords)
{
    if(indexOfWords == word.size())//means we have settled all the word perfectly
    {
        return true;
    }
    for(int row=0 ; row<N ; row++)
    {
        for(int col=0 ; col <N ; col++)
        {
            if(grid[row][col]=='-' || grid[row][col]==word[indexOfWords][0]) //if this is empty position
            {
                //cout<<row<<"\n"<<col<<endl;
                if(isValidVertical(grid , word[indexOfWords]  , row ,col))
                    {
                        //cout<<"Valid vertical"<<endl;
                        bool Memoarray[word[indexOfWords].size()];
                        setVertical(grid , word[indexOfWords] , row  ,col ,Memoarray );
                       if( crossWordHelper(grid , word , indexOfWords+1))//if all word successfully inserted then above  if(indexOfWords == word.size()) will return
                       {
                           return true;
                       }
                        //else we have to track back and reset what i did earlier
                        resetVertical(grid , row , col , Memoarray ,  word[indexOfWords].size());
                    }
                    if(isValidHorizontal(grid , word[indexOfWords] , row , col ))
                    {
                       // cout<<"Valid Horizontal"<<endl;
                       bool Memoarray[word[indexOfWords].size()];
                       setHorizontal(grid , word[indexOfWords]  ,row ,col, Memoarray);
                        if( crossWordHelper(grid , word , indexOfWords+1) )//if all word successfully inserted then above  if(indexOfWords == word.size()) will return
                        {
                            return true;
                        }
                        //else we have to track back and reset what i did earlier
                        resetHorizontal(grid , row , col , Memoarray ,word[indexOfWords].size());
                    }

            }
        }
    }
    //if nothing happened return false that's means crossword can't be filled
    return false;
}
int main()
{
    char grid[N][N];
    for(int i=0 ; i<N ; i++)
    {
        string row;
        cin>>row;
        for(int j=0 ; j<N ; j++)
        {
            grid[i][j]=row[j];
        }
    }
    string input;
    cin>>input;
    /*for(int i=0 ; i<input.size() ; i++)
    {
        cout<<input[i]<<" ";
    }
    display(grid);
    */
    //let's filter word in string
    vector<string> word;
    for(int i=0 ; i<input.size(); i++)
    {
        string str="";
        while(i<input.size() && input[i]!=';')
        {
            str += input[i];
            i++;
        }
        word.push_back(str);
    }
    /*for(vector<string>::iterator itr=word.begin() ; itr!=word.end() ; itr++)
    {
        cout<<*itr<<" ";
    }
    for(int i=0 ; i<word.size() ; i++)
    {
        cout<<word[i]<<"\n";
    }*/
   if(crossWordHelper(grid , word , 0))//initially call it with starting index of words
    {
        display(grid);
    }else
    {
        cout<<"hi\n";
        display(grid);
    }
    /* for(int i=0 ; i<word.size() ; i++)
    {
        for(int j=0 ; j<word[i].size() ; j++)
        {
            cout<<word[i][j]<<"\n";
        }
        cout<<endl;
    }*/
    return 0;
}
