#pragma once

struct Element;
struct LinkedGrath;
struct Edge;
LinkedGrath* CreateGrath(Edge[], int);
void PrintGrath(LinkedGrath*);

void NodeToDelete(LinkedGrath*, int);
void DeleteNode(Element* ptrs, int);

void VertexToDelete(LinkedGrath*, int);
void DeleteVertex(Element*, int);

Element* DeleteNodeOrVertexAroundHead(Element*, int); // Delete first keys if they exist and remove the beggining of list


void CreateAndShowAdjacencyMatrix(LinkedGrath*);
// Components of AdjacencyMatrix
void CreateEmptyMatrix();
void FillMatrixWithData(LinkedGrath*);
void PrintAdjacencyMatrix();
// Components of AdjacencyMatrix
