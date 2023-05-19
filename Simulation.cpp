#include "Simulation.h"
#include "Pomieszczenie.h"
#include<windows.h>
#include <fstream>
constexpr float POWER = 1;
void Simulation::iteration(float time)
{
	while (true)
	{
		Sleep(time);
		time_sim += time;
		room.aktualizuj(time);
		grzejnik.set_current_power(POWER);
		room.dodajCieplo(grzejnik.power());
		
		break;
	}
	
}

void Simulation::run(int iterations, float time_probing)
{

	for (int i = 0; i < iterations; i++)
	{
		iteration(time_probing);
		time.push_back(get_time());
		std::cout << "time: " << get_time() << "ms" << std::endl;
		temp.push_back(room.getTemperatura());
		std::cout << "pomieszczczenie: " << room.getTemperatura() << "^C" << std::endl;
		power.push_back(grzejnik.power());
		std::cout << "moc grzejnika: " << grzejnik.power()<< "W" << std::endl;
		std::cout << std::endl;
	}
}

void Simulation::save(const std::string name)
{

	std::ofstream file;
	std::locale polishLocale("pl_PL.UTF-8");
	file.imbue(polishLocale);
	file.open(name, std::ofstream::out);

	// Save time, power, and temp columns
	file << "Time;Power;Temp" << std::endl; // Column headers
	for (int i = 0; i < time.size(); i++)
	{
		if (i < time.size())
			file << time[i];
		file << ";";

		if (i < power.size())
			file << power[i];
		file << ";";

		if (i < temp.size())
			file << temp[i];
		file << std::endl;
	}

	file.close();
}



