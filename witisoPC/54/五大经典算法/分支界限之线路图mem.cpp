#include <iostream>
#include <queue>
using namespace std;

const int n = 7;
const int m = 7;
int grid[n+2][m+2];

int cells[n+2][m+2]={
	{1, 1, 1, 1, 1, 1, 1, 1, 1},
	{1, 0, 0, 1, 0, 0, 0, 0, 1},
	{1, 0, 0, 1, 1, 0, 0, 0, 1},
	{1, 0, 0, 0, 0, 1, 0, 0, 1},
	{1, 0, 0, 0, 1, 1, 0, 0, 1},
	{1, 1, 0, 0, 0, 1, 0, 0, 1},
	{1, 1, 1, 1, 0, 0, 0, 0, 1},
	{1, 1, 1, 1, 0, 0, 0, 0, 1},
	{1, 1, 1, 1, 1, 1, 1, 1, 1},
};
//布线问题队列式分支限界法求解




struct Position
{
	int row;
	int col;
};

bool FindPath(Position start,Position finish,int& PathLen,Position *&path);

int main()
{
	int PathLen;
	
	Position start,finish,*path;
	
	start.row = 3;
	start.col = 2;
	
	finish.row = 4;
	finish.col = 6;
	
	cout<<"布线起点"<<endl;
	cout<<start.col<<" "<<start.row<<endl;
	cout<<"布线结束点"<<endl;
	cout<<finish.col<<" "<<finish.row<<endl;
	
	cout<<"布线方格阵列如下(0表示允许布线，1表示不允许布线)："<<endl;
	for(int i=0; i<=m+1; i++)
	{
		for(int j=0; j<=n+1; j++)
		{
			grid[i][j]=cells[i][j];
			cout<<grid[i][j]<<" ";
		}
		cout<<endl;
	}
	
	FindPath(start,finish,PathLen,path);
	
	cout<<"布线长度为:"<<PathLen<<endl;
	cout<<"布线路径如下："<<endl;
	for(i=0; i<=PathLen; i++)
	{
		cout<<path[i].col<<" "<<path[i].row<<endl;
	}
	
	return 0;
}

bool FindPath(Position start,Position finish,int& PathLen,Position *&path)
{
	//计算从起始位置start到目标位置finish的最短布线路径
	if((start.row == finish.row) && (start.col == finish.col))
	{
		PathLen = 0;
		return true;
	}
	
	//设置方格阵列“围墙”
	for(int i=0; i<= m+1; i++)
	{
		grid[0][i]=grid[n+1][i]=1; //顶部和底部
	}
	for(i=0; i<= n+1; i++)
	{
		grid[i][0]=grid[i][m+1]=1; //左翼和右翼
	}
	
	//初始化相对位移
	Position offset[4];
	
	offset[0].row=0;
	offset[0].col=1;//右
	
	offset[1].row=1;
	offset[1].col=0;//下
	
	offset[2].row=0;
	offset[2].col=-1;//左
	
	offset[3].row=-1;
	offset[3].col=0;//上
	
	int NumOfNbrs=4;//相邻方格数
	Position here,nbr;
	here.row=start.row;
	here.col=start.col;
	
	grid[start.row][start.col]=2;//标记可达方格位置
	queue<Position> Q;
	
	do {//标记相邻可达方格
		for(int i=0; i<=NumOfNbrs;i++)
		{
			nbr.row=here.row + offset[i].row;
			nbr.col=here.col + offset[i].col;
			
			if(grid[nbr.row][nbr.col]==0)//该方格未被标记

			    grid[nbr.row][nbr.col]=grid[here.row][here.col]+1; 
			if((nbr.row==finish.row) && (nbr.col==finish.col))
			{
				break; //完成布线
			}
			Q.push(nbr);

		}
		//是否到达目标位置finish
		if((nbr.row==finish.row) && (nbr.col==finish.col))
		{
			break;//完成布线
		}
		
		//活结点队列是否非空？
		if(Q.empty())
		{
			return false;//无解
		}
		here=Q.front();//取下一个扩展结点
		Q.pop();
	}while(true);
	
	//构造最短布线路径
	PathLen=grid[finish.row][finish.col]-2;
	path=new Position[PathLen];//从目标位置finish开始向起始位置回溯
    here=finish;	
	for(int j=PathLen-1; j>=0; j--)
	{
		path[j]=here;//找前驱位置
		for(int i=0; i<=NumOfNbrs; i++)
		{
			nbr.row=here.row+offset[i].row; 
			nbr.col=here.col+offset[i].col; 
			if(grid[nbr.row][nbr.col]==j+2) 
			{
				break;
			}
		}
		here=nbr;//向前移动
	}
	return true;
}
