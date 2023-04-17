#include <stdio.h>
#include <stdlib.h>

// Including necessary header files
#include <bits/stdc++.h> 

// Using standard namespace
using namespace std;

int currentIndexMemberNext(vector<char> oldQueue, vector<char> newQueue, int currentIndex){
	int newIndex = 0; //iterator iterating in newQueue
	int oldIndex = 0; //iterator iterating in oldQueue
	while(oldIndex != currentIndex && (newIndex < newQueue.size() && oldIndex < oldQueue.size())){
	    if(oldIndex == currentIndex){
	        break;
	    }
		if(oldQueue[oldIndex] == newQueue[newIndex]){ // If oldQueue member is equal to the newQueue member, then the member is not removed. SO we move on.
			oldIndex++;
			newIndex++;
		}
		else{ // If oldQueue member is not equal to the newQueue member, then that element is removed.
			oldIndex++;
		}
	}
	return newIndex; //returning the newIndex of the queue
}

// Main function
int main() {
    vector<char> oldQueue = {'A', 'B', 'C', 'D', 'E', 'F', 'A', 'B', 'C', 'D', 'A', 'B', 'C', 'A', 'B', 'A'};
    vector<char> newQueue = {'B', 'C', 'E', 'F', 'B', 'C', 'B', 'C', 'B'};
    int currentIndex = 7;
    cout<<"The members of the old Queue are: ";
    for(int i = 0;i<oldQueue.size();i++){
    	cout<<oldQueue[i]<<" ";
    }
    cout<<endl;
    cout<<"The members of the new Queue are: ";
    for(int i = 0;i<newQueue.size();i++){
    	cout<<newQueue[i]<<" ";
    }
    cout<<endl;
    
    char currentIndexMember = oldQueue[currentIndex-1];
    int newIndex = currentIndexMemberNext(oldQueue, newQueue, currentIndex-1);
    cout<<"The new current Index member is: "<<newIndex+1<<endl;

    // The worst case time complexity of the above problem is O(n + m) where n is the length of 
    // old Queue and m is the length of new Queue.

}