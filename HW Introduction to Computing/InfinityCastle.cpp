#include<iostream>
#include<iomanip>
using namespace std;


int main(){
	int slayerLevel, hp, hasTalisman; 
	int demonPresence, demonRank, allyCount;
	int bossHP, totalDamage, specialMoveReady;
	double breathingMastery, swordSharpness;
	char timeOfDay;

	cin >> slayerLevel >> hp >> breathingMastery >> hasTalisman >> timeOfDay >> demonPresence >> demonRank >>
	swordSharpness >> allyCount >> bossHP >> totalDamage >> specialMoveReady;

//Scene 1 - Power Classification
	cout << "[Scene 1] ";
	double power = slayerLevel*10 + (float)(hp/10) + breathingMastery*50;
	if(power >= 120){
		cout <<"Rank: Hashira (power = " << fixed << setprecision(1) << power << ")"<< endl;
	}else if(power < 80){
		cout <<"Rank: Novice (power = " << fixed << setprecision(1) << power << ")"<< endl;
	}else{
		cout <<"Rank: Elite (power = " << fixed << setprecision(1) << power << ")"<< endl;
	}

//Scene 2 - The infinity Castle Gate
	cout << "[Scene 2] ";
	if(hasTalisman == 0) cout << "Denied: No talisman." << endl;
	else if(timeOfDay != 'D' && timeOfDay != 'N') cout << "Warning: invalid timeOfDay." << endl;
	else if(timeOfDay == 'N' && demonPresence == 1) cout << "Open silently." << endl;
	else cout << "Open cautiously." << endl;
//Scene 3 - Battle Strategy
	cout << "[Scene 3] ";
	double adv = (float)(101 - demonRank*15) + swordSharpness*0.4 + allyCount*5;
	if(adv >= 100) cout << "Engage head-on (adv = " << fixed << setprecision(1) << adv << ")" << endl;
	else if (adv < 60) cout << "Retreat and regroup (adv = " << fixed << setprecision(1) << adv << ")" << endl;
	else cout << "Harass and probe (adv = " << fixed << setprecision(1) << adv << ")" << endl;

//Scene 4 - Final Outcome
	cout << "[Scene 4] ";
	int finalHP = bossHP - totalDamage;
	if(finalHP <= 0) cout << "Boss defeated! (finalHP = 0)" << endl;
	else if(finalHP > 0 && specialMoveReady == 1 && finalHP <= 50) cout << "Use special move to finish! (finalHP = " << finalHP << ")" << endl;
	else cout << "Withdraw to heal. (finalHP = " << finalHP << ")" << endl;

    return 0;
}
//Input:
//8 950 0.8 1 N 1 3 72.5 2 420 380 1
//Output:
// [Scene 1] Rank: Hashira (power = 215.0)
// [Scene 2] Open silently.
// [Scene 3] Harass and probe (adv = 95.0)
// [Scene 4] Use special move to finish! (finalHP = 40)