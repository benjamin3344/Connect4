
#include"connect4.h"
#include"my_socket.h"
#define IP "127.0.0.1"
#define PORT 8888
void connect4_show(char connect4[][N2]){
	int i,j;
	for(i=0;i<N1;i++){
		for(j=0;j<N2;j++){
			printf("%c ",connect4[i][j]);
		}
		printf("\n");
	}
}
void connect4_init(char connect4[][N2]){
	int i,j;
	for(i=0;i<N1;i++){
		for(j=0;j<N2;j++){
			connect4[i][j]='_';
//			printf("%c %d %d\n",connect4[i][j],i,j);
		}
	}
	for(i=0;i<N1;i++){
		connect4[0][i]=connect4[i][0]=(i+'0');
	}
	connect4[0][N2-1]=(N2-1+'0');
}
int checkWin(int x,int y,char connect4[N1][N2],char flagWin);
int main(){
	int msg[1];
	char connect4[N1][N2];
	SA client_addr;
	int fd_socket,fd_client;
	my_socketSer(&fd_socket,MY_TCP,IP,PORT);
	my_listen(fd_socket,5);
	int sendlen=0,recvlen=0,len=0;
	int i,j,x,y;
	connect4_init(connect4);
	connect4_show(connect4);
	printf("Connect Four START!......\n");
	my_accept(&fd_client,fd_socket,(pSA)&client_addr,&len);
	while(1){
		printf("Client's turn:\n");
		my_recv(&recvlen,fd_client,msg,1024);
		for(i=N1-1;i>0;i--){
			if(connect4[i][msg[0]]=='_'){
				connect4[i][msg[0]]='0';
				y=i;
				break;
			}
		}
		connect4_show(connect4);
		if(checkWin(y,msg[0],connect4,'0')){
                        printf("client win\n");
                        break;
                }

loop:
		printf("Server's turn:\n");
		scanf("%d",&x);
		if(connect4[1][x]!='_'){
			printf("Exceed_boundary\n");
			goto loop;
		}
		for(i=N1-1;i>0;i--){
                        if(connect4[i][x]=='_'){
                                connect4[i][x]='*';
				y=i;
                                break;
                        }
		}
		connect4_show(connect4);
		msg[0]=x;
		//msg[1]=y;
		my_send(&sendlen,fd_client,msg,recvlen);
		if(checkWin(y,x,connect4,'*')){
                        printf("server win\n");
                        break;
                }

	}
	my_close(fd_socket);
	my_close(fd_client);
}
