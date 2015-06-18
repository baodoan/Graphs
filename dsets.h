/* Your code here! */

//#ifndef DSETS_H
//#define DSETS_H

#include <vector>

/*
**	DisjointSets object will represent a family of disjoint sets
**	, where each element has an integer index
**
*/ 

class DisjointSets
{
	private:
	// Vector of integer elements
	std::vector<int> sets;

	public:	
	
	void addelements(int num);
	int find(int elem);
	void setunion(int a, int b);

	//std::vector<int> getsets(){return sets;};
};




