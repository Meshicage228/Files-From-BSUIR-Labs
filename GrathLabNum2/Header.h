#pragma once

#define N 10 // Here write YOUR N = (number of vertexes + 1)
#define DELETE_VERTEX 6 // Here write YOUR vertex, which you want to delete
#define DELETE_NODE 3 // Here write YOUR node, which you want to delete

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
