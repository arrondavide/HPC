#include <stdio.h>
#include <stdlib.h>

//the cuda crypt function takes in a raw password of ONLY 2 letters (ONLY LOWERCASE) and 2 numbers. Your task is to take this function and create a "__device__ crypt" function which can be used within the "__global__" function. That way, you can encrypt all combinations and check this password with rawPassword to determine whether a match has been found. 

char* cudaCrypt(char* rawPassword){

	static char newPassword[11]; //use static as a local pointer should not be returned

	newPassword[0] = rawPassword[0] + 2;
	newPassword[1] = rawPassword[0] - 2;
	newPassword[2] = rawPassword[0] + 1;
	newPassword[3] = rawPassword[1] + 3;
	newPassword[4] = rawPassword[1] - 3;
	newPassword[5] = rawPassword[1] - 1;
	newPassword[6] = rawPassword[2] + 2;
	newPassword[7] = rawPassword[2] - 2;
	newPassword[8] = rawPassword[3] + 4;
	newPassword[9] = rawPassword[3] - 4;
	newPassword[10] = '\0';

	for(int i =0; i<10; i++){
		if(i >= 0 && i < 6){ //checking all lower case letter limits
			if(newPassword[i] > 122){
				newPassword[i] = (newPassword[i] - 122) + 97;
			}else if(newPassword[i] < 97){
				newPassword[i] = (97 - newPassword[i]) + 97;
			}
		}else{ //checking number section
			if(newPassword[i] > 57){
				newPassword[i] = (newPassword[i] - 57) + 48;
			}else if(newPassword[i] < 48){
				newPassword[i] = (48 - newPassword[i]) + 48;
			}
		}
	}
	return newPassword;
}

void main(){

char *passInput = malloc(sizeof(char) * 4);

passInput = "hp93";

char *newPasswordFromMethod = malloc(sizeof(char)* 11);
newPasswordFromMethod = cudaCrypt(passInput);

printf("%s\n", newPasswordFromMethod);


}
