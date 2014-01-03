#include <stdio.h>

struct base;
struct base_vtable{
	void (*dance)(struct base*);
	void (*jump)(struct base*, int high);
};

struct base{
	struct base_vtable *vtable;
};

void base_dance(struct base *b){
    	printf("In base dance\n");
	b->vtable->dance(b);
}

void base_jump(struct base *b, int hugh){
    	printf("In base jump\n");
	b->vtable->jump(b, hugh);
}

struct derived1{
	struct base super;
};

void derived1_dance(struct derived1 *d){
    /* implementation of derived1's dance function */
    printf("In derived 1 dance\n");
}

void derived1_jump(struct derived1 *d, int how_high){
    /* implementation of derived 1's jump function */
    printf("In derived 1 jump\n");
}

struct base_vtable derived1_vtable = 
{
    &derived1_dance,
    &derived1_jump
};

void derived1_init(struct derived1 *d){
    d->super.vtable = &derived1_vtable;
}

struct derived2
{
    struct base super;
    /* derived2 members */
};

void derived2_dance(struct derived2 *d){
    /* implementation of derived2's dance function */
    printf("In derived 2 dance\n");
}

void derived2_jump(struct derived2 *d, int how_high){
    /* implementation of derived2's jump function */
    printf("In derived 2 jump\n");
}

struct base_vtable derived2_vtable =
{
   &derived2_dance,
   &derived2_jump
};

void derived2_init(struct derived2 *d){
    d->super.vtable = &derived2_vtable;
}

int main(){
	struct derived1 d1;
	derived1_init(&d1);

	struct derived2 d2;
	derived2_init(&d2);

	struct base *bptr1 = (struct base*)&d1;
	struct base *bptr2 = (struct base*)&d2;

	base_dance(bptr1);
	base_dance(bptr2);

	return 0;
}
