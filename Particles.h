#pragma once
#include "Points vectors.h"
#include <vector>
#include "Globals.h"

class Particle
{
public:
	Point2<float> pos;
	Point3<unsigned char> color;
	Point2<float> velocity;
	float alpha; // transparency
	Particle();
	Particle(float x, float y);
	Particle(float x, float y, unsigned char r, unsigned char g, unsigned char b, float alpha);
};

class Particles_grid {
public:
	Particles_grid(int width, int height);
	void update_grid();
	void add_particle(Particle particle);
	std::vector<std::vector<Point3<float>>>& get_ptrGrid();
	std::vector<Particle>& get_ptrParticles();
protected:
	void update_particlesGrid();
	void update_colorsGrid();
	void draw_line_in_particlesGrid(int x1, int y1, int x2, int y2, int idx);

	int width, height;
	float fade = 20;
	Point3<float> fillColor;
	std::vector<Particle> particles;
	std::vector <std::vector<Point3<float>>> colorsGrid;
	std::vector <std::vector<std::vector<int>>> particlesGrid;
};

class Draw_particles {
public:
	Draw_particles(Particles_grid &ptrGrid);
	void update_window_frame();
	int* get_window_frame();
	float screenScale;

private:
	Particles_grid &ptrGrid;
	int* img;
};

class Physics_particles {
public:
	Physics_particles(std::vector<Particle>& particles);
	void move_particles();
private:
	std::vector<Particle>& ptrParticles;
};