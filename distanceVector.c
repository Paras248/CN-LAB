#include<stdio.h>
struct node
{
	unsigned distance[3];
	unsigned from[3];
}router[3];

int main()
{
	int distance_mat[3][3] = {
		{ 0, 2, 7 },
		{ 2, 0, 1 },
		{ 7, 1, 0 },
	};
	int n = 3,i,j,k,count=0;

	for(i=0;i<n;i++)
		for(j=0;j<n;j++)
		{	
			distance_mat[i][i]=0;
			router[i].distance[j]=distance_mat[i][j];
			router[i].from[j]=j;
		}
		do
		{	
			count=0;
			for(i=0;i<n;i++){
				for(j=0;j<n;j++){
					for(k=0;k<n;k++){
						if(router[i].distance[j]>distance_mat[i][k]+router[k].distance[j])
						{
							router[i].distance[j]=router[i].distance[k]+router[k].distance[j];
							router[i].from[j]=k;
							count++;
						}
					}
				}
			}
		}while(count!=0);
		for(i=0;i<n;i++)
		{
			printf("\n\nState value for router %d is \n",i+1);
			for(j=0;j<n;j++)
			{
				printf("\t\nnode %d via %d Distance %d",j+1,router[i].from[j]+1,router[i].distance[j]);
			}
		}	
	printf("\n\n");
}



