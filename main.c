#include "user.h"
#include "menu.h"

int main(int argc, char* argv[]) {
  LOGIN* userlist[100]; // 사용자목록 포인터 배열 (최대 100)
  int is_login=0; // 로그인 여부 (0 NO, 1 Yes)
  char echo[50];
  char select[10];
  if (argc != 2) {
    printf("Usage : manager <datafile>\n");
    return 0;
  }
  int count = load_file(userlist, argv[1]);
  while(1){
    printf("> ");
    scanf("%s", select);   
    if(strcmp(select, "login")==0){
	 if(is_login==0) is_login = login(userlist, count);
	while(is_login==1){
		printf("#");
		fgets(echo, sizeof(echo),stdin);
		echo[strlen(echo)-1]=0;
		if(strcmp(echo, "logout")==0){
			logout(&is_login);
		} else{
			printf("%s\n",echo);
		}

	}
   //	 menu_id = ask_menu(is_login); // 현재 로그인 되었는지의 여부를 파라미터로 알려야 한다.
    } 
    else if(strcmp(select, "join")==0){
	 join(userlist, count);
        count++;
    }
    else if(strcmp(select, "list")==0){
	list(userlist, count);
    }
    else if(strcmp(select, "exit")==0){
	break;
    }
    else {
	printf("No such command!\n");
    }

 /*   if(is_login==0) is_login = login(userlist, count);
    menu_id = ask_menu(is_login); // 현재 로그인 되었는지의 여부를 파라미터로 알려야 한다.
    if(menu_id==1) join(userlist, count);
    else if (menu_id==2) is_login = login(userlist, count);
    else if (menu_id==3) logout(&is_login);
    else break;*/
  }
  save_file(userlist, count, argv[1]);
  return 0;
}
