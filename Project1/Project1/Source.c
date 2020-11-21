#include<stdio.h>
#include<stdint.h>
#include<math.h>
#include<allegro5/allegro.h>
#include<allegro5/allegro_primitives.h>
int n;
double x[1000], y[1000], z, t, d, e,P;

double dist(double a, double b) {
	return a * a + b * b;
}

int main() {
	
	printf("Gireceginiz nokta sayisi = ");
	scanf_s("%d", &n);
	for (int i = 0; i < n; i++) {
		printf("X icin %d . deger  ", i+1);
		scanf_s("%lf", &x[i]);
		printf("Y icin %d . deger  ", i + 1);
		scanf_s("%lf", &y[i]);
		z += x[i]; 
		t += y[i];
	}
	P = 0.999;
	for (int i = 0; i < 10000; i++) {
		int o = 0;
		d = dist(z - x[0], t - y[0]);
		for (int j = 1; j < n; j++) {
			e = dist(z - x[j], t - y[j]);
			if (d < e) { 
				d = e; o = j;}}
		z += (x[o]-z)*P;
		t += (y[o]-t)*P;
		P *= 0.999;}
	printf("\n");
	printf(" Yukaridaki daire = %.3lf \n ve ", sqrt(d));
	printf("merkez (%.1lf , %.1lf) ile cizildiginde, belirtilen tum noktalarin \n dairenin icinde veya uzerinde oldugu gorulmektedir \n", z, t);
	al_init_primitives_addon();
	ALLEGRO_DISPLAY* display = NULL;
	al_init();
	display = al_create_display(600, 600);
	ALLEGRO_COLOR blue = al_map_rgb(0, 0, 255);
	al_draw_line(0, 300, 600, 300, al_map_rgb(255, 255, 255), 2);
	al_flip_display();
	al_draw_line(300, 0, 300, 600, al_map_rgb(255, 255, 255), 2);
	al_flip_display();
	for (int y = 0; y < 600; y++) {
		y += 15;
		al_draw_line(y, 305, y, 295, al_map_rgb(255, 255, 255), 1);
		al_flip_display();}
	for (int g = 0; g < 600; g++) {
		g += 15;
		al_draw_line(305, g, 295, g, al_map_rgb(2550, 255, 255), 1);
		al_flip_display();}
	for (int j = 0; j < n; j++) {
		al_draw_filled_circle(300 + (15*x[j]), 300 - (15*y[j]), 2, al_map_rgb(0, 255, 0));
		al_flip_display();}
	al_draw_circle(300+(15*z),300-(15*t), 15*sqrt(d), al_map_rgb(255, 0, 0), 2);
	al_flip_display();

    float points[8] = {300+(15 * x[0]), 300-(15 * y[0]),300+(15 * x[1]),300 - (15 * y[1]),300+(15 * x[2]),300 - (15 * y[2]),300+(15*sqrt(d)),300+(15*sqrt(d)) };
	al_draw_spline(points, blue, 3);
	al_flip_display();
	
	system("pause");
	
	

	
	
	


	return 0;
}