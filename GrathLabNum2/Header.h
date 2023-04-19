#pragma once

struct Element;
struct LinkedGrath;
struct Edge;
LinkedGrath* CreateGrath(Edge[], int);
void PrintGrath(LinkedGrath*);
void DeleteNodes(LinkedGrath*, int);
void DeleteVertex(LinkedGrath*, int);

void CreateAndShowAdjacencyMatrix(LinkedGrath*);
// Components of AdjacencyMatrix
void CreateEmptyMatrix();
void FillMatrixWithData(LinkedGrath*);
void PrintAdjacencyMatrix();
// Components of AdjacencyMatrix
