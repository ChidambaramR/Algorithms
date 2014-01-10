#include <stdio.h>

void FooBar(int n){
        int i1 = 1, i3 = 3, i5 = 5;
        for(; i1 <= n; ++i1){
            if(i1 != i3 && i1 != i5)
		continue;
            else{
		if(i1 == i3 && i1 == i5){
			printf("FooBar %d\n",i1);
			i3 += 3;
			i5 += 5;
			continue;
		}
                if(i1 == i3){
                    printf("Foo %d\n",i1);
                    i3 += 3;
                }
                if(i1 == i5){
                    printf("Bar %d\n",i1);
                    i5 += 5;
                }
            }
            putchar('\n');
        }
}

int main(){
	FooBar(20);
	return 0;
}
