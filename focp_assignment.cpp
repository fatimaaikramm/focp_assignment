//A C++ Program for Flood Relief System
#include <iostream>
#include <string>
using namespace std;
int main()
{
	//Initialize the available trucks and supply packs
	int trucks = 5;
	int supply_packs = 120;
	//Initialize counters for handled and deferred requests
	int handled = 0;
	int deferred = 0;
	//Process 5 village relief requests as mentioned in manual
	for (int request = 1; request <= 5; request++)
	{
		//Declare variables to store the village conditions
		string damage, route, flood, medical_need, previous_aid;
		string action;
		string village;
		//Declare variables to store family count and need score
		int families;
		int needscore;
		//Declare variables to store points for each condition
		signed int damagepoints, floodpoints, familypoints, medicalpoints, routepoints, previousaid_points;

		//Assign a village name according to the request number
		if (request == 1)
		{
			village = "Riverside Village";
		}
		else if (request == 2)
		{
			village = "Hilltop Settlement";
		}
		else if (request == 3)
		{
			village = "Lakeside Camp";
		}
		else if (request == 4)
		{
			village = "Market Town";
		}
		else
		{
			village = "Bridge Colony";
		}
		//Display the village name
		cout << village << endl;
		//Ask the user to enter the number of families
		cout << "Enter no. of families (10-200): ";
		cin >> families;
		//Validate the family count
		while (families < 10 || families > 200)
		{
			cout << "Invalid input. Enter number between 10 and 200. " << endl;
			cin >> families;
		}
		//Calculate points based on the number of families
		familypoints = families / 10;

		//Input the village damage level
		cout << "What is the level of damage? (low/medium/high): ";
		cin >> damage;
		//Repeat until a valid damage level is entered
		while (damage != "low" && damage != "medium" && damage != "high")
		{
			cout << "Invalid input. Enter low,medium or high: ";
			cin >> damage;
		}
		//Input the flood warning status
		cout << "Is there any flood warning? (yes/no): ";
		cin >> flood;
		//Repeat until yes or no is entered
		while (flood != "yes" && flood != "no")
		{
			cout << "Invalid input. Enter yes or no: ";
			cin >> flood;
		}
		//Input the route status
		cout << "What's the route status? (open/damaged): ";
		cin >> route;
		//Repeat until yes or no is entered
		while (route != "open" && route != "damaged")
		{
			cout << "Invalid input. Enter open or damaged: ";
			cin >> route;
		}
		//Input whether medical assistance is needed
		cout << "Is there any medical need? (yes/no): ";
		cin >> medical_need;
		//Repeat until yes or no is entered
		while (medical_need != "yes" && medical_need != "no")
		{
			cout << "Invalid input. Enter yes or no: ";
			cin >> medical_need;
		}
		//Input whether the village received aid previously
		cout << "Did they get any aid previously? (yes/no): ";
		cin >> previous_aid;
		//Repeat until yes or no is entered
		while (previous_aid != "yes" && previous_aid != "no")
		{
			cout << "Invalid input. Enter yes or no: ";
			cin >> previous_aid;
		}
		cout << "\n" << endl;

		//Assign points according to the damage level
		if (damage == "high")
		{
			damagepoints = 15;
		}
		else if (damage == "medium")
		{
			damagepoints = 10;
		}

		else
		{
			damagepoints = 5;
		}

		//Assign flood warning points
		if (flood == "yes")
		{
			floodpoints = 15;
		}
		else
		{
			floodpoints = 0;
		}

		//Assign points if the route is damaged
		if (route == "damaged")
		{
			routepoints = 10;
		}
		else
		{
			routepoints = 0;
		}

		//Assign medical need points
		if (medical_need == "yes")
		{
			medicalpoints = 25;
		}
		else
		{
			medicalpoints = 0;
		}

		//Deduct points if the village received aid previously
		if (previous_aid == "yes")
		{
			previousaid_points = -10;
		}
		else
		{
			previousaid_points = 0;
		}
		//Calculate the total need score
		needscore = damagepoints + familypoints + routepoints + floodpoints + medicalpoints + previousaid_points;

		//Initialize the required resources
		int trucksneeded = 0;
		int supplyneeded = 0;

		//Select the relief action according to the need score
		if (needscore >= 70)
		{
			trucksneeded = 2;
			supplyneeded = 50;
			action = "Full Relief";
		}
		else if (needscore >= 50)
		{
			trucksneeded = 1;
			supplyneeded = 30;
			action = "Standard Relief";
		}
		else if (needscore >= 30)
		{
			trucksneeded = 1;
			supplyneeded = 10;
			action = "Emergency Kit Only";
		}
		else
		{
			action = "Defer";
		}
		//Check resource availability for Full Relief
		if (action == "Full Relief")
		{
			//Provide full relief if enough resources are available
			if (trucks >= 2 && supply_packs >= 50)
			{
				trucksneeded = 2;
				supplyneeded = 50;
			}
			//Downgrade to Standard Relief if full relief is unavailable
			else if (trucks >= 1 && supply_packs >= 30)
			{
				action = "Standard Relief";
				trucksneeded = 1;
				supplyneeded = 30;
			}
			//Downgrade to Emergency Kit Only if necessary
			else if (trucks >= 1 && supply_packs >= 10)
			{
				action = "Emergency Kit Only";
				trucksneeded = 1;
				supplyneeded = 10;
			}
			//Defer the request if no resources are sufficient
			else
			{
				action = "Defer";
				trucksneeded = 0;
				supplyneeded = 0;
			}
		}
		//Check resource availability for Standard Relief
		else if (action == "Standard Relief")
		{
			if (trucks >= 1 && supply_packs >= 30)
			{
				trucksneeded = 1;
				supplyneeded = 30;
			}
			//Downgrade to Emergency Kit Only if necessary
			else if (trucks >= 1 && supply_packs >= 10)
			{
				action = "Emergency Kit Only";
				trucksneeded = 1;
				supplyneeded = 10;
			}
			//Defer the request if resources are insufficient
			else
			{
				action = "Defer";
				trucksneeded = 0;
				supplyneeded = 0;
			}
		}
		//Check resource availability for Emergency Kit Only
		else if (action == "Emergency Kit Only")
		{
			//Provide the emergency kit if enough resources are available
			if (trucks >= 1 && supply_packs >= 10)
			{
				trucksneeded = 1;
				supplyneeded = 10;
			}
			//Defer the request if resources are insufficient
			else
			{
				 action = "Defer";
				 trucksneeded = 0;
				 supplyneeded = 0;
			}
		}

		//Subtract the used resources from the available resources
		trucks = trucks - trucksneeded;
		supply_packs = supply_packs - supplyneeded;

		//Update the handled and deferred request counters
		if (action == "Defer")
		{
			deferred++;
		}
		else
		{
			handled++;
		}

		//Display the report for the current village
		cout << "Request Report " << endl;
		cout << "--------------------------" << endl;
		cout << "Village: " << village << endl;
		cout << "No. of Families: " << families << endl;
		cout << "Damage: " << damage << endl;
		cout << "Route: " << route << endl;
		cout << "Flood warning: " << flood << endl;
		cout << "Medical Need: " << medical_need << endl;
		cout << "Previous Aid: " << previous_aid << endl;
		cout << "Need Score: " << needscore << endl;
		cout << "Selected Action: " << action << endl;
		cout << "Trucks Used: " << trucksneeded << endl;
		cout << "Supply Packs Used: " << supplyneeded << endl;
		cout << "Trucks Remaining: " << trucks << endl;
		cout << "Supply Packs Remaining: " << supply_packs << endl;
		cout << "--------------------------" << endl;
	}

	//Display the final summary of all requests
	cout << "Final Summary " << endl;
	cout << "--------------------------" << endl;
	cout << "Request Handled: " << handled << endl;
	cout << "Requests Deffered: " << deferred << endl; 

	//Pause the program before closing
	system("pause");
	return 0;
}