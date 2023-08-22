#include<stdio.h>
#include<string.h>

int main(){
	int a = 0;
	int b = 0;
	int c = 0;
	int d = 0;
	int e = 0;



	char str[100];
	fgets(str, 100, stdin);

	printf("Der eingegebene String lautet -> %s", str);
	printf("Es werden nun alle verwendeten Zeichen gezählt.\n");


	int size = strlen(str) - 1;

	for(int i = 0; i < size; i++){
		if(str[i] == 'a'){
			a++;
		}
		if(str[i] == 'b'){
			b++;
		}
		if(str[i] == 'c'){
			c++;
		}
		if(str[i] == 'd'){
			d++;
		}
		if(str[i] == 'e'){
			e++;
		}
	}

	printf("Es gibt %d 'a'\n", a);
	printf("Es gibt %d 'b'\n", b);
	printf("Es gibt %d 'c'\n", c);
	printf("Es gibt %d 'd'\n", d);
	printf("Es gibt %d 'e'\n", e);


	return 0;
}
