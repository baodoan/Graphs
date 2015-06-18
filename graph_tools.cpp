/**
 * @file graph_tools.cpp
 * This is where you will implement several functions that operate on graphs.
 * Be sure to thoroughly read the comments above each function, as they give
 *  hints and instructions on how to solve the problems.
 */

#include "graph_tools.h"

#include <map>

/**
 * Returns the shortest distance (in edges) between the Vertices
 *  start and end.
 * THIS FUNCTION IS GRADED.
 *
 * @param graph - the graph to search
 * @param start - the vertex to start the search from
 * @param end - the vertex to find a path to
 * @return the minimum number of edges between start and end
 *
 * @todo Label each edge "MINPATH" if it is part of the minimum path
 *
 * @note Remember this is the shortest path in terms of edges,
 *  not edge weights.
 * @note Again, you may use the STL stack and queue.
 * @note You may also use the STL's unordered_map, but it is possible
 *  to solve this problem without it.
 *
 * @hint In order to draw (and correctly count) the edges between two
 *  vertices, you'll have to remember each vertex's parent somehow.
 */
int GraphTools::findShortestPath(Graph & graph, Vertex start, Vertex end)
{
	int Shortest_Path =0;	

	std::map<Vertex, Vertex> Vertex_map;	
	vector<Vertex> Verticies = graph.getVertices();
	queue<Vertex> Queue;
	
	// Initialize all Vertices being UNEXPLORED 
	for(auto v: Verticies)
	graph.setVertexLabel(v, "UNEXPLORED");	


	// First, add the Vertex start into the queue as our initial location, mark it VISITED
	Queue.push(start);
	graph.setVertexLabel(start, "VISITED");

	// BFS Traversal
	while(!Queue.empty())
	{

	  vector<Vertex> Adj_Verticies = graph.getAdjacent(Queue.front());
	  
	Vertex v =Queue.front(); 
	Queue.pop();
		
		// Travel BFS
	  for(auto aV: Adj_Verticies)
		{
			// int strcmp ( const char * str1, const char * str2 );
		  if(graph.getVertexLabel(aV) == "UNEXPLORED")
			{
			 Queue.push(aV);
			 Vertex_map.insert(std::pair<Vertex,Vertex>(aV, v) );
			 graph.setVertexLabel(aV, "VISITED");
			}

		}

	}
	

	while(start!=end)
	{
	graph.setEdgeLabel(end, Vertex_map[end], "MINPATH");
	end = Vertex_map[end];
	Shortest_Path ++;
	}

	
    return Shortest_Path;
}

/**
 * Finds the minimum edge weight in the Graph graph.
 * THIS FUNCTION IS GRADED.
 *
 * @param graph - the graph to search
 * @return the minimum weighted edge
 *
 * @todo Label the minimum edge as "MIN". It will appear blue when
 *  graph.savePNG() is called in minweight_test.
 *
 * @note You must do a traversal.
 * @note You may use the STL stack and queue.
 * @note You may assume the graph is connected.
 *
 * @hint Initially label vertices and edges as unvisited.
 */
int GraphTools::findMinWeight(Graph & graph)
{

	vector<Edge> Edges = graph.getEdges();

	Edge Min_Edge;
	int minWeight = Edges[0].weight;

	//Traversing through all the Edges to find the least Weight
	for(auto E : Edges)
	    {
		if(minWeight >= E.weight)
			{
			 minWeight = E.weight;	
			 Min_Edge = E;	  
			}
	    }


   graph.setEdgeLabel(Min_Edge.source, Min_Edge.dest, "MIN");

    return minWeight;
}

/**
 * Finds a minimal spanning tree on a graph.
 * THIS FUNCTION IS GRADED.
 *
 * @param graph - the graph to find the MST of
 *
 * @todo Label the edges of a minimal spanning tree as "MST"
 *  in the graph. They will appear blue when graph.savePNG() is called.
 *
 * @note Use your disjoint sets class from MP 7.1 to help you with
 *  Kruskal's algorithm. Copy the files into the libdsets folder.
 * @note You may call std::sort (http://www.cplusplus.com/reference/algorithm/sort/)
 *  instead of creating a priority queue.
 */
void GraphTools::findMST(Graph & graph)
{

	//Get a list of all edges in the graph and sort them by increasing weight.
	vector<Edge> Edges = graph.getEdges();
	vector<Vertex> Vertices = graph.getVertices();
	std::sort(Edges.begin(), Edges.end());
	
	//Create a disjoint sets structure where each vertex is represented by a set.
	DisjointSets Dset;
	Dset.addelements(Vertices.size());

	//Traverse the list from the start (i.e., from lightest weight to heaviest).
	for(auto s: Edges)
	{
	int v1 = Dset.find(s.source);
	int v2 = Dset.find(s.dest);

	/* Inspect the current edge. If that edge connects two vertices from different sets, 
	   union their respective sets and mark the edge as part of the MST. 
  	   Otherwise there would be a cycle, so do nothing.
	*/
	
		if(v1 != v2)
			{
			 Dset.setunion(v1, v2);
			 graph.setEdgeLabel(s.source, s.dest, "MST");
			}
	}	



}






