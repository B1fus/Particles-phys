#include "Particles.h"

Particle::Particle()
{
	pos = { 0,0 };
	color = { 255,255,255 };
	alpha = 1;
	velocity = { 0,0 };
}

Particle::Particle(float x, float y):pos{x,y}
{
	color = { 255,255,255 };
	alpha = 1;
	velocity = { 0,0 };
}

Particle::Particle(float x, float y, unsigned char r, unsigned char g, unsigned char b, float alpha) :pos{ x,y }, color{r,g,b}, alpha(alpha) {
	velocity = { 0,0 };
}

Particles_grid::Particles_grid(int width, int height):width(width),height(height) {
	fillColor = { 10,10,10 }; 
	colorsGrid = std::vector<std::vector<Point3<float>>>{ static_cast<const unsigned __int64>(width), std::vector < Point3<float>>{static_cast<const unsigned __int64>(height), fillColor} };
	particlesGrid = std::vector<std::vector<std::vector<int>>>{ static_cast<const unsigned __int64>(width), std::vector < std::vector<int>>{static_cast<const unsigned __int64>(height), std::vector<int>()} };
}

//add pariticle in vector
void Particles_grid::add_particle(Particle particle) {
	particles.push_back(particle);
}

//update count of particled in 1 pixel on grid
void Particles_grid::update_particlesGrid() {
	int i = 0;
	for (auto& j : particlesGrid) {
		for (auto& k : j) {
			k.clear();
		}
	}
	for (auto& iter : particles) {
		//if (iter.pos.x >= 0 && iter.pos.x < width && iter.pos.y >= 0 && iter.pos.y < height) {
		//	//particlesGrid[int(iter.pos.x)][int(iter.pos.y)].push_back(i);
		//	//draw_line_in_particlesGrid(iter.pos.x, iter.pos.y, iter.pos.x + iter.velocity.x * DELTA_TIME, iter.pos.y + iter.velocity.y * DELTA_TIME, i);
		//}	
		draw_line_in_particlesGrid(iter.pos.x, iter.pos.y, iter.pos.x + iter.velocity.x * DELTA_TIME, iter.pos.y + iter.velocity.y * DELTA_TIME, i);

		i++;
	}
}

//update grid of colors
void Particles_grid::update_colorsGrid() {
	int i, j, k;
	float alphaSum;
	Particle par;
	for (i = 0; i < width; i++) {
		for (j = 0; j < height; j++) {
			alphaSum = 0;
			//fill all canvas color for filling
			if (REAL_FPS > fade) {
				if (colorsGrid[i][j].x != fillColor.x) {
					colorsGrid[i][j].x -= (colorsGrid[i][j].x - fillColor.x) / REAL_FPS * fade;
				}
				if (colorsGrid[i][j].y != fillColor.y) {
					colorsGrid[i][j].y -= (colorsGrid[i][j].y - fillColor.y) / REAL_FPS * fade;
				}
				if (colorsGrid[i][j].z != fillColor.z) {
					colorsGrid[i][j].z -= (colorsGrid[i][j].z - fillColor.z) / REAL_FPS * fade;
				}
			}
			else {
				if (colorsGrid[i][j].x != fillColor.x) {
					colorsGrid[i][j].x -= (colorsGrid[i][j].x - fillColor.x) ;
				}
				if (colorsGrid[i][j].y != fillColor.y) {
					colorsGrid[i][j].y -= (colorsGrid[i][j].y - fillColor.y) ;
				}
				if (colorsGrid[i][j].z != fillColor.z) {
					colorsGrid[i][j].z -= (colorsGrid[i][j].z - fillColor.z) ;
				}
			}
			for (k = 0; k < particlesGrid[i][j].size(); k++) {
				par = particles[particlesGrid[i][j][k]];
				colorsGrid[i][j].x += par.color.x * par.alpha; //red
				colorsGrid[i][j].y += par.color.y * par.alpha; //green
				colorsGrid[i][j].z += par.color.z * par.alpha; //blue
				alphaSum += par.alpha;
			}
			if (particlesGrid[i][j].size() > 0) {
				if (alphaSum < 1) alphaSum = 1;
				colorsGrid[i][j] /= alphaSum; //normilize color
				if (colorsGrid[i][j].x > 255) {
					colorsGrid[i][j] /= (colorsGrid[i][j].x / 255);
				}
				if (colorsGrid[i][j].y > 255) {
					colorsGrid[i][j] /= (colorsGrid[i][j].y / 255);
				}
				if (colorsGrid[i][j].z > 255) {
					colorsGrid[i][j] /= (colorsGrid[i][j].z / 255);
				}
			}
		}
	}
}

