#include <fstream>
#include <iostream>
#include "Ray.h"
#include "float.h"
#include "HitShap.h"
#include "Camera.h"

#include <ctime> // Подключаем библиотеку для времени
#include <random> // Подключаем библиотек для случайных значений

std::default_random_engine reng(time(nullptr)); // Определяем начальное значение нашего движка как nullptr
std::uniform_real_distribution<double> uni_dist(0.0f, 1.0f); // Говорим конечные значения наших фигур

using namespace std;

vec3 radom_unit_sphere()
{
	vec3 p; // Создаем вектор P
	do
	{
		p = 2.0 * vec3(uni_dist(reng), uni_dist(reng), uni_dist(reng)) - vec3(1.0f, 1.0f, 1.0f); // Вычисляем вектор P

	} while (p.squared_length() >= 1.0); // Его длина должна быть меньше или равна 1

	return p; // Возвращаем вектор Р
}

vec3 color(const ray& r, hitable* world) // Определяем цвет нашего вектора
{
	hit_record rec;
	if (world->hit(r, 0.0f, DBL_MAX, rec))
	{
		vec3 target = rec.p + rec.normal + radom_unit_sphere(); // Формула света
		return 0.5f * color(ray(rec.p, target - rec.p), world); // Возращаем свет
	}
	else
	{
		vec3 unit_direction = unit_vector(r.direction()); // Определяем расстояие до объекта
		double t = 0.5f * (unit_direction.y() + 1.0); // Формула для определения расстояния
		return (1.0f - t) * vec3(1.0f, 1.0f, 1.0f) + t * vec3(0.5f, 0.7f, 1.0f); // Возвращаем умножение вектора на свет и расстояние
	}

}


int main()
{
	// Определяем координаты окна
	int nx = 600;
	int ny = 300;
	int ns = 64;

	// Выводим файл
	ofstream fout("image.ppm");
	fout << "P3\n" << nx << " " << ny << "\n255\n";
	cout << "Rendering..." << endl;

	// Создаем сферу из вектора
	hitable* list[2];
	list[0] = new sphere(vec3(0, 0, -1), 0.5);
	list[1] = new sphere(vec3(0, -100.5, -1), 100);
	hitable* world = new hitable_list(list, 2);

	camera cam; // Создаем камеру

	for (int j = ny - 1; j >= 0; j--)
	{
		for (int i = 0; i < nx; i++)
		{
			vec3 col(0, 0, 0);
			for (int s = 0; s < ns; s++)
			{
				// Рисуем векторы
				float u = float(i) / float(nx);
				float v = float(j) / float(ny);
				ray r = cam.get_ray(u, v);
				vec3 p = r.point_at_parameter(2.0);
				col += color(r, world);
			}

			// Добавляем цвет для вектора
			col /= float(ns);
			col = vec3(sqrt(col[0]), sqrt(col[1]), sqrt(col[2]));
			int ir = int(255.99f * col[0]);
			int ig = int(255.99f * col[1]);
			int ib = int(255.99f * col[2]);

			fout << ir << " " << ig << " " << ib << "\n";
		}
	}
	// Выводим результат
	cout << "Rendering completed" << endl;
	fout.close();
}