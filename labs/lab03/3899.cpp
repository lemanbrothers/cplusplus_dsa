//https://web.facebook.com/CungHocLapTrinhUIT/

#include <iostream>
using namespace std;
int main()
{
	string str = "LA0KCAA0BABBAJ0AP0BP0BQ0DS0CR0DO0IH0JG0KE0HG0GH0IE0JD0LC0MD0NC0OC0PC0QC0QEKABA0SDMA0TD0TE0VD0UE0UF0UF0TH0UG0UG0UG0UH0UH0TH0RJ0OM0OL0OJ0LL0JL0GABI0GACGQAAA0KGQA0KEPAAAAAAA0KCEAMA0KBUA0";
	int i = 0, j = 1, c;
	while (str[i] != 0){
		c = str[i++];
		if (c > 64){
			while (c-- > 64) cout << (33 ^ (j & 0x01));
			j++;
		}
		else{
			cout << (c - 38);
			j = 1;
		}
	}
	//getc(stdin); 
	getchar();
	return 0;
}