#include <bits/stdc++.h>
using namespace std;
struct range
{
  long int first;
  long int second;
  long int size;
};

bool
compareRange (range i1, range i2)
{
  return (i1.second > i2.second);
}

long int
translate (vector < range > tmap, long int init)
{
  int flag = 0;
  sort (tmap.begin (), tmap.end (), compareRange);
for (auto x:tmap)
	{
	  if (init > x.second)
		{
		  flag = 1;
		  if ((init - x.second) < x.size)
			{
			  return x.first + (init - x.second);
			}
		  else
			{
			  return init;
			}
		}
	}
  if (flag == 0)
	{
	  return init;
	}
  return 0;
}

int
main ()
{
  fstream file;
  vector < range > seed_to_soil;
  vector < range > soil_to_fertilizer;
  vector < range > fertilizer_to_water;
  vector < range > water_to_light;
  vector < range > light_to_temperature;
  vector < range > temperature_to_humidity;
  vector < range > humidity_to_location;
  string map_type;
  vector < long int >seeds;
  long int nums[3];
  int k;
  long int smallloc = INT_MAX;

  file.open ("day5.txt", ios::in);
  if (file.is_open ())
	{
	  string tp;
	  string T;
	  string p;

	  while (getline (file, tp))
		{

		  if (tp.find ("seeds:") == 0)
			{
			  size_t pos = tp.find (':');
			  string ss = tp.substr (pos + 2, tp.size () - pos-2);
			  stringstream X (ss);
			  while (getline (X, T, ' '))
				{
				  seeds.push_back (stol (T));
				}
			}

		  if (tp[0] >= 'a' && tp[0] <= 'z')
			map_type = tp;

		  if (map_type == "seed-to-soil map:")
			{
			  k = 0;
			  if (isdigit (tp[0]) == 1)
				{
				  string ss = tp.substr (0, tp.size ());
				  stringstream X (ss);
				  stringstream sp;
				  while (getline (X, p, ' '))
					{

					  nums[k] = stol (p);
					  k++;
					}
				  range r;
				  r.first = nums[0];
				  r.second = nums[1];
				  r.size = nums[2];
				  seed_to_soil.push_back (r);
				}

			}
		  if (map_type == "soil-to-fertilizer map:")
			{
			  k = 0;
			  if (isdigit (tp[0]) == 1)
				{
				  string ss = tp.substr (0, tp.size ());
				  stringstream X (ss);
				  stringstream sp;
				  while (getline (X, p, ' '))
					{

					  nums[k] = stol (p);
					  k++;
					}
				  range r;
				  r.first = nums[0];
				  r.second = nums[1];
				  r.size = nums[2];
				  soil_to_fertilizer.push_back (r);
				}
			}
		  if (map_type == "fertilizer-to-water map:")
			{
			  k = 0;
			  if (isdigit (tp[0]) == 1)
				{
				  string ss = tp.substr (0, tp.size ());
				  stringstream X (ss);
				  stringstream sp;
				  while (getline (X, p, ' '))
					{

					  nums[k] = stol (p);
					  k++;
					}
				  range r;
				  r.first = nums[0];
				  r.second = nums[1];
				  r.size = nums[2];
				  fertilizer_to_water.push_back (r);
				}

			}
		  if (map_type == "water-to-light map:")
			{
			  k = 0;
			  if (isdigit (tp[0]) == 1)
				{
				  string ss = tp.substr (0, tp.size ());
				  stringstream X (ss);
				  stringstream sp;
				  while (getline (X, p, ' '))
					{

					  nums[k] = stol (p);
					  k++;
					}
				  range r;
				  r.first = nums[0];
				  r.second = nums[1];
				  r.size = nums[2];
				  water_to_light.push_back (r);
				}

			}
		  if (map_type == "light-to-temperature map:")
			{
			  k = 0;
			  if (isdigit (tp[0]) == 1)
				{
				  string ss = tp.substr (0, tp.size ());
				  stringstream X (ss);
				  stringstream sp;
				  while (getline (X, p, ' '))
					{

					  nums[k] = stol (p);
					  k++;
					}
				  range r;
				  r.first = nums[0];
				  r.second = nums[1];
				  r.size = nums[2];
				  light_to_temperature.push_back (r);
				}

			}
		  if (map_type == "temperature-to-humidity map:")
			{
			  k = 0;
			  if (isdigit (tp[0]) == 1)
				{
				  string ss = tp.substr (0, tp.size ());
				  stringstream X (ss);
				  stringstream sp;
				  while (getline (X, p, ' '))
					{

					  nums[k] = stol (p);
					  k++;
					}
				  range r;
				  r.first = nums[0];
				  r.second = nums[1];
				  r.size = nums[2];
				  temperature_to_humidity.push_back (r);
				}

			}
		  if (map_type == "humidity-to-location map:")
			{
			  k = 0;
			  if (isdigit (tp[0]) == 1)
				{
				  string ss = tp.substr (0, tp.size ());
				  stringstream X (ss);
				  stringstream sp;
				  while (getline (X, p, ' '))
					{

					  nums[k] = stol (p);
					  k++;
					}
				  range r;
				  r.first = nums[0];
				  r.second = nums[1];
				  r.size = nums[2];
				  humidity_to_location.push_back (r);
				}
			}
		}
	}
  long int temp;
for (auto x:seeds)
	{
	  temp = translate (seed_to_soil, x);
	  temp = translate (soil_to_fertilizer, temp);
	  temp = translate (fertilizer_to_water, temp);
	  temp = translate (water_to_light, temp);
	  temp = translate (light_to_temperature, temp);
	  temp = translate (temperature_to_humidity, temp);
	  temp = translate (humidity_to_location, temp);
	  if (temp < smallloc)
		{
		  smallloc = temp;
		}
	}
  cout << "\n" << smallloc;


}
