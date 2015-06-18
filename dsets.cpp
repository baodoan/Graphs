/* Your code here! */

#include <iostream>
#include "dsets.h"

using namespace std;

void DisjointSets:: addelements(int num)
{
	for(int i=0; i<num; i++)
		sets.push_back(-1);	// The root should be negative number
}


// Path Compression
int DisjointSets::find(int elem)
{
	if(sets[elem] < 0)
	  return elem;

	else
	  {
  	    return sets[elem] = find(sets[elem]);
	  }

}

// Union by Size
void DisjointSets::setunion(int a, int b)
{
	int root_a = find(a);
	int root_b = find(b);

	int newSize = sets[root_a] + sets[root_b];

	// If size of root_a > size of root_b. (Note that sets[root_a] and sets[root_b] are negative number
	if(sets[root_a] <= sets[root_b])	
	  {
	    sets[root_b] = root_a;
	    sets[root_a] = newSize;	
	  }

	else
	  {
	     sets[root_a] = root_b;
	     sets[root_b] = newSize;
	  }
	
}









