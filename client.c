
#include<connect4.h>
#include<my_socket.h>
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
//                      printf("%c %d %d\n",connect4[i][j],i,j);
                }
        }
        for(i=0;i<N1;i++)
                connect4[0][i]=connect4[i][0]=(i+'0');
        connect4[0][N2-1]=(N2-1+'0');
}
int checkWin(int x,int y,char connect4[N1][N2],char flagWin);
int main(){
	char connect4[N1][N2];
	SA server_addr;
	int msg[1];
	int fd_socket,index,sendlen=0,recvlen=0;
	my_socketCli(&fd_socket,MY_TCP,IP,PORT,&server_addr);
	my_connect(fd_socket,(pSA)&server_addr,sizeof(SA));
	printf("Client START!......\n");
	connect4_init(connect4);
	int i,j,x,y;
	while(1){
loop:
		printf("Client's turn：\n");
		scanf("%d",&x);
		if(connect4[1][x]!='_'){
                        printf("Exceed_boundary\n");
                        goto loop;
                }

		for(i=N1-1;i>0;i--){
                        if(connect4[i][x]=='_'){
                                connect4[i][x]='0';
                                y=i;
                                break;
                        }
                }
		connect4_show(connect4);
		msg[0]=x;
		my_send(&sendlen,fd_socket,msg,8);
		if(checkWin(y,x,connect4,'0')){
                        printf("client win\n");
                        break;
                }

		printf("Server's turn:\n");
		my_recv(&recvlen,fd_socket,msg,1024);
		for(i=N1-1;i>0;i--){
                        if(connect4[i][msg[0]]=='_'){
                                connect4[i][msg[0]]='*';
                                y=i;
				break;
                        }
                }

		connect4_show(connect4);
		if(checkWin(y,msg[0],connect4,'*')){
                        printf("server win\n");
                        break;
                }

	}
	my_close(fd_socket);
}
