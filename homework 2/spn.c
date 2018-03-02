#include <stdio.h>
#include <unistd.h>
#define MAX 17
typedef char line[MAX];

/* sbox eval system
 *
 */
int boxcheck(char a, char b, char c, char d, int box, char in[]) {
	//box passed 
	if(in[0+box] == a && in[1+box] == b && in[2+box] == c && in[3+box] == d)
		return 1;
	return 0;
}

/* in - 16 'bits'(chars) to be evaluated
 * box - 4 boces eval 4 bits each, this selects the box in use
 * 
 */
char substitute(char in[], int box) {
	box *= 4;
	//box passed 0 gives E
	if(boxcheck('0', '0', '0', '0', box, in)) {
		in[0 + box] = '1'; 
		in[1 + box] = '1';
		in[2 + box] = '1';
		in[3 + box] = '0';
		return 0;
	}
	//box passed 1 gives 4
	if(boxcheck('0', '0', '0', '1', box, in)) {
		in[0 + box] = '0'; 
		in[1 + box] = '1';
		in[2 + box] = '0';
		in[3 + box] = '0';
		return 0;
	}
	//box passed 2 gives D
	if(boxcheck('0', '0', '1', '0', box, in)) {
		in[0 + box] = '1'; 
		in[1 + box] = '1';
		in[2 + box] = '0';
		in[3 + box] = '1';
		return 0;
	}
	//box passed 3 gives 1
	if(boxcheck('0', '0', '1', '1', box, in)) {
		in[0 + box] = '0'; 
		in[1 + box] = '0';
		in[2 + box] = '0';
		in[3 + box] = '1';
		return 0;
	}
	//box passed 4 gives 2
	if(boxcheck('0', '1', '0', '0', box, in)) {
		in[0 + box] = '0'; 
		in[1 + box] = '0';
		in[2 + box] = '1';
		in[3 + box] = '0';
		return 0;
	}
	//box passed 5 gives F
	if(boxcheck('0', '1', '0', '1', box, in)) {
		in[0 + box] = '1'; 
		in[1 + box] = '1';
		in[2 + box] = '1';
		in[3 + box] = '1';
		return 0;
	}
	//box passed 6 gives B
	if(boxcheck('0', '1', '1', '0', box, in)) {
		in[0 + box] = '1'; 
		in[1 + box] = '0';
		in[2 + box] = '1';
		in[3 + box] = '1';
		return 0;
	}
	//box passed 7 gives 8
	if(boxcheck('0', '1', '1', '1', box, in)) {
		in[0 + box] = '1'; 
		in[1 + box] = '0';
		in[2 + box] = '0';
		in[3 + box] = '0';
		return 0;
	}
	//box passed 8 gives 3
	if(boxcheck('1', '0', '0', '0', box, in)) {
		in[0 + box] = '0'; 
		in[1 + box] = '0';
		in[2 + box] = '1';
		in[3 + box] = '1';
		return 0;
	}
	//box passed 9 gives A
	if(boxcheck('1', '0', '0', '1', box, in)) {
		in[0 + box] = '1'; 
		in[1 + box] = '0';
		in[2 + box] = '1';
		in[3 + box] = '0';
		return 0;
	}
	//box passed A(10) gives 6
	if(boxcheck('1', '0', '1', '0', box, in)) {
		in[0 + box] = '0'; 
		in[1 + box] = '1';
		in[2 + box] = '1';
		in[3 + box] = '0';
		return 0;
	}
	//box passed B(11) gives C(12)
	if(boxcheck('1', '0', '1', '1', box, in)) {
		in[0 + box] = '1'; 
		in[1 + box] = '1';
		in[2 + box] = '0';
		in[3 + box] = '0';
		return 0;
	}
	//box passed C(12) gives 5
	if(boxcheck('1', '1', '0', '0', box, in)) {
		in[0 + box] = '0'; 
		in[1 + box] = '1';
		in[2 + box] = '0';
		in[3 + box] = '1';
		return 0;
	}
	//box passed D(13) gives 9
	if(boxcheck('1', '1', '0', '1', box, in)) {
		in[0 + box] = '1'; 
		in[1 + box] = '0';
		in[2 + box] = '0';
		in[3 + box] = '1';
		return 0;
	}
	//box passed E(14) gives 0
	if(boxcheck('1', '1', '1', '0', box, in)) {
		in[0 + box] = '0'; 
		in[1 + box] = '0';
		in[2 + box] = '0';
		in[3 + box] = '0';
		return 0;
	}
	//box passed F(15) gives 7
	if(boxcheck('1', '1', '1', '1', box, in)) {
		in[0 + box] = '0'; 
		in[1 + box] = '1';
		in[2 + box] = '1';
		in[3 + box] = '1';
		return 0;
	}

	return 0;
}

