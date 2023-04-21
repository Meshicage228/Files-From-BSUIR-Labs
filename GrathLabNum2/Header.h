#pragma once

#define N 9
#define DELETE_VERTEX 7
#define DELETE_NODE 2

struct Element;
struct LinkedGrath;
struct Edge;
LinkedGrath* CreateGrath(Edge[], int);
void PrintGrath(LinkedGrath*);

void DeleteVertexOrNode(LinkedGrath*, int);
void DeleteNode(Element* ptrs, int);
void DeleteVertex(Element*, int);

Element* DeleteNodeOrVertexAroundHead(Element*, int); // Delete first keys if they exist and remove the beggining of list

void CreateAndShowAdjacencyMatrix(LinkedGrath*);
// Components of AdjacencyMatrix
void CreateEmptyMatrix();
void FillMatrixWithData(LinkedGrath*);
void PrintAdjacencyMatrix();
// Components of AdjacencyMatrix