void Particles_grid::update_grid() {
	update_particlesGrid();
	update_colorsGrid();
}

void Particles_grid::draw_line_in_particlesGrid(int x1, int y1, int x2, int y2, int idx)
{
	Point2<char> pos1;
	pos1.x = x1 < 0 ? -1 : 0;
	pos1.x = x1 >= width ? 1 : pos1.x;
	pos1.y = y1 < 0 ? -1 : 0;
	pos1.y = y1 >= height ? 1 : pos1.y;
	Point2<char> pos2;
	pos2.x = x2 < 0 ? -1 : 0;
	pos2.x = x2 >= width ? 1 : pos2.x;
	pos2.y = y2 < 0 ? -1 : 0;
	pos2.y = y2 >= height ? 1 : pos2.y;
	if (abs(pos1.x + pos2.x) == 2)
		return;
	if (abs(pos1.y + pos2.y) == 2)
		return;

	int dx = x2 - x1;
	int dy = y2 - y1;

	int x, y;

	if (pos1.x == -1) {
		x = 0;
		y = (dy * x - x1 * dy + y1 * dx) / dx;
		if (y < 0 || y >= height) {
			y = 0;
			x = (dx * y + x1 * dy - y1 * dx) / dy;
		}
		if (x < 0 || y >= width)
			return;
		x1 = x;
		y1 = y;
	}

	else if (pos1.x == 1) {
		x = width - 1;
		y = (dy * x - x1 * dy + y1 * dx) / dx;
		if (y < 0 || y >= height) {
			y = height - 1;
			x = (dx * y + x1 * dy - y1 * dx) / dy;
		}
		if (x < 0 || y >= width)
			return;
		x1 = x;
		y1 = y;
	}

	else if (pos1.y == -1) {
		y = 0;
		x = (dx * y + x1 * dy - y1 * dx) / dy;
		if (x < 0 || x >= width) {
			x = 0;
			y = (dy * x - x1 * dy + y1 * dx) / dx;
		}
		if (y < 0 || y >= height)
			return;
		x1 = x;
		y1 = y;
	}

	else if (pos1.y == 1) {
		y = height - 1;
		x = (dx * y + x1 * dy - y1 * dx) / dy;
		if (x < 0 || x >= width) {
			x = width - 1;
			y = (dy * x - x1 * dy + y1 * dx) / dx;
		}
		if (y < 0 || y >= height)
			return;
		x1 = x;
		y1 = y;
	}

	if (pos2.x == -1) {
		x = 0;
		y = (dy * x - x2 * dy + y2 * dx) / dx;
		if (y < 0 || y >= height) {
			y = 0;
			x = (dx * y + x2 * dy - y2 * dx) / dy;
		}
		if (x < 0 || y >= width)
			return;
		x2 = x;
		y2 = y;
	}

	else if (pos2.x == 1) {
		x = width - 1;
		y = (dy * x - x2 * dy + y2 * dx) / dx;
		if (y < 0 || y >= height) {
			y = height - 1;
			x = (dx * y + x2 * dy - y2 * dx) / dy;
		}
		if (x < 0 || y >= width)
			return;
		x2 = x;
		y2 = y;
	}

	else if (pos2.y == -1) {
		y = 0;
		x = (dx * y + x2 * dy - y2 * dx) / dy;
		if (x < 0 || x >= width) {
			x = 0;
			y = (dy * x - x2 * dy + y2 * dx) / dx;
		}
		if (y < 0 || y >= height)
			return;
		x2 = x;
		y2 = y;
	}

	else if (pos2.y == 1) {
		y = height - 1;
		x = (dx * y + x2 * dy - y2 * dx) / dy;
		if (x < 0 || x >= width) {
			x = width - 1;
			y = (dy * x - x2 * dy + y2 * dx) / dx;
		}
		if (y < 0 || y >= height)
			return;
		x2 = x;
		y2 = y;
	}
	dx = x2 - x1;
	dy = y2 - y1;

	int dx1, dy1, px, py, xe, ye, i;
	dx1 = abs(dx);
	dy1 = abs(dy);
	px = 2 * dy1 - dx1;
	py = 2 * dx1 - dy1;
	if (dy1 <= dx1)
	{
		if (dx >= 0)
		{
			x = x1;
			y = y1;
			xe = x2;
		}
		else
		{
			x = x2;
			y = y2;
			xe = x1;
		}
		if (!(x < 0 || y < 0 || x >= width || y >= height))
		particlesGrid[x][y].push_back(idx);
		for (i = 0; x < xe; i++)
		{
			x = x + 1;
			if (px < 0)
			{
				px = px + 2 * dy1;
			}
			else
			{
				if ((dx < 0 && dy < 0) || (dx > 0 && dy > 0))
				{
					y = y + 1;
				}
				else
				{
					y = y - 1;
				}
				px = px + 2 * (dy1 - dx1);
			}
			if (!(x < 0 || y < 0 || x >= width || y >= height))
			particlesGrid[x][y].push_back(idx);
		}
	}
	else
	{
		if (dy >= 0)
		{
			x = x1;
			y = y1;
			ye = y2;
		}
		else
		{
			x = x2;
			y = y2;
			ye = y1;
		}
		if (!(x < 0 || y < 0 || x >= width || y >= height))
		particlesGrid[x][y].push_back(idx);
		for (i = 0; y < ye; i++)
		{
			y = y + 1;
			if (py <= 0)
			{
				py = py + 2 * dx1;
			}
			else
			{
				if ((dx < 0 && dy < 0) || (dx > 0 && dy > 0))
				{
					x = x + 1;
				}
				else
				{
					x = x - 1;
				}
				py = py + 2 * (dx1 - dy1);
			}
			if (!(x < 0 || y < 0 || x >= width || y >= height))
			particlesGrid[x][y].push_back(idx);
		}
	}

}


