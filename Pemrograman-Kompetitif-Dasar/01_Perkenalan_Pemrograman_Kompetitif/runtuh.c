#include<stdio.h>
#include<stdbool.h>

#define Rm 22
#define Cm 10

int R,C,last_full;

void read_maze(char mz[Rm][Cm], bool fl[Rm]){
	char c;
	for(int i=0;i<R;i++){
		int j = 0;
		while(j<C){
			c = getchar_unlocked();
			if (c == '\n') continue;
			mz[i][j]=c;
			j++;
		}
	}
}

void check_full(char mz[Rm][Cm], bool fl[Rm]){
	for (int i = 0;i<R;i++)fl[i]=1;
	
	for (int i=0;i<R;i++){
		for(int j = 0;j<C;j++){
			if(mz[i][j]=='0'){
				fl[i] = 0;
				break;
			}
		}
	}
}

void clear_full(char mz[Rm][Cm], bool fl[Rm]){
	for (int i=0;i<R;i++){
		if(fl[i]){
			for(int j = 0;j<C;j++){
				mz[i][j]='0';
			}
		last_full = i;
		}
	}
	
}

void print_maze(char mz[Rm][Cm]){
	for (int i=0;i<R;i++){
		for(int j = 0;j<C;j++){
			printf("%c",mz[i][j]);
		}
		printf("\n");
	}
}

void check_finish(bool* fn, bool fl[Rm] ){
	*fn = 0;
	for (int i=0;i<R;i++){
		*fn |= fl[i];
	}
}

void check_last(char mz[Rm][Cm],int last[Cm]){
	int k = 0;
	for (int i=0;i<C;i++){
		last[i] = last_full;
		k = last_full+1;
		while((mz[k][i]!='1')&&(k<R)){
			last[i]++;
			k++;
		}
	}
}

void runtuh(char mz[Rm][Cm], int last[Cm]){
	for(int j = 0;j<C;j++){
		for(int i = last[j];i>=0;i--){
			if(mz[i][j]=='1'){
				mz[i][j]='0';
				mz[last[j]][j]= '1';
				last[j]--;
			}
		}
	}
}

int main() {
	// your code goes here
	char maze[Rm][Cm];
	bool full[Rm], finish=1;
	int last[Cm];
	
	scanf("%d %d",&R,&C);
	
    for(int i=0;i<R;i++){
        full[i] = 1;
    }
	
	read_maze(maze,full);
	
	while(finish){
		check_full(maze,full);
		clear_full(maze,full); 
		check_last(maze,last);
		runtuh(maze,last);
		check_finish(&finish,full);
	}
	print_maze(maze);
	
	return 0;
}