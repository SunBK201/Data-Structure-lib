#include <cstdlib>
#include "SqQueue.h"
#define MaxSize 100
#define ElemType int

using namespace std;

typedef char VertexType;
typedef int EdgeType;
typedef struct
{
    VertexType Vex[MaxSize];
    EdgeType Edge[MaxSize][MaxSize];
    int vexnum, arcnum;
} MGraph;

void MGraph_Visit(int v)
{
    ;
}

bool DFSvisited[MaxSize];
void DFSTravers(MGraph G)
{
    for (int v = 0; v < G.vexnum; v++)
    {
        DFSvisited[v] = false;
    }
    for (int v = 0; v < G.vexnum; v++)
    {
        if (!DFSvisited[v])
        {
            DFS(G, v);
        }
    }
}
void DFS(MGraph G, int v)
{
    MGraph_Visit(v);
    DFSvisited[v] = true;
    for (int j = 0; j < G.vexnum; j++)
    {
        if (G.Edge[v][j] == 1 && !DFSvisited[j])
        {
            DFS(G, j);
        }
    }
}

bool BFSvisited[MaxSize];
SqQueue BFSQueue;
void BFSTravers(MGraph G)
{
    for (int v = 0; v < G.vexnum; v++)
    {
        BFSvisited[v] = false;
    }
    SqQueue_InitQueue(BFSQueue);
    for (int v = 0; v < G.vexnum; v++)
    {
        if (!BFSvisited[v])
        {
            BFS(G, v);
        }
    }
}
void BFS(MGraph G, int v)
{
    MGraph_Visit(v);
    BFSvisited[v] = true;
    SqQueue_EnQueue(BFSQueue, v);
    while (!SqQueue_IsEmpty(BFSQueue))
    {
        SqQueue_DeQueue(BFSQueue, v);
        for (int j = 0; j < G.vexnum; j++)
        {
            if (G.Edge[v][j] == 1 && !BFSvisited[j])
            {
                MGraph_Visit(j);
                BFSvisited[j] = true;
                SqQueue_EnQueue(BFSQueue, j);
            }
        }
    }
}