std::vector<std::vector<Point3<float>>>& Particles_grid::get_ptrGrid() {
	return colorsGrid;
}

std::vector<Particle>& Particles_grid::get_ptrParticles() {
	return particles;
}

Draw_particles::Draw_particles(Particles_grid& ptrGrid) :ptrGrid(ptrGrid) {
	img = new int[ptrGrid.get_ptrGrid().size() * ptrGrid.get_ptrGrid()[0].size()];
}

int* Draw_particles::get_window_frame() {
	return img;
}

//update array for output in window
void Draw_particles::update_window_frame() {
	auto colorsGrid = ptrGrid.get_ptrGrid();
	int* ptrColor;
	int i, j;
	for (j = 0; j < colorsGrid[0].size(); j++) {
		for (i = 0; i < colorsGrid.size(); i++) {
			ptrColor = &img[colorsGrid.size() * j + i];
			*ptrColor = 0 | unsigned char(colorsGrid[i][j].x) << 16;
			*ptrColor |= unsigned char(colorsGrid[i][j].y) << 8;
			*ptrColor |= unsigned char(colorsGrid[i][j].z);
		}
	}
}

Physics_particles::Physics_particles(std::vector<Particle>& particles) : ptrParticles(particles) {}

//editing velocity and position particle
void Physics_particles::move_particles() {
	int j;
	float dist = 0;
	for (auto& iter : ptrParticles) {

		iter.pos += iter.velocity * DELTA_TIME; //move particle
		Particle* ptrPart;

		//edit velocity
		for (j = 0; j < 1; j++) {
			ptrPart = &ptrParticles[rand() % ptrParticles.size()];
			dist = Vec2<float>(iter.pos.x - ptrPart->pos.x, iter.pos.y - ptrPart->pos.y).length();
			
			ptrPart->velocity += (iter.pos - ptrPart->pos) / (pow(dist + 1, 1.5)) * 10 * 10;
			iter.velocity -= (iter.pos - ptrPart->pos) / (pow(dist + 1, 1.5)) * 10 * 10;

			//iter.velocity -= (iter.pos - ptrPart->pos) / 30000;
			//iter.pos -= (ptrPart->velocity.x - iter.velocity.y) * (ptrPart->velocity.y - iter.velocity.x * float(rand())/RAND_MAX*10) / 2000000;
			//dist = Vec2<float>(iter.pos.x - ptrPart->pos.x, iter.pos.y - ptrPart->pos.y).length();
			//iter.velocity -= (ptrPart->velocity.x/20 - iter.velocity.y/2000) * (ptrPart->pos.x - iter.pos.x) * (ptrPart->pos.y - iter.pos.y) / pow(dist+1,1.5 )/ 10000;
		}
		//iter.velocity = { 1,1 };
	}
}