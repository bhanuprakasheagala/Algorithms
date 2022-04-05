/*
There is an ATM machine. Initially, it contains a total of K units of money. N people (numbered 1 through N) 
want to withdraw money; for each valid i, the i-th person wants to withdraw Ai units of money.

The people come in and try to withdraw money one by one, in the increasing order of their indices. 
Whenever someone tries to withdraw money, if the machine has at least the required amount of money, 
it will give out the required amount. Otherwise, it will throw an error and not give out anything; 
in that case, this person will return home directly without trying to do anything else.

For each person, determine whether they will get the required amount of money or not.
2
5 10
3 5 3 2 1
4 6
10 8 6 4

11010
0010
Explanation

Example case 1: The ATM machine initially contains 10
units of money. The first person comes and withdraws 3 units, so the amount remaining in the machine is 7. 
Then the second person withdraws 5 units and the remaining amount is 2. The third person wants to withdraw 3 units,but since 
there are only 2 units of money in the machine, it throws an error and the third person must leave without getting anything.
Then the fourth person withdraws 2 units, which leaves nothing in the machine, so the last person does not get anything.

Example case 2: The ATM machine initially contains 6
units of money, so it cannot give anything to the first and second person. 
When the third person comes, it gives them all the money it has, so the last person does not get anything either.
*/

#include <iostream>
using namespace std;

int main() {
	// your code goes here
	int t;
	cin>>t;
	while(t--){
	    int n,k;
	    cin>>n;
	    cin>>k;
	    int money[n];
	    for(int i=0; i<n; i++){
	        cin>>money[i];
	    }
	    for(int i=0; i<n; i++){
	        if(money[i] <= k){
	            cout<<"1";
	            k = k - money[i];
	        }
	        else{
	            cout<<"0";
	        }
	    }
	    cout<<endl;
	}
	return 0;
}
