#pragma once
#include "Vec3.h"

class ray {
public:
	// Создаем свет для вектора
	ray() = default;
	// Формула света для вектора
	ray(const vec3& a, const vec3& b, double ti = 0) { A = a; B = b; _time = ti; }

	// Формула света для начального вектора
	vec3 origin() const { return A; }
	// Формула для определения расстояния
	vec3 direction() const { return B; }
	// Определяем время для рендеринга
	double time() const { return _time; }
	// Параметры вектора и точки в 3D-пространстве
	vec3 point_at_parameter(double t) const { return A + t * B; }

	vec3 A;
	vec3 B;
	double _time;
};