char substitute_decrypt(char in[], int box) {
	box *= 4;
	//box passed 0 gives E(14)
	if(boxcheck('0', '0', '0', '0', box, in)) {
		in[0 + box] = '1'; 
		in[1 + box] = '1';
		in[2 + box] = '1';
		in[3 + box] = '0';
		return 0;
	}
	//box passed 1 gives 3
	if(boxcheck('0', '0', '0', '1', box, in)) {
		in[0 + box] = '0'; 
		in[1 + box] = '0';
		in[2 + box] = '1';
		in[3 + box] = '1';
		return 0;
	}
	//box passed 2 gives 4
	if(boxcheck('0', '0', '1', '0', box, in)) {
		in[0 + box] = '0'; 
		in[1 + box] = '1';
		in[2 + box] = '0';
		in[3 + box] = '0';
		return 0;
	}
	//box passed 3 gives 8
	if(boxcheck('0', '0', '1', '1', box, in)) {
		in[0 + box] = '1'; 
		in[1 + box] = '0';
		in[2 + box] = '0';
		in[3 + box] = '0';
		return 0;
	}
	//box passed 4 gives 1
	if(boxcheck('0', '1', '0', '0', box, in)) {
		in[0 + box] = '0'; 
		in[1 + box] = '0';
		in[2 + box] = '0';
		in[3 + box] = '1';
		return 0;
	}
	//box passed 5 gives C(12)
	if(boxcheck('0', '1', '0', '1', box, in)) {
		in[0 + box] = '1'; 
		in[1 + box] = '1';
		in[2 + box] = '0';
		in[3 + box] = '0';
		return 0;
	}
	//box passed 6 gives a(10)
	if(boxcheck('0', '1', '1', '0', box, in)) {
		in[0 + box] = '1'; 
		in[1 + box] = '0';
		in[2 + box] = '1';
		in[3 + box] = '0';
		return 0;
	}
	//box passed 7 gives F(15)
	if(boxcheck('0', '1', '1', '1', box, in)) {
		in[0 + box] = '1'; 
		in[1 + box] = '1';
		in[2 + box] = '1';
		in[3 + box] = '1';
		return 0;
	}
	//box passed 8 gives 7
	if(boxcheck('1', '0', '0', '0', box, in)) {
		in[0 + box] = '0'; 
		in[1 + box] = '1';
		in[2 + box] = '1';
		in[3 + box] = '1';
		return 0;
	}
	//box passed 9 gives D(13)
	if(boxcheck('1', '0', '0', '1', box, in)) {
		in[0 + box] = '1'; 
		in[1 + box] = '1';
		in[2 + box] = '0';
		in[3 + box] = '1';
		return 0;
	}
	//box passed A(10) gives 9
	if(boxcheck('1', '0', '1', '0', box, in)) {
		in[0 + box] = '1'; 
		in[1 + box] = '0';
		in[2 + box] = '0';
		in[3 + box] = '1';
		return 0;
	}
	//box passed B(11) gives 6
	if(boxcheck('1', '0', '1', '1', box, in)) {
		in[0 + box] = '0'; 
		in[1 + box] = '1';
		in[2 + box] = '1';
		in[3 + box] = '0';
		return 0;
	}
	//box passed C(12) gives B(11)
	if(boxcheck('1', '1', '0', '0', box, in)) {
		in[0 + box] = '1'; 
		in[1 + box] = '0';
		in[2 + box] = '1';
		in[3 + box] = '1';
		return 0;
	}
	//box passed D(13) gives 2
	if(boxcheck('1', '1', '0', '1', box, in)) {
		in[0 + box] = '0'; 
		in[1 + box] = '0';
		in[2 + box] = '1';
		in[3 + box] = '0';
		return 0;
	}
	//box passed E(14) gives 0
	if(boxcheck('1', '1', '1', '0', box, in)) {
		in[0 + box] = '0'; 
		in[1 + box] = '0';
		in[2 + box] = '0';
		in[3 + box] = '0';
		return 0;
	}
	//box passed F(15) guves 5
	if(boxcheck('1', '1', '1', '1', box, in)) {
		in[0 + box] = '0'; 
		in[1 + box] = '1';
		in[2 + box] = '0';
		in[3 + box] = '1';
		return 0;
	}

	return 0;
}

