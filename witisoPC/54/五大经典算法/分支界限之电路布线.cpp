#include<iostream>
#include<iomanip>
#include<queue>
using namespace std;

typedef struct Position
{
    int row;
    int col;
}Posi;

// find the shortest path for the grid
bool FindPath(Posi start,Posi finish,int & PathLen,
              int **&grid,Posi *& path,int n,int m)
{
    // if the start position is the finish position
    if((start.row == finish.row) && (start.col == finish.col))
    {
        PathLen = 0;
        return true;
    }

    Position offset[4];

    offset[0].row = -1; // up
    offset[0].col = 0;

    offset[1].row = 1;  // down
    offset[1].col = 0;

    offset[2].row = 0;  // left
    offset[2].col = -1;

    offset[3].row = 0;  // right
    offset[3].col = 1;

    Posi here,nbr;      // new born
    here.row = start.row;
    here.col = start.col;
    int NumOfNbrs = 4;  // ajacent position;

    grid[start.row][start.col] = 2;
	                    // init the start position's length  with value 2,
    queue<Posi> Q;
    do
    {
        for(int i = 0;i < NumOfNbrs;i++)
        {
            nbr.row = here.row + offset[i].row;
            nbr.col = here.col + offset[i].col;

            if(grid[nbr.row][nbr.col] == 0) 
				         // this position haven't been visited
            {
                grid[nbr.row][nbr.col] = grid[here.row][here.col] + 1;

                if((nbr.row == finish.row) && (nbr.col == finish.col))
                          // find the shortest path
                    break;
                Q.push(nbr);
            }
        }

        if((nbr.row == finish.row) && (nbr.col ==finish.col))
            break;        // wiring was completed

        if(Q.empty())     // if queue is empty
            return false; // no result

        here = Q.front();
        Q.pop();

    }while(true);

    // traceback the shortest path
    PathLen = grid[finish.row][finish.col]-2;
    path = new Posi[PathLen];

    here = finish;

    for(int i = PathLen-1;i >=0;i--)
    {
        path[i] = here;
        for(int j = 0;j < NumOfNbrs;j++)
        {
            nbr.row = here.row + offset[j].row;
            nbr.col = here.col + offset[j].col;

            if(grid[nbr.row][nbr.col] == i+2)
                // It is the nbr's grid that why the  
                // grid[nbr.row][nbr.col] can give index of "i+2"
                break;
        }
        here = nbr;// move to the previous node
    }
    return true;
}

// allocate memory for the grid
void InitGrid(int **&grid,int n,int m)
{
    int cells[7][7]={
        {0, 0, 1, 0, 0, 0, 0},
        {0, 0, 1, 1, 0, 0, 0},
        {0, 0, 0, 0, 1, 0, 0},
        {0, 0, 0, 1, 1, 0, 0},
        {1, 0, 0, 0, 1, 0, 0},
        {1, 1, 1, 0, 0, 0, 0},
        {1, 1, 1, 0, 0, 0, 0},
    };
    grid = new int*[n+2];
    for(int i = 0;i < n+2;i++)
        grid[i] = new int[m+2];
    // set the bound
    for(int index = 0;index < m+2;index++) // top and bottom
        grid[0][index] = grid[n+1][index]  = 1;

    for(index = 0;index < n+2;index++)     // left and right
        grid[index][0] = grid[index][m+1] = 1;

    for(i = 1;i < n+1;i++)
    {
        for(int j = 1;j < m+1;j++)
            grid[i][j]=cells[i-1][j-1];
    }
}

// destroy the resource for the grid
void Destroy(int ** &grid,int n,int m)
{
    if(grid != NULL)
    {
        for(int i  = 0;i < n+2;i++)
        {
            delete [] grid[i];
            grid[i]  = NULL;
        }
        delete grid;
        grid = NULL;
    }
}

void outputMap(int** grid,int n,int m)
{
    for(int i = 1;i < n+1;i++)
    {
        for(int j = 1;j < m+1;j++)
            cout<<setw(2)<<grid[i][j]<<" ";
        cout<<endl;
    }
    cout<<endl;
}

int main(void)
{
    int m = 0,n = 0;
    Posi start,finish;
    int PathLength = 0;

    Posi * path = NULL;
    int ** grid  = NULL;

    //cout<<"Please input the m and n of the grid:"<<endl;
    //cin>>n>>m;
    m=7;n=7;
    //cout<<"Please input the start position:"<<endl;
    //cout<<"start:row =";
    //cin>>start.row;
    start.row = 3;
    //cout<<"start:col =";
    //cin>>start.col;
    start.col = 2;

    //cout<<"Please input the finish position:"<<endl;
    //cout<<"finish:row =";
    //cin>>finish.row;
    finish.row = 4;
    //cout<<"finish:col =";
    //cin>>finish.col;
    finish.col = 6;

    InitGrid(grid,n,m);
    cout<<"the map resource:"<<endl;

    outputMap(grid,m,n);

    FindPath(start,finish,PathLength,grid,path,n,m);
    cout<<"The shortest path of wiring is :"<<PathLength<<endl;
    cout<<"The path if follow:"<<endl;

    for(int index = 0;index < PathLength;index++)
    {
        cout<<"("<<path[index].row<<","<<path[index].col<<")";
        if(index < PathLength-1)
            cout<<"-->";
        if(index>1 && (index+1)%3==0) cout<<endl;
    }
    cout<<endl;
    
    outputMap(grid,m,n);
    
    // Destory the resource of grid
    Destroy(grid,n,m);

    // release the path's resource
    if(path != NULL)
    {
        delete [] path;
        path = NULL;
    }

    getchar();
    return 0;
}
/*
the map resource:
 0  0  1  0  0  0  0
 0  0  1  1  0  0  0
 0  0  0  0  1  0  0
 0  0  0  1  1  0  0
 1  0  0  0  1  0  0
 1  1  1  0  0  0  0
 1  1  1  0  0  0  0

The shortest path of wiring is :9
The path if follow:
(3,3)-->(4,3)-->(5,3)-->
(5,4)-->(6,4)-->(6,5)-->
(6,6)-->(5,6)-->(4,6)

 5  4  1  0  0  0  0
 4  3  1  1  0  0  0
 3  2  3  4  1  0  0
 4  3  4  1  1 11  0
 1  4  5  6  1 10  0
 1  1  1  7  8  9 10
 1  1  1  8  9 10 11
 */