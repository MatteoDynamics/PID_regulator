#include "Simulation.h"
#include "Pomieszczenie.h"
#include "Regulator.h"
#include "RegulatorBB.h"
#include "RegulatorPID.h"
#include<windows.h>
#include <fstream>
#include <exception>

void Simulation::iteration(float time)
{
		
		RegulatorBB regulatorBB(room, grzejnik);
		RegulatorPID PID(room, grzejnik);
		regulator = &PID;
		
	while (true)
	{
		Sleep(time);
		time_sim += time;
		//regulator = &regulatorBB;
		regulator = &PID;
		try{
			regulator->steering(-10, time);
		}
		catch (const std::exception& e)
		{
			e.~exception();
			std::cerr << "not configured Regulator" << std::endl;
			exit(1);

		}
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