/* swap binary values according to permutation table
 * 2 & 5
 * 3 & 9
 * 4 & 13
 * 7 & 10
 * 8 & 14
 * 12 & 15
 * 1, 6, 11, and 16 do NOT get swapped
 * -1 from all for 0-indexing
 */
int permutation(char in[])
{
	char safePlace = in[1];
	in[1] = in[4];
	in[4] = safePlace;

	safePlace = in[2];
	in[2] = in[8];
	in[8] = safePlace;

	safePlace = in[3];
	in[3] = in[12];
	in[12] = safePlace;

	safePlace = in[6];
	in[6] = in[9];
	in[9] = safePlace;

	safePlace = in[7];
	in[7] = in[13];
	in[13] = safePlace;

	safePlace = in[11];
	in[11] = in[14];
	in[14] = safePlace;

	return 0;
}

int keyschedule(char k[]) {
	int i;
	char temp1, temp2, temp3, temp4;
	temp1 = k[0];
	temp2 = k[1];
	temp3 = k[2];
	temp4 = k[3];
	for(i = 0; i < 12; i++){
		k[i] = k[i + 4];
	}
	k[12] = temp1;
	k[13] = temp2;
	k[14] = temp3;
	k[15] = temp4;

	return 0;
}

int keymix(char in[], char k[]) {
	int i;
	for(i = 0; i < 16; i++) {
		if((in[i] == '1' && k[i] == '1') || (in[i] == '0' && k[i] == '0'))
			in[i] = '0';
		else
			in[i] = '1';
	}

}

int encrypt(char text[], char key[]) {
	keymix(text, key);
	substitute(text, 0);
	substitute(text, 1);
	substitute(text, 2);
	substitute(text, 3);
	permutation(text);
	keyschedule(key);

	keymix(text, key);
	substitute(text, 0);
	substitute(text, 1);
	substitute(text, 2);
	substitute(text, 3);
	permutation(text);
	keyschedule(key);

	keymix(text, key);
	substitute(text, 0);
	substitute(text, 1);
	substitute(text, 2);
	substitute(text, 3);
	permutation(text);
	keyschedule(key);

	keymix(text, key);
	substitute(text, 0);
	substitute(text, 1);
	substitute(text, 2);
	substitute(text, 3);
	keyschedule(key);

	keymix(text, key);
	text[17] = '\0';
	printf("end:\t%s\n", text);

}

int decrypt(char text[], char key[]) {
	keymix(text, key);

	substitute_decrypt(text, 0);
	substitute_decrypt(text, 1);
	substitute_decrypt(text, 2);
	substitute_decrypt(text, 3);
	keyschedule(key);
	keyschedule(key);
	keyschedule(key);

	keymix(text, key);
	permutation(text);
	substitute_decrypt(text, 0);
	substitute_decrypt(text, 1);
	substitute_decrypt(text, 2);
	substitute_decrypt(text, 3);
	keyschedule(key);
	keyschedule(key);
	keyschedule(key);

	keymix(text, key);
	permutation(text);
	substitute_decrypt(text, 0);
	substitute_decrypt(text, 1);
	substitute_decrypt(text, 2);
	substitute_decrypt(text, 3);
	keyschedule(key);
	keyschedule(key);
	keyschedule(key);

	keymix(text, key);
	permutation(text);
	substitute_decrypt(text, 0);
	substitute_decrypt(text, 1);
	substitute_decrypt(text, 2);
	substitute_decrypt(text, 3);
	keyschedule(key);
	keyschedule(key);
	keyschedule(key);

	keymix(text, key);
	text[17] = '\0';
	printf("end:\t%s\n", text);

	return 0;
}

int main(int argc, char* argv[]) {
	//line text = "1111111111111111";
	//line key = "0101010101010101";

	//line text = "1010001101000000";
	//line key = "0101010101010101";

	/*
	printf("/*************************\n");
	printf("%s [-e] [-d] [text] [key]\n\n", argv[0]);
	printf("OPTION\n-e SPN Cipher Encryption");
	printf("-d SPN Cipher Decryption\n\nINPUT");
	printf("key 16-bit key\n");
	printf("text 16-bit (plain/cipher)text\n");
	*/

	return 0;
}