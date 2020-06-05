// 5 kyu
// Can You OOP in C? - Polymorphism


////////////////////////////////////////////////////////
// shape.h
typedef struct _shape_vtable_t {
	double (*get_area)();
	double (*get_perimenter)();
	void (*destroy)();
} shape_vtable_t;

typedef struct _shape_t {
	shape_vtable_t *vtable;
} shape_t;

////////////////////////////////////////////////////////
// right_triangle.h

typedef struct {
	shape_t shape;
	double a, b;
} rtriangle;

rtriangle *right_triangle_create(double, double);

////////////////////////////////////////////////////////
// right_triangle.c
#include <stdlib.h>


double
get_area(rtriangle *t)
{
	return (t->a * t->b) / 2.0;
}

double
get_perimeter(rtriangle *t)
{
	return t->a + t->b + sqrt(t->a * t->a + t->b * t->b);
}


const shape_vtable_t triangle_vtab = { get_area, get_perimeter, free };

rtriangle *
right_triangle_create(double a, double b)
{
	rtriangle *p = malloc(sizeof(*p));
	p->shape.vtable = &triangle_vtab;
	p->a = a;
	p->b = b;
	return p;
}
