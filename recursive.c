#include<stdio.h>
#include<math.h>
#include<stdlib.h>
void generate_hofstadters_sequence (int *arr, int n){
	int k=n-1;	
	if(n == 2){
		arr[0] = 1;
		arr[1] = 1;
	}
	else{
		generate_hofstadters_sequence(arr,n-1);
		arr[k] = arr[k - arr[k-1]] + arr[k - arr[k-2]];
	}
}
int find_max (int arr[], int index, int max_value){
    if(index == 1){

    	return max_value; 
    }
    else{
        if(max_value<arr[index-1]){
            max_value = arr[index-1];
              
        }
        return find_max(arr,index-1,max_value);
    }
}   
int sum_array (int arr[]){
    int *p = arr;
    if(*(p) == 0){
      return *(p);
    }
    else{
      return *p + sum_array(p+1);
    }
}
double std_array (int arr[], double *mean, int n, int index){
       double sum;

      if(index == n){

        return sum;

      }
      else{

      
        *mean+=((double)arr[index]/(double)n);
        sum = std_array(arr,mean,n,index+1) + pow((double)arr[index] - *mean, 2)/(double)(n-1);
        if(index == 0){
          sum = sqrt(sum);
        }
       
      }

        
}
void part_one(){
	int option,n,arr[500],max,i,*p,sd;
	double mean = 0.0,std;
	for(i=0;i<500;i++){
		arr[i] = 0;
	}
	while(option != 5){
		printf("\nPlease make your choice:\n----------------\n1) Fill array\n2) Find biggest number\n3) Calculate sum\n4) Calculate standart deviation\n5) Exit\n");
		scanf("%d",&option);
		switch(option){
			case 1:
				printf("Please enter an integer:\n");
				scanf("%d",&n);
				generate_hofstadters_sequence(arr,n);
				printf("\n");
				for(i=0;i<n;i++){
					printf("%d ",arr[i]);
				}
				break;
			case 2:
				max = arr[0];
				printf("The biggset number is:%d",find_max(arr,n,max));
				break;
			case 3:
				p = &arr[0];
				printf("The sum of the array is:%d\n",sum_array(p));
				break;
			case 4:
				std = std_array(arr,&mean,n,0);
				printf("The standart deviation is: %f\nThe mean is: %f\n",std,mean);
				break;
			case 5:
				printf("quitting...\n");
				break;


		}
	}

}
void install_pipes (int visited[8][8], int x, int y, int orientation,int counter){
	int z=-1;
	if(counter>64){
		for(int i=0;i<8;i++){
			for (int j = 0; j < 8; j++)
			{
				printf("%d\t",visited[i][j]);
			}
			printf("\n\n");
		}
		
		printf("---------------------------------------------------------------\n");
	}
	switch(orientation){
		case 1:
			if(((x+1)<=7 && (y+2)<=7) && (visited[y+2][x+1]==0)){
				z=1;
				x+=1;
				y+=2;
				visited[y][x]=counter;
				counter++;
				install_pipes(visited,x,y,orientation,counter);
			}else{
				install_pipes(visited,x,y,orientation+1,counter);
			}
			break;

		case 2:
			if((((x-2)<=7 && (x-2)>=0) && (y+1)<=7)  && (visited[y+1][x-2]==0)){
				z=2;
				x-=2;
				y+=1;
				visited[y][x]=counter;
				counter++;
				install_pipes(visited,x,y,orientation-1,counter);
			}else{
				install_pipes(visited,x,y,orientation+1,counter);
			}
			break;

		case 3:
			if((((x-1)<=7 && (x-1)>=0) && ((y-2)<=7 && (y-2)>=0)) && (visited[y-2][x-1]==0)){
				z=3;
				x-=1;
				y-=2;
				visited[y][x]=counter;
				counter++;
				install_pipes(visited,x,y,orientation-2,counter);
			}else{
				install_pipes(visited,x,y,orientation+1,counter);
			}
			break;

		case 4:
			if(((x+2)<=7 && ((y-1)<=7 && (y-1)>=0)) && (visited[y-1][x+2]==0)){
				z=4;
				x+=2;
				y-=1;
				visited[y][x]=counter;
				counter++;
				install_pipes(visited,x,y,orientation-3,counter);
			}else{
				install_pipes(visited,x,y,orientation+1,counter);
			}
			break;

		case 5:
			if((x+2)<=7 && ((y+1)<=7) && (visited[y+1][x+2]==0)){
				z=5;
				x+=2;
				y+=1;
				visited[y][x]=counter;
				counter++;
				install_pipes(visited,x,y,orientation-4,counter);
			}else{
				install_pipes(visited,x,y,orientation+1,counter);
			}
			break;

		case 6:
			if((((x-1)<=7 && (x-1)>=0) && (y+2)<=7) && (visited[y+2][x-1]==0)){
				z=6;
				x-=1;
				y+=2;
				visited[y][x]=counter;
				counter++;
				install_pipes(visited,x,y,orientation-5,counter);
			}else{
				install_pipes(visited,x,y,orientation+1,counter);
			}
			break;

		case 7:
			if((((x-2)<=7 && (x-2)>=0) && ((y-1)<=7 && (y-1)>=0)) && (visited[y-1][x-2]==0)){
				z=7;
				x-=2;
				y-=1;
				visited[y][x]=counter;
				counter++;
				install_pipes(visited,x,y,orientation-6,counter);
			}else{
				install_pipes(visited,x,y,orientation+1,counter);
			}
			break;

		case 8:
			if(((x+1)<=7 && ((y-2)<=7 && (y-2)>=0)) && (visited[y-2][x+1]==0)){
				z=8;
				x+=1;
				y-=2;
				visited[y][x]=counter;
				counter++;
				install_pipes(visited,x,y,orientation-7,counter);
			}else{
				install_pipes(visited,x,y,orientation+1,counter);
			}
			break;
		default:
			return;
	}
	
	
		visited[y][x]=0;
		counter--;
		if(z==1){
			x-=1;
			y-=2;
			install_pipes(visited,x,y,2,counter);
		}else if(z==2){
			x+=2;
			y-=1;
			install_pipes(visited,x,y,3,counter);
		}else if(z==3){
			x+=1;
			y+=2;
			install_pipes(visited,x,y,4,counter);
		}else if(z==4){
			x-=2;
			y+=1;
			install_pipes(visited,x,y,5,counter);
		}else if(z==5){
			x-=2;
			y-=1;
			install_pipes(visited,x,y,6,counter);
		}else if(z==6){
			x+=1;
			y-=2;
			install_pipes(visited,x,y,7,counter);
		}else if(z==7){
			x+=2;
			y+=1;
			install_pipes(visited,x,y,8,counter);
		}else if(z==8){
			x-=1;
			y+=2;
			install_pipes(visited,x,y,9,counter);
		}
	
}
char* remove_duplicates (char* str){
	if (*str != '\0') 
   { 	
   		if(*str == *(str+1)){
   	   	for(int i=0;str[i]!='\0';i++){
   	   		str[i] = str[i+1];
   	   	}
   	   	remove_duplicates(str);
   	   }
   	  	return remove_duplicates(str+1); 
   		
   	   	
   }
  
    
	
}
void menu(){
	int option,visited[8][8],i,j;
	char str[200],*p;
	printf("Welcome to homework 8, please chose one of the parts to continue\n-----------------\n1) Execute part1\n2) Execute part2\n3) Execute part3\n4) Exit\n");
	scanf("%d",&option);
	switch(option){
		case 1:
			part_one();
			break;
		case 2:
			for(i=0;i<8;i++){
				for(j=0;j<8;j++){
					if(i == 0 && j == 0){
						visited[i][j]=1;
					}
					else{
						visited[i][j]=0;
					}
				}
			}
		install_pipes(visited,0,0,1,2);


		case 3:
			printf("Please enter a string: ");
			scanf(" %[^\n]s",str);
			remove_duplicates(str);
			printf("%s\n",str);
			break;
		
	}




}
void main(){

	menu();


}