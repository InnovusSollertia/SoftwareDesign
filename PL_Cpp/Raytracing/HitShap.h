#pragma once
#include "Ray.h"

struct hit_record
{
	double t;
	vec3 p; // Создаем вектор Р
	vec3 normal; // Создаем вектор Нормали
};

class hitable {
public:

	virtual bool hit(const ray& r, float t_min, float t_max, hit_record& rec) const = 0;

};

class sphere : public hitable {
public:

	sphere() = default;
	sphere(vec3 cen, float r) : center(cen), radius(r) {}
	virtual bool hit(const ray& r, float t_min, float t_max, hit_record& rec) const override
	{
		vec3 oc = r.origin() - center;
		double a = dot(r.direction(), r.direction());
		double b = dot(oc, r.direction());
		double c = dot(oc, oc) - radius * radius;
		double discripminant = b * b - a * c;

		if (discripminant > 0)
		{
			double temp = (-b - sqrt(b * b - a * c)) / a;
			if (temp < t_max && temp > t_min)
			{
				rec.t = temp;
				rec.p = r.point_at_parameter(rec.t);
				rec.normal = (rec.p - center) / radius;
				return true;
			}
		}
		return false;

	}
	vec3 center;
	float radius;

};

class hitable_list : public hitable {
public:

	hitable_list() = default;
	hitable_list(hitable** l, int n)
	{
		list = l;
		list_size = n;
	}

	virtual bool hit(const ray& r, float t_min, float t_max, hit_record& rec) const override
	{
		hit_record temp_rec;
		bool hit_anything = false;
		double closest_so_far = t_max;
		for (int i = 0; i < list_size; i++)
		{
			if (list[i]->hit(r, t_min, closest_so_far, temp_rec))
			{
				hit_anything = true;
				closest_so_far = temp_rec.t;
				rec = temp_rec;
			}
		}
		return hit_anything;
	}

	hitable** list;
	int list_size;
};
